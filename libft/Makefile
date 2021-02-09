# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzhou <hzhou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/12 21:32:12 by hzhou             #+#    #+#              #
#    Updated: 2021/02/08 14:45:01 by hzhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = -I ./
RM = rm -f
CC = clang -Wall -Wextra -Werror
SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_intlen.c \
		ft_uintlen.c \
		ft_uitoa.c \
		ft_itoa_base.c \
		ft_c_to_str.c \
		ft_intlen_base.c \

SRC_B =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)

all : $(NAME)

.c.o :
	$(CC) -c $< -o ${<:.c=.o} $(HEADERS)

$(NAME) : $(OBJS)
	ar rc $@ $^
	ranlib $@

bonus :	$(OBJS) $(OBJS_B)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean :
	$(RM) $(OBJS) $(OBJS_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re

