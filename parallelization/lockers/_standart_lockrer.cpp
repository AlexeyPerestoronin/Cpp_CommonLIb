#include "_standart_lockrer.h"

namespace parallelization {
    bool _StandartLocker::lock() {
        d_mutex.lock();
        return (d_isLocked = true);
    }

    void _StandartLocker::unlock() {
        if (d_isLocked)
            d_mutex.unlock();
    }

	_StandartLocker::blocker _StandartLocker::GetBlocker()
    {
        return blocker(*this);
    }
} // namespace parallelization