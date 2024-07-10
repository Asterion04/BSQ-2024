NAME = bsq
SRCS = alloc.c gnl.c gnl_utils.c helper.c main.c map.c solve.c utils.c solve_stdin.c gc_utils.c gc.c
INCLUDE = .
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all
