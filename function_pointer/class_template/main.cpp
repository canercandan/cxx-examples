#include "header.hpp"

int	main(void)
{
  Test<int>	obj;

  Test<int>::F	fct;

  fct = &Test<int>::callback;
  (obj.*fct)();

  fct = &Test<int>::callback<int>;
  (obj.*fct)();

  return 0;
}
