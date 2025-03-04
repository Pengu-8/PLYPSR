//
// Created by 123ye on 27/02/2025.
//

#ifndef BORDER_H
#define BORDER_H
#include <vector>


class Border {
    public:
    std::vector<SDL_Rect> border1;

    std::vector<SDL_Rect> border2;
    std::vector<SDL_Rect> location_square;


    Border(int amount, int window_width, int window_height);
};



#endif //BORDER_H
