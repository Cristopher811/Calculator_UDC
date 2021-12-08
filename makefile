IN = calculator.c \
	 src/algebra.c \
	 src/vectors.c
OUT = calculator.out
FLAGS = -W -g

all:
	gcc $(IN) -o $(OUT) $(FLAGS)

clean:
	rm $(OUT)
