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
#include <set>

int main()
{
    std::set< int > s;

    for (int i = 1; i < 10; ++i)
	{
	    s.insert(i*10);
	    s.insert(i*10);
	}

    for (std::set< int >::iterator it = s.begin(), end = s.end();
	 it != end; ++it)
	{
	    std::cout << *it << " ";
	}
    std::cout << std::endl;

    std::cout << *s.lower_bound(10) << std::endl;
    std::cout << *s.upper_bound(10) << std::endl;

    return 0;
}
