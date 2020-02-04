CXX=gcc
CXXFLAGS=-axMIC-AVX512 -fopenmp -lmkl -std=c++11 

default : app


worker.o : worker.cc
	${CXX} -c ${OPTRPT} ${CXXFLAGS} -o "$@" "$<"

app : main.cc worker.o
	${CXX} ${OPTRPT} ${CXXFLAGS} -o "$@" "$<" worker.o

queue: app

clean :
	rm app *.o *.optrpt