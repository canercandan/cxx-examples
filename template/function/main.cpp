#include <iostream>

template <typename T>
T	GetMax(T a, T b)
{
  return (a > b ? a : b);
}

template <typename T, typename U>
T	GetMax(T a, U b)
{
  return (a > (T)b ? a : (T)b);
}

int	main(void)
{
  std::cout << GetMax(5.0, 6.0) << std::endl;
  return 0;
}
