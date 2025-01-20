CFLAGS = -Wall -Wextra -Werror
CC = cc
BUFFER_SIZE = 3

NAME = get_next_line
BONUS_NAME = get_next_line_bonus

SRCS = get_next_line.c main.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c main.c get_next_line_utils_bonus.c

all: ${NAME}

${NAME}: ${SRCS}
	$(CC) ${CFLAGS} -o ${NAME} -D BUFFER_SIZE=${BUFFER_SIZE} ${SRCS}

simple: ${SRCS}
	$(CC) ${CFLAGS} -o ${NAME} ${SRCS}

bonus: ${BONUS_SRCS}
	$(CC) ${CFLAGS} -o ${BONUS_NAME} -D BUFFER_SIZE=${BUFFER_SIZE} ${BONUS_SRCS}

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME} ${BONUS_NAME}

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus