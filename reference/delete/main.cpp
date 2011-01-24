#include <iostream>

class	Alloc
{
public:
  Alloc(std::string s) : _s(s){}
  ~Alloc(){std::cout << "cool cool [" << _s << "]" << std::endl;}
private:
  std::string	_s;
};

int	main(void)
{
  Alloc* allo = new Alloc("caca");

  {
    Alloc& allocR = *allo; // 1st step
    Alloc	tata("tata"); // 2nd step

    Alloc* troc = new Alloc("troc"); // 3rd step
    Alloc& trocR = *troc;
  }

  while(1);

  delete allo;

  return 0;
}
