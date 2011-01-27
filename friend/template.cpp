#include <iostream>

template < typename T >
class	Test
{
public:
    Test() : _a(0), _b(0) {}

    template < typename T1 > friend void convertTestTo42(Test< T1 >& test);

    void printME(void)
    {
	std::cout << "A [" << _a << "] B [" << _b << "]" << std::endl;
    }

private:
    int _a;
    int _b;
};

template < typename T >
void convertTestTo42(Test< T >& test)
{
    test._a = 42;
    test._b = 42;
}

int main(void)
{
    Test< int > test;

    test.printME();

    convertTestTo42(test);

    test.printME();

    return 0;
}
