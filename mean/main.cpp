#include <iostream>

template < typename Atom >
class Mean
{
public:
    Mean() : _n(0), _value(0) {}

    void operator()( Atom value )
    {
	++_n;
	_value += ( 1 / _n ) * ( value - _value );
    }

    Atom value() const { return _value; }

private:
    double _n;
    Atom _value;
};

int main(void)
{
    int array[] = { 10, 2, 3, 34, 3, 4, 45, 99 };
    int array_size = sizeof( array ) / sizeof( array[0] );

    Mean< int > mean;

    for ( unsigned int i = 0; i < array_size; ++i )
	{
	    mean( array[i] );
	}

    std::cout << "mean: " << mean.value() << std::endl;

    return 0;
}
