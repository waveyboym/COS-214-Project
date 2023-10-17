CXX=g++
TARGET=project
OBJS=main.o

all: $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%/%/%/%.o: %.cpp
	$(CXX) -c -g $< -o $@

%/%/%.o: %.cpp
	$(CXX) -c -g $< -o $@

%/%.o: %.cpp
	$(CXX) -c -g $< -o $@

%.o: %.cpp
	$(CXX) -c -g $< -o $@

run:
	./$(TARGET)
	
clean:
	rm -f $(OBJS) $(TARGET)

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(TARGET)

valgrind_more: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./$(TARGET)

gdb:
	gdb ./$(TARGET)

everything: clean all run