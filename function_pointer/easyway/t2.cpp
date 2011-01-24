#include <iostream>
#include <map>

struct	Test
{
  static void	test1(){}
  static void	test2(){}
  static void	test3(){}

  typedef void	(*fct)();
  typedef std::map<fct, int>	MyMap;

  MyMap	_m;
};

int	main(void)
{
  Test	test;

  test._m[Test::test1] = 1;
  test._m[Test::test2] = 2;

  if (test._m.find(Test::test3) != test._m.end())
    std::cout << "test2 found" << std::endl;

  return 0;
}
