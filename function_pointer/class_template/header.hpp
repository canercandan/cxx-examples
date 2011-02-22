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

template <typename C>
class	Test
{
public:
  Test();

  void	callback(void);

  template <typename T>
  void	callback(void);

  typedef void	(Test<C>::*F)(void);
};

template <typename C>
Test<C>::Test()
{
  std::cout << "Starting Test class ..." << std::endl;
}

template <typename C>
void	Test<C>::callback(void)
{
  std::cout << "I am a callback!!!" << std::endl;
}

template <typename C>
template <typename T>
void	Test<C>::callback(void)
{
  std::cout << "I am a template function callback!!!" << std::endl;
}
