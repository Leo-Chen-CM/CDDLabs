#Leo Chen 09/03/2023
#Second improved Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread
CPPFILES= Semaphore.cpp main.cpp
OBJFILES= Semaphore.o main.o
#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

ALL: $(OBJFILES)
	$(CC) -o semaphores  $(OBJFILES) $(CFLAGS)


#this is customary and just deletes all .o files
CLEAN:
	rm *.o
