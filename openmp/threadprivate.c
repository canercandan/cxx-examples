#include "threadprivate.h"

int* a;
int b;

int main(void)
{
#pragma omp parallel
    {
	(void)a;
    }
}
