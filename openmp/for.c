#include <omp.h>
#include <stdio.h>

void set_threads()
{
#ifdef _OPENMP
    omp_set_num_threads(100);
#endif // !_OPENMP
}

void do_for()
{
#pragma omp parallel
    {
	if ( 0 == omp_get_thread_num() )
	    {
		printf("thread nums: %d\n", omp_get_num_threads());
	    }
    }

    int i = 0;

#pragma omp parallel for
    for (i = 0; i < 10; i++)
	{
#ifdef _OPENMP
	    printf("th(%d)->", omp_get_thread_num());
#endif // !_OPENMP

	    printf("i(%d)\n", i);
	}
}

int main(void)
{
    set_threads();
    do_for();

    return (0);
}
