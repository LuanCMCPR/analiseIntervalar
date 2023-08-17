OBJS = analiseIntervalar.o libaux.o
OUT	= analiseIntervalar
CC = gcc
FLAGS = -g -c -Wall -std=c99
LFLAGS = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

analiseIntervalar.o: analiseIntervalar.c libaux.h
	$(CC) $(FLAGS) analiseIntervalar.c 

libaux.o: libaux.c libaux.h
	$(CC) $(FLAGS) libaux.c 

clean:
	rm -f $(OBJS)
purge: 
	makrm -f *~ $(OUT)