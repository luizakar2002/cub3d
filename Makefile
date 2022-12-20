NAME        = cub3d

SRCS        = $(wildcard *.c)
OBJS        = $(SRCS:.c=.o)
CC          = gcc -g
FLAGS		= -Wall -Werror -Wextra
MLXFLAG		= -lmlx -framework OpenGL -framework AppKit
RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) ${MLXFLAG} $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:            fclean all

.PHONY:        all clean fclean re
