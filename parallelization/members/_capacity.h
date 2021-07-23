#pragma once

namespace parallelization {
    namespace members_map {
        template<class BaseContainerType>
        struct _Capacity_size : protected virtual BaseContainerType {
            [[nodiscard]] typename BaseContainerType::size_type size() const noexcept {
                GET_LOCK
                return BaseContainerType::size();
            }
        };

        template<class BaseContainerType>
        struct _Capacity_max_size : protected virtual BaseContainerType {
            [[nodiscard]] typename BaseContainerType::size_type max_size() const noexcept {
                GET_LOCK
                return BaseContainerType::max_size();
            }
        };

        template<class BaseContainerType>
        struct _Capacity_empty : protected virtual BaseContainerType {
            [[nodiscard]] bool empty() const noexcept {
                GET_LOCK
                return BaseContainerType::empty();
            }
        };

        template<class BaseContainerType>
        struct _Capacity_resize : protected virtual BaseContainerType {
            template<class... ArgsTypes>
            void resize(ArgsTypes&&... i_args) {
                GET_LOCK
                BaseContainerType::resize(std::forward<ArgsTypes>(i_args)...);
            }
        };
    } // namespace members_map
} // namespace parallelization
