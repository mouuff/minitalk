/*
** my_str_to_nbr.c for str to nbr in /home/alies_a/rendu/PSU_2015_minitalk/client/src
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 13:29:31 2016 alies_a
** Last update Mon Feb  1 17:46:11 2016 alies_a
*/

#include "client.h"

int     my_compute(int len, const char *str, int *mul, int *result)
{
  int   add;

  add = 0;
  if (str[len] >= '0' && str[len] <= '9')
    {
      add = *mul * (str[len] - '0');
      *result += add;
      *mul *= 10;
    }
  return (0);
}

int     my_str_to_nbr(const char *str)
{
  int   result;
  int   len;
  int   mul;

  result = 0;
  mul = 1;
  len = my_strlen(str) - 1;
  if (len > 8)
    return (-1);
  while (len + 1 > 0)
    {
      my_compute(len, str, &mul, &result);
      len -= 1;
    }
  if (str[0] == '-')
    result = -result;
  return (result);
}
