
NAME = CUB3D

CC = @cc

RM = @rm -f

CFLAGS = -fsanitize=address -g3

LIBFT	=	libft/libft.a

HEADERS =	main.h parsing/parsing.h  raycasting/raycasting.h

SRC =		main.c											\
			parsing/parsing.c								\
			parsing/ft_split.c								\
			parsing/get_next_line.c							\
			raycasting/init.c								\
			raycasting/img.c								\
			raycasting/mlx_funs.c							\
			raycasting/actions.c							\
			raycasting/extra_math.c							\

OBJ = $(SRC:.c=.o)

all :	$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)  $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit  $(OBJ) -o $(NAME)
	@echo [GAME CREATED]

$(LIBFT):
	@make -C ./libft

clean :
	$(RM) $(OBJ)
	@make clean -C ./libft
	@echo [OBJECTS DELETED]

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	@echo [GAME DELETED]

re : fclean all