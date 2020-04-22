//
// Created by leandro on 21/04/2020.
//

#ifndef INC_2D_RGP_EXAMPLE_SDL2_ENTITY_H
#define INC_2D_RGP_EXAMPLE_SDL2_ENTITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float getX();
    float getY();
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
    void setCurrentFrame(int x, int y, int w, int h);
private:
    float x, y;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};

#endif //INC_2D_RGP_EXAMPLE_SDL2_ENTITY_H
