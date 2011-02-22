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

#include <omp.h>
#include <stdio.h>

int main(void)
{
#ifdef _OPENMP
    omp_set_num_threads(100);
#endif // !_OPENMP

    const int array[] = {100, 200, 300, 400, 500, 999};
    const unsigned int size = sizeof(array) / sizeof(*array);

    unsigned int i = 0;

    int sum = 0;

#pragma omp parallel for reduction(+:sum)
    for (i = 0; i < size; i++)
	{
	    sum += array[i];

#ifdef _OPENMP
	    printf("th(%d)->", omp_get_thread_num());
#endif // !_OPENMP

	    printf("sum(%d)\n", sum);
	}

    printf("sum total: %d\n", sum);

    return (0);
}
