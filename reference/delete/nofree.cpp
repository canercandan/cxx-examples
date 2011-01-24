#include <iostream>
#include <list>
#include <cstdlib>
#include <unistd.h>
#include <csignal>

std::list<void*>* g_l = NULL;

void	signal_handler(int)
{
  ::signal(SIGINT, SIG_IGN);

  for (std::list<void*>::iterator it = g_l->begin(), end = g_l->end();
       it != end; ++it)
    {
      std::cout << "x1 freezed" << std::endl;
      free(*it);
    }

  delete g_l;

  std::cout << "freezed!!!" << std::endl;

  exit(0);
}

int	main(void)
{
  g_l = new std::list<void*>;

  ::signal(SIGINT, signal_handler);

  for (int i = 0; true; ++i)
    {
      g_l->push_back((void*)malloc(sizeof(int) * 10000000));
      std::cout << i << " seconds..." << std::endl;
      sleep(1);
    }

  signal_handler(0);

  return 0;
}
