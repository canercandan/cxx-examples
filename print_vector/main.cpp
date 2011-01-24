#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

int	main(void)
{
  std::vector<std::string>	vec;

  vec.push_back("toto");
  vec.push_back("tata");
  vec.push_back("titi");

  std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));
  std::cout << std::endl;
}
