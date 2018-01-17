CC=gcc
CFLAGS= -Wall -Wextra -Werror -std=c99 -pedantic
DEPS = trata_entrada.h bandeirola.h
OBJ = trata_entrada.o bandeirola.o tp3.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp3: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm *.o	
