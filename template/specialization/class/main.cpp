#include "Test.h"

int	main(void)
{
  Test<int>	test;

  test.call<int>();
  test.call<char>();
}
