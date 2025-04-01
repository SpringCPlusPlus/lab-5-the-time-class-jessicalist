all: a.out

a.out: src/Time.cpp test/test.cpp 
	g++ -std=c++11  src/Time.cpp test/test.cpp -o a.out

test: a.out
	./a.out -s -d -t