NAME		= push_swap
CHECKER		= checker

LIB			= -Llibft -lft
INCLUDE		= -Iincludes -Ilibft
FLAGS		= -Wall -Werror -Wextra #-g3 -fsanitize=address
CC			= gcc
RM			= rm -rf
OBJS_DIR	= ./obj

P_SRCS		= $(wildcard push_swap_src/*.c)
C_SRCS		= $(wildcard checker_src/*.c)

P_OBJS		= ${P_SRCS:push_swap_src/%.c=${OBJS_DIR}/%.o}
C_OBJS		= ${C_SRCS:checker_src/%.c=${OBJS_DIR}/%.o}

vpath %.c push_swap_src checker_src

all		: ${NAME}
bonus	: ${NAME} ${CHECKER}

${NAME} : ${P_OBJS}
	@make -C libft
	@${CC} ${FLAGS} ${INCLUDE} $^ ${LIB} -o $@

${CHECKER} : ${C_OBJS}
	@make -C libft
	@${CC} ${FLAGS} ${INCLUDE} $^ ${LIB} -o $@

obj/%.o : %.c
	@mkdir -p obj
	@${CC} ${FLAGS} ${INCLUDE} -c $< -o $@

clean :
	@rm -rf obj 
	@echo "Cleaning binary files 'push_swap'..."

fclean : clean
	@rm -rf ${NAME} ${CHECKER}
	@make fclean -C libft

re : fclean all

.PHONY: all clean fclean re