NAME = push_swap

CC 	 =	gcc
CFLAGS = -Wall -Wextra #-Werror
INCLUDE = -I ./includes

S_FOLDER  = ./source/
U_FOLDER  = utils/
O_FOLDER  = operations/
SO_FOLDER = sort/

LIBFT =	-L ./libft -lft

UTILS =			$(addprefix $(U_FOLDER), \
		array_utils.c error_utils.c free_utils.c \
		ft_atoi_error.c init_utils.c \
)

OPERATIONS =	$(addprefix $(O_FOLDER), \
		swap.c push.c rotate.c reverse_rotate.c \
)

SORT = $(addprefix $(SO_FOLDER), \
		trilogy.c \
)

SRC =			$(addprefix $(S_FOLDER), \
		$(UTILS) $(OPERATIONS) $(SORT) \
		push_swap.c check_args.c check_string.c \
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
	./push_swap 2 1 3
	./push_swap 3 2 1
	./push_swap 3 1 2
	./push_swap 1 3 2
	./push_swap 2 3 1

error:clean
	rm -rf push_swap
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 3 1 -2147483649
	./push_swap 2147483648 3 1

valgrind:clean
	$(CC) $(CFLAGS) -g $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	valgrind --leak-check=full ./push_swap 3 2 1