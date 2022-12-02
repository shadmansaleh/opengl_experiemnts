MAIN = openGL_exp
SRCS = src/main.cpp libraries/src/glad/glad.c
INCLUDES = 
LIBS = -lGL -lglfw -lX11 -lpthread -lXrandr -lXi -ldl
CFLAGS = -Wall -O0 -gdwarf-4 -Wextra -pedantic-errors -Weffc++ -std=c++17 -Ilibraries/include/
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
	$(RM) src/*.o libraries/src/glad/*.o *~ $(MAIN)
run :	$(MAIN)
	./$(MAIN)
install :	$(MAIN)
	cp $(MAIN) $(PREFIX)/local/bin
uninstall :	$(PREFIX)/local/bin/$(MAIN)
	rm -i $(PREFIX)/local/bin/$(MAIN)
depend:	$(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

