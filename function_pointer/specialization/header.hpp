#ifndef __HEADER_HPP__
# define __HEADER_HPP__

#include <iostream>

namespace CACA
{
  typedef void	Return;
}

typedef CACA::Return	(*F)(void);

template <typename T>
CACA::Return	callback(void);

template <typename T>
CACA::Return	callback(void)
{
  std::cout << "default callback!!!" << std::endl;
}

template <>
CACA::Return	callback<char>(void)
{
  std::cout << "char callback!!!" << std::endl;
}

template <>
CACA::Return	callback<CACA::Return>(void)
{
  std::cout << "CACA::Return callback!!!" << std::endl;
}

template <typename T>
void	caller(void)
{
  F	fct;

  fct = callback<T>;
  fct();
}

#endif // !__HEADER_HPP__
