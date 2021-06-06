#include "test-unit-common.hpp"

#include "advanced_algorithms_coverage/find.hpp"

using namespace Common::AAC;

TEST(AdvancedAlgorithms, Find) {
    {
        std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        ASSERT_TRUE(Find(vec, 5).has_value());
        ASSERT_TRUE((Find<0, -2>(vec, 5).has_value()));
        ASSERT_TRUE((Find<0, -3>(vec, 5).has_value()));
        ASSERT_TRUE((Find<0, -4>(vec, 5).has_value()));
        ASSERT_TRUE((Find<0, -5>(vec, 5).has_value()));
        ASSERT_FALSE((Find<0, -6>(vec, 5).has_value()));

        ASSERT_TRUE((Find<0, -1>(vec, 5).has_value()));
        ASSERT_TRUE((Find<1, -1>(vec, 5).has_value()));
        ASSERT_TRUE((Find<2, -1>(vec, 5).has_value()));
        ASSERT_TRUE((Find<3, -1>(vec, 5).has_value()));
        ASSERT_TRUE((Find<4, -1>(vec, 5).has_value()));
        ASSERT_TRUE((Find<5, -1>(vec, 5).has_value()));
        ASSERT_FALSE((Find<6, -1>(vec, 5).has_value()));

        //Find<-1, -2>(vec, 5); // compilation error
        //Find<+2, +1>(vec, 5); // compilation error
        ASSERT_THROW((Find<0, -11>(vec, 5)), Common::Errors::BaseError);
        ASSERT_THROW((Find<10, -1>(vec, 5)), Common::Errors::BaseError);
    }
}
