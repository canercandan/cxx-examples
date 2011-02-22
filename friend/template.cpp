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

template < typename T >
class	Test
{
public:
    Test() : _a(0), _b(0) {}

    template < typename T1 > friend void convertTestTo42(Test< T1 >& test);

    void printME(void)
    {
	std::cout << "A [" << _a << "] B [" << _b << "]" << std::endl;
    }

private:
    int _a;
    int _b;
};

template < typename T >
void convertTestTo42(Test< T >& test)
{
    test._a = 42;
    test._b = 42;
}

int main(void)
{
    Test< int > test;

    test.printME();

    convertTestTo42(test);

    test.printME();

    return 0;
}
