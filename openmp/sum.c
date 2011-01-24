#include <omp.h>
#include <stdio.h>

int main(void)
{
#ifdef _OPENMP
    omp_set_num_threads(100);
#endif // !_OPENMP

    const int array[] = {100, 200, 300, 400, 500, 999};
    const unsigned int size = sizeof(array) / sizeof(*array);

    unsigned int i = 0;

    int sum = 0;

#pragma omp parallel for reduction(+:sum)
    for (i = 0; i < size; i++)
	{
	    sum += array[i];

#ifdef _OPENMP
	    printf("th(%d)->", omp_get_thread_num());
#endif // !_OPENMP

	    printf("sum(%d)\n", sum);
	}

    printf("sum total: %d\n", sum);

    return (0);
}
