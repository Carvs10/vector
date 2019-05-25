output: ./obj/main.o 
	mkdir -p bin
	g++ -std=c++11 ./obj/main.o  -o ./bin/exe 

./obj/main.o: ./source/main.cpp 
	mkdir -p obj
	g++ -c ./source/main.cpp -o ./obj/main.o -std=c++11

