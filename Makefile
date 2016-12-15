CC = g++
CFLAGS = -std=c++11
OUT = -o pong
LIBS = -lncurses

pong: pong.o 
	$(CC) $(CFLAGS) $(LIBS) *.o $(OUT)

pong.o: pong.c    
	$(CC) $(CFLAGS) -c pong.c


.PHONY: clean
clean:
	rm *.o

	
	
