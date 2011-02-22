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

#include <complex>
#include <iostream>

template < typename T >
bool operator<( const std::complex< T >& lhs, const std::complex< T >& rhs )
{
    return lhs.real() < rhs.real();
}

int main(void)
{
    std::complex< float > cf(1.0, 2.0), cf2(2,3);
    std::complex< double > cd(1, 2);
    std::complex< long double > cld(1, 2);

    cf < cf2;

    std::cout << cf << " " << cd << " " << cld << std::endl;

    return 0;
}
