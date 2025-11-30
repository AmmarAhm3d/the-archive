all:hello
hello:main.o function1.o function2.o
	g++ main.o function1.o function2.o -o hello
main.o:main.cpp
	g++ -c main.cpp
function1.o:function1.cpp
	g++ -c function1.cpp
function2.o:function2.cpp
	g++ -c function2.cpp
clean:
	rm -rf *o hello