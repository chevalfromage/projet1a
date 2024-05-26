objects = main.o lectecr.o jpg_io.o gray.o mask.o flou.o

valgrind : $(objects)
	gcc -Wall -o program $(objects) -ljpeg
	valgrind ./program -t gray -o person.ppm -i person.ppm -m mask_person.ppm

run : $(objects)
	gcc -Wall -o program $(objects) -ljpeg
	./program -t flou -o person_flou.ppm -i person.ppm -s 1
	
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

flou.o : flou.c flou.h
	gcc -Wall -c flou.c

clean :
	rm $(objects)

