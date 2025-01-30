all: compile clean run

compile:
	g++ -c *.cpp 
	g++ *.o -o main.exe
run:
	./main.exe
clean:
	rm *.o

windows:
	g++ main.cpp RegulaFalsi.cpp -o main.exe && .\main.exe