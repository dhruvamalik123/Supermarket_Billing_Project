all: compile  link run

compile:
	g++ -c send_attachment.cxx -Isrc/include

link:
	g++ send_attachment.o -o send_attachment -Lsrc/lib -lcurl -lquickmail

run:
	send_attachment.exe

clean:
	del *.o
	del *.exe