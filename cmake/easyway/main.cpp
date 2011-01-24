#include <iostream>

static void	test(int)
{
  return;
}

int	main(void)
{
  std::cout << "hello test mania" << std::endl;

  test(12);

  return 0;
}
