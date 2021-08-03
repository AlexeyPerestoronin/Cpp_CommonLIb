#include "test-common.hpp"

#include "advanced_algorithms_coverage/algorithms.hpp"

using namespace Common::AAC;

using Container = typename std::vector<int>;

TEST(AdvancedAlgorithms, Search) {
    {
        Container where{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        Container what{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_TRUE((Search(MakeCIT(where), MakeCIT(what))));
        ASSERT_TRUE((Search(MakeCIT(where), MakeCIT(what, 4, 5))));
        ASSERT_FALSE((Search(MakeCIT(where, 1), MakeCIT(what))));
        ASSERT_FALSE((Search(MakeCIT(where, -4, -1), MakeCIT(what, 1, 3))));
    }
}

TEST(AdvancedAlgorithms, SearchN) {
    {
        Container where{ 0, 0, 1, 1, 1, 0, 1, 1, 0, 2 };

        ASSERT_TRUE((SearchN(MakeCIT(where), 1, 2)));
        ASSERT_TRUE((SearchN(MakeCIT(where), 1, 1)));
        ASSERT_TRUE((SearchN(MakeCIT(where), 2, 1)));
        ASSERT_TRUE((SearchN(MakeCIT(where), 3, 1)));
        ASSERT_FALSE((SearchN(MakeCIT(where), 4, 1)));
        ASSERT_FALSE((SearchN(MakeCIT(where), 3, 0)));
    }
}
