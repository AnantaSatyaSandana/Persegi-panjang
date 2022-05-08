#include "include/rectangle.h"

rectangle::rectangle(point _center, int _width, int _height, char _symbol, bool _isFill){
    center = _center; 
    width = _width; 
    height = _height; 
    symbol = _symbol; 
    isFill = _isFill;

    UpdateXMax();
    UpdateXMin();
    UpdateYMax();
    UpdateYMin();
}

rectangle::rectangle(float _xMin, float _xMax, float _yMin, float _yMax, char _symbol, bool _isFill){
    xMin = _xMin;
    xMax = _xMax;
    yMin = _yMin;
    yMax = _yMax;

    symbol = _symbol;
    isFill = _isFill;

    width = xMax - xMin;
    height = yMax - yMin;
    
    center.x = xMin + (width / 2.f);
    center.y = yMin + (height / 2.f);
}

bool rectangle::operator==(rectangle& rect){
    float xMin1 = this->GetXMin();
    float xMax1 = this->GetXMax();
    float yMin1 = this->GetYMin();
    float yMax1 = this->GetYMax();

    float xMin2 = rect.GetXMin();
    float xMax2 = rect.GetXMax();
    float yMin2 = rect.GetYMin();
    float yMax2 = rect.GetYMax();

    bool isXIntersect = (this->GetXMin() < rect.GetXMax()) && (rect.GetXMin() < this->GetXMax());
    bool isYIntersect = (this->GetYMin() < rect.GetYMax()) && (rect.GetYMin() < this->GetYMax());
    return isXIntersect && isYIntersect;
}

bool rectangle::operator!=(rectangle& rect){
    return !(*this == rect);
}

rectangle rectangle::operator+(rectangle& rect){
    if (*this != rect) throw;

    float xMin = this->GetXMin() < rect.GetXMin() ? this->GetXMin() : rect.GetXMin();
    float xMax = this->GetXMax() > rect.GetXMax() ? this->GetXMax() : rect.GetXMax();
    float yMin = this->GetYMin() < rect.GetYMin() ? this->GetYMin() : rect.GetYMin();
    float yMax = this->GetYMax() > rect.GetYMax() ? this->GetYMax() : rect.GetYMax();

    return rectangle(xMin, xMax, yMin, yMax, '+', true);
}

rectangle rectangle::operator-(rectangle& rect){
    if (*this != rect) throw;

    float xMin = this->GetXMin() > rect.GetXMin() ? this->GetXMin() : rect.GetXMin();
    float xMax = this->GetXMax() < rect.GetXMax() ? this->GetXMax() : rect.GetXMax();
    float yMin = this->GetYMin() > rect.GetYMin() ? this->GetYMin() : rect.GetYMin();
    float yMax = this->GetYMax() < rect.GetYMax() ? this->GetYMax() : rect.GetYMax();

    return rectangle(xMin, xMax, yMin, yMax, '-', true);
}

rectangle& rectangle::operator++(){
    this->SetWidth(width * 2);
    this->SetWidth(height * 2);
}

rectangle rectangle::operator++(int){
    rectangle old = *this;
    operator++();
    return old;
}

rectangle& rectangle::operator--(){
    this->SetWidth(width / 2);
    this->SetWidth(height / 2);
}

rectangle rectangle::operator--(int){
    rectangle old = *this;
    operator--();
    return old;
}

float rectangle::operator[](int index){
    int n = index % 4;

    if(n == 0) return xMin;
    else if(n == 1) return xMax;
    else if(n == 2) return yMin;
    else if(n == 3) return yMax;
}