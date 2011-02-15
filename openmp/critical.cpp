#include <omp.h>
#include <iostream>

static int data = 0;

int main(void)
{
#pragma omp parallel
    {
#pragma omp critical
	if ( 1 )
	    {
	    }
	data = omp_get_thread_num();
	std::cout << "data value: " << data << std::endl;
	//}
    }
}
