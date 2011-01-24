#include <iostream>

class Test
{
public:
    operator double() const { return 42; }
    operator std::string() const { return std::string("Hello"); }
};

int main(void)
{
    Test test;

    std::cout << test << std::endl;
    std::cout << std::string(test) << std::endl;
}
