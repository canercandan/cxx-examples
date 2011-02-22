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

#include <cusp/array1d.h>
#include <cusp/blas.h>
#include <cusp/print.h>
#include <iostream>

int main(void)
{
    typedef float T;

    //T u[] = {0,1,2,3,4,5,6,7,8,9};
    T u[] = {1,1,1,1,1,1,1,1,1,1};
    const int size = sizeof(u) / sizeof(*u);

    T w = cusp::blas::dot< T* >( u, u + size, u );

    std::cout << "w: " << w << std::endl;

    //cusp::print_matrix(u);

    return 0;
}
