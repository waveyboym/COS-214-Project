CXX=g++
TARGET=COS214Project
OBJECTS=main.o

all: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%/%/%.o: %.cpp
	$(CXX) -c -g $< -o $@

%/%.o: %.cpp
	$(CXX) -c -g $< -o $@

%.o: %.cpp
	$(CXX) -c -g $< -o $@

run:
	./$(TARGET)
	
clean:
	rm -f $(OBJECTS) $(TARGET)

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./$(TARGET)

valgrind_more: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes ./$(TARGET)

gdb:
	gdb ./$(TARGET)

everything: all run

everything_more: clean all run