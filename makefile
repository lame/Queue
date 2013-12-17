#YOLO
#BrObama
CC = g++
CFLAGS = -c -g 
LFLAGS= -Wall -lcrypt -g -o proj5.x

main: hashtable.o tokeMenu.o
	$(CC) $(LFLAGS) hashtable.o tokeMenu
	rm -f *.h.gch
	rm -f *.o
hashtable.o: hashtable.h hashtable.cpp	 
	$(CC) $(CFLAGS) hashtable.h
	$(CC) $(CFLAGS) hashtable.cpp
tokeMenu.o: tokeMenu.cpp 
	$(CC) $(CFLAGS) tokeMenu.cpp