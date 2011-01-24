#include <iostream>

struct	Test
{
  Test();
  int&	getA();
 private:
  int	a;
};

Test::Test() : a(24){}

int&	Test::getA(){return a;}

int	main(void)
{
  Test	test;

  test.getA() = 42;

  std::cout << "getA: " << test.getA() << std::endl;

  return 0;
}
