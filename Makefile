NAME = push_swap

CC 	 =	clang
INCLUDE = -I ./includes
SOURCE = ./source/
U_FOLDER = utils/
CFLAGS = -Wall -Wextra  #-Werror

LIBFT =	-L ./libft -lft

UTILS =	$(addprefix $(U_FOLDER), \
		ft_atoi_error.c  \
		error_utils.c free_utils.c \
)

SRC =	$(addprefix $(SOURCE), \
		$(UTILS) \
		push_swap.c check_args.c \
)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	make bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	make clean -C ./libft
	rm -rf $(OBJ)
	rm -rf ./a.out

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

push:clean
	rm -rf push_swap
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push

c:clean
	rm -rf push_swap
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 1 2 3 4

error:clean
	rm -rf push_swap
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 0 one 2 3

valgrind:clean
	$(CC) $(CFLAGS) -g $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	valgrind --leak-check=full ./push_swap 1 164 2 3 2147483650