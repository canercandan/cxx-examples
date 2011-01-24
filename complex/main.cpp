#include <complex>
#include <iostream>

template < typename T >
bool operator<( const std::complex< T >& lhs, const std::complex< T >& rhs )
{
    return lhs.real() < rhs.real();
}

int main(void)
{
    std::complex< float > cf(1.0, 2.0), cf2(2,3);
    std::complex< double > cd(1, 2);
    std::complex< long double > cld(1, 2);

    cf < cf2;

    std::cout << cf << " " << cd << " " << cld << std::endl;

    return 0;
}
