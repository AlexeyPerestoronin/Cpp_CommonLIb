#pragma once

#include <stdafx.h>
#include "optional.h"

namespace parallelization {
    template<class BaseIteratorType, class LockerType>
    class _BaseIterator : protected BaseIteratorType {
        using base_type = BaseIteratorType;
        using current_type = _BaseIterator;

        LockerType& d_access;
#define GET_LOCK d_access.lock();

        public:
        // clang-format off
        using difference_type = typename base_type::difference_type;
        using value_type      = typename base_type::value_type;
        using reference       = typename base_type::reference;
        using reference_opt   = parallelization::optional<reference>;
        using pointer         = typename base_type::pointer;
        // clang-format on

        template<class... ArgsTypes>
        _BaseIterator(LockerType& i_access, ArgsTypes&&... i_args)
            : d_access{ i_access }
            , base_type(std::forward<ArgsTypes>(i_args)...) {}

        [[nodiscard]] reference_opt operator*() const noexcept {
            reference_opt result;
            if (auto blocker = d_access.GetBlocker(); blocker.block()) {
                //result = base_type::operator*();
            }
            return result;
        }

        [[nodiscard]] pointer operator->() const noexcept {
            GET_LOCK
            return base_type::operator->();
        }

        current_type& operator++() noexcept {
            GET_LOCK
            return base_type::operator++();
        }

        current_type operator++(int) noexcept {
            GET_LOCK
            return base_type::operator++(0);
        }

        current_type& operator--() noexcept {
            GET_LOCK
            return base_type::operator--();
        }

        current_type operator--(int) noexcept {
            GET_LOCK
            return base_type::operator--(0);
        }

        [[nodiscard]] bool operator==(const current_type& i_right) const noexcept {
            GET_LOCK
            return base_type::operator==(i_right);
        }

        [[nodiscard]] bool operator!=(const current_type& i_right) const noexcept {
            GET_LOCK
            return base_type::operator!=(i_right);
        }
#undef GET_LOCK
    };
} // namespace parallelization
