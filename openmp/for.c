#include <omp.h>
#include <stdio.h>

int main(void)
{
#ifdef _OPENMP
    omp_set_num_threads(100);
#endif // !_OPENMP

    int i = 0;

#pragma omp parallel for
    for (i = 0; i < 10; i++)
	{
#ifdef _OPENMP
	    printf("th(%d)->", omp_get_thread_num());
#endif // !_OPENMP

	    printf("i(%d)\n", i);
	}

    return (0);
}
