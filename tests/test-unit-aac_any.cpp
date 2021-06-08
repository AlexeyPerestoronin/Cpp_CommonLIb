#include "test-unit-common.hpp"

#include "advanced_algorithms_coverage/algorithms.hpp"

using namespace Common::AAC;

using Container = typename std::vector<int>;

TEST(AdvancedAlgorithms, AnyOf) {
    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_TRUE((AnyOf(MakeCIT(vec), [](int v) { return v >= 0; })));
    }

    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_FALSE((AnyOf(MakeCIT(vec), [](int v) { return v < 0; })));
        ASSERT_TRUE((AnyOf(MakeCIT(vec, 4), [](int v) { return v < 5; })));
        ASSERT_FALSE((AnyOf(MakeCIT(vec, 5), [](int v) { return v < 5; })));
    }
}

TEST(AdvancedAlgorithms, AllOf) {
    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_TRUE((AllOf(MakeCIT(vec), [](int v) { return v >= 0; })));
    }

    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_FALSE((AllOf(MakeCIT(vec), [](int v) { return v < 5; })));
        ASSERT_TRUE((AllOf(MakeCIT(vec, 0, 4), [](int v) { return v < 5; })));
        ASSERT_FALSE((AllOf(MakeCIT(vec, 5), [](int v) { return v < 5; })));
    }
}

TEST(AdvancedAlgorithms, NoneOf) {
    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_TRUE((NoneOf(MakeCIT(vec), [](int v) { return v < 0; })));
    }

    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_FALSE((NoneOf(MakeCIT(vec), [](int v) { return v < 5; })));
        ASSERT_TRUE((NoneOf(MakeCIT(vec, 0, 4), [](int v) { return v > 5; })));
        ASSERT_TRUE((NoneOf(MakeCIT(vec, 5), [](int v) { return v < 5; })));
    }
}
