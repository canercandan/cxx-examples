#include <iostream>
#include <numeric>
#include <vector>

class	IFunctor
{
public:
  virtual ~IFunctor(){}
  virtual int	operator()(int, int) = 0;
};

class	Functor : public IFunctor
{
public:
  Functor(int value) : _value(value){}

  virtual int	operator()(int a, int b)
  {
    return a + b + _value;
  }
private:
  int	_value;
};

class	Functor2 : public IFunctor
{
public:
  Functor2(int value) : _value(value){}

  virtual int	operator()(int a, int b)
  {
    return a - b + _value;
  }
private:
  int	_value;
};

int	main(void)
{
  std::vector<int>	a;

  for (int i = 0, size = 100; i < size; ++i)
    a.push_back(size - i);

  std::vector<int>	b;

  b.reserve(a.size());

  IFunctor*	fct = Functor(1234);

  std::partial_sum(a.begin(), a.end(), b.begin(), *fct);

  delete fct;

  for (int i = 0, size = a.size(); i < size; ++i)
    {
      std::cout << "a[" << i << "] = [" << a[i] << "] ";
      std::cout << "b[" << i << "] = [" << b[i] << "]" << std::endl;
    }

  return 0;
}
