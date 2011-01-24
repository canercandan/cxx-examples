#include <iostream>
#include <fstream>

int	main(void)
{
  std::ofstream	out;
  std::filebuf*	buf;

  out.open("out.txt");
  buf = out.rdbuf();
  std::clog << buf << std::endl;
  out.close();
  return 0;
}
