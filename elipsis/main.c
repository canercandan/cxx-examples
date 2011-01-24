#include <stdio.h>
#include <stdarg.h>

void	test(int first, ...)
{
    va_list	ap;
    int	x;

    va_start(ap, first);
    while (1)
    	{
	    x = va_arg(ap, int);
    	}
    va_end(ap);
}

int	main(void)
{
    test(325,4425);

    return (0);
}
