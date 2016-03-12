/*
** my_strlen.c for strlen in /home/alies_a/rendu/PSU_2015_minitalk/server/src
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  1 13:25:00 2016 alies_a
** Last update Mon Feb  1 13:25:41 2016 alies_a
*/

int	my_strlen(const char *str)
{
  int	x;

  x = 0;
  while (str[x] != '\0')
    x += 1;
  return (x);
}
