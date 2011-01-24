#include <time.h>
#include <stdio.h>

int	main(void)
{
  unsigned int	start;
  unsigned int	end;

  start = (unsigned int)time(NULL);

  int	i;
  for (i = 0; i < 1000000; i++)
    {
      printf("%d\n", i);
    }

  end = (unsigned int)time(NULL);

  printf("execution has taken [%d] seconds\n", end - start);

  return (0);
}
