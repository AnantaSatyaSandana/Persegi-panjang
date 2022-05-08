#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <iostream>

struct point{
    float x, y;
};


class rectangle{
    private:
        point center;
        int width;
        int height;
        char symbol;

        float xMin;
        float xMax;
        float yMin;
        float yMax;

        bool isFill;

        void UpdateXMin() { xMin = center.x - (width / 2.f); };
        void UpdateXMax() { xMax = center.x + (width / 2.f); };

        void UpdateYMin() { yMin = center.y - (height / 2.f); };
        void UpdateYMax() { yMax = center.y + (height / 2.f); };


    public:
        rectangle(point _center, int _width, int _height, char _symbol, bool _isFill);
        rectangle(float _xMin, float _xMax, float _yMin, float _yMax, char _symbol, bool _isFill);

        void SetWidth(int value) { width = value; UpdateXMin(); UpdateXMax(); };
        void SetHeight(int value) { height = value; UpdateYMin(); UpdateYMax(); };

        void SetSymbol(char value) { symbol = value; };

        void SetFill(bool value) { isFill = value; };

        float GetX() { return center.x; };
        float GetY() { return center.y; };

        int GetWidth() { return width; };
        int GetHeight() { return height; };

        char GetSymbol() { return symbol; };

        float GetXMin() { return xMin; };
        float GetXMax() { return xMax; };
        float GetYMin() { return yMin; };
        float GetYMax() { return yMax; };

        bool GetFill() { return isFill; }



        bool operator==(rectangle& rect);
        bool operator!=(rectangle& rect);
        rectangle operator+(rectangle& rect);
        rectangle operator-(rectangle& rect);
        rectangle& operator++();
        rectangle operator++(int);
        rectangle& operator--();
        rectangle operator--(int);
        float operator[](int index);

};

#endif