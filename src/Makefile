Srcs   := $(wildcard *.c)
Objs   := $(patsubst %.c, %.o, $(Srcs))
Out    := Test
CC     := gcc
CFLAGS := -Wall -g

$(Out): $(Objs)
		$(CC) $^ -o $@

%.o: %.c # add header file here
		$(CC) -c $< $(CFLAGS)

.PHONY: clean rebuild
clean:
		$(RM) $(Out) $(Objs)
rebuild: clean $(Out)
