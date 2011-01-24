#include <iostream>
#include <functional>

class	Fct
{
public:
  Fct(){a = 0;}

  void operator()(int)
  {
    std::cout << "coucou caca" << ' ' << a << std::endl;
  }
  int	a;
};

template <class T>
void	print(T fct)
{
  fct(0);
}

// void	printC(void (*fct)(int)) // not allowed
// {
//   fct(0);
// }

int	main(void)
{
  Fct	fct;

  print(fct);
  fct.a = 12;
  print(fct);
  fct.a = 23;
  print(fct);
  fct.a = 42;
  print(fct);

  return 0;
}
