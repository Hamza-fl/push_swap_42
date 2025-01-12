CC = cc
LCC = ar rcs
FLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
HF = push_swap.h
SRC = src/ft_split.c src/push.c src/push_swap_utils.c src/reverse.c src/rotate.c src/sort.c src/sort_stack.c src/swap.c src/push_swap_utils_1.c src/push_swap.c
SRCB = bonus/ft_split.c bonus/push.c bonus/push_swap_utils.c bonus/reverse.c bonus/rotate.c bonus/sort.c bonus/sort_stack.c bonus/swap.c \
		bonus/ft_strcmp.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/push_swap_utils_1.c bonus/checker.c
OBJF = $(SRC:.c=.o)
BOBJF = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJF)
	$(LCC) $(NAME) $(OBJF)
bonus: $(BOBJF)
	$(LCC) $(NAME) $(BOBJF)
%.o: %.c $(HF)
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	rm -f $(OBJF) $(BOBJF)

fclean: clean
	rm -f $(NAME)

re: fclean all
