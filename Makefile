NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC = check_validity.c find_position.c find_solution.c prepare_job.c manipulate_shape.c

BIN = $(SRC:.c=.o)

LIB = libft/libft.a

HEADER = fillit.h

LIBDIR = libft/

MAKE = Makefile

MAIN = main.c

.PHONY: all clean fclean re

all: $(LIB) $(NAME)

$(NAME): $(BIN) $(LIB) $(HEADER) $(MAKE)
	@ gcc $(FLAGS) -o $(NAME) $(MAIN) $(BIN) -I. -I $(LIBDIR) $(LIB)

%.o: %.c
	@ gcc $(FLAGS) -o $@ -c $<

$(LIB):
	@ make -C $(LIBDIR)
	
clean:
	@ rm -f $(BIN)
	@ make clean -C $(LIBDIR)

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIBDIR)

re: fclean all
