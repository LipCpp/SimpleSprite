#ifndef SIMPLESPRITE_ANIMATIONHANDLER_H
#define SIMPLESPRITE_ANIMATIONHANDLER_H

#include <vector>
#include "AnimationHandler.h"
#include "constants.h"

class Animation;

enum ANIM_FUNC
{
    LINEAR,
    PARABOLIC
};

enum ANIM_STATUS
{
    READY,
    RUNNING,
    TERMINATED
};

class AnimationHandler
{
public:
    AnimationHandler() = default;
    explicit AnimationHandler(vector<Animation> initialAnims);
    ~AnimationHandler() = default;
    void updateAnimations();
    unsigned long  registerNewAnim(Animation newAnim);
    void runAnimation(u_int8_t index, uint direction);    // TODO: arg as enum
private:
    vector<Animation> currAnims;
};


class Animation
{
public:
    Animation(ANIM_FUNC animFunc, float initX, float initY, Texture2D* animatedObj);
    ~Animation() = default;
    void runAnimation(uint direction);
    void resetAnim();
    void update();
    int status();
private:
    ANIM_FUNC func;
    ANIM_STATUS statusCode;
    Texture2D* animatedObj;
    uint direction;
    float x;
    float y;
    float initX;
    float initY;
};

#endif //SIMPLESPRITE_ANIMATIONHANDLER_H
