SHELL=cmd
IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++17 -g

INCLUDES=-I../include

ODIR=obj
LDIR =../lib

LIBS=-s -lfreeglut -lopengl32 -Wl,--subsystem,windows

FILES = p5_data p5_trig p5_vector p5_math p5

#_DEPS = p5_math.hpp p5.hpp
_DEPS = $(patsubst %,%.hpp,$(FILES))
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_OBJ = p5_math.o p5.o 
_OBJ = $(patsubst %,%.o,$(FILES))
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(LDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDES)

p5.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(INCLUDES) $(LIBS) -L../lib/GLUT
	
clean:
	del "obj\*.o"
