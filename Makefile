CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -I. -Lmlx -lmlx -framework OpenGL -framework Appkit
SRCS = fdf.c gnl.c gnl_utils.c ft_atoi.c ft_split.c parsing.c parsing_utils.c ft_math.c draw.c connect_dot.c press_key_1.c press_key_2.c press_key_3.c ft_mlx.c parallel.c
SRCS_BONUS = connect_dot_bonus.c draw_bonus.c fdf_bonus.c ft_atoi_bonus.c ft_math_bonus.c ft_mlx_bonus.c ft_split_bonus.c gnl_bonus.c gnl_utils_bonus.c parallel_bonus.c parsing_bonus.c parsing_utils_bonus.c press_key_1_bonus.c press_key_2_bonus.c press_key_3_bonus.c
NAME = fdf
OBJSALL = fdf.o gnl.o gnl_utils.o ft_atoi.o ft_split.o parsing.o parsing_utils.o ft_math.o draw.o connect_dot.o press_key_1.o press_key_2.o press_key_3.o ft_mlx.o parallel.o connect_dot_bonus.o draw_bonus.o fdf_bonus.o ft_atoi_bonus.o ft_math_bonus.o ft_mlx_bonus.o ft_split_bonus.o gnl_bonus.o gnl_utils_bonus.o parallel_bonus.o parsing_bonus.o parsing_utils_bonus.o press_key_1_bonus.o press_key_2_bonus.o press_key_3_bonus.o

ifdef BONUS_FLAG
OBJS = $(SRCS_BONUS:.c=.o)
else
OBJS = $(SRCS:.c=.o)
endif

all : $(NAME)

bonus :
	make BONUS_FLAG=1

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) -O3 $^ -c
	
clean :
	rm -rf $(OBJSALL)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all
	
.PHONY : re clean fclean all bonus