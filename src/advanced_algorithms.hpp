/**
* Brief:
* This file contains all algorithms from STL-library modified are by Alexey.Perestoronin (Alexey.Perestoronin@yandex.ru) for more convenient using in, for example:
* - standart case: instead `std::find(vec.begin(), vec.end(), number)`now is possible to write `AA::Find(vec, number)`
* - different range iterators cases: instead `std::find(++vec.begin(), --vec.end(), number)` possible to write `AA::Find<1, -2>(vec, number)`
* Note1: detailed description of all standart STL-algorithms was found in http://www.cplusplus.com/reference/algorithm/
* Author: Alexey Perestoronin (Alexey.Perestoronin@yandex.ru)
* Year: 2021
*/

#pragma once

#include "index_iterator_static.hpp"
#include "index_iterator.hpp"

#include "errors/base_error.hpp"

#include <algorithm>
#include <optional>


#define AA_RAISE_ERROR(what_happend) \
  RAISE_ERROR("common.lib:AdvancedAlgorithms", what_happend);


namespace Common
{
  /**
  * brief: the class that contains all advanced versions of standard std-algorithms from <algorithm>-include-file
  */
  namespace AA // Advanced Algorithms
  {
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
    template<int64_t from = 0, int64_t to = -1, bool isOptionalResult = true, class Collection, class Value>
    decltype(auto) Find(Collection& collection, Value&& value);

    template<int64_t from = 0, int64_t to = -1, bool isOptionalResult = true, class Collection, class Action>
    decltype(auto) FindIf(Collection& collection, Action&& action);

  } // namespace AA

} // namespace Common


#include "advanced_algorithms/_find.hpp"
#include "advanced_algorithms/_any.hpp"


#undef AA_RAISE_ERROR
