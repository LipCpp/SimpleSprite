#ifndef SIMPLESPRITE_UTIL_H
#define SIMPLESPRITE_UTIL_H

#include <map>
#include "constants.h"

/*
 * ATTENTION: this class is mainly intended for
 * development purposes and should not be used
 * in production!
 */
class Util
{
public:
    // draws a custom curve (e.g. for throwing or jumping pos)
    static void drawCurve();

    inline static map<string, Vector2> pos; // TODO: Why need to be inline
};


#endif //SIMPLESPRITE_UTIL_H
