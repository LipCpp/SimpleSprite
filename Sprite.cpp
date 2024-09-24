#include "Sprite.h"


/*
 * Constructor and destructor
 */
Sprite::Sprite(string fileName, uint numRows, uint numCols) :
        fileName(fileName),
        numMaxRows(numRows),
        numMaxCols(numCols)
{
    Image img = LoadImage(fileName.c_str());
    Image imgInv = LoadImage(fileName.c_str());
    const float sizeFactor = 2;
    ImageResize(&img, img.width * sizeFactor, img.height * sizeFactor);
    ImageResize(&imgInv, imgInv.width * sizeFactor, imgInv.height * sizeFactor);
    ImageFlipHorizontal(&imgInv);
    texture = LoadTextureFromImage(img);
    textureInv = LoadTextureFromImage(imgInv);
    SPRITE_WIDTH = (float) (texture.width / numMaxCols);
    SPRITE_HEIGHT = (float) (texture.height / numMaxRows);
}

Sprite::~Sprite()
{
    // free resources
    UnloadTexture(texture);
    UnloadTexture(textureInv);
}

/*
 * Class methods
 */
void Sprite::drawSprite(uint row, Vector2 pos, bool inverted)
{
    float currTime = GetTime();

    if (inverted)
    {
        uint col = (int)(currTime * CURR_TIME_FACTOR) % NUM_COLUMNS[row] ;
        Rectangle currSprRec = { (textureInv.width - SPRITE_WIDTH) - col * SPRITE_WIDTH,
                                row * SPRITE_HEIGHT,
                                SPRITE_WIDTH,
                                SPRITE_HEIGHT };
        DrawTextureRec(textureInv, currSprRec, pos,  WHITE);

    }
    else
    {
        uint col = (int)(currTime * CURR_TIME_FACTOR) % NUM_COLUMNS[row];
        Rectangle currSprRec = {col * SPRITE_WIDTH,
                                row * SPRITE_HEIGHT,
                                SPRITE_WIDTH,
                                SPRITE_HEIGHT };
        DrawTextureRec(texture, currSprRec, pos, WHITE);
    }
}

string Sprite::getFileName() { return fileName; }

Texture2D Sprite::getTexture() { return texture; }

const float Sprite::getSprWidth() { return SPRITE_WIDTH; }

const float Sprite::getSprHeight() { return SPRITE_HEIGHT; }
