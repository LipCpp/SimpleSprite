#ifndef SIMPLESPRITE_SPRITE_H
#define SIMPLESPRITE_SPRITE_H

#include "constants.h"
#include "Sprite.h"

// factor for GetTime() to accelerate sprite animation
#define CURR_TIME_FACTOR 10
// aliases for 'row' in spritesheet
#define SPRITE_IDLE 0
#define SPRITE_WALKING 1
#define SPRITE_ATTACK 5
// maximum of sprites (cols) in one sprite .png
#define MAX_SPIRTE_COLS 10
#define MAX_SPIRTE_ROWS 7
// number of  columns for every sprite animation (row)
const uint NUM_COLUMNS[] = { 5, 8, 8, 4, 4, 6, 10 };

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
    Texture2D texture;          // texture looking towards x
    Texture2D textureInv;       // texture looking towards -x
    uint numMaxRows;
    uint numMaxCols;
    float SPRITE_WIDTH;
    float SPRITE_HEIGHT;
};


#endif //SIMPLESPRITE_SPRITE_H
