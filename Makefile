VPATH = srcs\

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRCS = check_validity.c find_position.c find_solution.c prepare_job.c manipulate_shape.c main.c

BIN = $(SRCS:.c=.o)

LIB = libft/libft.a

HEADER = includes

LIBDIR = libft/

MAKE = Makefile

.PHONY: all clean fclean re

all: $(LIB) $(NAME)

$(NAME): $(BIN) $(LIB) $(HEADER) $(MAKE)
	@ gcc $(FLAGS) -o $(NAME) -I $(HEADER) -I $(LIBDIR) $(LIB) $(BIN)

%.o: %.c
	@ gcc $(FLAGS) -o $@ -c $< -I $(HEADER) -I $(LIBDIR)

$(LIB):
	@ make -C $(LIBDIR)
	
clean:
	@ rm -f $(BIN)
	@ make clean -C $(LIBDIR)

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C $(LIBDIR)

re: fclean all
