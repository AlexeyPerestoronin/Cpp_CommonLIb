#pragma once

namespace Common {
    namespace AAC // Advanced Algorithms Coverage
    {
        /**
        * Description:
        * Here are the implementation of all search-algorithms from SLT by means of applying AAC-Logic to each of them.
        * For example, consider the std::search-algorithm vs its advanced implementation - AAC::Search:
        * (1)
        * `std::search(where.begin(), where.end(), what.begin(), what.end())`
        * vs
        * `AAC::Search(MakeCIT(where), MakeCIT(what))`
        * (2)
        * `std::search(where.begin(), where.end(), what.begin(), ++(++(++what.begin())))`
        * vs
        * `AAC::Search(MakeCIT(where), MakeCIT(what, 0, 3))`
        * (3)
        * `std::search(where.begin(), where.end(), --(--(--what.end())), what.end())`
        * vs
        * `AAC::Search(MakeCIT(where), MakeCIT(what, -3, -1))`
        */

        // link: http://www.cplusplus.com/reference/algorithm/search/
        template<bool is_bool_result = true, class CollectionTypeWhere, class CollectionTypeWhat>
        decltype(auto) Search(const CIT<CollectionTypeWhere>& cit_where, const CIT<CollectionTypeWhat>& cit_what) {
            typename CollectionTypeWhere::const_iterator resultIt{ std::search(cit_where.GetFrom(), cit_where.GetTo(), cit_what.GetFrom(), cit_what.GetTo()) };
            if constexpr (is_bool_result) {
                return resultIt != cit_where.GetTo();
            } else {
                return resultIt;
            }
        }

        // link: http://www.cplusplus.com/reference/algorithm/search_n/
        template<bool is_bool_result = true, class CollectionTypeWhere, class ValueTypeWhat>
        decltype(auto) SearchN(const CIT<CollectionTypeWhere>& cit_where, uint64_t how_many, const ValueTypeWhat& value_what) {
            typename CollectionTypeWhere::const_iterator resultIt{ std::search_n(cit_where.GetFrom(), cit_where.GetTo(), how_many, std::forward<decltype(value_what)>(value_what)) };
            if constexpr (is_bool_result) {
                return resultIt != cit_where.GetTo();
            } else {
                return resultIt;
            }
        }

    } // namespace AAC

} // namespace Common
