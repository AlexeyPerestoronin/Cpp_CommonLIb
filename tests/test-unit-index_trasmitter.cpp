#include "test-unit-common.hpp"

#include "advanced_algorithms_coverage/index_transmitter.hpp"

#include <algorithm>

using namespace Common::AAC;

TEST(IndexTrasmitter, Test1) {
    using Container = typename std::vector<int>;

    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        auto it = MakeIT(vec);
        auto from = it.GetFrom();
        auto to = it.GetTo();

        std::transform(from, to, from, [](int _from) { return 10; });
        for (auto v : vec)
            ASSERT_EQ(v, 10);
    }
}
