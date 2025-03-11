program: main.o LetterCount.o WordCount.o LineCount.o
	g++ -o program main.o LetterCount.o WordCount.o LineCount.o 

main.o: main.cpp
	g++ -c main.cpp 

LetterCount.o: LetterCount.cpp
	g++ -c LetterCount.cpp 

WordCount.o: WordCount.cpp
	g++ -c WordCount.cpp 

LineCount.o: LineCount.cpp
	g++ -c LineCount.cpp 

clean:
	rm -f *.o program