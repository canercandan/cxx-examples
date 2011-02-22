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

class SubData
{
public:
    SubData() : a(2), b(3) {}

    const int getA() const { return a; }
    const int getB() const { return b; }

private:
    int a;
    int b;
};

class Data
{
public:
    Data() : sub() {}

    const SubData& getSub() const { return sub; }

private:
    SubData sub;
};

struct Setter
{
    void operator()(Data& data) const
    {
	std::cout << data.getSub().getA() << std::endl;
	std::cout << data.getSub().getB() << std::endl;
    }
};

int main(void)
{
    Data data;

    Setter()(data);
}
