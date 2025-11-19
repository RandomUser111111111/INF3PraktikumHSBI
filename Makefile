CC=g++

CFLAGS=$(shell pkg-config --cflags opencv) 
LIBS=$(shell pkg-config --libs opencv) 

OBJS= main.o TASK1.o TASK2.o  TASK3.o TASK4.o TASK5.o SHA256.o SIMPLESOCKET.o
DEMOTARGET=main server client mainTest

SRCDIR= ./src/

client.o:	$(SRCDIR)client.cpp
	$(CC) -c $<  -std=c++11

server.o:	$(SRCDIR)server.cpp
	$(CC) -c $<  -std=c++11

SIMPLESOCKET.o:	$(SRCDIR)SIMPLESOCKET.cpp
	$(CC) -c $<  -std=c++11

SHA256.o:	$(SRCDIR)SHA256.cpp
	$(CC) -c $<  -std=c++11

TASK1.o:	$(SRCDIR)TASK1.cpp
	$(CC) -c $<  -std=c++11

TASK2.o:	$(SRCDIR)TASK2.cpp
	$(CC) -c $<  -std=c++11

TASK3.o:	$(SRCDIR)TASK3.cpp
	$(CC) -c $<  -std=c++11

TASK4.o:	$(SRCDIR)TASK4.cpp
	$(CC) -c $<  -std=c++11 

TASK5.o:	$(SRCDIR)TASK5.cpp
	$(CC) -c $<  -std=c++11 

main.o:	$(SRCDIR)main.cpp
	$(CC) -c $<  -std=c++11	

mainTest.o:	$(SRCDIR)mainTest.cpp
	$(CC) -c $<  -std=c++11		



main:	$(OBJS)
	$(CC) -o $@ $^ -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11 -lpthread $(LIBS)

mainTest:	mainTest.o
	$(CC) -o $@ $^ SHA256.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11 -lpthread $(LIBS)

server:	server.o
	$(CC) -o server server.o  SIMPLESOCKET.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11

client:	client.o
	$(CC) -o client client.o SIMPLESOCKET.o -L/usr/lib/x86_64-linux-gnu -ldl -lstdc++  -std=c++11

clean:
	-rm -r -f   $(DEMOTARGET) *.o DOXYGENDOC  *.txt

doc:
	doxygen Doxyfile 


all:	$(DEMOTARGET)
	make clean  && make main && make server && make client && make mainTest

run:	main	
	./main

