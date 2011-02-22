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

#include <set>
#include <list>
#include <iostream>

class	Test
{
public:
  Test() : _a(0){}
  bool	operator<(const Test& t) const
  {
    return _a < t._a;
  }

  int	_a;
};

int	main(void)
{
  std::set<int>	s;

  s.insert(42);
  std::set<int>::iterator last = s.end();
  last--;

  std::cout << "s last value: " << *last << std::endl;

  return 0;
}
