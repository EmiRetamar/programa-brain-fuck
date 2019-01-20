CFLAGS=-Wall -std=c99 -g
BIN=bf
OBJ=principal.o bf.o ivector.o

$(BIN): $(OBJ)

ivector.o: ivector.c ivector.h
bf.o: bf.h

doc:
	doxygen

clean:
	rm -f $(OBJ) $(BIN)

reallyclean: clean
	rm -fr html

.PHONY: clean doc reallyclean
