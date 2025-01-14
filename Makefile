CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
SRC = src/ft_split.c src/push.c src/push_swap.c src/push_swap_utils_1.c src/push_swap_utils.c src/reverse.c src/rotate.c src/sort.c src/sort_stack.c src/swap.c
SRCB = bonus/checker.c bonus/ft_split.c bonus/ft_strcmp.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/push.c bonus/push_swap_utils_1.c \
		bonus/push_swap_utils.c bonus/reverse.c bonus/rotate.c bonus/sort.c bonus/sort_stack.c bonus/swap.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) src/push_swap.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJB) bonus/push_swap.h
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
