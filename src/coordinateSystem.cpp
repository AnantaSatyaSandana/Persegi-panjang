#include "include/coordinateSystem.h"

void coordinateSystem::Draw(worldData* data){
    int offsetX = data->offsetX;
    int offsetY = data->offsetY;

    char rectanglePoints[25][15] = {0};

    for(unsigned int i = 0; i < data->rectangles.size(); i++){
        rectangle* rectangle = &data->rectangles[i];

        int xMin = ceil(rectangle->GetXMin());
        int xMax = ceil(rectangle->GetXMax()) - 1;
        int yMin = ceil(rectangle->GetYMin());
        int yMax = ceil(rectangle->GetYMax()) - 1;

        for(int j = xMin; j <= xMax; j++){
            for(int k = yMin; k <= yMax; k++){
                if(!rectangle->GetFill())
                    if((j != xMin && j != xMax) && (k != yMin && k != yMax)) continue;
                if((j < 0 + offsetX || j > 25 + offsetX) || (k < 0 + offsetY || k > 15 + offsetY)) continue;

                rectanglePoints[j - offsetX][k - offsetY] = rectangle->GetSymbol();
            }
        }
    }

    for(int y = 14; y >= 0; y--){
        cout << setfill(' ') << setw(4) << y + offsetY << " ";

        for(unsigned int x = 0; x <= 24; x++){
            if(rectanglePoints[x][y] != 0) cout << rectanglePoints[x][y] << " ";
            else cout << "* ";
        }
        cout << endl;
    }

    cout << "     ";
    for(int x = 0; x <= 24; x++){
        if(x + offsetX < 0)
            cout << "- ";
        else
            cout << "+ ";
    }
    cout << endl;

    for(int i = 3; i >= 1; i--){
        cout << "     ";

        for(int x = 0; x <= 24; x++){
            int n = abs(x + offsetX);

            if(utils::GetDigit(n) >= i)
                cout << utils::GetDigit(n, i) << " ";
            else
                cout << "  ";
        }

        cout << endl;
    }
}