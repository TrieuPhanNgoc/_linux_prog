CFLAG = `sdl2-config --cflags --libs`
SOURCES = Game.h Game.cpp
sdl: ${SOURCES}
	g++ main.cpp ${SOURCES} -o sdl ${CFLAG}

clean:
	rm -rf sdl