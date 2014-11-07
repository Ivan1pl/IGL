CC=g++ -std=c++11
CFLAGS=-fPIC -c -O0 -Wall -Wextra -I../usr/include/
LIBFLAGS=-shared -fPIC
FILES=Init.o Exception.o Window.o LoopHandler.o Point.o Color.o Drawable.o Triangle.o TriangleFan.o TriangleStrip.o Line.o Shader.o Font.o Text.o Lines.o LineStrip.o FilledCircle.o Circle.o
LINKS=-lGL -lGLEW -lglfw

all: igl

igl: $(FILES)
	$(CC) $(LIBFLAGS) -o ../usr/lib/libIGL.so $(FILES) $(LINKS)

.cpp.o:
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o
