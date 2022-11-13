
NAME = CUB3D

CC = @cc

RM = @rm -f

CFLAGS = -Wall -Wextra -Werror

LIBFT	=	libft/libft.a

SRC =		main.c											\
			parsing/parsing.c								\
			raycasting/init.c								\

OBJ = $(SRC:.c=.o)

all :	$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)  $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
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