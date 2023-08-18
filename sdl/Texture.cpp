#include "Texture.h"

Texture::Texture(SDL_Renderer* renderer, const std::string& imagePath) {
    image = SDL_LoadBMP(imagePath.c_str());
    if (!image) {
        std::cerr << "Failed to load image: " << imagePath << " - " << SDL_GetError() << std::endl;
        return;
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

void Texture::Render(SDL_Renderer* renderer, int x, int y, int width, int height) {
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}
