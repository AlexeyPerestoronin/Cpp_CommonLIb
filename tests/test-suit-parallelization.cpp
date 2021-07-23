 #include "tests/test-unit-common.hpp"

 #include <parallelization/list.h>

 TEST(parallelization, list) {
     std::list<int> a;
     parallelization::list<int> list{ 1, 2, 3 };
     // capacity
     list.empty();
     list.size();
     list.max_size();
     list.resize(0);
     list.resize(2, 3);
     // iterators
     *list.begin() = 4;
     list.cbegin();
     list.end();
     list.cend();
     list.rend();
     list.crend();
     list.rbegin();
     list.crbegin();
     list.size();
 }