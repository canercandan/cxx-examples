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

x#include <iostream>
#include <stdio.h>
#include <stdint.h>

inline uint32_t get_rdtsc()
{
    __asm__ ("xor %eax, %eax;" //flush the pipeline
	     "cpuid;"
	     "rdtsc;" //get RDTSC counter in edx:eax
	     );
}

// #define GCLK(m) { int _t = rdtsc(); m; _t = rdtsc() - _t; printf("\n:CLK: %-50.50s :%d\n", #m, _t); }
// static int rdtsc(void) { asm("rdtsc"); }		/* read CPU clock counter */

int main(void)
{
    while (1)
	std::cout << "rdstc: " << get_rdtsc() << std::endl;
}
