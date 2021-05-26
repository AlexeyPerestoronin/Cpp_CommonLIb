/**
* Brief: Advanced implementation of std::find algorithm
* Author: Alexey Perestoronin (Alexey.Perestoronin@yandex.ru)
* Year: 2021
*/

#pragma once

#include "_common_aa_include.hpp"


namespace Common
{
  template<bool isNeedCheck>
  class AdvancedAlgorithms
  {
  public:
    /**
    * brief: finds element in collection in predefined range - [from, to)
    * t-param: from - index of start element
    * t-param: to - index of end element
    * t-param: isOptionalResult - if true the result is option type; if false - iterator type
    * param: collection - target collection for find
    * param: value - desired element
    * return: if isOptionalResult-flag is true - optional value with desired element; otherwise - iterator to found element or end-iterator
    * ---
    * example1: Find(vec, 5) - pass over all container elements
    * example2: Find<1, -2>(vec, 5) - pass over all container elements excepted first and last elements
    * example3: Find<-2, -1>(vec, 5) - pass over penultimate and last container elements
    */
    template<int64_t from = 0, int64_t to = -1, bool isOptionalResult = true, class Collection, class Action>
    static decltype(auto) Find(Collection& collection, Action&& value)
    {
      static_assert((from > 0 && to > 0 ? from <= to : true) && (from < 0 && to < 0 ? from <= to : true), "from-position must be less then to-position");

      if constexpr (isNeedCheck)
      {
        size_t size{ collection.size() };
        if (!(from > 0 ? from < size : -from <= size))
          AA_RAISE_ERROR("from-position cannot be greater than collection size");
        if (!(to > 0 ? to < size : -to <= size))
          AA_RAISE_ERROR("to-position cannot be greater than collection size");
      }

      IIS<from, Collection> iisFrom(collection);
      IIS<to, Collection> iisTo(collection);
      Collection::iterator resultIt(std::find(iisFrom.Get(), iisTo.Get(), value));
      if constexpr (isOptionalResult)
      {
        std::optional<Collection::value_type> resultOp;
        if (resultIt != iisTo.Get())
          resultOp = *resultIt;
        return resultOp;
      }
      else
      {
        return resultIt;
      }
    }

  };

} // namespace Common
