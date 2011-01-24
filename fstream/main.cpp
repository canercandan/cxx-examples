#include <iostream>
#include <fstream>

int	main(int ac, char** av)
{
  if (ac < 2)
    {
      std::cout << "please put a file in argument" << std::endl;
      return -1;
    }

  std::ifstream	file;

  file.open(av[0]);
  if (file.is_open() == false)
    {
      std::cout << "your entered file is incorrect, please type another one" << std::endl;
      return -1;
    }

  std::cout << "file correct, thx!" << std::endl;

  file.close();

  return 0;
}
