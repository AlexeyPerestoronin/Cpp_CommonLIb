#pragma once

#include "stdafx.h"
#include "../blocker.h"

namespace parallelization {
    class _StandartLocker {
        std::mutex d_mutex{};
        bool d_isLocked{ false };

        public:
        using blocker = Blocker<_StandartLocker>;

        bool lock();

        void unlock();

        blocker GetBlocker();
    };
} // namespace parallelization