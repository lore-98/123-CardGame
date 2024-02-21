//HEADER PER LE FUNZIONI DI UTILITA'//
#ifndef UTIL_H
#define UTIL_H

#include "windows.h"

//GESTIONE COLORI OUTPUT//
void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}

/*
1: Blue
2: Green
3: Cyan
4: Red
5: Purple
6: Yellow (Dark)
7: Default white
8: Gray/Grey
9: Bright blue
10: Brigth green
11: Bright cyan
12: Bright red
13: Pink/Magenta
14: Yellow
15: Bright white
-Numbers after 15 are background colors-
*/

#endif // UTIL_H