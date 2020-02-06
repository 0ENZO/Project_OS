NAME = superpixmanip
FLAG = -std=c11 -pthread -Werror -Wall -Wextra
SRC = main.c 
OBJ = main.o
LD=gcc


all: $(NAME)

$(NAME):
	$(LD) $(FLAG) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all

