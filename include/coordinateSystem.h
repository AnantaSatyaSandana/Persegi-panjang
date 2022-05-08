#ifndef _COORDINATESYSTEM_H_
#define _COORDINATESYSTEM_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <string.h>

#include "include/utils.h"
#include "include/rectangle.h"

using namespace std;

struct worldData{
    vector<rectangle> rectangles;

    int offsetX = 0;
    int offsetY = 0;
};

namespace coordinateSystem{
    void Draw(worldData* data);
};

#endif