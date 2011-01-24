#include <iostream>

template <int A, int B>
void	add()
{
  std::cout << A << " + " << B << " = " << A + B << std::endl;
}

int	main(void)
{
  add<12, 42>();

  return 0;
}
