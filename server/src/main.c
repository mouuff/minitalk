/*
** main.c for main in /home/alies_a/rendu/PSU_2015_minitalk/server
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 11:05:27 2016 alies_a
** Last update Thu Feb  4 18:55:21 2016 alies_a
*/

#include <sys/types.h>
#include <unistd.h>
#include "server.h"

static t_info g_info;

void	add_pid(int sig)
{
  g_info.ch = 0;
  g_info.count = 0;
  if (g_info.pid_count == 0)
    g_info.pid = 0;
  g_info.pid <<= 1;
  if (sig == SONE)
    g_info.pid |= 1;
  g_info.pid_count += 1;
}

void	add_ch(int sig)
{
  g_info.ch <<= 1;
  if (sig == SONE)
    g_info.ch |= 1;
  g_info.count += 1;
  if (g_info.count >= (int)(sizeof(char) * 8))
    {
      write(1, &(g_info.ch), 1);
      if (g_info.ch == 0)
	{
	  my_putchar('\n');
	  g_info.pid_count = 0;
	}
      g_info.ch = 0;
      g_info.count = 0;
    }
  kill(g_info.pid, SIGUSR1);
}

void	handler(int sig)
{
  if (sig == SONE || sig == SZERO)
    {
      if (g_info.pid_count < (int)(sizeof(int) * 8))
	add_pid(sig);
      else
	add_ch(sig);
    }
}

int	main()
{
  my_put_nbr(getpid());
  g_info.count = 0;
  g_info.ch = 0;
  g_info.pid_count = 0;
  if (signal(SONE, handler) == SIG_ERR)
    return (1);
  if (signal(SZERO, handler) == SIG_ERR)
    return (1);
  while (42)
    usleep(5000);
  return (0);
}
