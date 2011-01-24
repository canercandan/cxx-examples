#ifndef __TEST_H__
# define __TEST_H__

# include <iostream>

template <typename A, typename C>
void	callback(void){std::cout << "fct for default" << std::endl;}

template <typename A>
void	callback<A, char>(void){std::cout << "fct for char" << std::endl;}

template <typename T>
class	Caller
{
public:
  Caller()
  {
    callback<int, T>();
  }
};

#endif // !__TEST_H__
