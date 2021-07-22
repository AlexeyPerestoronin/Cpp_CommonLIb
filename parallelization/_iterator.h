#pragma once
#include "stdafx.hpp"

namespace parallelization {
    template<class BaseIteratorType>
    class _Iterator : protected BaseIteratorType {
        using base_type = BaseIteratorType;
        using current_type = _Iterator;

        std::mutex& d_access;
#define GET_LOCK std::lock_guard<std::mutex> _lock(d_access);

        public:
        // clang-format off
        using difference_type = typename base_type::difference_type;
        using value_type      = typename base_type::value_type;
        using reference       = typename base_type::reference;
        using pointer         = typename base_type::pointer;
        // clang-format on

        template<class... ArgsTypes>
        _Iterator(std::mutex& i_access, ArgsTypes&&... i_args)
            : d_access{ i_access }
            , base_type(std::forward<ArgsTypes>(i_args)...) {}

        [[nodiscard]] reference operator*() const noexcept {
            GET_LOCK
            return base_type::operator*();
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
