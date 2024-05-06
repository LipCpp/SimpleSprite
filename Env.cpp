//
// Created by hyperion on 06.05.24.
//

#include "Env.h"
#include "Sprite.h"


/*
 * Constr. and destr.
 */
Env::Env(string envName) :
    envName(envName)
{
    // window options
    InitWindow(WIDTH, HEIGHT, envName.c_str());
    SetTargetFPS(FPS);

    // allocate resources
    chdir("../sprites/Character skin colors");
    sprites.push_back((Sprite) { "Female Skin1.png", 7, 10 });
    sprites.push_back((Sprite) { "Female Skin3.png", 7, 10 });
    sprites.push_back((Sprite) { "Male Skin2.png", 7, 10 });
    sprites.push_back((Sprite) { "Male Skin3.png", 7, 10 });

    Sprite sprFemale1 = sprites.at(0);
    Sprite sprFemale2 = sprites.at(1);
    Sprite sprMale1 = sprites.at(2);
    Sprite sprMale2 = sprites.at(3);

    while (!WindowShouldClose())
    {
        // update
        float currTime =  GetTime();
        uint currColFem1 = (int)(currTime * 10) % 5;    // mod 5 because there are 5 sprites in row 0
        uint currColFem2 = (int)(currTime * 10) % 5;
        uint currColMale1 = (int)(currTime * 10) % 6;
        uint currColMale2 = (int)(currTime * 10) % 10;
        const float H_SPR_W = sprFemale1.getSprWidth() / 2;
        const float H_SPR_H = sprFemale1.getSprHeight() / 2;

        // draw
        BeginDrawing();
            ClearBackground(DARKGREEN);

            sprFemale1.drawSprite(1,      // row 1 means the second row in the sprite sheet
                                  currColFem1,
                                  (Vector2) {WIDTH / 2 - sprFemale1.getSprWidth() - H_SPR_W, HEIGHT / 2 - sprFemale1.getSprHeight() - H_SPR_H });
            sprFemale2.drawSprite(0,
                                  currColFem2,
                                  (Vector2) {WIDTH / 2 + sprFemale2.getSprWidth(), HEIGHT / 2 - sprFemale2.getSprHeight() - H_SPR_H });
            sprMale1.drawSprite(5,
                                  currColMale1,
                                  (Vector2) {WIDTH / 2 - sprMale1.getSprWidth() - H_SPR_W, HEIGHT / 2 + sprMale1.getSprHeight() });
            sprMale2.drawSprite(6,
                                  currColMale2,
                                  (Vector2) {WIDTH / 2 + sprMale2.getSprWidth(), HEIGHT / 2 + sprMale2.getSprHeight() });
        EndDrawing();
    }
}

Env::~Env()
{
    for (int i = 0; i < sprites.size(); ++i)
    {
        UnloadTexture(sprites.at(i).getTexture());
    }
}


/*
 * Class methods
 */