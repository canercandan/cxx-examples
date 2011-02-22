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

#ifndef __MYPAIR_H__
# define __MYPAIR_H__

# include <iostream>

template <typename T>
class	myPair
{
    T	values[2];
public:
    myPair(T first, T second)
    {
	values[0] = first;
	values[1] = second;
    }

    template <typename U> void printME(U u)
    {
	for (int i = 0; i < 2; ++i)
	    std::cout << "values[" << i << "] = [" << values[i] << "]" << std::endl;

	std::cout << "[" << u << "]" << " WTF ?!?" << std::endl;
    }
};

#endif // !__MYPAIR_H__
