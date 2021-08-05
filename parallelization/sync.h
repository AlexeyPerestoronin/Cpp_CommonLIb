#pragma once

#include "stdafx.h"

namespace parallelization {
    template<class ObjType>
    class sync {
        mutable std::mutex d_access{};
        ObjType d_object;

        class owner {
            friend class sync;

            std::mutex& d_own_access;
            ObjType& d_own_object;

            owner(std::mutex& i_own_access, ObjType& i_own_object)
                : d_own_access(i_own_access)
                , d_own_object(i_own_object) {
                d_own_access.lock();
            }

            public:
            ~owner() {
                d_own_access.unlock();
            }

            [[nodiscard]] constexpr ObjType& getObj() {
                return d_own_object;
            }

            [[nodiscard]] constexpr const ObjType& getObj() const {
                return d_own_object;
            }
        };

        public:
        template<class... ArgsTypes>
        sync(ArgsTypes&&... args)
            : d_object{ std::forward<ArgsTypes>(args)... } {};

        owner getOwner() {
            return owner{ d_access, d_object };
        }
    };
} // namespace parallelization
