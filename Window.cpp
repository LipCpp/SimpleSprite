#include <algorithm>
#include "Window.h"
#include "Sprite.h"
#include "Util.h"
#include "AnimationHandler.h"

/*
 * Constructor and destructor
 */
Window::Window(string envName) :
        windowName(envName)
{
    // window props
    InitWindow(WIDTH, HEIGHT, envName.c_str());
    SetTargetFPS(FPS);

    // load sprites
    loadtextures();
    // load textures
    chdir("../../img");
    textures["bg"] = LoadTexture("forest.png");
    Image imgPilum = LoadImage("pilum.png");
    ImageResize(&imgPilum, 100, 100);
    ImageRotate(&imgPilum, 45);
    textures["pilum"] = LoadTextureFromImage(imgPilum);

    // set game props
    currBgX = 0;
    currCharX = WIDTH/2 - (sprites["char"].at(0)->getSprWidth() / 2);
    currCharY = HEIGHT/2;
    lastCharDir = LEFT;
    // loading animation resources
    animHandler.registerNewAnim(Animation(LINEAR, currCharX, currCharY - 20, &textures["pilum"]));

    // setup static Util props
    Util::pos["throwing"] = { 0, 0 };

    // main game loop
    while (!WindowShouldClose())
    {
        // draw textures / sprites
        BeginDrawing();
            ClearBackground(DARKGREEN);

            drawingLoop();

        EndDrawing();
    }
}

Window::~Window()
{

    // TODO: create class wrapper for textures: map to unload automatically resources

    // unload every element form textures: map
    UnloadTexture(textures["bg"]);
    UnloadTexture(textures["pilum"]);

    // sprites: map unloads itself automatically due to class wrapper
}


/*
 * Class methods
 */
void Window::drawingLoop()
{
    // bg as first layer
    DrawTexture(textures["bg"], currBgX, 0, WHITE);

    animHandler.updateAnimations();

    if (IsKeyDown(KEY_A))           // going left
    {
        moveBackGround(LEFT);
        drawCharWalking(sprites["char"], LEFT);
        lastCharDir = LEFT;
    }
    else if (IsKeyDown(KEY_D))       // MOVEMENT:  going right
    {
        moveBackGround(RIGHT);
        drawCharWalking(sprites["char"], RIGHT);
        lastCharDir = RIGHT;
    }
    else if (IsKeyDown(KEY_UP))      // ATTACK: throw spear
    {
        drawCharAttack(sprites["char"]);
        drawThrowItem(textures["pilum"]);
    }
    else if (IsKeyDown(KEY_SPACE))   // MOVEMENT: jumping
    {
        // TODO: 1. jumping animation (bgY++) 2. falling animation (bgY--)
    }
    else                                  // MOVEMENT: idle
    {
        drawCharIdle(sprites["char"], lastCharDir);
    }
}

void Window::loadtextures()
{
    chdir("../sprites/Character skin colors");
    shared_ptr<Sprite> femaleBody(new Sprite("Female Skin1.png",
                                             MAX_SPIRTE_ROWS,
                                             MAX_SPIRTE_COLS));
    chdir("../Female Hair");
    shared_ptr<Sprite> femaleHair(new Sprite("Female Hair4.png",
                                             MAX_SPIRTE_ROWS,
                                             MAX_SPIRTE_COLS));
    chdir("../Female Clothing");
    shared_ptr<Sprite> femaleCorset(new Sprite("Purple Corset.png",
                                               MAX_SPIRTE_ROWS,
                                               MAX_SPIRTE_COLS));
    vector<shared_ptr<Sprite>> femaleChar = { femaleBody, femaleHair, femaleCorset };
    sprites["char"] = femaleChar;
}

void Window::moveBackGround(uint dir)
{
    // TODO: bg moving towards right screen edge
    if (currBgX >= 0)
    {

    }

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
#ifdef DEBUG
    cout << "[DEBUG] :: currBgX = " << currBgX << endl;
#endif
}

void Window::drawCharIdle(vector<shared_ptr<Sprite>>& spriteVector, uint dir)
{
    for (int i = 0; i < spriteVector.size(); ++i)
    {
        spriteVector.at(i)->drawSprite(
                SPRITE_IDLE,
                (Vector2) { currCharX, currCharY},
                lastCharDir);
    }
}

void Window::drawCharWalking(vector<shared_ptr<Sprite>>& spriteVector, uint dir)
{
    for (int i = 0; i < spriteVector.size(); ++i)
    {
        spriteVector.at(i)->drawSprite(
                SPRITE_WALKING,
                (Vector2) { currCharX, currCharY },
                dir);
    }
}

void Window::drawCharAttack(vector<shared_ptr<Sprite>> &spriteVector)
{
    for (int i = 0; i < spriteVector.size(); ++i)
    {
        spriteVector.at(i)->drawSprite(
                SPRITE_ATTACK,
                (Vector2) {
                        currCharX,
                        currCharY },
                lastCharDir);
    }
}

void Window::drawThrowItem(Texture item)
{
    cout << "Throwing item!!!" << endl;
    animHandler.runAnimation(0, lastCharDir);
}

