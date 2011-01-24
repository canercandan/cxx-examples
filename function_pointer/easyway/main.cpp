#include <iostream>
#include <list>

class	Test
{
public:
  typedef void	(Test::*fct)(void);

  inline void addFct(fct func)
  {_list.push_back(func);}

  inline void	aaa(void)
  {std::cout << "aaa function" << std::endl;}
  inline void	bbb(void)
  {std::cout << "bbb function" << std::endl;}

  inline void	callFcts(void)
  {
    for (std::list<fct>::iterator
	   it = _list.begin(),
	   end = _list.end(); it != end; ++it)
      {
	fct f = *it;
	(this->*f)();
      }
  }

private:
  std::list<fct>	_list;
};

int	main(void)
{
  Test	test;

  test.addFct(&Test::aaa);
  test.addFct(&Test::bbb);
  test.addFct(&Test::bbb);
  test.addFct(&Test::bbb);
  test.addFct(&Test::bbb);

  test.callFcts();

  return 0;
}
