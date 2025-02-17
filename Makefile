cc = gcc
cflags = -Wall -Wextra -I/usr/local/include
ldflags = -L/usr/local/lib -lraylib
target = gpt-loading
srcs = main.c

all: build
	
build:
	$(cc) $(cflags) $(srcs) -o $(target) $(ldflags)
	./$(target)

clean:
	rm -rf $(target)
