#include <algorithm>
#include <iostream>
#include <vector>

namespace	EOT
{
  typedef double	Fitness;
}

static EOT::Fitness	compare(EOT::Fitness a,
				EOT::Fitness b)
{
  return (a > b ? b : a);
}

int	main(void)
{
  std::vector<EOT::Fitness>	v;

  v.push_back(23);
  v.push_back(88);
  v.push_back(10);

  std::cout << "max = [" << *std::max_element(v.begin(),
					      v.end(),
					      compare)
	    << "]" << std::endl;

  return 0;
}
