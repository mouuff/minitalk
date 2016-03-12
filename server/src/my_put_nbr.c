/*
** my_put_nbr.c for put nbr in /home/alies_a/rendu/PSU_2015_minitalk
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 16:46:31 2016 alies_a
** Last update Mon Feb  1 17:29:34 2016 alies_a
*/

#include "server.h"

void	my_put_nbr(unsigned int nb)
{
  int	x;

  x = 1;
  while ((nb / (x * 10)) > 0)
    x *= 10;
  while (x > 0)
    {
      my_putchar((nb / x) % 10 + '0');
      x /= 10;
    }
  my_putchar('\n');
}
