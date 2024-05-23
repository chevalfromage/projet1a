objects = main.o lectecr.o jpg_io.o gray.o mask.o

valgrind : $(objects)
	gcc -Wall -o program $(objects) -ljpeg
	valgrind ./program -t gray -o person.ppm -i person.ppm -m mask_person.ppm

run : $(objects)
	gcc -Wall -o program $(objects) -ljpeg
	./program -t gray -o person_masked.ppm -i person.ppm -m mask_person.ppm
	
main.o : main.c lectecr.h jpg_io.h
	gcc -Wall -c main.c

lectecr.o : lectecr.c lectecr.h jpg_io.h
	gcc -Wall -c lectecr.c

jpg_io.o : jpg_io.c jpg_io.h 
	gcc -Wall -c jpg_io.c

gray.o : gray.c gray.h
	gcc -Wall -c gray.c

mask.o : mask.c mask.h
	gcc -Wall -c mask.c

clean :
	rm $(objects)

