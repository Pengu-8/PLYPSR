#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    if (IMG_Init(IMG_INIT_PNG) < 0) {
        std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
    }
    int window_width = 1000;
    int window_height = 750;
    SDL_Window* window = SDL_CreateWindow(
        "Game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        SDL_WINDOW_OPENGL);
    if (window == nullptr) {std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;}
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;}
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    return 0;
}
