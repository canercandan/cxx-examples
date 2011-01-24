#include <iostream>
#include <map>

struct	Test
{
  void	test1(){}

  void	test2(){}

  void	test3(){}

  typedef void	(Test::*fct)();
  typedef std::map<int, fct>	MyMap;

  MyMap	_m;
};

int	main(void)
{
  Test	test;

  test._m[0] = &Test::test1;
  test._m[1] = &Test::test2;

  for (Test::MyMap::iterator
	 it = test._m.begin(),
	 end = test._m.end();
       it != end; ++it)
    {
      Test::fct f = it->second;

      if (f == &Test::test1)
	std::cout << "test1 found" << std::endl;

      if (f == &Test::test3)
	std::cout << "test3 found" << std::endl;

    }

  return 0;
}
