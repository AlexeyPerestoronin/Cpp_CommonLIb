#pragma once

#include <type_traits>

namespace Common {
    namespace MT // manipulating types
    {
#pragma region GetLeftType
        template<bool is_need_left, class LeftType, class RightType>
        struct GetLeftType {
            using Value = RightType;
        };

        template<class LeftType, class RightType>
        struct GetLeftType<true, LeftType, RightType> {
            using Value = LeftType;
        };
#pragma endregion

#pragma region GetRightType
        template<bool is_need_right, class LeftType, class RightType>
        struct GetRightType {
            using Value = LeftType;
        };

        template<class LeftType, class RightType>
        struct GetRightType<true, LeftType, RightType> {
            using Value = RightType;
        };
#pragma endregion

        template<bool is_need_const, class Type, class ConstType = std::add_const_t<Type>>
        struct AddConstIfNeed {
            using Value = typename GetRightType<is_need_const, Type, ConstType>::Value;
        };

#pragma region Get < Begin | End> Iterator
        template<bool is_need_const, class CollectionType>
        struct GetBeginIterator {
            private:
            using _CollectionType = typename AddConstIfNeed<is_need_const, CollectionType>::Value;
            using _CollectionIteratorType = typename AddConstIfNeed<is_need_const, typename _CollectionType::iterator, typename _CollectionType::const_iterator>::Value;

            private:
            _CollectionType& _collection;

            public:
            GetBeginIterator(_CollectionType& collection)
                : _collection{ collection } {}

            _CollectionIteratorType Get() {
                if constexpr (is_need_const)
                    return std::cbegin(_collection);
                else
                    return std::begin(_collection);
            }

            operator _CollectionIteratorType() {
                return Get();
            }
        };

        template<bool is_need_const, class CollectionType>
        struct GetEndIterator {
            private:
            using _CollectionType = typename AddConstIfNeed<is_need_const, CollectionType>::Value;
            using _CollectionIteratorType = typename AddConstIfNeed<is_need_const, typename _CollectionType::iterator, typename _CollectionType::const_iterator>::Value;

            private:
            _CollectionType& _collection;

            public:
            GetEndIterator(_CollectionType& collection)
                : _collection{ collection } {}

            _CollectionIteratorType Get() {
                if constexpr (is_need_const)
                    return std::cend(_collection);
                else
                    return std::end(_collection);
            }

            operator _CollectionIteratorType() {
                return Get();
            }
        };
#pragma endregion

    } // namespace MT

} // namespace Common