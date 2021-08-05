#pragma once

#include "stdafx.h"

namespace parallelization {
    template<class Type>
    struct optional : std::optional<Type> {
        using value_type = Type;
        using base_type = std::optional<Type>;

        template<class... ArgsTypes>
        optional(ArgsTypes&&... args)
            : base_type(std::forward<ArgsTypes>(args)...) {}

        [[nodiscard]] operator value_type&() {
            if (!base_type::has_value())
                throw std::exception("instance of parallelization::optional class wasn't be assigned with value");
            return base_type::value();
        }

        [[nodiscard]] operator const value_type&() const {
            if (!base_type::has_value())
                throw std::exception("instance of parallelization::optional class wasn't be assigned with value");
            return base_type::value();
        }
    };

    template<class Type>
    struct optional<Type&> : std::optional<Type*> {
        using value_type = Type;
        using base_type = std::optional<Type>;

        optional() = default;
    	
        optional(Type& i_arg)
            : base_type(&i_arg) {}

        [[nodiscard]] operator value_type&() {
            if (!base_type::has_value())
                throw std::exception("instance of parallelization::optional class wasn't be assigned with value");
            return *base_type::value();
        }

        [[nodiscard]] operator const value_type&() const {
            if (!base_type::has_value())
                throw std::exception("instance of parallelization::optional class wasn't be assigned with value");
            return *base_type::value();
        }
    };
} // namespace parallelization