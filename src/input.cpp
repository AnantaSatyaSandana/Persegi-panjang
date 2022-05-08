#include "include/input.h"

void input::MainMenu(worldData* data){
    while(1){
        c_clrscr();

        cout << "Persegi Panjang Simulation Ver 0.00.1" << endl;
        cout << endl;
        cout << "menu: " << endl;
        cout << "1. Show Persegi Panjang" << endl;
        cout << "2. Add/Edit Persegi Panjang" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "-> Select Menu: ";

        char input;

        cin >> input;
        fflush(stdin);

        switch (input){
            case '1':
                Graph(data);
                break;

            case '2':
                c_clrscr();
                RectangleMenu(data);
                break;
            case '0':
                c_clrscr();
                return;
            
            default:
                break;
        }
    }
}

void input::Graph(worldData* data){
    while(1){
        c_clrscr();

        coordinateSystem::Draw(data);

        cout << endl;
        cout << "Use WASD to Move" << endl;
        cout << "Press Escape to Exit" << endl;
        
        int input = 0;
        
        input = c_getch();


        switch (input){
            case 'w':
                data->offsetY++;
                break;
            case 's':
                data->offsetY--;
                break;
            case 'a':
                data->offsetX--;
                break;
            case 'd':
                data->offsetX++;
                break;
             case 'W':
                data->offsetY++;
                break;
            case 'S':
                data->offsetY--;
                break;
            case 'A':
                data->offsetX--;
                break;
            case 'D':
                data->offsetX++;
                break;

            case 27: //escape
                return;

            default:
                break;
        }
    }
}
void input::PrintRectangles(worldData* data){
    for(unsigned int i = 0; i < data->rectangles.size(); i++){
        rectangle rectangle = data->rectangles[i];

        cout << i + 1 << ". ";
        cout << rectangle.GetSymbol() << " ";
        cout << "(" << rectangle.GetX() << ", " << rectangle.GetY() << ")";
        cout << "   " << "Lebar: " << rectangle.GetWidth();
        cout << "   " << "Panjang: " << rectangle.GetHeight();
        cout << endl;

    }
}
void input::RectangleMenu(worldData* data){


     int input;

    while(1){
        c_clrscr();

        cout << endl;
        cout << "Persegi Panjang data: " << endl;
        PrintRectangles(data);
        cout << endl;

        cout << endl;
        cout << "Menu: " << endl;
        cout << "1. Edit Persegi Panjang" << endl;
        cout << "2. Add Persegi Panjang" << endl;
        cout << "0. Back" << endl;
        cout << endl;
        cout << "-> Select Menu: ";

       

        cin >> input;

        switch (input)
        {
        case 2:
            data->rectangles.push_back(InputRectangle());
            c_clrscr();
            cout << "New Persegi Panjang Has Been Added" << endl;
            cout << endl << "Press Any Key to Continue";

            break;
        
        case 0:
            return;
        
        default:
            if(input < 1 || input > data->rectangles.size()) break;


            ShowRectangle(data, input - 1);

            break;
        }
    }
}

rectangle input::InputRectangle(){
    point point;
    int width, height, n;
    string str;
    char c[n];
    char symbol;
    c_clrscr();

    cout << "Input New Persegi Panjang Data";
    cout << endl;

      cout << endl << "Input Symbol: ";
    cin >> str;
    strcpy(c, str.c_str());
    symbol = c[0];
    cout << endl << "Input Titik Tengah X: ";
    cin >> point.x;
    cout << endl << "Input Titik Tengah Y: ";
    cin >> point.y;
    cout << endl << "Input lebar: ";
    cin >> width;
    cout << endl << "Input panjang: ";
    cin >> height;
  
        

    return rectangle(point, width, height, symbol, false);
}



void input::ShowRectangle(worldData* data, int index){
    rectangle* rect = &data->rectangles[index];

    int input;
    string str;
     int n;
    char c[n];
    while(1){
        c_clrscr();

        cout << "Titik Tengah: " << "{" << rect->GetX() << ", " << rect->GetY() << ")" << endl;
        cout << "lebar: " << rect->GetWidth() << endl;
        cout << "panjang: " << rect->GetHeight() << endl;
        cout << "X Border: " << rect->GetXMin() << " - " << rect->GetXMax() << endl;
        cout << "Y Border: " << rect->GetYMin() << " - " << rect->GetYMax() << endl;
        cout << "Symbol: " << rect->GetSymbol() << endl;
        cout << "Fill Mode: " << (rect->GetFill() ? "Filled" : "Hollow") << endl;
        cout << endl;
        cout << "Options: " << endl;
        cout << "1. Change Size" << endl;
        cout << "2. Change Symbol" << endl;
        cout << "3. Change Fill Mode" << endl;
        cout << "4. Check Intersection" << endl;
        cout << "5. Create New Persegi Panjang from Onion" << endl;
        cout << "6. Create New Persegi Panjang from Intersection" << endl;
        cout << "7. Delete Rectangle" << endl;
        cout << "0. Back" << endl;
        cout << endl;
        cout << "-> Select Option: ";

        cin >> input;

        cout << endl;

        switch (input){
            case 1:
                ChangeSize(rect);

                break;

            case 2:
                c_clrscr();

                cout << "Input New Symbol: ";

               
                char symbol;
                cin >> str;
                strcpy(c, str.c_str());
                symbol = c[0];
                
                rect->SetSymbol(symbol);

                c_clrscr();

                cout << "Symbol Succesfully Changed to" << symbol << endl;
                cout << endl << "Pres Any Key To Continue";

                c_getch();

                break;
            case 3:
                c_clrscr();

                rect->SetFill(!rect->GetFill());

                c_clrscr();

                cout << "Fill Mode Succesfully Changed to " << (rect->GetFill() ? "Filled" : "Hollow") << endl;
                cout << endl << "Pres Any Key To Continue";

                c_getch();

                break;

            case 4:
                c_clrscr();

                PrintRectangles(data);
                cout << endl <<  "Select Second Persegi Panjang: " ;

                cin >> input;

                if(input < 1 || input > data->rectangles.size()) break;

                c_clrscr();

                if(*rect == data->rectangles[input - 1]){
                    cout << "Persegi Panjang Intersected" << endl;
                }
                else{
                    cout << "Persegi Panjang NOT Intersected" << endl;
                }

                cout << endl << "Pres Any Key To Continue";

                c_getch();

                break;

            case 5:
                c_clrscr();

                PrintRectangles(data);
                cout << endl <<  "Select Second Persegi Panjang: " ;

                cin >> input;

                if(input < 1 || input > data->rectangles.size()) break;

                data->rectangles.push_back(*rect + data->rectangles[input - 1]);

                break;

            case 6:
                c_clrscr();

                PrintRectangles(data);
                cout << endl <<  "Select Second Persegi Panjang: " ;

                cin >> input;

                if(input < 1 || input > data->rectangles.size()) break;

                data->rectangles.push_back(*rect - data->rectangles[input - 1]);

                break;

            case 7:
                cout << "Are You Sure You Want To Delete This Persegi Panjang?(y/n) ";

                char YN;
                cin >> YN;

                if(YN != 'Y' && YN != 'y') break;

                data->rectangles.erase(data->rectangles.begin() + index);

                c_clrscr();

                cout << "Persegi Panjang Succesfully Deleted" << endl;
                cout << endl << "Press Any Key to Continue";

                c_getch();
                return;

            case 0:
                return;
            
            default:
                break;
        }
    }

    
}

void input::ChangeSize(rectangle* rect){
    c_clrscr();

    cout << "Options: " << endl;
    cout << "1. Change Lebar" << endl;
    cout << "2. Change Panjang" << endl;
    cout << "3. Set Size to Double" << endl;
    cout << "4. Set Size to Half" << endl;
    cout << endl;
    cout << "-> Select Option: ";

    int input;

    cin >> input;

    c_clrscr();

    switch (input){
        case 1:
            cout << "Input New Lebar: ";

            int width;

            cin >> width;

            rect->SetWidth(width);

            c_clrscr();

            cout << "Lebar Persegi Panjang Succesfully Changed to " << width << endl;
            cout << endl << "Press Any Key to Continue";

            c_getch();

            break;
        
        case 2:
            cout << "Input New Height: ";

            int height;

            cin >> height;

            rect->SetHeight(height);

            c_clrscr();

            cout << "Panjang Persegi Panjang Succesfully Changed to" << height << endl;
            cout << endl << "Press Any Key to Continue";

            c_getch();

            break;

        case 3:
            *rect++;

            c_clrscr();

            cout << "Persegi Panjang Size Succesfully Changed to Double" << endl;
            cout << endl << "Press Any Key to Continue";

            c_getch();

            break;

        case 4:
            *rect--;

            c_clrscr();

            cout << "Persegi Panjang Size Succesfully Changed to Half" << endl;
            cout << endl << "Press Any Key to Continue";

            c_getch();

            break;

        default:
            break;
    }
}