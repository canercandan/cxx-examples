#include <cusp/array1d.h>
#include <cusp/blas.h>
#include <cusp/print.h>
#include <iostream>

int main(void)
{
    typedef float T;

    //T u[] = {0,1,2,3,4,5,6,7,8,9};
    T u[] = {1,1,1,1,1,1,1,1,1,1};
    const int size = sizeof(u) / sizeof(*u);

    T w = cusp::blas::dot< T* >( u, u + size, u );

    std::cout << "w: " << w << std::endl;

    //cusp::print_matrix(u);

    return 0;
}
