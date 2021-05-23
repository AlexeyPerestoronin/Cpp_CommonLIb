#pragma once

#include "ptr.hpp"

#include <stdint.h>


namespace Common
{
  /**
  * brief: creates static iterator to predefined position inside container
  * param: index - predefined position to iterator
  * note1:
  *   `index` can be a negative value!
  *   for example:
  *   -1 = std::end(container)
  *   -2 = --std::end(container)
  *   -3 = --(--std::end(container))
  *    ...
  *   -N = --(...N-3...(--std::end(container)...N-3...)
  */
  template<int64_t index, class Collection>
  class IndexIteratorStatic
  {
    using CollectIt = typename Collection::iterator;
    using MainClass = typename IndexIteratorStatic<index, Collection>;
    PtrCls(MainClass)

  private:
    CollectIt _it;

  private:
    template<int64_t start, int64_t stop>
    void StepToEnd()
    {
      if constexpr (start != stop)
      {
        ++_it;
        StepToEnd<start + 1, stop>();
      }
    }

    template<int64_t start, int64_t stop>
    void StepToBegin()
    {
      if constexpr (start != stop)
      {
        --_it;
        StepToBegin<start - 1, stop>();
      }
    }

  public:
    IndexIteratorStatic(Collection& collection)
      : _it{ index >= 0 ? std::begin(collection) : std::end(collection) }
    {
      if constexpr (index >= 0)
        StepToEnd<0, index>();
      else
        StepToBegin<-1, index>();
    }


  public:
    /**
    * brief: gets iterator to predefined position
    * return: iterator to the static-indexed element
    */
    CollectIt Get() const
    {
      return _it;
    }

    operator CollectIt() const
    {
      return Get();
    }
  };

  
  template<int64_t index, class Collection>
  using IIS = typename IndexIteratorStatic<index, Collection>;

} // namespace Common
