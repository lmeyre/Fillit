# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emuckens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:46:27 by emuckens          #+#    #+#              #
#    Updated: 2017/12/08 14:19:32 by lmeyre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_putchar.c ft_putstr.c ft_putnbr.c ft_memset.c ft_memchr.c ft_memcpy.c ft_memccpy.c ft_memcmp.c ft_memmove.c ft_bzero.c ft_strlen.c ft_strdup.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_strcmp.c ft_strncmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strcpy.c ft_strncpy.c ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c ft_strclr.c ft_atoi.c ft_itoa.c ft_strnew.c ft_strdel.c ft_striter.c ft_striteri.c ft_strequ.c ft_strnequ.c ft_strmap.c ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_memalloc.c ft_memdel.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c ft_lst_new.c ft_lst_del_one.c ft_lst_del.c ft_lst_add.c ft_lstiter.c ft_lst_map.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

HEAD = libft.h

MAKE = Makefile

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ) $(MAKE) $(HEAD)
	@ ar rcu $(NAME) $(OBJ)
	@ ranlib $(NAME)

%.o: %.c
	@ $(CC) -o $@ -c $< $(CFLAGS) -I $(HEAD)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all



