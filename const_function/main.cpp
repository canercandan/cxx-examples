#include <iostream>

class SubData
{
public:
    SubData() : a(2), b(3) {}

    const int getA() const { return a; }
    const int getB() const { return b; }

private:
    int a;
    int b;
};

class Data
{
public:
    Data() : sub() {}

    const SubData& getSub() const { return sub; }

private:
    SubData sub;
};

struct Setter
{
    void operator()(Data& data) const
    {
	std::cout << data.getSub().getA() << std::endl;
	std::cout << data.getSub().getB() << std::endl;
    }
};

int main(void)
{
    Data data;

    Setter()(data);
}
