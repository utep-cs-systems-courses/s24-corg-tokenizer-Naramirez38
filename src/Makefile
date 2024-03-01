OBJS = tokenizer.o uimain.o

CFlags = -g -O3

all:tokenizer

tokenizer: $(OBJS)
	cc -o $(CFlags) $(OBJS)

$(OBJS):tokenizer.h

clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer
