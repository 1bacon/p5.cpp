SHELL=cmd
IDIR = ../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

ODIR=obj
LDIR =../lib

LIBS=

FILES = p5_trig p5_vector p5_math p5

#_DEPS = p5_math.hpp p5.hpp
_DEPS = $(patsubst %,%.hpp,$(FILES))
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_OBJ = p5_math.o p5.o 
_OBJ = $(patsubst %,%.o,$(FILES))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(LDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

p5.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	
clean:
	del "obj\*.o"
