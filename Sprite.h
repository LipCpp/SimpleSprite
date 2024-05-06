//
// Created by hyperion on 06.05.24.
//

#ifndef SIMPLESPRITE_SPRITE_H
#define SIMPLESPRITE_SPRITE_H

#include "constants.h"
#include "Sprite.h"

class Sprite
{
public:
    Sprite(string fileName, uint numRows, uint numCols);
    ~Sprite();
public:
    string getFileName();
    Texture2D getTexture();
    void drawSprite(uint row, uint col, Vector2 pos);
    const float getSprWidth();
    const float getSprHeight();
private:
    string fileName;
    Texture2D texture;
    uint numMaxRows;
    uint numMaxCols;
    float SPRITE_WIDTH;
    float SPRITE_HEIGHT;
};


#endif //SIMPLESPRITE_SPRITE_H
