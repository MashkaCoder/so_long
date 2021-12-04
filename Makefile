NAME = so_long

SRC = mandatory/get_next_line/get_next_line_utils.c\
	mandatory/get_next_line/get_next_line.c\
	mandatory/utils/ft_strncmp.c\
	mandatory/utils/ft_substr.c\
	mandatory/utils/ft_strdup.c\
	mandatory/utils/ft_itoa.c\
	mandatory/utils/ft_strjoin.c\
	mandatory/so_long.c\
	mandatory/initialization.c\
	mandatory/hook_event.c\
	mandatory/help_check_map.c\
	mandatory/gr_and_free.c\
	mandatory/draw.c\
	mandatory/check_valid_map.c\

SRC_BONUS = bonus/so_long_bonus.c\
	bonus/get_next_line/get_next_line.c\
	bonus/get_next_line/get_next_line_utils.c\
	bonus/utils/ft_strncmp.c\
	bonus/utils/ft_substr.c\
	bonus/utils/ft_strdup.c\
	bonus/utils/ft_itoa.c\
	bonus/utils/ft_strjoin.c\
	bonus/check_valid_map.c\
	bonus/draw.c\
	bonus/help_check_map.c\
	bonus/hook_event.c\
	bonus/initialization.c\
	bonus/enemy.c\
	bonus/bonus_gr_and_free.c\

HDRS = mandatory/so_long.h

HDRS_BONUS = bonus/so_long_bonus.h

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
		make -C mlx
		$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ) -I. -o $(NAME)

bonus: $(OBJ_BONUS) $(HDRS_BONUS)
		make -C mlx
		$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ_BONUS) -I. -o $(NAME)

clean:
		make clean -C mlx
		rm -f $(OBJ_BONUS)
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME_BONUS)
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean
