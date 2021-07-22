#pragma once
#include "_iterator.h"

namespace parallelization {
    template<class BaseContainerType>
    struct _InternalAliases {
        // clang-format off
        using base_type   = BaseContainerType;
        
        using value_type      = typename base_type::value_type;
        using reference       = typename base_type::reference;
        using const_reference = typename base_type::const_reference;

        using allocator_type  = typename base_type::allocator_type;
        using size_type       = typename base_type::size_type;
        using difference_type = typename base_type::difference_type;
        using pointer         = typename base_type::pointer;
        using const_pointer   = typename base_type::const_pointer;

        using iterator                = _Iterator<typename base_type::iterator>;
        using const_iterator          = _Iterator<typename base_type::const_iterator>;
        using reverse_iterator        = _Iterator<typename base_type::reverse_iterator>;
        using const_reverse_iterator  = _Iterator<typename base_type::const_reverse_iterator>;
        // clang-format on
    };
} // namespace parallelization
