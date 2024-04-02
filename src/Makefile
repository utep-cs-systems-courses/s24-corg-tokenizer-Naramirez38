OBJS = tokenizer.o uimain.o history.o

CFLAGS = -g -O3

all:tokenizer

tokenizer: $(OBJS)
	cc -o $(CFLAGS) $(OBJS)

$(OBJS):tokenizer.h history.h

clean:
	rm -f *.o tokenizer

run: tokenizer
	./-g
