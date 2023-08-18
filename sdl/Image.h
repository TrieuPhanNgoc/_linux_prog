#ifndef __IMAGE__
#define __IMAGE__

#include "Common.h"

class Image {
    public:
        Image(const std::string& filename);
        ~Image();
    private:
        SDL_Surface* imageSurface;
};

#endif // __IMAGE