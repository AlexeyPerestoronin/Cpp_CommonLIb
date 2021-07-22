#pragma once
#include "_iterator.h"
#include "./_internal_aliases.h"
#include "_macrosses.h"

namespace parallelization {
    template<class ElementType, template<class...> class BaseContainerType, class... ContainerSettingsTypes>
    class _BaseContainer
#define BASE_CONTAINER_TYPE BaseContainerType<ElementType, ContainerSettingsTypes...>
        : protected virtual BASE_CONTAINER_TYPE,
          public _InternalAliases<BASE_CONTAINER_TYPE> {
        using base_type = BaseContainerType<ElementType, ContainerSettingsTypes...>;

        protected:
        mutable std::mutex d_access{};

        public:
        template<class... ArgsTypes>
        _BaseContainer(ArgsTypes&&... i_args)
            : base_type(std::forward<ArgsTypes>(i_args)...) {}

        _BaseContainer(std::initializer_list<ElementType> i_elements)
            : base_type(i_elements) {}

#undef BASE_CONTAINER_TYPE
    };
} // namespace parallelization
