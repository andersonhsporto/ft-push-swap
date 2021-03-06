NAME = push_swap

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE =	-I ./includes

S_FOLDER  = ./source/
U_FOLDER  = utils/

SO_FOLDER = sort/
LI_FOLDER = linked_list/
OL_FOLDER = operation_linked/

LIBFT =	-L ./libft -lft

UTILS =			$(addprefix $(U_FOLDER), \
		error_utils.c free_utils.c \
		ft_atoi_error.c init_utils.c \
)

SORT = 			$(addprefix $(SO_FOLDER), \
		algorithm_medium.c algorithm_simple.c \
		scan_number.c \
)

LINKED = 		$(addprefix $(LI_FOLDER), \
		basic_functions_aux.c basic_functions.c list_scan_utils.c \
)

OPERATIONS_L = $(addprefix $(OL_FOLDER), \
		swap_list.c reverse_rotate_list.c rotate_list.c push_list.c \
)

SRC =			$(addprefix $(S_FOLDER), \
		$(UTILS) $(SORT) $(LINKED) $(OPERATIONS_L)  \
		push_swap.c check_args.c check_string.c \
)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:%.c=%.o)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	make all -C ./libft
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
	$(CC) $(CFLAGS) -g $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 20000 8 7 1 5 2 4 3 10
	ARG="20000 8 7 1 5 2 4 3 10"; ./push_swap $$ARG

tri:clean
	rm -rf push_swap
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 2 1
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
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
	--num-callers=20 ./push_swap 72 3000 -30 88 45 -70 36 65 85 5 8 9 1000

sanitize:clean
	$(CC) $(CFLAGS) -fsanitize=address -g $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 3 9 4 2 8 10 444444 7

test:re
	python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`