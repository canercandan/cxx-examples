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

#ifndef __HEADER_HPP__
# define __HEADER_HPP__

#include <iostream>

namespace CACA
{
  typedef void	Return;
}

typedef CACA::Return	(*F)(void);

template <typename T>
CACA::Return	callback(void);

template <typename T>
CACA::Return	callback(void)
{
  std::cout << "default callback!!!" << std::endl;
}

template <>
CACA::Return	callback<char>(void)
{
  std::cout << "char callback!!!" << std::endl;
}

template <>
CACA::Return	callback<CACA::Return>(void)
{
  std::cout << "CACA::Return callback!!!" << std::endl;
}

template <typename T>
void	caller(void)
{
  F	fct;

  fct = callback<T>;
  fct();
}

#endif // !__HEADER_HPP__
