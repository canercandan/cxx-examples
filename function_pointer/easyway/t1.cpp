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
#include <map>

struct	Test
{
  void	test1(){}

  void	test2(){}

  void	test3(){}

  typedef void	(Test::*fct)();
  typedef std::map<int, fct>	MyMap;

  MyMap	_m;
};

int	main(void)
{
  Test	test;

  test._m[0] = &Test::test1;
  test._m[1] = &Test::test2;

  for (Test::MyMap::iterator
	 it = test._m.begin(),
	 end = test._m.end();
       it != end; ++it)
    {
      Test::fct f = it->second;

      if (f == &Test::test1)
	std::cout << "test1 found" << std::endl;

      if (f == &Test::test3)
	std::cout << "test3 found" << std::endl;

    }

  return 0;
}
