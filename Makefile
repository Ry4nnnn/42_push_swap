NAME	= push_swap
CHECKER	= checker

P_SRCS		= $(wildcard push_swap_src/*.c)
C_SRCS		= $(wildcard checker_src/*.c)

INSTR		= $(wildcard ./instr/*.c)

P_OBJS		= ${P_SRCS:push_swap_src/%.c=%.o}
C_OBJS		= ${C_SRCS:checker_src/%.c=%.o}

OBJS_INSTR	= ${INSTR:./instr/%.c=%.o}

LIB		= -Llibft -lft

INCLUDE = -Iincludes -Ilibft

FLAGS	= -Wall -Werror -Wextra #-g3 -fsanitize=address
CC		= gcc
RM		= rm -rf

vpath %.c instr push_swap_src checker_src

all		: ${NAME}
bonus	: ${NAME} ${CHECKER}

${NAME} : ${P_OBJS} ${OBJS_INSTR}
	@make -C libft
	@${CC} ${FLAGS} ${INCLUDE} $(addprefix obj/, $^) ${LIB} -o $@

${CHECKER} : ${C_OBJS} ${OBJS_INSTR}
	@make -C libft
	@${CC} ${FLAGS} ${INCLUDE} $(addprefix obj/, $^) ${LIB} -o $@

%.o : %.c
	@mkdir -p obj
	@${CC} ${FLAGS} ${INCLUDE} -c $< -o obj/$@

clean :
	@rm -rf obj
	@echo "Cleaning binary files 'push_swap'..."

fclean : clean
	@rm -rf ${NAME} ${CHECKER}
	@make fclean -C libft

re : fclean all

.PHONY: all clean fclean re