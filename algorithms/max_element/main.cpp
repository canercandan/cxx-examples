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

#include <algorithm>
#include <iostream>
#include <vector>

namespace	EOT
{
  typedef double	Fitness;
}

static EOT::Fitness	compare(EOT::Fitness a,
				EOT::Fitness b)
{
  return (a > b ? b : a);
}

int	main(void)
{
  std::vector<EOT::Fitness>	v;

  v.push_back(23);
  v.push_back(88);
  v.push_back(10);

  std::cout << "max = [" << *std::max_element(v.begin(),
					      v.end(),
					      compare)
	    << "]" << std::endl;

  return 0;
}
