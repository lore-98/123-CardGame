//HEADER PER LA DEFINIZIONE DELLA STRUCT CARD//
#ifndef CHECK_H
#define CHECK_H

#include <iostream>
#include <string>

#include "utils.h"

//INSERIMENTO MODALITA' E CONTROLLO VALIDITA'//
int Check_Mode(){
    int mode; //variabile per la modalità
    SetColor(6);
    std::cin>>mode;
    SetColor(7);
    bool FAILURE=0; //flag errore inserimento

    if(mode!=1 && mode!=2 && mode!=999){
        FAILURE=1;
    }

    while(FAILURE){
        system("cls"); //pulizia schermo
        SetColor(4);
        std::cout<<"ERROR: Insert Number (1 or 2)"<<std::endl;
        SetColor(13);
        std::cout<<"***Select Mode***"<<std::endl<<"1. Automatic"<<std::endl<<"2. One Shot"<<std::endl<<"Insert Number : ";
        SetColor(6);
        std::cin>>mode;
        SetColor(7);
        if((mode==1||mode==2)||mode==999)
            FAILURE=0;
    }
    return mode;
}

//CONTROLLO VITTORIA//
void Check_Win(bool WINNING, int games, int mode){
SetColor(87);
std::cout<<std::endl;
if(WINNING==1){
    std::cout<<std::endl<<"WINNER!!!"<<std::endl<<std::endl;
    if(mode==1)
        std::cout<<"GAME PLAYED : "<<games<<std::endl;
    }else{
        std::cout<<"LOSER!"<<std::endl;
    }
    SetColor(7);
}

#endif // CHECK_H