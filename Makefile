#Author: Peter Lucan
#Student Number: C00228946
#Date: 24/02/2021
#Description: The Makefile for the Concurrency Project
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o
	$(CC) main.cpp $(CFLAGS) -o main  $(DEBUGFLAGS)
	rm *.o

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL