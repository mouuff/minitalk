/*
** my_putstr.c for my put str in /home/alies_a/rendu/PSU_2015_minitalk
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 16:43:38 2016 alies_a
** Last update Mon Feb  1 16:45:06 2016 alies_a
*/

#include <unistd.h>
#include "client.h"

void	my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}
