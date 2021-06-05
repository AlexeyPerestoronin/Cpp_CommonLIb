#pragma once

#include "ptr.hpp"
#include "errors/base_error.hpp"
#include "manipulating_types/choosing_types.hpp"

#include <stdint.h>

namespace Common {
    namespace AAC // Advanced Algorithms Coverage
    {
        /**
        * brief: creates iterator to some container for get its values by index
        * param-t: is_const - flag: if true working as iterator to constant data; if false - as iterator to not constant data
        */
        template<bool is_const, class Collection>
        class IndexIterator {
            using MainClass = typename IndexIterator<is_const, Collection>;
            PtrCls(MainClass);

            using _CollectionType = typename MT::AddConstIfNeed<is_const, Collection>::Value;
            using _CollectionIteratorType = typename MT::AddConstIfNeed<is_const, typename _CollectionType::iterator, typename _CollectionType::const_iterator>::Value;

            private:
            _CollectionType& _collection;

            public:
            IndexIterator(Collection& collection)
                : _collection(collection) {}

            /**
            * brief: gets the container value by index
            * param: index - position of the needed element in the container
            * note1:
            *   `index` can be a negative value!
            *   for example:
            *   -1 = std::end(container)
            *   -2 = --std::end(container)
            *   -3 = --(--std::end(container))
            *    ...
            *   -N = --(...N-3...(--std::end(container)...N-3...)
            * return: iterator to the indexed element
            */
            _CollectionIteratorType operator[](int64_t index) const {
                if (size_t elements_quantity{ collection.size() }; index > 0 ? index >= elements_quantity : -index > elements_quantity)
                    RAISE_ERROR("advanced_algorithms_coverage", "index out of range in index-iterator");
                _CollectionIteratorType result;
                if (index >= 0) {
                    result = _collection.begin();
                    for (; index > 0; --index)
                        ++result;
                } else {
                    result = _collection.end();
                    for (; index < -1; ++index)
                        --result;
                }
                return result;
            }
        }; // class IndexIterator

        template<class Collection>
        using II = typename IndexIterator<false, Collection>;

        template<class Collection>
        using CII = typename IndexIterator<true, Collection>;

    } // namespace AAC

} // namespace Common
