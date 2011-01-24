#include <iostream>
#include <vector>
#include <list>

typedef std::list< int > INTS;

int main(void)
{
    INTS v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    INTS::iterator it = v.begin();

    it = it + 1;

    std::cout << "current position: " << *it << " current + 2: " << *(it + 2) << std::endl;

    return 0;
}
