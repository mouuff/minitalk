##
## Makefile for name in /home/alies_a/rendu/PSU_2015_minitalk
## 
## Made by alies_a
## Login   <alies_a@epitech.net>
## 
## Started on  Mon Feb  1 11:06:37 2016 alies_a
## Last update Mon Feb  1 17:27:35 2016 alies_a
##

SNAME	=	./server/server

SSRC	=	./server/src/

SINC	=	./server/include/

SSRCS	=	$(SSRC)main.c \
		$(SSRC)my_putchar.c \
		$(SSRC)my_put_nbr.c

CNAME	=	./client/client

CSRC	=	./client/src/

CINC	=	./client/include/

CSRCS	=	$(CSRC)main.c \
		$(CSRC)my_strlen.c \
		$(CSRC)my_str_to_nbr.c \
		$(CSRC)my_putstr.c

CC	=	gcc

CFLAGS	=	-I$(CINC) -I$(SINC) \
		-Wall -Wextra

COBJS	=	$(CSRCS:.c=.o)

SOBJS	=	$(SSRCS:.c=.o)

RM	=	rm -f

all:		$(SNAME) $(CNAME)

$(SNAME):	$(SOBJS)
		$(CC) $(SOBJS) -o $(SNAME) $(CFLAGS)

$(CNAME):	$(COBJS)
		$(CC) $(COBJS) -o $(CNAME) $(CFLAGS)

clean:
		$(RM) $(SOBJS)
		$(RM) $(COBJS)

fclean:		clean
		$(RM) $(SNAME)
		$(RM) $(CNAME)

re:		fclean all

.PHONY: all clean fclean re
