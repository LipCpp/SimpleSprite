//
// Created by hyperion on 06.05.24.
//

#include "Sprite.h"


/*
 * Constr. destr.
 */
Sprite::Sprite(string fileName, uint numRows, uint numCols) :
        fileName(fileName),
        numMaxRows(numRows),
        numMaxCols(numCols)
{
    Image img = LoadImage(fileName.c_str());
    const float sizeFactor = 2;
    ImageResize(&img, img.width * sizeFactor, img.height * sizeFactor);
    texture = LoadTextureFromImage(img);
    SPRITE_WIDTH = (float) (texture.width / numMaxCols);
    SPRITE_HEIGHT = (float) (texture.height / numMaxRows);
}

Sprite::~Sprite()
{

}

/*
 * Class methods
 */
void Sprite::drawSprite(uint row, uint col, Vector2 pos)
{
    Rectangle currSprRec = {col * SPRITE_WIDTH,
                            row * SPRITE_HEIGHT,
                            SPRITE_WIDTH,
                            SPRITE_HEIGHT };

    DrawTextureRec(texture, currSprRec, pos, WHITE);
}

string Sprite::getFileName() { return fileName; }

Texture2D Sprite::getTexture() { return texture; }

const float Sprite::getSprWidth() { return SPRITE_WIDTH; }

const float Sprite::getSprHeight() { return SPRITE_HEIGHT; }
