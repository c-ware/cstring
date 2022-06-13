OBJS=./src/cstring.o 
TESTS=./tests/find ./tests/loadf ./tests/concat ./tests/strip ./tests/finds ./tests/concats ./tests/endswiths ./tests/startswith ./tests/init ./tests/endswith ./tests/startswiths 
HEADERS=./src/cstring.h ./src/liberror/liberror.h 
CC=cc
PREFIX=/usr/local
CFLAGS=-fpic

all: $(OBJS) $(TESTS) libcstring.so

clean:
	rm -rf $(OBJS)
	rm -rf $(TESTS)
	rm -rf vgcore.*
	rm -rf core*
	rm -rf libcstring.so

install:
	mkdir -p $(PREFIX)
	mkdir -p $(PREFIX)/lib
	mkdir -p $(PREFIX)/include
	mkdir -p $(PREFIX)/include/libcstring
	install -m 755 libcstring.so $(PREFIX)/lib
	install -m 644 $(HEADERS) $(PREFIX)/include/libcstring

uninstall:
	rm -rf $(PREFIX)/include/libcstring
	rm -f $(PREFIX)/lib/libcstring.so

./tests/find: ./tests/find.c ./tests/common.h $(OBJS)
	$(CC) ./tests/find.c -o ./tests/find $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/loadf: ./tests/loadf.c ./tests/common.h $(OBJS)
	$(CC) ./tests/loadf.c -o ./tests/loadf $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/concat: ./tests/concat.c ./tests/common.h $(OBJS)
	$(CC) ./tests/concat.c -o ./tests/concat $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/strip: ./tests/strip.c ./tests/common.h $(OBJS)
	$(CC) ./tests/strip.c -o ./tests/strip $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/finds: ./tests/finds.c ./tests/common.h $(OBJS)
	$(CC) ./tests/finds.c -o ./tests/finds $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/concats: ./tests/concats.c ./tests/common.h $(OBJS)
	$(CC) ./tests/concats.c -o ./tests/concats $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/endswiths: ./tests/endswiths.c ./tests/common.h $(OBJS)
	$(CC) ./tests/endswiths.c -o ./tests/endswiths $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/startswith: ./tests/startswith.c ./tests/common.h $(OBJS)
	$(CC) ./tests/startswith.c -o ./tests/startswith $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/init: ./tests/init.c ./tests/common.h $(OBJS)
	$(CC) ./tests/init.c -o ./tests/init $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/endswith: ./tests/endswith.c ./tests/common.h $(OBJS)
	$(CC) ./tests/endswith.c -o ./tests/endswith $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/startswiths: ./tests/startswiths.c ./tests/common.h $(OBJS)
	$(CC) ./tests/startswiths.c -o ./tests/startswiths $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./src/cstring.o: ./src/cstring.c ./src/cstring.h
	$(CC) -c $(CFLAGS) ./src/cstring.c -o ./src/cstring.o $(LDFLAGS) $(LDLIBS)

libcstring.so: $(OBJS)
	$(CC) $(OBJS) -shared -o libcstring.so
