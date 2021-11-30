NAME = push_swap

CC 	 =	gcc
CFLAGS = -Wall -Wextra  #-Werror
INCLUDE = -I ./includes

S_FOLDER = ./source/
U_FOLDER = utils/
O_FOLDER = operations/

LIBFT =	-L ./libft -lft

UTILS =			$(addprefix $(U_FOLDER), \
		ft_atoi_error.c  \
		error_utils.c free_utils.c \
)

OPERATIONS =	$(addprefix $(O_FOLDER), \
		swap.c push.c  \
)

SRC =			$(addprefix $(S_FOLDER), \
		$(UTILS) $(OPERATIONS) \
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

.PHONY: all bonus clean fclean re push

push:clean
	rm -rf push_swap
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push

c:clean
	rm -rf push_swap
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 1 2 8 3 4 5

error:clean
	rm -rf push_swap
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 3 1 -2147483649
	./push_swap 2147483648 3 1

valgrind:clean
	$(CC) $(CFLAGS) -g $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	valgrind --leak-check=full ./push_swap 1 2 3 4 5