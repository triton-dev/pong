CC = g++
CFLAGS = -std=c++11
OUT = -o pong
LIBS = -lncurses

bump: bump.o
	$(CC) $(CFLAGS) $(LIBS) bump.o -o bump

pong: pong.o 
	$(CC) $(CFLAGS) $(LIBS) *.o $(OUT)

pong.o: pong.c    
	$(CC) $(CFLAGS) -c pong.c
	
bump.o: bump.c
	$(CC) $(CFLAGS) $(LIBS) -c bump.c


.PHONY: clean
clean:
	rm *.o

	
	
