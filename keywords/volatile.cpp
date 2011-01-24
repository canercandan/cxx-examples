#include <iostream>

static volatile int	test;

static int	foo()
{
  test = 23;

  std::cout << "in foo: " << test << std::endl;
}

int	main(void)
{
  foo();

  std::cout << "in main: " << test << std::endl;

  return 0;
}
