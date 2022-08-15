NAME	= push_swap
SRCS	= $(wildcard *.c)
INSTR	= $(wildcard ./instr/*.c)
OBJS	= ${SRCS:.c=.o} 
OBJS_INSTR	= ${INSTR:./instr/%.c=%.o}
LIB		= -Llibft -lft
INCLUDE = -Iincludes -Ilibft

FLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address
CC		= gcc
RM		= rm -rf

vpath %.c instr

all		: ${NAME}

${NAME} : ${OBJS} ${OBJS_INSTR}
	@make -C libft
	@${CC} ${FLAGS} ${INCLUDE} ${LIB}  $(addprefix obj/, ${OBJS} ${OBJS_INSTR}) -o $@
 
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