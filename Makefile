CC = cc
LCC = ar rcs
FLAGS = -Wall -Wextra -Werror
NAME = push_swap.a
HF = push_swap.h
SRC = src/ft_split.c src/push.c src/push_swap_utils.c src/reverse.c src/rotate.c src/sort.c src/sort_stack.c src/swap.c src/push_swap_utils_1.c
SRCB = bounus/ft_split.c bounus/push.c bounus/push_swap_utils.c bounus/reverse.c bounus/rotate.c bounus/sort.c bounus/sort_stack.c bounus/swap.c \
		bounus/ft_strcmp.c bounus/get_next_line.c bounus/get_next_line_utils.c bounus/push_swap_utils_1.c
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
