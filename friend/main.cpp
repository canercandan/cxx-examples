#include <iostream>

class	Test
{
public:
  inline Test()
    : _a(0), _b(0)
  {}

  friend Test	convertTestTo42(Test& test);

  void	printME(void)
  {
    std::cout << "A [" << _a << "] B [" << _b << "]" << std::endl;
  }
private:
  int _a;
  int _b;
};

Test	convertTestTo42(Test& test)
{
  test._a = 42;
  test._b = 42;
}

int	main(void)
{
  Test	test;

  test.printME();

  convertTestTo42(test);

  test.printME();

  return 0;
}
