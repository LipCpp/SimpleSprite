#ifndef SIMPLESPRITE_WINDOW_H
#define SIMPLESPRITE_WINDOW_H

#include <map>
#include <memory>
#include "constants.h"
#include "Sprite.h"
#include "AnimationHandler.h"

class Window
{
public:
    // window creation and game init
    explicit Window(string envName);
    ~Window();
private:
    void loadtextures();            // load textures from disk
    void drawingLoop();             // keyboard listener
    void moveBackGround(uint dir);  // move bg (LEFT or RIGHT)
    void drawCharIdle(vector<shared_ptr<Sprite>>& spriteVector, uint dir);
    void drawCharWalking(vector<shared_ptr<Sprite>>& spriteVector, uint dir);
    void drawCharAttack(vector<shared_ptr<Sprite>>& spriteVector);
    void drawThrowItem(Texture item);
    string windowName;
    map<string, Texture> textures;                   // have to be unloaded manually in constr
    map<string, vector<shared_ptr<Sprite>>> sprites; // will be unloaded automatically
    AnimationHandler animHandler;
    uint lastCharDir;
    int currBgX;
    float currCharX;
    float currCharY;
    float currSpearX;
    float currSpearY;
};


#endif //SIMPLESPRITE_WINDOW_H
