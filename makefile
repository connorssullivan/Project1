PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = Card.o main.o 

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

Card.o : Card.cpp
	$(CC) $(CPPFLAGS) -c Card.cpp

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make