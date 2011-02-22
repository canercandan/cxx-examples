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

#ifndef __TEST_H__
# define __TEST_H__

# include <iostream>

template <typename A, typename C>
void	callback(void){std::cout << "fct for default" << std::endl;}

template <typename A>
void	callback<A, char>(void){std::cout << "fct for char" << std::endl;}

template <typename T>
class	Caller
{
public:
  Caller()
  {
    callback<int, T>();
  }
};

#endif // !__TEST_H__
