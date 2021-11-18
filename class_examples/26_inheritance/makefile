# Makefile for Lecture 26
CXX = g++
CXXFLAGS = -Wall
THREE = inheritance_chain
FOUR = inheritance_constructors_correct

# Type 'make' to create the executables
all: base derived ${THREE} ${FOUR}

base: person.h base_main.cpp
	${CXX} ${CXXFLAGS} base_main.cpp -o base.run
	
derived: person.h baseball_player.h derived_main.cpp
	${CXX} ${CXXFLAGS} derived_main.cpp -o derived.run
	
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
${FOUR}: ${FOUR}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run