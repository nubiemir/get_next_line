SRCS			= get_next_line_utils.c get_next_line.c main.c

OBJS			= $(SRCS:.c=.o)

CC				= cc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= get_next_line.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re