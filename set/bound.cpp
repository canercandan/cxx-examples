#include <iostream>
#include <set>

int main()
{
    std::set< int > s;

    for (int i = 1; i < 10; ++i)
	{
	    s.insert(i*10);
	    s.insert(i*10);
	}

    for (std::set< int >::iterator it = s.begin(), end = s.end();
	 it != end; ++it)
	{
	    std::cout << *it << " ";
	}
    std::cout << std::endl;

    std::cout << *s.lower_bound(10) << std::endl;
    std::cout << *s.upper_bound(10) << std::endl;

    return 0;
}
