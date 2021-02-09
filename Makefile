NAME = libftprintf.a

SRCS_LIST		= \
			  ft_printf.c \
			  ft_parse.c \
			  ft_convert_char.c \
			  ft_convert_int.c \
			  ft_join_sp.c \
			  ft_atoitoa_dupl.c \

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

LIBFT 			= libft

CC				= clang
FLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar -rcs $@ $^
	ranlib $@

%.o: %.c
	@${CC} ${FLAGS} -I ${HEADER} -o $@ -c $<

bonus : $(NAME)

clean:
	@${RM} ${OBJS}
	@make clean -C $(LIBFT)

fclean:			clean
	@${RM} ${NAME}
	@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re
