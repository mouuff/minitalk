/*
** my_putchar.c for my putchar in /home/alies_a/rendu/PSU_2015_minitalk
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 17:25:44 2016 alies_a
** Last update Mon Feb  1 17:27:09 2016 alies_a
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
