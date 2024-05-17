//
// Created by hyperion on 06.05.24.
//

#ifndef SIMPLESPRITE_SPRITE_H
#define SIMPLESPRITE_SPRITE_H

#include "constants.h"
#include "Sprite.h"

// factor for GetTime() to accelerate sprite animation
#define CURR_TIME_FACTOR 10
// aliases for 'row' in spritesheet
#define SPRITE_IDLE 0
#define SPRITE_WALKING 1
// number of  columns for every sprite animation (row)
const uint NUM_COLUMNS[] = { 5, 8 };

class Sprite
{
public:
    Sprite(string fileName, uint numRows, uint numCols);
    ~Sprite();
public:
    string getFileName();
    Texture2D getTexture();
    void drawSprite(uint row, Vector2 pos, bool inverted);
    const float getSprWidth();
    const float getSprHeight();
private:
    string fileName;
    Texture2D texture;
    Texture2D textureInv;
    uint numMaxRows;
    uint numMaxCols;
    float SPRITE_WIDTH;
    float SPRITE_HEIGHT;
};


#endif //SIMPLESPRITE_SPRITE_H
