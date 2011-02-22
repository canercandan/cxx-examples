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
#include <typeinfo>

class MemorySpace {};
class Device : public MemorySpace {};
class Host : public MemorySpace {};

template < typename IndexType, typename ValueType, typename MemorySpace >
class csr_matrix
{
public:
    csr_matrix()
    {
	std::cout << "csr_matrix" << std::endl;
	std::cout << typeid(IndexType).name() << std::endl;
	std::cout << typeid(ValueType).name() << std::endl;
	std::cout << typeid(MemorySpace).name() << std::endl;
    }
};

template < typename IndexType, typename ValueType, typename MemorySpace >
class hyb_matrix
{
public:
    hyb_matrix()
    {
	std::cout << "hyb_matrix" << std::endl;
	std::cout << typeid(IndexType).name() << std::endl;
	std::cout << typeid(ValueType).name() << std::endl;
	std::cout << typeid(MemorySpace).name() << std::endl;
    }
};

class BaseMatrix {};

template <
    typename T,
    template < typename, typename, typename > class MatrixFormat
    >
class Matrix : public BaseMatrix, public MatrixFormat< int, T, Device >
{};

int main()
{
    Matrix< float, csr_matrix > matrix;
    Matrix< float, hyb_matrix > matrix2;
}
