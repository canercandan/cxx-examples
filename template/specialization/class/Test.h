#ifndef __TEST_H__
# define __TEST_H__

# include <iostream>

template <typename C>
class	Test
{
public:
  template <typename T>
  void	call();
};

template <typename C>
template <typename T>
void	Test<C>::call()
{
  std::cout << "basic call function" << std::endl;
}

// specialization does not work because of the location of template function in a template class
template <typename C>
template <>
void	Test<C>::call<char>()
{
  std::cout << "specializied function with typename CHAR" << std::endl;
}

#endif // !__TEST_H__
