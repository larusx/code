CXX = g++ -g 

objs = test.o tree.o

test:$(objs)
	$(CXX) -o test $(objs)

.PHONY:clean
clean:
	-rm test $(objs)
