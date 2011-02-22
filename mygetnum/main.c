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

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int	mygetnum(char *s)
{
    int	i;
    int	res;
    int	size;

    for (i = 0, size = strlen(s), res = 0; i < size; i++)
	{
	    if (!isdigit(s[i]))
		{
		    res /= pow(10, size - i);
		    break;
		}
	    res += (s[i] - 48) * pow(10, size - 1 - i);
	}
    return (res);
}

int	main(int ac, char **av)
{
    if (ac > 1)
	printf("mygetnum(\"%s\") = %d\n", av[1], mygetnum(av[1]));
    return (0);
}
