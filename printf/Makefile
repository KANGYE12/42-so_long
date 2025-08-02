NAME	= libftprintf.a

SRCS	= ft_printf.c  print_char.c  print_digit.c  print_str.c print_pointer.c print_hex.c



OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

%o:%.c
	$(CC)$(CFLAGS) -< $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re