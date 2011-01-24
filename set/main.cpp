#include <set>
#include <list>
#include <iostream>

class	Test
{
public:
  Test() : _a(0){}
  bool	operator<(const Test& t) const
  {
    return _a < t._a;
  }

  int	_a;
};

int	main(void)
{
  std::set<int>	s;

  s.insert(42);
  std::set<int>::iterator last = s.end();
  last--;

  std::cout << "s last value: " << *last << std::endl;

  return 0;
}
