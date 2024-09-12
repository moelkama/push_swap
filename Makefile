OBJS = src/push_swap.o src/ft_split.o src/move.o\
		src/get_numbers.o src/ft_list.o\
		src/sort.o src/utilse.o

BONUS_OBJS =	bonus/src/ft_split_bonus.o bonus/src/get_next_line_utils_bonus.o bonus/src/instruction_bonus.o\
				bonus/src/checker_bonus.o bonus/src/get_next_line_bonus.o bonus/src/get_numbers_bonus.o\
				bonus/src/utilse_bonus.o bonus/src/instruction2_bonus.o

BONUS_NAME = checker
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME):$(BONUS_OBJS)
	cc $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re