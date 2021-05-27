#include "str.hpp"

#include "errors/base_error.hpp"

#define RAISE_STR_ERROR(what_happend) RAISE_ERROR("common.lib:Str", what_happend);

namespace Common {
    Str& Str::Replace(const Str& from, const Str& to) {
        if (to.find(from) != std::string::npos)
            RAISE_STR_ERROR("cannot perform recursive replacing");

        for (size_t from_size = from.size(), start = BaseType::find(from); start != std::string::npos; start = BaseType::find(from))
            BaseType::replace(start, from_size, std::move(to));
        return *this;
    }

} // namespace Common

#undef RAISE_STR_ERROR
