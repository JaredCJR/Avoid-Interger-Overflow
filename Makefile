CC = arm-angstrom-linux-gnueabi-gcc
#CC = gcc
CFLAGS = -O0 -Wall
LDFLAGS = -lrt



default: max.c
	$(CC) $(CFLAGS) $(LDFLAGS) max.c -o max_bit -D BITWISE
	$(CC) $(CFLAGS) $(LDFLAGS) max.c -o max_op -D OPERATOR

clean:
	rm -f max_*

