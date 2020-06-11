link_library = -lgtest -lpthread
include_dirs = ./include

Cflag = -Wall -std=c++17 -I $(include_dirs) $(link_library) -g

test: ./unit_test/wrapper_test.cpp ./include/swrapper/wrapper.hpp
	$(CXX) $< $(Cflag) -o $@
clean:
	rm test
