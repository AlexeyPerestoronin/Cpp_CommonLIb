#pragma once

#include "_common_aa_include.hpp"


namespace Common
{
  namespace AA
  {
    template<int64_t from = 0, int64_t to = -1, class Collection, class Action>
    decltype(auto) Find(Collection& collection, Action&& action)
    {
      // TODO: need add static assertions to checking given diapason
      return std::find(
        IIS<from, Collection>(collection).Get(),
        IIS<to, Collection>(collection).Get(),
        action);
    }

  } // namespace AA

} // namespace Common