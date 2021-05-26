/**
* Brief: Common dependencies for all advanced algorithms
* Author: Alexey Perestoronin (Alexey.Perestoronin@yandex.ru)
* Year: 2021
*/

#pragma once

#include "index_iterator_static.hpp"
#include "index_iterator.hpp"

#include "errors/base_error.hpp"

#include <algorithm>
#include <optional>


/**
* brief: the class that contains all advanced versions of standard std-algorithms from <algorithm>-include-file
* t-param: isNeedCheck - flag that activate extended checking of ranges of iterators inside algorithms
*/
template<bool isNeedCheck>
class AdvancedAlgorithms;


#define AA_RAISE_ERROR(what_happend) \
  RAISE_ERROR("common.lib:AdvancedAlgorithms", what_happend);
