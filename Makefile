CFLAGS = -Wall -Wextra -Werror
CC = cc

NAME = get_next_line

SRCS =

BSRCS =

OBJS = ${SRCS:.c=.o}

BOBJS = ${BSRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
        $(CC) ${CFLAGS} -o ${NAME} ${OBJS}

%.o: %.c
        ${CC} ${CFLAGS} -c $< -o $@

clean:
        rm -rf *.o

fclean: clean
        rm -rf ${NAME}

re: clean all

.PHONY: all clean fclean re