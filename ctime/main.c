#include <time.h>
#include <stdio.h>

int	main(void)
{
  time_t t = time(0);
  printf("ctime [%s]\n", ctime(&t));
  return (0);
}
