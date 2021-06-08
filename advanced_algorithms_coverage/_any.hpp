#pragma once

namespace Common {
    namespace AAC // Advanced Algorithms Coverage
    {
        /**
        * Description:
        * Here are the implementation of all any-algorithms from SLT by means of applying AAC-Logic to each of them.
        */

        // link: http://www.cplusplus.com/reference/algorithm/any_of/
        template<class CollectionType, class UnaryPredicateType>
        bool AnyOf(const CIT<CollectionType>& cit, UnaryPredicateType&& predicate) {
            return std::any_of(cit.GetFrom(), cit.GetTo(), std::forward<decltype(predicate)>(predicate));
        }

        // link: http://www.cplusplus.com/reference/algorithm/all_of/
        template<class CollectionType, class UnaryPredicateType>
        bool AllOf(const CIT<CollectionType>& cit, UnaryPredicateType&& predicate) {
            return std::all_of(cit.GetFrom(), cit.GetTo(), std::forward<decltype(predicate)>(predicate));
        }

        // link: http://www.cplusplus.com/reference/algorithm/none_of/
        template<class CollectionType, class UnaryPredicateType>
        bool NoneOf(const CIT<CollectionType>& cit, UnaryPredicateType&& predicate) {
            return std::none_of(cit.GetFrom(), cit.GetTo(), std::forward<decltype(predicate)>(predicate));
        }
    } // namespace AAC

} // namespace Common
