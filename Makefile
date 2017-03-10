MAIN = bench
OBJS = $(MAIN).o

CC = cc
LIBS = -lm
SRCS = bench.c
CFLAGS = -Wall


$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -O1 $(OBJS) $(LIBS) -o $@-o1
	$(CC) $(CFLAGS) -O2 $(MAIN)-o2.o $(LIBS) -o $@-o2
	$(CC) $(CFLAGS) -O3 $(MAIN)-o3.o $(LIBS) -o $@-o3

$(MAIN).o: $(MAIN).c
	$(CC) $(CFLAGS) -O1 -c $(MAIN).c
	$(CC) $(CFLAGS) -O2 -c $(MAIN).c -o $(MAIN)-o2.o
	$(CC) $(CFLAGS) -O3 -c $(MAIN).c -o $(MAIN)-o3.o

clean:
	rm -f $(OBJS) $(MAIN) $(MAIN).core
