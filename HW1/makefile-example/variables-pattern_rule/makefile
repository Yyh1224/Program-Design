# Variable
CFLAGS  = -O2 -Wall -g
objects = main.o lib.o square.o

all: main

main: $(objects)
	g++ $(CFLAGS) $(objects) -o main

# Define a pattern rule that compiles every .cpp file into a .o file
# EX: %  = xxxx         :: %.o = xxxx.o,    %.cpp = xxxx.cpp
#     $@ = Target       :: %.o = xxxx.o
#     $< = Prerequisite :: ../start_project/%.cpp = ../start_project/xxxx.cpp
%.o: ../start_project/%.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm $(objects) main
