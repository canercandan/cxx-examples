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
#include <numeric>
#include <vector>

class	IFunctor
{
public:
  virtual ~IFunctor(){}
  virtual int	operator()(int, int) = 0;
};

class	Functor : public IFunctor
{
public:
  Functor(int value) : _value(value){}

  virtual int	operator()(int a, int b)
  {
    return a + b + _value;
  }
private:
  int	_value;
};

class	Functor2 : public IFunctor
{
public:
  Functor2(int value) : _value(value){}

  virtual int	operator()(int a, int b)
  {
    return a - b + _value;
  }
private:
  int	_value;
};

int	main(void)
{
  std::vector<int>	a;

  for (int i = 0, size = 100; i < size; ++i)
    a.push_back(size - i);

  std::vector<int>	b;

  b.reserve(a.size());

  IFunctor*	fct = Functor(1234);

  std::partial_sum(a.begin(), a.end(), b.begin(), *fct);

  delete fct;

  for (int i = 0, size = a.size(); i < size; ++i)
    {
      std::cout << "a[" << i << "] = [" << a[i] << "] ";
      std::cout << "b[" << i << "] = [" << b[i] << "]" << std::endl;
    }

  return 0;
}
