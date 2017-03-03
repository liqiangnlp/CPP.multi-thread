CXXFLAGS = -O2

OBJS = main.o multi_threads.o

MultiThread: $(OBJS)
	g++ -o ../bin/$@ $^ -lpthread

$(OBJS): %.o:%.cpp
	g++ $(CXXFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	-rm $(OBJS) ../bin/MultiThread
