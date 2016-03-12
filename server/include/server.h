/*
** server.h for server in /home/alies_a/rendu/PSU_2015_minitalk/server/include
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 11:30:37 2016 alies_a
** Last update Tue Feb  2 16:41:51 2016 alies_a
*/

#ifndef SERVER_H_
#define SERVER_H_

#define SONE SIGUSR1
#define SZERO SIGUSR2

#include <signal.h>

typedef struct s_info
{
  int count;
  char ch;
  int pid;
  int pid_count;
} t_info;

void	my_putchar(char c);
void	my_put_nbr(unsigned int nb);

#endif
