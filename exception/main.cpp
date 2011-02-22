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
#include <exception>

class	Exception : public std::exception
{
public:
  std::string	what()
  {
    return "coucou";
  }

  friend std::ostream&	operator<<(std::ostream& os, Exception& e)
  {
    os << e.what();
    return os;
  }
};

class	Exception2 : public std::exception
{};

static void	foo2()
{
  if (2 == 2)
    throw Exception2();
}

static void	foo()
{
  if (1 == 1)
    {
      foo2();
      throw Exception();
    }
}

int	main(void)
{
  try
    {
      foo();
    }
  catch (Exception e)
    {
      std::cout << "foo has been catched" << std::endl;
      std::cout << e.what() << std::endl;
      std::cout << e << std::endl;
    }
  catch (Exception2 e)
    {
      std::cout << e.what() << std::endl;
    }
}
