#include <csignal>

int	main(void)
{
  ::signal(SIGINT, SIG_IGN);
  // ::signal(SIGQUIT, SIG_IGN);
  // ::signal(SIGABRT, SIG_IGN);
  // ::signal(SIGKILL, SIG_IGN);// not allowed

  while (1);

  return 0;
}
