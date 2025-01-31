all : roboticus.cpp
	g++ -Wall -Wextra -ggdb -o roboticus roboticus.cpp

run : all
	./roboticus