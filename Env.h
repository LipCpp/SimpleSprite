//
// Created by hyperion on 06.05.24.
//

#ifndef SIMPLESPRITE_ENV_H
#define SIMPLESPRITE_ENV_H

#include "constants.h"
#include "Sprite.h"

class Env
{
public:
    Env(string envName);
    ~Env();
private:
    string envName;
    vector<Sprite> sprites;

};


#endif //SIMPLESPRITE_ENV_H
