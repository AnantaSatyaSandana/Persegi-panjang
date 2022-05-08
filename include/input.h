#ifndef _INPUT_H_
#define _INPUT_H_

#include <iostream>

#include "include/conio.h"
#include "include/utils.h"
#include "include/coordinateSystem.h"
#include "include/rectangle.h"

using namespace std;

namespace input{
    void MainMenu(worldData* data);
    void Graph(worldData* data);
    void RectangleMenu(worldData* data);

    rectangle InputRectangle();
    void PrintRectangles(worldData* data);
    void ShowRectangle(worldData* data, int index);

    void ChangeSize(rectangle* rect);
};

#endif