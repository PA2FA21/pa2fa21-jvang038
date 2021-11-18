# Makefile for Lecture 27
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = vectors
TWO = iterators
THREE = vectors_and_iterators
FOUR = stl_algorithms

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE} ${FOUR}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
  
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
  
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^

${FOUR}: ${FOUR}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
