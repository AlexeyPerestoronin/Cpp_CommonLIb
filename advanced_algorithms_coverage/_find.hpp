#pragma once

#define FIND_RETURN_LOGIC                                            \
    if constexpr (is_optional_result) {                              \
        std::optional<typename CollectionType::value_type> resultOp; \
        if (resultIt != cit.GetTo())                                 \
            resultOp = *resultIt;                                    \
        return resultOp;                                             \
    } else {                                                         \
        return resultIt;                                             \
    }

namespace Common {
    namespace AAC // Advanced Algorithms Coverage
    {
        /**
        * Description:
        * Here are the implementation of all find-algorithms from SLT by means of applying AAC-Logic to each of them.
        * For example, consider the std::find-algorithm vs its advanced implementation - AAC::Find:
        * (1)
        * Let us need to find some element among all elements of the vec vector.
        * Using the algorithm from STL, we would write like this: `std::find(vec.begin(), vec.end(), element)`
        * Using the algorithm from AAC, we will write like this:  `AAC::Find(MakeCIT(vec), element)`
        * (2)
        * Let us need to find some element between the second and the penultimate elements of the vec vector.
        * Using the algorithm from STL, we would write like this: `std::find(++vec.begin(), --vec.end(), element)`
        * Using the algorithm from AAC, we will write like this:  `AAC::Find(MakeCIT(vec, 1, -2), element)`
        * (3)
        * Let us need to find some element between the third and third with the end of the elements of the vec vector.
        * Using the algorithm from STL, we would write like this: `std::find(++(++vec.begin()), --(--vec.end()), element)`
        * Using the algorithm from AAC, we will write like this:  `AAC::Find(MakeCIT(vec, 2, -3), element)`
        * Note1:
        * All find-algorithms from AAC are returns ither optional value with the result of searching or the iterator values like an canonical find-algirithm from SLT
        */

        // link: http://www.cplusplus.com/reference/algorithm/find/
        template<bool is_optional_result = true, class CollectionType, class ValueType>
        decltype(auto) Find(const CIT<CollectionType>& cit, ValueType&& value) {
            typename CollectionType::const_iterator resultIt{ std::find(cit.GetFrom(), cit.GetTo(), std::forward<decltype(value)>(value)) };
            FIND_RETURN_LOGIC;
        }

        // link: http://www.cplusplus.com/reference/algorithm/find_if/
        template<bool is_optional_result = true, class CollectionType, class ValueType>
        decltype(auto) FindIf(const CIT<CollectionType>& cit, ValueType&& value) {
            typename CollectionType::const_iterator resultIt{ std::find_if(cit.GetFrom(), cit.GetTo(), std::forward<decltype(value)>(value)) };
            FIND_RETURN_LOGIC;
        }

        // link: http://www.cplusplus.com/reference/algorithm/find_if_not/
        template<bool is_optional_result = true, class CollectionType, class ValueType>
        decltype(auto) FindIfNot(const CIT<CollectionType>& cit, ValueType&& value) {
            typename CollectionType::const_iterator resultIt{ std::find_if_not(cit.GetFrom(), cit.GetTo(), std::forward<decltype(value)>(value)) };
            FIND_RETURN_LOGIC;
        }

        // link: http://www.cplusplus.com/reference/algorithm/find_end/
        template<bool is_optional_result = true, class CollectionType, class CollectionTypeWhere, class... ValuesTypes>
        decltype(auto) FindEnd(const CIT<CollectionType>& cit, const CIT<CollectionTypeWhere>& cit_what, ValuesTypes&&... values) {
            static_assert(sizeof...(ValuesTypes) <= 1, "mustn't send more then one ValuesTypes-type in FindEnd-function");
            typename CollectionType::const_iterator resultIt{ std::find_end(cit.GetFrom(), cit.GetTo(), cit_what.GetFrom(), cit_what.GetTo(), (std::forward<decltype(values)>(values))...) };
            FIND_RETURN_LOGIC;
        }

        // link: http://www.cplusplus.com/reference/algorithm/find_first_of/
        template<bool is_optional_result = true, class CollectionType, class CollectionTypeWhere, class... ValuesTypes>
        decltype(auto) FindFirstOf(const CIT<CollectionType>& cit, const CIT<CollectionTypeWhere>& cit_what, ValuesTypes&&... values) {
            static_assert(sizeof...(ValuesTypes) <= 1, "mustn't send more then one ValuesTypes-type in FindFirstOf-function");
            typename CollectionType::const_iterator resultIt{ std::find_first_of(cit.GetFrom(), cit.GetTo(), cit_what.GetFrom(), cit_what.GetTo(), (std::forward<decltype(values)>(values))...) };
            FIND_RETURN_LOGIC;
        }

        // link: http://www.cplusplus.com/reference/algorithm/adjacent_find/
        template<bool is_optional_result = true, class CollectionType, class... ValuesTypes>
        decltype(auto) FindAdjacent(const CIT<CollectionType>& cit, ValuesTypes&&... values) {
            static_assert(sizeof...(ValuesTypes) <= 1, "mustn't send more then one ValuesTypes-type in FindAdjacent-function");
            typename CollectionType::const_iterator resultIt{ std::adjacent_find(cit.GetFrom(), cit.GetTo(), (std::forward<decltype(values)>(values))...) };
            FIND_RETURN_LOGIC;
        }

    } // namespace AAC

} // namespace Common

#undef FIND_RETURN_LOGIC
