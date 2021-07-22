#pragma once
#include "_iterator.h"

namespace parallelization {
    namespace members_map {
        template<class BaseContainerType>
        struct _Iterators_begin_end : protected virtual BaseContainerType {
            [[nodiscard]] typename BaseContainerType::iterator begin() noexcept {
                GET_LOCK
                return typename BaseContainerType::iterator(d_access, BaseContainerType::begin());
            }

            [[nodiscard]] typename BaseContainerType::const_iterator begin() const noexcept {
                GET_LOCK
                return typename BaseContainerType::const_iterator(d_access, BaseContainerType::begin());
            }

            [[nodiscard]] typename BaseContainerType::iterator end() noexcept {
                GET_LOCK
                return typename BaseContainerType::iterator(d_access, BaseContainerType::end());
            }

            [[nodiscard]] typename BaseContainerType::const_iterator end() const noexcept {
                GET_LOCK
                return typename BaseContainerType::const_iterator(d_access, BaseContainerType::end());
            }
        };

        template<class BaseContainerType>
        struct _Iterators_cbegin_cend : protected virtual BaseContainerType {
            [[nodiscard]] typename BaseContainerType::const_iterator cbegin() const noexcept {
                GET_LOCK
                return typename BaseContainerType::const_iterator(d_access, BaseContainerType::cbegin());
            }

            [[nodiscard]] typename BaseContainerType::const_iterator cend() const noexcept {
                GET_LOCK
                return typename BaseContainerType::const_iterator(d_access, BaseContainerType::cend());
            }
        };

        template<class BaseContainerType>
        struct _Iterators_rbegin_rend : protected virtual BaseContainerType {
            [[nodiscard]] typename BaseContainerType::reverse_iterator rbegin() noexcept {
                GET_LOCK
                return typename BaseContainerType::reverse_iterator(d_access, BaseContainerType::rbegin());
            }

            [[nodiscard]] typename BaseContainerType::const_reverse_iterator rbegin() const noexcept {
                GET_LOCK
                return typename BaseContainerType::const_reverse_iterator(d_access, BaseContainerType::rbegin());
            }

            [[nodiscard]] typename BaseContainerType::reverse_iterator rend() noexcept {
                GET_LOCK
                return typename BaseContainerType::reverse_iterator(d_access, BaseContainerType::rend());
            }

            [[nodiscard]] typename BaseContainerType::const_reverse_iterator rend() const noexcept {
                GET_LOCK
                return typename BaseContainerType::const_reverse_iterator(d_access, BaseContainerType::end());
            }
        };

        template<class BaseContainerType>
        struct _Iterators_crbegin_crend : protected virtual BaseContainerType {
            [[nodiscard]] typename BaseContainerType::const_reverse_iterator crbegin() const noexcept {
                GET_LOCK
                return typename BaseContainerType::const_reverse_iterator(d_access, BaseContainerType::crbegin());
            }

            [[nodiscard]] typename BaseContainerType::const_reverse_iterator crend() const noexcept {
                GET_LOCK
                return typename BaseContainerType::const_reverse_iterator(d_access, BaseContainerType::cend());
            }
        };
    } // namespace members_map
} // namespace parallelization
