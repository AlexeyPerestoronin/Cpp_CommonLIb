#include "test-common.hpp"

#include "parallelization/sync.h"
#include "parallelization/list.h"
#include "parallelization/optional.h"


TEST(Class_sync, Test1) {
    parallelization::sync<std::vector<int>> s_vec{ 1, 2, 3 };

    // clang-format off
	// because method std::vector<int>::size hasn't any overloads there is possible to not define first template parameter clearly
    size_t s = s_vec.invoke(&std::vector<int>::size);
	
	// because method std::vector<int>::push_back has two overloads by argument type there is need to define first template parameter clearly
    s_vec.invoke<void (std::vector<int>::*)(const int&)>(&std::vector<int>::push_back, 4);

	// because method std::vector<int>::at has two overloads by returned type there is need to define first template parameter clearly
    ASSERT_EQ(
        s_vec.invoke<int& (std::vector<int>::*)(const size_t)>(&std::vector<int>::at, 3),
        4);
    ASSERT_EQ(
        s_vec.invoke<const int& (std::vector<int>::*)(const size_t) const>(&std::vector<int>::at, 3),
        4);
    // clang-format on
}

TEST(Parallelization_optional, Test_1) {
    parallelization::optional<int> opt_i{ 3 };
    ASSERT_EQ(opt_i, 3);
    opt_i = 4;
    ASSERT_EQ(opt_i, 4);
    int i = opt_i;
    ASSERT_EQ(i, 4);
    i = 5;
    ASSERT_EQ(i, 5);
    ASSERT_EQ(opt_i, 4);
}

TEST(Parallelization_optional, Test_2) {
    parallelization::optional<int> opt_i{ 4 };
    int& i = opt_i;
    ASSERT_EQ(opt_i, 4);
    ASSERT_EQ(i, 4);
    i = 5;
    ASSERT_EQ(i, 5);
    ASSERT_EQ(opt_i, 5);
}

TEST(Parallelization_optional, Test_3) {
    using vector_str = std::vector<std::string>;
    using vector_str_it = vector_str::iterator;

    vector_str strs{ "str1", "str2", "str3" };

    parallelization::optional<vector_str_it> itB{ strs.begin() };
    parallelization::optional<vector_str_it> itE{ strs.end() };

    std::for_each<vector_str_it>(itB, itE, [](const std::string& str) {
        bool condition = (str == "str1") || (str == "str2") || (str == "str3");
        ASSERT_TRUE(condition);
    });

    std::for_each<vector_str_it>(itB, itE, [](std::string str) {
        bool condition = (str == "str1") || (str == "str2") || (str == "str3");
        ASSERT_TRUE(condition);
    });
}

TEST(Parallelization, Test2) {
    parallelization::list<int> plist{ 1, 2, 3, 4 };
    auto beg = plist.begin();
    beg.operator*();
}