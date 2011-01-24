#include <iostream>

class	A
{
public:
  int	a;
};

class	B : virtual public A{};
class	C : virtual public A{};

class	D : public B, public C
{};

int	main(void)
{
  D	d;

  d.C::a = 12;

  std::cout << d.B::a << std::endl;

  return 0;
}
