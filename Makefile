
CXXFLAGS=-g

LDLIBS=-lX11 -lstdc++ -lm

mand: mand.o gfx.o

clean: 
		rm -f mand *.o                          
