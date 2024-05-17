//
// Created by hyperion on 06.05.24.
//

#ifndef SIMPLESPRITE_ENV_H
#define SIMPLESPRITE_ENV_H

#include <memory>

#include "constants.h"
#include "Sprite.h"

#define LEFT 0
#define RIGHT 1

class Env
{
public:
    explicit Env(string envName);
    ~Env();
private:
    string envName;
    Texture bg;
    uint lastDir;
    int currBgX;
    // methods used for  animations (sprites)
    void drawCharIdle(vector<shared_ptr<Sprite>>& sprites, uint dir);
    void drawCharWalking(vector<shared_ptr<Sprite>>& sprites, uint dir);
    void moveBackGround(uint dir);
};


#endif //SIMPLESPRITE_ENV_H
