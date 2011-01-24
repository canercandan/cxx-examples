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
