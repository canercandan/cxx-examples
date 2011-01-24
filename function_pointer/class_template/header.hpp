#include <iostream>

template <typename C>
class	Test
{
public:
  Test();

  void	callback(void);

  template <typename T>
  void	callback(void);

  typedef void	(Test<C>::*F)(void);
};

template <typename C>
Test<C>::Test()
{
  std::cout << "Starting Test class ..." << std::endl;
}

template <typename C>
void	Test<C>::callback(void)
{
  std::cout << "I am a callback!!!" << std::endl;
}

template <typename C>
template <typename T>
void	Test<C>::callback(void)
{
  std::cout << "I am a template function callback!!!" << std::endl;
}
