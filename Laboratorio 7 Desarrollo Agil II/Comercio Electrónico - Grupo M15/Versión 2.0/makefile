CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS= main.o product.o perfil.o funciones.o client.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o comercio ${OBJS}


clean: 
	rm -rf *.o comercio