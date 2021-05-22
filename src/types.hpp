#pragma once

#include "str.hpp"

#include <optional>

namespace Common
{
  using OptStr = typename std::optional<Str>;
  using OptInt = typename std::optional<int64_t>;

} // namespace Common