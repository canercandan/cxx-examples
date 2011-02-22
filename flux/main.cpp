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

#include <ios>
#include <ostream>
#include <iosfwd>
#include <cstdio>
#include <unistd.h>

class	Obuffer : public std::streambuf
{
public:
  Obuffer(int fd) : _fd(fd)
  {}
protected:
  virtual int	overflow(int c)
  {
    if (c != traits_type::eof())
      {
	char	z = c;
	if (::write(_fd, &z, 1) != 1)
	  return traits_type::eof();
      }
    return c;
  }

  virtual std::streamsize	xsputn(const char* s, std::streamsize num)
  {
    return ::write(_fd, s, num);
  }

  int	_fd;
};

class	Ostream : public std::ostream
{
public:
  Ostream() : std::ostream(&_buf), _buf(0)
  {}
protected:
  Obuffer	_buf;
};

Ostream	os;

int	main(void)
{
  std::ios::sync_with_stdio(false);

  std::string	s("caca");

  os << s << std::endl;

  return 0;
}
