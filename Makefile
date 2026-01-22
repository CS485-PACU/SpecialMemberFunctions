#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################

all: bin bin/main # bin/compMain

ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ecpp --color -fCourier8
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all 

compiler=clang++
#compiler=g++

# clang
# https://clang.llvm.org/cxx_status.html
CPP_VERSION=c++23

# g++ (Linux)
# Version 10 or later
# CPP_VERSION=c++20
# Version 9 or earlier (Codespaces)
# Enable C++23 support
# CPP_VERSION=c++2b

bin:
	mkdir -p bin

bin/Example.o: src/Example.cpp include/Example.h
	${compiler} -std=${CPP_VERSION} -c -o bin/Example.o -g -Wall src/Example.cpp -Iinclude -O0

bin/Comp.o: src/Comp.cpp include/Comp.h include/Example.h
	${compiler} -std=${CPP_VERSION} -c -o bin/Comp.o -g -Wall src/Comp.cpp -Iinclude -O0

bin/main.o: src/main.cpp include/Example.h
	${compiler} -std=${CPP_VERSION} -c -o bin/main.o -g -Wall src/main.cpp -Iinclude -O0

bin/main: bin bin/main.o bin/Example.o
	${compiler} -std=${CPP_VERSION} -o bin/main -g -Wall bin/main.o bin/Example.o -O0

bin/compMain.o: src/compMain.cpp include/Example.h include/Comp.h
	${compiler} -std=${CPP_VERSION} -c -o bin/compMain.o -g -Wall src/compMain.cpp -Iinclude -O0

bin/compMain: bin bin/compMain.o bin/Example.o bin/Comp.o
	${compiler} -std=${CPP_VERSION} -o bin/compMain -g -Wall bin/compMain.o bin/Example.o bin/Comp.o -O0

valgrind: bin/main
	valgrind ${VALGRIND_FLAGS} bin/main

printAll:
	enscript ${ENSCRIPT_FLAGS} src/*.cpp include/*.h  | ps2pdf - bin/src.pdf

runMe: bin/main
	bin/main
	
clean:
	rm -rf bin/main bin/*.o bin/*.pdf
