CC=g++ -std=c++11
CFLAGS=-fPIC -c -O0 -Wall -Wextra -I../usr/include/
LIBFLAGS=-shared -fPIC
FILES1=Init.o Exception.o Window.o LoopHandler.o Location.o Color.o Axis.o
FILES2=Vertex.o Drawable.o Point.o Triangle.o TriangleFan.o TriangleStrip.o Line.o Text.o Lines.o LineStrip.o FilledCircle.o Circle.o
FILES3=Shader.o Font.o MatrixStack.o
FILES4=Container.o DrawableContainer.o Transformable.o
LINKS=-lGL -lGLEW -lglfw

all: igl

igl: $(FILES1) $(FILES2) $(FILES3) $(FILES4)
	$(CC) $(LIBFLAGS) -o ../usr/lib/libIGL.so $(FILES1) $(FILES2) $(FILES3) $(FILES4) $(LINKS)

.cpp.o:
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o
