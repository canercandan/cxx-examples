#include <cstdlib>
#include <iostream>

int main(void)
{
    while ( 1 )
	{
	    srand(time(NULL));
	    unsigned int r = 100 * ( (double)rand() / RAND_MAX );
	    std::cout << "rand: " << r << std::endl;
	    usleep(r);
	}
}
