// -*- mode: c++; c-indent-level: 4; c++-member-init-indent: 8; comment-column: 35; -*-

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 * Caner Candan <caner@candan.fr>, http://caner.candan.fr
 */

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
