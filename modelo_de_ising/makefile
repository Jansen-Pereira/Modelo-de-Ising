CC=g++
CFLAGS=-I.
DEPS =  header.h funcGeraSpins.h funcCalcEnergiaLocal.h funcCalcEnergiaTotal.h funcCalcMagTotal.h funcValidaGiro.h 
OBJ = main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

modelo: $(OBJ) $(DEPS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *o modelo
