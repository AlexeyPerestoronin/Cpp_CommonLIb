#pragma once

#include "ptr.hpp"

#include <string>


namespace Common
{
  /**
  * brief: common utf-8 string class that extends of std::string base class
  */
  class Str : public std::string
  {
    PtrCls(Str)

  private:
    using BaseType = typename std::string;

  public:
    Str() = default;
    Str(Str&&) = default;
    Str(const Str&) = default;
    Str& operator= (Str&&) = default;
    Str& operator= (const Str&) = default;

    template<class ... Args>
    Str(Args&& ... args)
      : BaseType(std::forward<Args>(args)...)
    {
    }

    /**
    * brief: replaces substing in target string
    * note1: performs replacing for all found substrings
    * param: from - current substring
    * param: to - new substring
    * return: current string
    * ---
    * example1: Str("hellow {color} world").Replace("{color}", "green") --> "hellow green world"
    * example2: Str(Replace("how much? - {how}-{how}-{how}").Replace("{how}", "many") --> "how much? - many-many-many"
    */
    Str& Replace(const Str& from, const Str& to);


#pragma region Format
  private:
    template<uint64_t index>
    Str& FormatByIndex(const Str& substring)
    {
      static const Str from = Str("{").append(std::to_string(index)).append("}");
      return Replace(from, substring);
    }

  public:
    /**
    * brief: performs formating string by templates - {0}, {1}, ... {N}
    * note1: performs replacing for all found same templates
    * param: startIndex - index from which replacing must start
    * param: subsring - first substring for replacing
    * param: remainSubstrings - remaining substrings for replacing
    * return: current string
    * ---
    * example1: Str("F-Name L-Name: {0} {1}").Foramt("Alexey", "Perestoronin") --> "F-Name L-Name: Alexey Perestoronin"
    * example2: Str("Today is {2}-{1}-{0}").Format("22", "may", "2021") --> "Today is 2021-may-22"
    */
    template<uint64_t startIndex = 0, class ... Types>
    Str& Format(const Str& substring, const Types& ... remainSubstrings)
    {
      if constexpr (sizeof...(remainSubstrings) == 0)
        return FormatByIndex<startIndex>(substring);
      else
        return FormatByIndex<startIndex>(substring).Format<startIndex + 1>(remainSubstrings...);
    }
  };
#pragma endregion

} // namespace Common