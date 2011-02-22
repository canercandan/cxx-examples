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

template < typename Atom >
class Mean
{
public:
    Mean() : _n(0), _value(0) {}

    void operator()( Atom value )
    {
	++_n;
	_value += ( 1 / _n ) * ( value - _value );
    }

    Atom value() const { return _value; }

private:
    double _n;
    Atom _value;
};

int main(void)
{
    int array[] = { 10, 2, 3, 34, 3, 4, 45, 99 };
    int array_size = sizeof( array ) / sizeof( array[0] );

    Mean< int > mean;

    for ( unsigned int i = 0; i < array_size; ++i )
	{
	    mean( array[i] );
	}

    std::cout << "mean: " << mean.value() << std::endl;

    return 0;
}
