NAME = push_swap

CC		=	clang
CFLAGS	=	-Wall -Wextra #-Werror
INCLUDE =	-I ./includes

S_FOLDER  = ./source/
U_FOLDER  = utils/
O_FOLDER  = operations_array/
SO_FOLDER = sort/
LI_FOLDER = linked_list/
OL_FOLDER = operation_linked/

LIBFT =	-L ./libft -lft

UTILS =			$(addprefix $(U_FOLDER), \
		error_utils.c free_utils.c \
		ft_atoi_error.c init_utils.c \
)

OPERATIONS =	$(addprefix $(O_FOLDER), \
		push_utils.c push.c rotate.c reverse_rotate.c swap.c \
)

SORT = 			$(addprefix $(SO_FOLDER), \
		algorithm.c scan_number.c trilogy.c algorithm_medium.c \
)

LINKED = 		$(addprefix $(LI_FOLDER), \
		basic_functions_aux.c basic_functions.c list_scan_utils.c \
)

OPERATIONS_L = $(addprefix $(OL_FOLDER), \
		swap_list.c reverse_rotate_list.c rotate_list.c push_list.c \
)

SRC =		$(addprefix $(S_FOLDER), \
		$(UTILS) $(OPERATIONS) $(SORT) $(LINKED) $(OPERATIONS_L)  \
		push_swap.c check_args.c check_string.c \
)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

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
	./push_swap 72 3000 -30 88 45 -70 36 65 85 5 8 9 1000

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
	--num-callers=20 --track-fds=yes ./push_swap 72 3000 -30 88 45 -70 36 65 85 5 8 9 1000

sanitize:clean
	$(CC) $(CFLAGS) -fsanitize=address -g $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 3 9 4 2 8 10 444444 7

test:re
	python3 pyviz.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`


#ARG="0 5000 1 4 2000 10 11 3 2 7 100 200 300 400"; ./push_swap $ARG | ./checker_linux $ARG
#ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG 
#python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

#./push_swap 0 5000 1 4 2000 10 11 3 2 7 100 200 300 400

big:clean
	rm -rf push_swap
	$(CC) $(CFLAGS) -g $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 0 5000 1 4 2000 10 11 3 2 7 100 200 300 400