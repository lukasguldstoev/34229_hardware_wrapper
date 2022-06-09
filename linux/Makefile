CC=gcc
all:output/server output/reference.o

clean:
	rm -rf output/*.o
	rm -rf output/server
	rm -f output/reference.o

output/reference.o: hps_linux.c header/hps_linux.h
	$(CC) -c -o output/reference.o hps_linux.c

output/server: output/main.o output/httpd.o
	$(CC) -o output/server $^

output/main.o: main.c header/httpd.h
	$(CC) -c -o output/main.o main.c

output/httpd.o: httpd.c header/httpd.h
	$(CC) -c -o output/httpd.o httpd.c

