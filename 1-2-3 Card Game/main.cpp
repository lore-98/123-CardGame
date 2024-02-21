//LIBRERIE//

#include <iostream>
#include <string>


#include "card_definition.h"
#include "deck_definition.h"
#include "deck_procedures.h"
#include "game.h"
#include "checks.h"
#include "windows.h"
#include "iomanip"

using namespace std;

int main(){
    SetColor(13);
    cout<<setw(65)<<"1 2 3 CARD GAME"<<endl<<endl;
    Sleep(2000);
    cout<<"Select Mode"<<endl<<"1. Automatic"<<endl<<"2. One Shot"<<endl<<"Insert Number : ";
    int mode = Check_Mode();

    system("cls");
    SetColor(7);

    Game_Mode(mode);

    SetColor(7);
    cout<<endl;
    system("pause");
    return 0;
}