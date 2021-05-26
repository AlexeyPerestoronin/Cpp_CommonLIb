#include "test-common.hpp"

#include "advanced_algorithms.hpp"


using namespace Common;


TEST(AdvancedAlgorithms, Find)
{
  {
    std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    ASSERT_TRUE(AA::Find(vec, 5).has_value());
    ASSERT_TRUE((AA::Find<0, -2>(vec, 5).has_value()));
    ASSERT_TRUE((AA::Find<0, -3>(vec, 5).has_value()));
    ASSERT_TRUE((AA::Find<0, -4>(vec, 5).has_value()));
    ASSERT_TRUE((AA::Find<0, -5>(vec, 5).has_value()));
    ASSERT_FALSE((AA::Find<0, -6>(vec, 5).has_value()));

    ASSERT_TRUE((AA::Find<0, -1>(vec, 5).has_value()));
    ASSERT_TRUE((AA::Find<1, -1>(vec, 5).has_value()));
    ASSERT_TRUE((AA::Find<2, -1>(vec, 5).has_value()));
    ASSERT_TRUE((AA::Find<3, -1>(vec, 5).has_value()));
    ASSERT_TRUE((AA::Find<4, -1>(vec, 5).has_value()));
    ASSERT_TRUE((AA::Find<5, -1>(vec, 5).has_value()));
    ASSERT_FALSE((AA::Find<6, -1>(vec, 5).has_value()));

    //AA::Find<-1, -2>(vec, 5); // compilation error
    //AA::Find<+2, +1>(vec, 5); // compilation error
    ASSERT_THROW((AA::Find<0, -11>(vec, 5)), Common::Errors::BaseError);
    ASSERT_THROW((AA::Find<10, -1>(vec, 5)), Common::Errors::BaseError);
  }
}
