objects = main.o lectecr.o jpg_io.o
	
program : $(objects)
	gcc -Wall -o program $(objects) -ljpeg
	./program -t copy -o cat.ppm -i cat.jpg
	
main.o : main.c lectecr.h jpg_io.h
	gcc -Wall -c main.c

lectecr.o : lectecr.c lectecr.h jpg_io.h
	gcc -Wall -c lectecr.c

jpg_io.o : jpg_io.c jpg_io.h 
	gcc -Wall -c jpg_io.c

clean :
	rm $(objects)

