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

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main(void)
{
    std::vector< std::string > vec(2);
    std::vector< std::string >::iterator it;

    vec[ 0 ] = "aaa";
    vec[ 1 ] = "bbb";

    it = std::find(vec.begin(), vec.end(), "aaa");
    std::cout << "idx aaa: " << it - vec.begin() << std::endl;

    it = std::find(vec.begin(), vec.end(), "bbb");
    std::cout << "idx bbb: " << it - vec.begin() << std::endl;

    it = std::find(vec.begin(), vec.end(), "ccc");
    std::cout << "idx ccc: " << it - vec.begin() << std::endl;

    it = std::find(vec.begin(), vec.end(), "ddd");
    std::cout << "idx ddd: " << it - vec.begin() << std::endl;

    return 0;
}
