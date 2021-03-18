CC = gcc
LIBFLAG = -L. -lpower -lresistance -lcomponent -Wl,-rpath,. -g
CFLAGS = -g -Wall -Wextra
OBJECTS_Global = /usr/lib/libresistance.so /usr/lib/libpower.so /usr/lib/libcomponent.so


all:			electrotest

electrotest:		main.c libpower.so libresistance.so libcomponent.so
			$(CC) $(CFLAGS) -o electrotest main.c $(LIBFLAG) 

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
			sudo install electrotest /usr/bin/electrotest
			sudo install libresistance.so /usr/lib
			sudo install libpower.so /usr/lib
			sudo install libcomponent.so /usr/lib
			
			

uninstall:
			sudo rm -f /usr/bin/electrotest
			sudo rm -f /usr/lib/libresistance.so
			sudo rm -f /usr/lib/libpower.so
			sudo rm -f /usr/lib/libcomponent.so
