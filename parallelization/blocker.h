#pragma once

namespace parallelization {
    template<class LockerType>
    class Blocker {
        friend LockerType;

        LockerType& d_locker;
        Blocker(LockerType& i_locker)
            : d_locker{ i_locker } {};

        public:
        ~Blocker() {
            d_locker.unlock();
        }

        bool block() {
            return d_locker.lock();
        }

        void unblock() {
            d_locker.unlock();
        }
    };
} // namespace parallelization