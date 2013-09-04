CC = g++ 

objs = tree.o mystack.o a.o

a.out:$(objs)
	$(CC) -o a.out $(objs) 

.PHONY:clean
clean:
	-rm a.out $(objs)
