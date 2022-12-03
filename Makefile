MAIN = openGL_exp
SRCS = src/main.cpp libraries/src/glad/glad.c libraries/src/stb/stb_image.cpp src/shaderClass.cpp src/EBO.cpp src/VBO.cpp src/VAO.cpp src/textureClass.cpp src/utils.cpp
INCLUDES =
LIBS = -lGL -lglfw -lX11 -lpthread -lXrandr -lXi -ldl
CFLAGS = -Wall -O0 -gdwarf-4 -Wextra -pedantic-errors -Weffc++ -std=c++17 -Ilibraries/include/ -Iinclude/
LFLAGS = -Llibraries/lib
CC = g++
OBJS = $(SRCS:.cpp=.o)

#End of variables

.PHONY: depend clean
all:	$(MAIN)
	@echo  $(MAIN) has been compiled
$(MAIN):	$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@
clean:
	$(RM) src/*.o libraries/src/glad/*.o libraries/src/std/*.o *~ $(MAIN)
run :	$(MAIN)
	./$(MAIN)
depend:	$(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

