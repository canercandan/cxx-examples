#ifndef __TEST_H__
# define __TEST_H__

# include <iostream>

template <typename A, typename C>
class	Test
{
public:
  Test(){std::cout << "Test<default> init" << std::endl;}
  void	operator()(void){std::cout << "fct for Test<default>" << std::endl;}
};

template <typename A>
class	Test<A, char>
{
public:
  Test(){std::cout << "Test<char> init" << std::endl;}
  void	operator()(void){std::cout << "fct for Test<char>" << std::endl;}
};

template <typename T>
class	Caller
{
public:
  Caller()
  {
    Test<int, T>	test;
    test();
  }
};

#endif // !__TEST_H__
