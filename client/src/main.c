/*
** main.c for main in /home/alies_a/rendu/PSU_2015_minitalk/client
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 11:04:27 2016 alies_a
** Last update Tue Feb  2 19:05:52 2016 alies_a
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "client.h"

static int g_lock;

void	unlock(int sig)
{
  if (sig == SIGUSR1)
    g_lock = 0;
}

int	send_pid(pid_t pid)
{
  int   x;
  int	mypid;

  mypid = getpid();
  x = (sizeof(int) * 8) - 1;
  while (x >= 0)
    {
      if (kill(pid, (1 << x & mypid ? SONE : SZERO)) == -1)
	return (1);
      if (usleep(2500) == -1)
	return (1);
       x -= 1;
    }
  return (0);
}

int	send_char(pid_t pid, char c)
{
  int	x;
  int	time;

  x = (sizeof(char) * 8) - 1;
  while (x >= 0)
    {
      g_lock = 1;
      if (kill(pid, (1 << x & c ? SONE : SZERO)) == -1)
	return (1);
      time = 0;
      while (g_lock)
	{
	  time += 1;
	  usleep(WAIT);
	  if (time > TIMEOUT)
	    return (1);
	}
      x -= 1;
    }
  return (0);
}

int	send_str(pid_t pid, const char *str)
{
  int	x;

  x = 0;
  send_pid(pid);
  while (str[x] != '\0')
    {
      if (send_char(pid, str[x]))
	return (1);
      x += 1;
    }
  send_char(pid, 0);
  return (0);
}

int	main(int ac, char **av)
{
  int	sig;

  g_lock = 0;
  signal(SIGUSR1, unlock);
  if (ac != 3)
    {
      my_putstr("Usage: ./client [dest pid] [message]\n");
      return (1);
    }
  sig = my_str_to_nbr(av[1]);
  if (sig < 0)
    {
      my_putstr("Invalid pid.\n");
      return (1);
    }
  if (send_str(sig, av[2]))
    my_putstr("Kill failed.\n");
  return (0);
}
