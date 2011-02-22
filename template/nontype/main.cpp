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
