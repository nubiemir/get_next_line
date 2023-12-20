SRCS			= get_next_line_utils.c get_next_line.c

OBJS			= $(SRCS:.c=.o)

BONUS			= get_next_line_utils_bonus.c get_next_line_bonus.c main.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= cc -g
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -D BUFFER_SIZE=10

NAME			= get_next_line.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re