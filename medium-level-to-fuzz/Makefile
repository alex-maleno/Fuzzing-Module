build:
	clang++ -Wall -Wextra -std=c++11 -o execute main.cpp airplane_object.cpp

valgrind: build
	valgrind --leak-check=full --show-leak-kinds=all ./database

clean:
	rm -f ./database ./core*