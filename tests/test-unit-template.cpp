#include "test-common.hpp"
#include "ptr.hpp"

class A
{
  PtrCls(A)
public:
  virtual const char* what()
  {
    return "A::what()";
  }

protected:
  virtual const char* that()
  {
    return "A::that()";
  }
};

class B : public A
{
  PtrCls(B)
public:
  virtual const char* what() override
  {
    return "B::what()";
  }
};

class C : public A
{
  PtrCls(C)
private:
  virtual const char* what() override
  {
    return "C::what()";
  }

public:
  virtual const char* that() override
  {
    return "C::that()";
  }
};

TEST(SomeTest, TestTest)
{
  using namespace std;
  cout << A().what() << endl;
  cout << B().what() << endl;
  A::ShaPtr a1 = std::make_shared<A>(B());
  A::ShaPtr a2 = std::make_shared<B>();
  A::ShaPtr a3 = std::make_shared<B>(B());
  A::ShaPtr a4 = std::make_shared<C>();
  A::ShaPtr a5 = std::make_shared<C>(C());
  cout << endl;
  cout << a1->what() << endl;
  cout << a2->what() << endl;
  cout << a3->what() << endl;
  cout << a4->what() << endl;
  cout << a5->what() << endl;
  cout << reinterpret_cast<C*>(&(*a5))->that() << endl;
}
