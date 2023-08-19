CFLAG = `sdl2-config --cflags --libs`
SOURCES = Game.h Game.cpp Texture.cpp Texture.h
API_LIB = $PWD/API/*
sdl: ${SOURCES}
	g++ main.cpp ${SOURCES} -o sdl ${CFLAG}

clean:
	rm -rf sdl