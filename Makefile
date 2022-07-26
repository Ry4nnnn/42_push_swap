NAME	= push_swap
SRCS	= $(wildcard *.c)
OBJS	= ${SRCS:.c=.o} 
LIB		= -Llibft -lft
INCLUDE = -Iincludes -Ilibft

FLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address
CC		= gcc
RM		= rm -rf

all		: ${NAME}

${NAME} : ${OBJS} ${OBJS_INSTR}
	@make -C libft
	@${CC} ${FLAGS} ${LIB} ${INCLUDE} $(addprefix obj/, ${OBJS}) -o $@
 
%.o : %.c
	@mkdir -p obj
	@${CC} ${FLAGS} ${INCLUDE} -c $< -o obj/$@

clean :
	@rm -rf obj
	@echo "Cleaning binary files 'push_swap'..."

fclean : clean
	@rm -rf ${NAME}
	@make fclean -C libft

re : fclean all

.PHONY: all clean fclean re