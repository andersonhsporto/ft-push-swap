NAME = push_swap

CC 	 =	clang
INCLUDE = -I ./includes
SOURCE = ./source/
CFLAGS = -Wall -Wextra  #-Werror

LIBFT =	-L ./libft -lft

SRC =	$(addprefix $(SOURCE), \
		push_swap.c \
)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C ./libft
	rm -rf $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	make clean -C ./libft
	rm -rf $(OBJ)
	rm -rf ./a.out

fclean: clean
	make clean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

push:fclean
	rm -rf file2 test
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push

c:fclean
	rm -rf push_swap
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)
	./push_swap 0 1 2