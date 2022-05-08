#include <iostream>

#include "include/input.h"
#include "include/coordinateSystem.h"

using namespace std;

int main(){

    worldData* dat = new worldData;

    input::MainMenu(dat);

    return 0;
}