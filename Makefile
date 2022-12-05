NAME = cub3D

NAME_BONUS = cub3D_bonus

CC = @cc

MINILIBX = ./minilibx/libmlx.a

RM = @rm -f

CFLAGS = 

LIBFT	=	libft/libft.a

HEADERS =	main.h mandatory/parsing/parsing.h	\
			mandatory/raycasting/raycasting.h

HEADERS_BONUS =	main.h bonus/parsing/parsing_bonus.h  	\
				bonus/raycasting/raycasting_bonus.h		\
				bonus/main_bonus.h

SRC =			main.c															\
				mandatory/parsing/parsing.c										\
				mandatory/parsing/check_textures_path.c							\
				mandatory/parsing/valid_map.c									\
				mandatory/parsing/ft_split.c									\
				mandatory/parsing/check_map.c									\
				mandatory/parsing/get_next_line.c								\
				mandatory/parsing/map_line_counter.c							\
				mandatory/parsing/map.c											\
				mandatory/raycasting/init.c										\
				mandatory/raycasting/img.c										\
				mandatory/raycasting/actions.c									\
				mandatory/raycasting/actions_utils.c							\
				mandatory/raycasting/extra_math.c								\
				mandatory/raycasting/draw.c										\
				mandatory/raycasting/rays.c										\
				mandatory/raycasting/rays_utils.c								\
				mandatory/raycasting/rays_intersection.c						\
				mandatory/raycasting/rays_intersection_utils.c					\

SRC_BONUS =		bonus/main_bonus.c													\
				bonus/parsing/parsing_bonus.c										\
				bonus/parsing/valid_map_bonus.c										\
				bonus//parsing/check_textures_path_bonus.c							\
				bonus/parsing/ft_split_bonus.c										\
				bonus/parsing/check_map_bonus.c										\
				bonus/parsing/get_next_line_bonus.c									\
				bonus/parsing/map_line_counter_bonus.c								\
				bonus/parsing/map_bonus.c											\
				bonus/raycasting/init_bonus.c										\
				bonus/raycasting/animation_bonus.c									\
				bonus/raycasting/mouse_rotation_bonus.c								\
				bonus/raycasting/img_bonus.c										\
				bonus/raycasting/mlx_funs_bonus.c									\
				bonus/raycasting/actions_bonus.c									\
				bonus/raycasting/extra_math_bonus.c									\
				bonus/raycasting/draw_bonus.c										\
				bonus/raycasting/rays_bonus.c										\
				bonus/raycasting/rays_intersection_bonus.c							\
				bonus/raycasting/mini_map_bonus.c									\

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all :	$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)  $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(MINILIBX) -lmlx -framework OpenGL -framework AppKit  $(OBJ) -o $(NAME)
	@echo [GAME CREATED]

$(LIBFT):
	@make -C ./libft

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	@make clean -C ./libft
	@echo [OBJECTS DELETED]

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(LIBFT)
	@echo [GAME DELETED]

bonus : $(NAME_BONUS)


$(NAME_BONUS):	$(OBJ_BONUS)  $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT)  $(MINILIBX) -lmlx -framework OpenGL -framework AppKit  $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo [GAME BONUS CREATED]

re : fclean all