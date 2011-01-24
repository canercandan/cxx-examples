#include <complex>
#include <iostream>

int main()
{
    std::complex< double > c1(1), c2(2), c3;

    std::complex< double > *p1 = &c1, *p2 = &c2;

    c3 = p1[0] * p2[0];

    std::cout << c3 << std::endl;
}
