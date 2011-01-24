#include <iostream>

template <typename T, int N>
class mysequence
{
  T	memblock[N];
public:
  void	setmember(int x, T value);
  T	getmember(int x);
};

template <typename T, int N>
void	mysequence<T, N>::setmember(int x, T value)
{
  memblock[x] = value;
}

template <typename T, int N>
T	mysequence<T, N>::getmember(int x)
{
  return memblock[x];
}

int	main(void)
{
  mysequence<int, 5>	myints;
  mysequence<float, 5>	myfloats;

  myints.setmember(0, 100);
  myfloats.setmember(3, 3.1416);

  std::cout << myints.getmember(0) << std::endl;
  std::cout << myfloats.getmember(3) << std::endl;

  return 0;
}
