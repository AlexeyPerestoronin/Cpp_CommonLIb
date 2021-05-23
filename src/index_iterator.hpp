#pragma once

#include "ptr.hpp"

#include <stdint.h>


namespace Common
{
  /**
  * brief: creates iterator to some container for get its values by index
  */
  template<class Collection>
  class IndexIterator
  {
    using CollectIt = typename Collection::iterator;
    using MainClass = typename IndexIterator<Collection>;
    PtrCls(MainClass)

  private:
    Collection& _collection;

  public:
    IndexIterator(Collection& collection)
      : _collection(collection)
    {
    }

    /**
    * brief: gets the container value by index
    * param: index - position of the needed element in the container
    * note1:
    *   `index` can be a negative value!
    *   for example:
    *   -1 = std::end(container)
    *   -2 = --std::end(container)
    *   -3 = --(--std::end(container))
    *    ...
    *   -N = --(...N-3...(--std::end(container)...N-3...)
    * return: iterator to the indexed element
    */
    CollectIt operator[] (int64_t index) const
    {
      CollectIt result;
      if (index >= 0)
      {
        result = _collection.begin();
        for (; index > 0; --index)
          ++result;
      }
      else
      {
        result = _collection.end();
        for (; index < -1; ++index)
          --result;
      }
      return result;
    }
  };

  template<class Collection>
  using II = typename IndexIterator<Collection>;

} // namespace Common