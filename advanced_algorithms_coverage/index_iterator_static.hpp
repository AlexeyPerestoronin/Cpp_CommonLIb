#pragma once

#include "ptr.hpp"
#include "errors/base_error.hpp"
#include "manipulating_types/choosing_types.hpp"

#include <stdint.h>
#include <type_traits>

namespace Common {
    namespace AAC // Advanced Algorithms Coverage
    {
        /**
        * brief: creates static iterator to predefined position inside container
        * param-t: is_const - flag: if true working as iterator to constant data; if false - as iterator to not constant data
        * param-t: index - predefined position to iterator
        * note1:
        *   `index` can be a negative value!
        *   for example:
        *   -1 = std::end(container)
        *   -2 = --std::end(container)
        *   -3 = --(--std::end(container))
        *    ...
        *   -N = --(...N-3...(--std::end(container)...N-3...)
        */
        template<bool is_const, int64_t index, class Collection>
        class IndexIteratorStatic {
            using _MainClassType = typename IndexIteratorStatic<is_const, index, Collection>;
            PtrCls(_MainClassType);

            using _CollectionType = typename MT::AddConstIfNeed<is_const, Collection>::Value;
            using _CollectionIteratorType = typename MT::AddConstIfNeed<is_const, typename _CollectionType::iterator, typename _CollectionType::const_iterator>::Value;

            private:
            _CollectionIteratorType _it;

            private:
            template<int64_t start, int64_t stop>
            void StepToEnd() {
                if constexpr (start != stop) {
                    ++_it;
                    StepToEnd<start + 1, stop>();
                }
            }

            template<int64_t start, int64_t stop>
            void StepToBegin() {
                if constexpr (start != stop) {
                    --_it;
                    StepToBegin<start - 1, stop>();
                }
            }

            public:
            IndexIteratorStatic(_CollectionType& collection)
                : _it{ index >= 0 ? MT::GetBeginIterator<is_const, _CollectionType>(collection).Get() : MT::GetEndIterator<is_const, _CollectionType>(collection).Get() } {
                if (size_t elements_quantity{ collection.size() }; index > 0 ? index >= elements_quantity : -index > elements_quantity)
                    RAISE_ERROR("advanced_algorithms_coverage", "index out of range in static-index-iterator");
                if constexpr (index >= 0)
                    StepToEnd<0, index>();
                else
                    StepToBegin<-1, index>();
            }

            /**
            * brief: gets iterator to predefined position
            * return: iterator to the static-indexed element
            */
            _CollectionIteratorType Get() const {
                return _it;
            }

            operator _CollectionIteratorType() const {
                return Get();
            }
        }; // class IndexIteratorStatic

        template<int64_t index, class Collection>
        using IIS = typename IndexIteratorStatic<false, index, Collection>;

        template<int64_t index, class Collection>
        using CIIS = typename IndexIteratorStatic<true, index, Collection>;

    } // namespace AAC

} // namespace Common
