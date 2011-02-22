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
#include <vector>
#include <list>

typedef std::list< int > INTS;

int main(void)
{
    INTS v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    INTS::iterator it = v.begin();

    it = it + 1;

    std::cout << "current position: " << *it << " current + 2: " << *(it + 2) << std::endl;

    return 0;
}
