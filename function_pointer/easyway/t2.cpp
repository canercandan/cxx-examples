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
  static void	test1(){}
  static void	test2(){}
  static void	test3(){}

  typedef void	(*fct)();
  typedef std::map<fct, int>	MyMap;

  MyMap	_m;
};

int	main(void)
{
  Test	test;

  test._m[Test::test1] = 1;
  test._m[Test::test2] = 2;

  if (test._m.find(Test::test3) != test._m.end())
    std::cout << "test2 found" << std::endl;

  return 0;
}
