#include <iostream>

int	main(void)
{
  int b = 12;
  int c = 324;
  int& a = b;

  std::cout << "a:" << a << std::endl;
  std::cout << "b:" << b << std::endl;
  std::cout << "c:" << c << std::endl;

  a = c;

  std::cout << "a:" << a << std::endl;
  std::cout << "b:" << b << std::endl;
  std::cout << "c:" << c << std::endl;

  return 0;
}
