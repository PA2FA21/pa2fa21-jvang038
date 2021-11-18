# Makefile for Lecture 21
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
ONE = four_max
TWO = templated_max
THREE = class_template

# Type 'make' to create the executables
all: ${ONE} ${TWO} ${THREE}

${ONE}: ${ONE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
  
${TWO}: ${TWO}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
  
${THREE}: ${THREE}.cpp
	${CXX} ${CXXFLAGS} -o ${@}.run $^
	
# Clean-Up the executables
clean:
	rm -rf *.run
