#include <iostream>
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
