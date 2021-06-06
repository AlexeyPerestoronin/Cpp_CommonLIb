#pragma once

#include "ptr.hpp"
#include "errors/base_error.hpp"
#include "manipulating_types/choosing_types.hpp"

#include <stdint.h>
#include <map>

namespace Common {
    namespace AAC // Advanced Algorithms Coverage
    {
        /**
        * brief: creates iterator to some container for get its values by index
        * param-t: is_const - flag: if true working as iterator to constant data; if false - as iterator to not constant data
        */
        template<bool is_const, class CollectionType>
        class IndexIterator {
            using MainClass = typename IndexIterator<is_const, CollectionType>;
            PtrCls(MainClass);

            using _IndexType = int64_t;

            using _CollectionType = typename MT::AddConstIfNeed<is_const, CollectionType>::Value;
            using _CollectionIteratorType = typename MT::AddConstIfNeed<is_const, typename _CollectionType::iterator, typename _CollectionType::const_iterator>::Value;
            using _CollectionIteratorValueType = typename MT::AddConstIfNeed<is_const, typename _CollectionIteratorType::value_type>::Value;

            using _CollectionIteratorCacheType = std::map<_IndexType, _CollectionIteratorType>;

            private:
            _CollectionType& _collection;
            mutable size_t _collection_size;
            mutable _CollectionIteratorCacheType _cache{};

            public:
            IndexIterator(_CollectionType& collection)
                : _collection(collection)
                , _collection_size{ _collection.size() } {}

            /**
            * brief: gets an iterator to the container element by index
            * param: index - position of the needed element in the container
            * note1:
            *   `index` can be a negative value!
            *   for example:
            *   -1 = std::end(container)
            *   -2 = --std::end(container)
            *   -3 = --(--std::end(container))
            *    ...
            *   -N = --(...N-3...(--std::end(container)...N-3...)
            * note2: all queried elements are cached in first query
            * return: iterator to the indexed element
            */
            _CollectionIteratorType& operator()(_IndexType index) const {
                // performs checking of sizes
                if (size_t elements_quantity{ _collection.size() }; index > 0 ? static_cast<size_t>(index) >= elements_quantity : static_cast<size_t>(-index) > elements_quantity) {
                    RAISE_ERROR("advanced_algorithms_coverage", "index out of range in index-iterator");
                } else {
                    if (_collection_size != elements_quantity) {
                        _collection_size = elements_quantity;
                        _cache.clear();
                    }
                }

                // checks if indexed element is already was be queried
                if (auto it{ _cache.find(index) }; it == _cache.end()) {
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
                    _cache.emplace(std::make_pair(index, std::move(result)));
                }
                return _cache[index];
            }

            /**
            * brief: gets a reference to the container value by index
            * param: index - position of the needed element in the container
            * note1:
            *   `index` can be a negative value!
            *   for example:
            *   -1 = std::end(container)
            *   -2 = --std::end(container)
            *   -3 = --(--std::end(container))
            *    ...
            *   -N = --(...N-3...(--std::end(container)...N-3...)
            * note2: all queried elements are cached in first query
            * return: reference to the value of the indexed element
            */
            _CollectionIteratorValueType& operator[](_IndexType index) const {
                return *(this->operator()(index));
            }

        }; // class IndexIterator

        template<class CollectionType>
        using II = IndexIterator<false, CollectionType>;

        template<class CollectionType>
        using CII = IndexIterator<true, CollectionType>;

    } // namespace AAC

} // namespace Common
