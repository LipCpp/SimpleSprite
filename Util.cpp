#include <math.h>
#include "Util.h"


/*
 * Static methods
 */
void Util::drawCurve()
{
    auto func = [](int x) -> int
    {
        int val = 20 * (1 / x);
        cout << val << endl;
        return val;
    };

    int start = WIDTH/2 - WIDTH/2/2;
    int end = WIDTH/2 + WIDTH/2/2;
    for (int x = start; x < end; ++x)
    {
        DrawPixel(x, func(x), RED);
    }
}
