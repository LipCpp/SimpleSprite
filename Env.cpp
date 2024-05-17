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
    shared_ptr<Sprite> femaleBody(new Sprite("Female Skin1.png", 7, 10));
    chdir("../Female Hair");
    shared_ptr<Sprite> femaleHair(new Sprite("Female Hair4.png", 7, 10));
    chdir("../Female Clothing");
    shared_ptr<Sprite> femaleCorset(new Sprite("Purple Corset.png", 7, 10));
    vector<shared_ptr<Sprite>> female = {femaleBody, femaleHair, femaleCorset };
    chdir("../../img");
    bg = LoadTexture("forest.png");
    currBgX = 0;
    lastDir = LEFT;

    while (!WindowShouldClose())
    {
        // draw
        BeginDrawing();
            ClearBackground(DARKGREEN);

            DrawTexture(bg, currBgX, 0, WHITE);
            if (IsKeyDown(KEY_A))
            {
                moveBackGround(LEFT);
                drawCharWalking(female, LEFT);
                lastDir = LEFT;
            }
            else if (IsKeyDown(KEY_D))
            {
                moveBackGround(RIGHT);
                drawCharWalking(female, RIGHT);
                lastDir = RIGHT;
            }
            else
            {
                drawCharIdle(female, lastDir);
            }

        EndDrawing();
    }
}

Env::~Env()
{
    UnloadTexture(bg);
}


/*
 * Class methods
 */
void Env::drawCharIdle(vector<shared_ptr<Sprite>>& sprites, uint dir)
{
    for (int i = 0; i < sprites.size(); ++i)
    {
        sprites.at(i)->drawSprite(
                SPRITE_IDLE,
                (Vector2) {
                    WIDTH/2 - sprites.at(i)->getSprWidth()/2,
                    HEIGHT/2 },
                lastDir);
    }
}

void Env::drawCharWalking(vector<shared_ptr<Sprite>>& sprites, uint dir)
{
    for (int i = 0; i < sprites.size(); ++i)
    {
        sprites.at(i)->drawSprite(
                SPRITE_WALKING,
                (Vector2) {
                    WIDTH/2 - sprites.at(i)->getSprWidth() / 2,
                    HEIGHT / 2 },
              dir);
    }
}

void Env::moveBackGround(uint dir)
{
    const int SPEED = 3;

    switch (dir)
    {
        case LEFT:
            currBgX += SPEED;
            break;
        case RIGHT:
            currBgX -= SPEED;
            break;
    }
}
