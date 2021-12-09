IN = calculator.c \
	 src/algebra.c \
	 src/vectors.c \
	 src/functions.c
OUT = calculator.out
FLAGS = -W -g

all:
	gcc $(IN) -o $(OUT) $(FLAGS)

clean:
	rm $(OUT)
