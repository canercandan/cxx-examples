#include <cuda.h>

#include <iostream>
//#include <complex>

#include "cudacomplex.h"

template < typename T >
__global__ void kernel( T v )
{
    v = v + v;
}

int main()
{
    int N = 1000;
    dim3  dimBlock(64, 1, 1);
    dim3  dimGrid((N + dimBlock.x - 1)/dimBlock.x, 1, 1);

    //singlecomplex v1 = cplx::one();
    doublecomplex v1 = doublecomplex::one();
    //double v1 = 2;

    kernel<<<dimGrid , dimBlock>>>( v1 );
}
