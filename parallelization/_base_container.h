#pragma once

#include "_base_iterator.h"

namespace parallelization {
    template<class ElementType, class LockerType, template<class...> class BaseContainerType, class... ContainerSettingsTypes>
    class _BaseContainer
#define BASE_CONTAINER_TYPE BaseContainerType<ElementType, ContainerSettingsTypes...>
        : protected virtual BASE_CONTAINER_TYPE {

        public:
        // clang-format off
        using base_type                 = BASE_CONTAINER_TYPE;
        
        using value_type                = typename base_type::value_type;
        using reference                 = typename base_type::reference;
        using const_reference           = typename base_type::const_reference;

        using allocator_type            = typename base_type::allocator_type;
        using size_type                 = typename base_type::size_type;
        using difference_type           = typename base_type::difference_type;
        using pointer                   = typename base_type::pointer;
        using const_pointer             = typename base_type::const_pointer;

        using iterator                  = _BaseIterator<typename base_type::iterator, LockerType>;
        using const_iterator            = _BaseIterator<typename base_type::const_iterator, LockerType>;
        using reverse_iterator          = _BaseIterator<typename base_type::reverse_iterator, LockerType>;
        using const_reverse_iterator    = _BaseIterator<typename base_type::const_reverse_iterator, LockerType>;
        // clang-format on

        protected:
        mutable LockerType d_access{};

#define GET_LOCK d_access.lock();

        public:
        template<class... ArgsTypes>
        _BaseContainer(ArgsTypes&&... i_args)
            : base_type(std::forward<ArgsTypes>(i_args)...) {}

        _BaseContainer(std::initializer_list<ElementType> i_elements)
            : base_type{ i_elements } {}

#undef BASE_CONTAINER_TYPE
    };
} // namespace parallelization
