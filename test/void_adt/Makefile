objs=main.o pet.o point.o list.o

test_void_list: $(objs)
	gcc -g -o test_void_list $(objs)

main.o: main.c list.h pet.h point.h
	gcc -c -g main.c list.h pet.h point.h

pet.o: pet.c pet.h
	gcc -c -g pet.c pet.h

point.o: point.c point.h
	gcc -c -g point.c point.h

list.o: list.c list.h
	gcc -c -g list.c list.h

clean:
	rm test_void_list $(objs)
