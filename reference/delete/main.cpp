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

class	Alloc
{
public:
  Alloc(std::string s) : _s(s){}
  ~Alloc(){std::cout << "cool cool [" << _s << "]" << std::endl;}
private:
  std::string	_s;
};

int	main(void)
{
  Alloc* allo = new Alloc("caca");

  {
    Alloc& allocR = *allo; // 1st step
    Alloc	tata("tata"); // 2nd step

    Alloc* troc = new Alloc("troc"); // 3rd step
    Alloc& trocR = *troc;
  }

  while(1);

  delete allo;

  return 0;
}
