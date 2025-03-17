CXXFLAGS = -ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
GTEST_LIBS = -lgtest -lgtest_main -pthread

all: dijkstras ladder

dijkstras: src/dijkstras_main.cpp dijkstras.o
	g++ $(CXXFLAGS) src/dijkstras_main.cpp dijkstras.o -o dmain

dijkstras.o: src/dijkstras.cpp
	g++ $(CXXFLAGS) -c src/dijkstras.cpp -o dijkstras.o

ladder: src/ladder.cpp ladder.o
	g++ $(CXXFLAGS) src/ladder_main.cpp ladder.o -o lmain

ladder.o: src/ladder.cpp
	g++ $(CXXFLAGS) -c src/ladder.cpp -o ladder.o

tests: dijkstras.o ladder.o gtest/student_gtests.cpp
	g++ $(CXXFLAGS) gtest/student_gtests.cpp dijkstras.o ladder.o -o tests $(GTEST_LIBS)

clean:
	/bin/rm dmain, lmain, *.o