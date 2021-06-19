FLAGS = -Wall -Wextra -Werror

NAME = push_swap

NAMELIB = libft.a

SRC = push_swap.c sort.c \
	sort_utils.c sort_utils2.c utils.c \
	operations/push.c operations/reverse.c operations/swap.c operations/rotate.c

all : $(NAME)

$(NAME) : $(NAMELIB) $(SRC)
	gcc $(FLAGS) $(SRC) $(NAMELIB) -o $(NAME)

$(NAMELIB) :
	make -C libft/
	mv libft/$(NAMELIB) .

clean :
	make clean -C libft/
	rm -f *.a

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all