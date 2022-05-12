CXX_FLAGS = -I./include/ -std=c++14 -w -fPIC # -w to disable all warning during compiling
CXX = g++
LD_FLAGS = ""
all: clean linked_list
linked_list: makedirs
    ${CXX} src/linked_list.cpp ${CXX_FLAGS} ${LD_FLAGS} -shared -o lib/liblinked_list.so
makedirs:
    mkdir -p lib
clean:
    rm -rf lib
