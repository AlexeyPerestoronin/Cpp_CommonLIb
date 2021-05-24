#include "test-common.hpp"

#include "advanced_algorithms.hpp"


using namespace Common;


TEST(AdvancedAlgorithms, Find)
{
  {
    std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    ASSERT_EQ(*(AA::Find(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<0, -1>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<0, -2>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<0, -3>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<0, -4>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<0, -5>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<0, -6>(vec, 5)), 5);
    ASSERT_NE(*(AA::Find<0, -7>(vec, 5)), 5);
    
    ASSERT_NE(*(AA::Find<0, 1>(vec, 5)), 5);
    ASSERT_NE(*(AA::Find<0, 2>(vec, 5)), 5);
    ASSERT_NE(*(AA::Find<0, 3>(vec, 5)), 5);
    ASSERT_NE(*(AA::Find<0, 4>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<0, 5>(vec, 5)), 5);
    
    ASSERT_EQ(*(AA::Find<1, 5>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<2, 5>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<3, 5>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<4, 5>(vec, 5)), 5);
    ASSERT_EQ(*(AA::Find<5, 5>(vec, 5)), 5);

    ASSERT_NE(*(AA::Find<6, 6>(vec, 5)), 5);
    ASSERT_NE(*(AA::Find<6, 7>(vec, 5)), 5);
    ASSERT_NE(*(AA::Find<6, 8>(vec, 5)), 5);
    ASSERT_NE(*(AA::Find<6, 9>(vec, 5)), 5);
  }
}
