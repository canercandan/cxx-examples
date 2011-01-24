#include <iostream>
#include <exception>

class	Exception : public std::exception
{
public:
  std::string	what()
  {
    return "coucou";
  }

  friend std::ostream&	operator<<(std::ostream& os, Exception& e)
  {
    os << e.what();
    return os;
  }
};

class	Exception2 : public std::exception
{};

static void	foo2()
{
  if (2 == 2)
    throw Exception2();
}

static void	foo()
{
  if (1 == 1)
    {
      foo2();
      throw Exception();
    }
}

int	main(void)
{
  try
    {
      foo();
    }
  catch (Exception e)
    {
      std::cout << "foo has been catched" << std::endl;
      std::cout << e.what() << std::endl;
      std::cout << e << std::endl;
    }
  catch (Exception2 e)
    {
      std::cout << e.what() << std::endl;
    }
}
