CC = gcc
LIBFLAG = -L. -lpower -lresistance -Wl,-rpath,. -g
CFLAGS = -g -Wall -Wextra

all:			electrotest

electrotest:		main.c libpower.so libresistance.so libcomponent.so
			$(CC) $(CFLAGS) -o electrotest main.c $(LIBFLAG)

#electrolib:		libpower.so libresistance.so 
#libcomponent.so

libpower.so:		lib/libpower.c lib/libpower.h
			$(CC) $(CFLAGS) -c -fPIC lib/libpower.c
			$(CC) $(CFLAGS) -shared -fPIC -o libpower.so libpower.o

libresistance.so:	lib/libresistance.c lib/libresistance.h
			$(CC) $(CFLAGS) -c -fPIC lib/libresistance.c
			$(CC) $(CFLAGS) -shared -fPIC -o libresistance.so libresistance.o

libcomponent.so:	lib/libcomponent.c lib/libcomponent.h
			$(CC) $(CFLAGS) -c -fPIC lib/libcomponent.c
			$(CC) $(CFLAGS) -shared -fPIC -o libcomponent.so libcomponent.o
			
clean:
			rm *.o electrotest *.so

install:
			sudo cp electrotest /usr/bin

uninstall:
			sudo rm -i electrotest /usr/bin/electrotest
