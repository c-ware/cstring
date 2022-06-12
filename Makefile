OBJS=./src/cstring.o ./src/cstring_internal.o 
TESTS=./tests/concat ./tests/init 
HEADERS=./src/cstring.h ./src/cstring_internal.h ./src/liberror/liberror.h 
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

./tests/concat: ./tests/concat.c ./tests/common.h $(OBJS)
	$(CC) ./tests/concat.c -o ./tests/concat $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./tests/init: ./tests/init.c ./tests/common.h $(OBJS)
	$(CC) ./tests/init.c -o ./tests/init $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

./src/cstring.o: ./src/cstring.c ./src/cstring.h ./src/cstring_internal.h
	$(CC) -c $(CFLAGS) ./src/cstring.c -o ./src/cstring.o $(LDFLAGS) $(LDLIBS)

./src/cstring_internal.o: ./src/cstring_internal.c ./src/cstring.h ./src/cstring_internal.h
	$(CC) -c $(CFLAGS) ./src/cstring_internal.c -o ./src/cstring_internal.o $(LDFLAGS) $(LDLIBS)

libcstring.so: $(OBJS)
	$(CC) $(OBJS) -shared -o libcstring.so
