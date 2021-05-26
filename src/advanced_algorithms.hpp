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

#include "advanced_algorithms/_common_aa_include.hpp"
#include "advanced_algorithms/_find.hpp"

namespace Common
{
  /**
  * breif: AdvancedAlgorithms with checking of iterating diapason
  */
  using AA = typename AdvancedAlgorithms<true>;

  /**
  * breif: AdvancedAlgorithms without checking of iterating diapason
  */
  using AAN = typename AdvancedAlgorithms<false>;

} // namespace Common


// defined in `advanced_algorithms/_common_aa_include.hpp`
#undef AA_RAISE_ERROR
#undef AA_ASSERT_POSITIONS
