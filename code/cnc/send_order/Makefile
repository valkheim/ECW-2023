CC=musl-gcc
CFLAGS=-Wall -Wextra -Werror -Os -static
NAME=cnc

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) cnc.c -o $(NAME)

fmt:
	clang-format -i cnc.c

clean:
	rm -f $(NAME)

re: clean all

