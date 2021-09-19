all:
	g++ queue.cpp -lboost_thread -lboost_system -pthread
clean:
	rm *.out
run: all
	./a.out
test:
	g++ queue.cpp test.cc -lboost_thread -lboost_system -pthread -lgtest
