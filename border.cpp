//
// Created by 123ye on 27/02/2025.
//
#include <SDL.h>
#include <SDL_image.h>
#include "border.h"



// creating borders
Border::Border(int amount, int window_width, int window_height) {
    // border1 = new SDL_Rect[amount];
    int width_distance = window_width / amount;
    int height_distance = window_height / amount;

    for(int i = 1; i < amount; i++)
    {
        border1.push_back(SDL_Rect{ width_distance * i, 0, 5,window_height });
        border2.push_back(SDL_Rect{ 0, height_distance * i, window_width,5 });
        // location_square.push_back(SDL_Rect{ width_distance * i, 0, window_width, window_height });
    }
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            location_square.push_back(SDL_Rect{ window_width*j/amount/2, (window_height*i/amount/2)});
        }
        // location_square.push_back(SDL_Rect{ window_width*i/amount/2, (window_height*i/amount/2)});
    }

}


// void Border::Number_border(int amount) {

// }
