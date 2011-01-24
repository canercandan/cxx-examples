#include <iostream>

void	callback(void);

template <typename T>
void	callback(void);

typedef void	(*F)(void);

int	main(void)
{
  F	fct;

  fct = callback;

  fct();
  fct();
  fct();
  fct();

  fct = callback<int>;

  fct();
  fct();
  fct();
  fct();
  fct();

  return 0;
}

void	callback(void)
{
  std::cout << "I am a callback!!!" << std::endl;
}

template <typename T>
void	callback(void)
{
  std::cout << "I am a template function callback!!!" << std::endl;
}
