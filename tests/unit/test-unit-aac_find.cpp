#include "test-common.hpp"

#include "advanced_algorithms_coverage/algorithms.hpp"

using namespace Common::AAC;

using Container = typename std::vector<int>;

TEST(AdvancedAlgorithms, Find) {
    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_TRUE((Find(MakeCIT(vec), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 0, -2), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 0, -3), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 0, -4), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 0, -5), 5).has_value()));
        ASSERT_FALSE((Find(MakeCIT(vec, 0, -6), 5).has_value()));

        ASSERT_TRUE((Find(MakeCIT(vec, 0, -1), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 1, -1), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 2, -1), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 3, -1), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 4, -1), 5).has_value()));
        ASSERT_TRUE((Find(MakeCIT(vec, 5, -1), 5).has_value()));
        ASSERT_FALSE((Find(MakeCIT(vec, 6, -1), 5).has_value()));

        //Find(MakeCIT(vec, -1, -2), 5); // compilation error
        //Find(MakeCIT(vec, +2, +1), 5); // compilation error
        ASSERT_THROW((Find(MakeCIT(vec, 0, -11), 5)), Common::Errors::BaseError);
        ASSERT_THROW((Find(MakeCIT(vec, 10, -1), 5)), Common::Errors::BaseError);
    }
}

TEST(AdvancedAlgorithms, FindIf) {
    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        std::optional<int> res{ FindIf(MakeCIT(vec), [](int v) { return v >= 5; }) };
        ASSERT_TRUE(res.has_value());
        ASSERT_EQ(res.value(), 5);
    }
}

TEST(AdvancedAlgorithms, FindIfNot) {
    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        std::optional<int> res{ FindIfNot(MakeCIT(vec), [](int v) { return v < 5; }) };
        ASSERT_TRUE(res.has_value());
        ASSERT_EQ(res.value(), 5);
    }
}

TEST(AdvancedAlgorithms, FindEnd) {
    {
        Container where{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        Container what{ 4, 5, 6 };

        std::optional<int> res{ FindEnd(MakeCIT(where), MakeCIT(what)) };
        ASSERT_TRUE(res.has_value());
        ASSERT_EQ(res.value(), 4);
    }
}

TEST(AdvancedAlgorithms, FindFirstOf) {
    {
        Container where{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        Container what{ 4, 5, 6 };

        std::optional<int> res{ FindFirstOf(MakeCIT(where), MakeCIT(what)) };
        ASSERT_TRUE(res.has_value());
        ASSERT_EQ(res.value(), 4);
    }
}

TEST(AdvancedAlgorithms, FindAdjacent) {
    {
        Container where{ 0, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9 };

        std::optional<int> res{ FindAdjacent(MakeCIT(where)) };
        ASSERT_TRUE(res.has_value());
        ASSERT_EQ(res.value(), 3);
    }
}
