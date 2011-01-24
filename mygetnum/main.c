#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int	mygetnum(char *s)
{
    int	i;
    int	res;
    int	size;

    for (i = 0, size = strlen(s), res = 0; i < size; i++)
	{
	    if (!isdigit(s[i]))
		{
		    res /= pow(10, size - i);
		    break;
		}
	    res += (s[i] - 48) * pow(10, size - 1 - i);
	}
    return (res);
}

int	main(int ac, char **av)
{
    if (ac > 1)
	printf("mygetnum(\"%s\") = %d\n", av[1], mygetnum(av[1]));
    return (0);
}
