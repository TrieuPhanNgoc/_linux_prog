all:
	gcc api_cat.c -o ${PWD}/bin/cat_cmd

run:
	${PWD}/bin/cat_cmd ${PWD}/api_cat.c

# to run with sdl
#CFLAG = `sdl2-config --cflags --libs`
#sdl:
# 	gcc -o myprogram myprogram.c `sdl2-config --cflags --libs`
#	gcc -o myprogram myprogram.c ${CFLAG}

clean:
	rm -rf ${PWD}/bin/cat_cmd