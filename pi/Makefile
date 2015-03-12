CXXFLAGS=-Wall -g
LINK=-lboost_regex

OBJECTS=pipair.o

.PHONY: all clean
all: pipair-core
clean:
	rm -f pipair-core
	rm -f *.o
	rm -f *.d

-include $(OBJECTS:.o=.d)

pipair-core: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LINK)
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@
	$(CXX) -MM $(CXXFLAGS) $< -o $*.d
