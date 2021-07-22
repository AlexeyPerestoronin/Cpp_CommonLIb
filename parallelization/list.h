#pragma once
#include "_base_container.h"
#include "_iterators.h"
#include "_capacity.h"

namespace parallelization {
    template<class ElementType, class... ContainerSettingsTypes>
    struct list : virtual _BaseContainer<ElementType, std::list, ContainerSettingsTypes...>,
#define BASE_CONTAINER_TYPE _BaseContainer<ElementType, std::list, ContainerSettingsTypes...>
                  members_map::_Iterators_begin_end<BASE_CONTAINER_TYPE>,
                  members_map::_Iterators_cbegin_cend<BASE_CONTAINER_TYPE>,
                  members_map::_Iterators_rbegin_rend<BASE_CONTAINER_TYPE>,
                  members_map::_Iterators_crbegin_crend<BASE_CONTAINER_TYPE>,
                  members_map::_Capacity_size<BASE_CONTAINER_TYPE>,
                  members_map::_Capacity_max_size<BASE_CONTAINER_TYPE>,
                  members_map::_Capacity_empty<BASE_CONTAINER_TYPE>,
                  members_map::_Capacity_resize<BASE_CONTAINER_TYPE> {

        template<class... ArgsTypes>
        list(ArgsTypes&&... i_args)
            : BASE_CONTAINER_TYPE(std::forward<ArgsTypes>(i_args)...) {}

        list(std::initializer_list<ElementType> i_elements)
            : BASE_CONTAINER_TYPE(i_elements) {}

#undef BASE_CONTAINER_TYPE
    };
} // namespace parallelization
