NAME = CUB3D

CC = @gcc

RM = @rm -f

SEG = -fsanitize=address -g3

LIBFT	=	../libft/libft.a

HEADERS =	../main.h parsing.h

SRC =		main.c		valid_map.c					\
			map.c		check_map.c					\
			parsing.c								\
			map_line_counter.c						\
			ft_split.c								\
			get_next_line.c							\

OBJ = $(SRC:.c=.o)

all :	$(NAME) clean

%.o : %.c
	$(CC) $(SEG) -c $< -o $@

$(NAME):	$(OBJ)  $(LIBFT)
	@gcc -fsanitize=address -g3 $(LIBFT) $(SRC) -o $(NAME)
	@echo [GAME CREATED]

$(LIBFT):
	@make -C ../libft

clean :
	$(RM) $(OBJ)
	@make clean -C ../libft
	@echo [OBJECTS DELETED]

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	@echo [GAME DELETED]

re : fclean all