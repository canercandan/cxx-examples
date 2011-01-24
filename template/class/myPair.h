#ifndef __MYPAIR_H__
# define __MYPAIR_H__

# include <iostream>

template <typename T>
class	myPair
{
    T	values[2];
public:
    myPair(T first, T second)
    {
	values[0] = first;
	values[1] = second;
    }

    template <typename U> void printME(U u)
    {
	for (int i = 0; i < 2; ++i)
	    std::cout << "values[" << i << "] = [" << values[i] << "]" << std::endl;

	std::cout << "[" << u << "]" << " WTF ?!?" << std::endl;
    }
};

#endif // !__MYPAIR_H__
