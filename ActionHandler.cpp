#include "AnimationHandler.h"


/*
 * Methods in namespace AnimationHandler
 */
AnimationHandler::AnimationHandler(vector<Animation> initialAnims) :
    currAnims(initialAnims)
{

}

void AnimationHandler::updateAnimations()
{
    for (int i = 0; i < currAnims.size(); ++i)
    {
        Animation& curr = currAnims.at(i);
        curr.update();
        if (curr.status() == TERMINATED)
            curr.resetAnim();
    }
}

unsigned long AnimationHandler::registerNewAnim(Animation newAction)
{
    currAnims.push_back(newAction);
    return currAnims.size();
}

void AnimationHandler::runAnimation(u_int8_t index, uint direction)
{
    currAnims.at(index).runAnimation(direction);
}

/*
 * Methods in namespace Animation
 */
Animation::Animation(ANIM_FUNC animFunc, float initX, float initY, Texture2D *animatedObj) :
        x(initX),
        y(initY),
        func(animFunc),
        animatedObj(animatedObj)
{
    this->statusCode = READY;
    this->initX = initX;
    this->initY = initY;
}

void Animation::update()
{
    cout << "animX: " << x << endl;

    if (statusCode == RUNNING)
    {
        DrawTexture(*animatedObj, x, y, WHITE);
        switch (func)
        {
            case LINEAR:
                if (direction)x += 10; else x -= 10;
                break;
            case PARABOLIC:
                break;
        }
    }

    if (direction)
    {
        if (x > WIDTH)
            statusCode = TERMINATED;
    }
    else
    {
        if (x < 0)
            statusCode = TERMINATED;
    }
}

int Animation::status() { return statusCode; }

void Animation::runAnimation(uint direction)
{
    this->statusCode = RUNNING;
    this->direction = direction;
}

void Animation::resetAnim()
{
    x = initX;
    y = initY;
}
