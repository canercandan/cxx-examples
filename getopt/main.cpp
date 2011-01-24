#include <iostream>
#include <cstdlib>
#include <unistd.h>

int	main(int ac, char** av)
{
  int	c;

  while ((c = getopt(ac, av, "he:")) != 1)
    {
      if (c == '?')
	exit(-1);
      std::cout << "option: " << optarg << std::endl;
    }

  return 0;
}
