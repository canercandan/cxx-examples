#include <iostream>

template <typename T>
void	call()
{
  std::cout << "basic call function" << std::endl;
}

template <>
void	call<char>()
{
  std::cout << "specializied function with typename CHAR" << std::endl;
}

int	main(void)
{
  call<int>();
  call<char>();
}
