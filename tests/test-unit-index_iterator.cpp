#include "test-unit-common.hpp"

#include "advanced_algorithms_coverage/index_iterator.hpp"

#include <algorithm>

using namespace Common::AAC;

TEST(IntexIterator, Test1) {
    using Container = typename std::vector<int>;

    {
      constexpr int64_t from = 10;
      constexpr int64_t to = -11;
      Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
      ASSERT_THROW((II<Container>(vec)(from)), Common::Errors::BaseError);
      ASSERT_THROW((II<Container>(vec)(to)), Common::Errors::BaseError);
      ASSERT_THROW((II<Container>(vec)[from]), Common::Errors::BaseError);
      ASSERT_THROW((II<Container>(vec)[to]), Common::Errors::BaseError);
    }

    {
        Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        II<decltype(vec)> ii1(vec);
        auto i1 = ii1(0);
        ASSERT_EQ(*i1, 0);
        ++ii1[0];
        ++ii1[0];
        ++ii1[0];
        ASSERT_EQ(*i1, 3);
    }
}

TEST(ConstIntexIterator, Test1)
{
  using Container = typename std::vector<int>;

  {
    Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    CII<decltype(vec)> ii1(vec);
    auto i1 = ii1(0);
    ASSERT_EQ(*i1, 0);
    //++ii1[0]; // compilation error
  }
}
