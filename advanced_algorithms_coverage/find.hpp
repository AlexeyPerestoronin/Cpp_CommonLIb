#pragma once

#include "advanced_algorithms_coverage/index_iterator.hpp"

#include <algorithm>

namespace Common {
    namespace AAC // Advanced Algorithms Coverage
    {
        template<int64_t from = 0, int64_t to = -1, bool is_optional_result = true, class CollectionType, class ValueType>
        decltype(auto) Find(const CollectionType& collection, const ValueType& value) {
            static_assert((from > 0 && to > 0 ? from <= to : true) && (from < 0 && to < 0 ? from <= to : true), "from-position must be less then to-position Common::AAC::Find");

            CII<CollectionType> iis(collection);
            typename CollectionType::const_iterator resultIt{ std::find(iis(from), iis(to), value) };
            if constexpr (is_optional_result) {
                std::optional<typename CollectionType::value_type> resultOp;
                if (resultIt != iis(to))
                    resultOp = *resultIt;
                return resultOp;
            } else {
                return resultIt;
            }
        }

    } // namespace AAC

} // namespace Common