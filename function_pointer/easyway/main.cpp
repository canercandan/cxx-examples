// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 * Caner Candan <caner@candan.fr>, http://caner.candan.fr
 */

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
