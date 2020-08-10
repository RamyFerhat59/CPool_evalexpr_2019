##
## EPITECH PROJECT, 2019
## CPool_evalexpr
## File description:
## Makefile
##

SRCS	= 	main.c 		\


OBJS	=	$(SRCS:.c=.o)

CFLAGS	=

CC		=	gcc

RM		=	rm -rf

NAME	=	eval_expr

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re