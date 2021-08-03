#include "test-common.hpp"

#include <list>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <optional>

using namespace std;

class Parent {
    protected:
    string m_name;

    public:
    Parent(string name)
        : m_name(name) {}

    virtual ~Parent() {}
};

class Child1 : public Parent {
    protected:
    string m_patronymic;

    public:
    Child1(string name, string patronymic)
        : Parent(name)
        , m_patronymic(patronymic) {}
    const string& getName() {
        return m_name;
    }
};

class Child2 : public Parent {
    protected:
    string m_patronymic;

    public:
    Child2(string name, string patronymic)
        : Parent(name)
        , m_patronymic(patronymic) {}
    const string& getName() {
        return m_name;
    }
};

Parent* Create1() {
    return new Child1("Alex", "Mike");
};

Parent* Create2() {
    return new Child2("Alex", "Mike");
};

TEST(Test1, Simple1) {
    using MyINT = int;
	using vector_int = std::vector<int>;
	//std::string
	
    // используем dynamic_cast для конвертации указателя класса Parent в указатель класса Child
    Parent* p1 = Create1();
    Child1* ch1 = dynamic_cast<Child1*>(p1);
	ASSERT_NE(ch1, nullptr);

	Parent* p2 = Create2();
    Child1* ch2 = dynamic_cast<Child1*>(p2);
    ASSERT_EQ(ch2, nullptr);
}

template<class Type, template<class> class Base>
struct A : Base<Type> {
    Base<Type> container;
};

template<class Base>
struct B {
    Base container;
};

TEST(Test1, Simple2) {
    std::list<int> list;
    A<int, std::list> a;
    B<std::list<int>> b;
}