#include <list>
#include "header.hpp"

int	main(void)
{
  F	fct;

  std::list<F>	L;

  for (int i = 0; i < 10; ++i)
    {
      if ((i % 2) == 0)
	L.push_back(caller<char>);
      L.push_back(caller<int>);
      if ((i % 3) == 0)
	L.push_back(caller<CACA::Return>);
    }

  for (std::list<F>::iterator it = L.begin(), end = L.end();
       it != end; ++it)
    (*it)();

  return 0;
}
