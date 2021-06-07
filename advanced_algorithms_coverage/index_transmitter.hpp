#pragma once

#include "advanced_algorithms_coverage/index_iterator.hpp"

namespace Common {
    namespace AAC // Advanced Algorithms Coverage
    {
        /**
        * brief: creates and manages iterators for some subrange of elements from an arbitrary container
        * param-t: is_const - flag: if true working only with iterator to constant data; if false - with iterator to not constant data
        * param-t: CollectionType - type of target collection of elements
        */
        template<bool is_const, class CollectionType>
        class IndexTrasmitter {
            using MainClass = typename IndexTrasmitter<is_const, CollectionType>;
            PtrCls(MainClass);

            using _CollectionType = typename MT::AddConstIfNeed<is_const, CollectionType>::Value;
            using _CollectionIteratorType = typename MT::AddConstIfNeed<is_const, typename _CollectionType::iterator, typename _CollectionType::const_iterator>::Value;
            using _IndexIterator = IndexIterator<is_const, CollectionType>;
            using _IndexType = int64_t;

            private:
            _IndexIterator _ii;
            _IndexType _from;
            _IndexType _to;

            public:
            /**
            * breif: creates an instance of the class
            * param: collection - target collection of elements from which an subrange of the elements will be chosen
            * param: from - index of the first element from the collection from which the subrange is init
            * param: to - index of the last element from the collection to which the subrange is long
            */
            IndexTrasmitter(_CollectionType& collection, _IndexType from = 0, _IndexType to = -1)
                : _ii{ collection }
                , _from{ from }
                , _to{ to } {
                if (!((from > 0 && to > 0 ? from <= to : true) && (from < 0 && to < 0 ? from <= to : true)))
                    RAISE_ERROR("advanced_algorithms_coverage", "from-position must be less then to-position");
            }

            /**
            * brief: gets iterator to first alement of the range
            */
            _CollectionIteratorType GetFrom() const {
                return _ii(_from);
            }

            /**
             brief: gets iterator to last element of the range
            */
            _CollectionIteratorType GetTo() const {
                return _ii(_to);
            }
        }; // class IndexTrasmitter

        template<class CollectionType>
        using IT = IndexTrasmitter<false, CollectionType>;

        template<class CollectionType>
        using CIT = IndexTrasmitter<true, CollectionType>;

        /**
        * brief: creates an instance of IndexTrasmitter-class for non const data
        * param: collection - target iterable collection of elements
        * param: from - index of first element from the collection for the subrange
        * param: to - index of last element from the collection for the subrange
        * return: an instance of IndexTransmitter-class for non const data
        */
        template<class CollectionType>
        IT<CollectionType> MakeIT(CollectionType& collection, int64_t from = 0, int64_t to = -1) {
            return IT<CollectionType>(collection, from, to);
        }

        /**
        * brief: creates an instance of IndexTrasmitter-class for const data
        * param: collection - target iterable collection of elements
        * param: from - index of first element from the collection for the subrange
        * param: to - index of last element from the collection for the subrange
        * return: an instance of IndexTransmitter-class for const data
        */
        template<class CollectionType>
        CIT<CollectionType> MakeCIT(const CollectionType& collection, int64_t from = 0, int64_t to = -1) {
            return CIT<CollectionType>(collection, from, to);
        }

    } // namespace AAC

} // namespace Common
