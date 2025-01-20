CFLAGS = -Wall -Wextra -Werror
CC = cc
BUFFER_SIZE = 3

NAME = get_next_line

SRCS = get_next_line.c main.c get_next_line_utils.c

all: ${NAME}

${NAME}: ${SRCS}
	$(CC) ${CFLAGS} -o ${NAME} -D BUFFER_SIZE=${BUFFER_SIZE} ${SRCS}

simple: ${SRCS}
	$(CC) ${CFLAGS} -o ${NAME} ${SRCS}

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re