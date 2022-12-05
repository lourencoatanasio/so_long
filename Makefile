SRCS		=	main.c mlx.c map.c screen.c controls.c functions.c free.c ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c

OBJS		=	$(addprefix objs/,$(SRCS:.c=.o))

CFLAGS		= 	-g

RM		=	rm -f

NAME		=	so_long

all:		$(NAME)

objs/%.o: srcs/%.c
			@mkdir -p objs
			$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:		fclean all