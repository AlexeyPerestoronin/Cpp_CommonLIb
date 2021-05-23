#include "test-common.hpp"

#include "index_iterator.hpp"

#include <algorithm>


using namespace Common;


TEST(IntexIterator, Test1)
{
  using Container = typename std::vector<int>;

  {
    constexpr int64_t from = 0;
    constexpr int64_t to = -1;
    Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    II<Container> ii1(vec);
    II<Container> ii2(vec);
    ASSERT_EQ(std::distance(ii1[from], ii2[to]), vec.size());
    Container res;
    std::copy(ii1[from], ii2[to], std::back_inserter(res));
    for (int64_t i1 = from, i2 = 0; i1 < int64_t(to >= 0 ? to : (vec.size() + 1 + to)); ++i1, ++i2)
      ASSERT_EQ(vec[i1], res[i2]) << "index 1 = " << i1 << std::endl << "index 2 = " << i2;
  }

  {
    constexpr int64_t from = 1;
    constexpr int64_t to = -2;
    Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    II<Container> ii1(vec);
    II<Container> ii2(vec);
    ASSERT_EQ(std::distance(ii1[from], ii2[to]), vec.size() - 2);
    Container res;
    std::copy(ii1[from], ii2[to], std::back_inserter(res));
    for (int64_t i1 = from, i2 = 0; i1 < int64_t(to >= 0 ? to : (vec.size() + 1 + to)); ++i1, ++i2)
      ASSERT_EQ(vec[i1], res[i2]) << "index 1 = " << i1 << std::endl << "index 2 = " << i2;
  }

  {
    constexpr int64_t from = 2;
    constexpr int64_t to = -3;
    Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    II<Container> ii1(vec);
    II<Container> ii2(vec);
    ASSERT_EQ(std::distance(ii1[from], ii2[to]), vec.size() - 4);
    Container res;
    std::copy(ii1[from], ii2[to], std::back_inserter(res));
    for (int64_t i1 = from, i2 = 0; i1 < int64_t(to >= 0 ? to : (vec.size() + 1 + to)); ++i1, ++i2)
      ASSERT_EQ(vec[i1], res[i2]) << "index 1 = " << i1 << std::endl << "index 2 = " << i2;
  }

  {
    constexpr int64_t from = 2;
    constexpr int64_t to = 3;
    Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    II<Container> ii1(vec);
    II<Container> ii2(vec);
    ASSERT_EQ(std::distance(ii1[from], ii2[to]), 1);
    Container res;
    std::copy(ii1[from], ii2[to], std::back_inserter(res));
    for (int64_t i1 = from, i2 = 0; i1 < int64_t(to >= 0 ? to : (vec.size() + 1 + to)); ++i1, ++i2)
      ASSERT_EQ(vec[i1], res[i2]) << "index 1 = " << i1 << std::endl << "index 2 = " << i2;
  }

  {
    constexpr int64_t from = 2;
    constexpr int64_t to = 4;
    Container vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    II<Container> ii1(vec);
    II<Container> ii2(vec);
    ASSERT_EQ(std::distance(ii1[from], ii2[to]), 2);
    Container res;
    std::copy(ii1[from], ii2[to], std::back_inserter(res));
    for (int64_t i1 = from, i2 = 0; i1 < int64_t(to >= 0 ? to : (vec.size() + 1 + to)); ++i1, ++i2)
      ASSERT_EQ(vec[i1], res[i2]) << "index 1 = " << i1 << std::endl << "index 2 = " << i2;
  }
}
