/*
** client.h for client in /home/alies_a/rendu/PSU_2015_minitalk/client
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 11:32:14 2016 alies_a
** Last update Tue Feb  2 18:38:31 2016 alies_a
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define SONE (SIGUSR1)
#define SZERO (SIGUSR2)
#define TIMEOUT (10000)
#define WAIT (5)

#include <signal.h>

int	my_strlen(const char *str);
void	my_putstr(const char *str);
int     my_str_to_nbr(const char *str);

#endif
