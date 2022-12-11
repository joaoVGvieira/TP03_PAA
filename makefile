all:  
	gcc Sources/*.c   main.c -o exec -lm
	./exec