FLAGS = -Wall -Wextra -Werror

NAME = push_swap

NAMELIB = libft.a

SRC = push_swap.c sort.c \
	sort_utils.c sort_utils2.c utils.c utils2.c\
	operations/push.c operations/reverse.c operations/swap.c operations/rotate.c

B_NAME = checker

B_SRC = checker_b/*.c operations/*.c utils.c utils2.c

all : $(NAME)

$(NAME) : $(NAMELIB) $(SRC)
	gcc $(FLAGS) $(SRC) $(NAMELIB) -o $(NAME)

$(NAMELIB) :
	make -C libft/
	mv libft/$(NAMELIB) .

bonus : $(NAMELIB)
	gcc $(FLAGS) $(B_SRC) $(NAMELIB) -o $(B_NAME)

clean :
	make clean -C libft/
	rm -f *.a

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)
	rm -f $(B_NAME)

re : fclean all