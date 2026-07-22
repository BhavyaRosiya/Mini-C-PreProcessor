exe: project.o comment.o header.o macro.o
	cc headerfile.o comment.o header_inclusion.o macro.o -o exe

headerfile.o: headerfile.c
	cc -c headerfile.c

comment.o: comment.c
	cc -c comment.c

header_inclusion.o: header_inclusion.c
	cc -c header_inclusion.c

macro.o: macro.c
	cc -c macro.c

clean:
	echo "Clearing Please Wait..."
	rm -rv *.o 
