//HEADER PER LO SVOLGIMENTO DEL GIOCO//
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "deck_definition.h"
#include "card_definition.h"
#include "deck_procedures.h"
#include "checks.h"
#include "utils.h"
#include "windows.h"

//ESTRAZIONE CARTE AUTOMATICA E RESTITUZIONE RISULTATO//
bool Game_Extraction_auto(card mazzo[]){
    bool WINNING=1;
    SetColor(9);
    std::cout<<std::endl<<"GAME START"<<std::endl<<std::endl;
    int contatore=1;

    SetColor(2);
    for(int i=NUMERO_CARTE-1;i>=0;i--){
        
        if(contatore==1){
            if(mazzo[i].valore==contatore)
                SetColor(4);
            std::cout<<mazzo[i].valore<<" "<<mazzo[i].seme<<"   (1)"<<std::endl;
        }
        if(contatore==2){
            if(mazzo[i].valore==contatore)
                SetColor(4);
            std::cout<<mazzo[i].valore<<" "<<mazzo[i].seme<<"   (2)"<<std::endl;
        }
        if(contatore==3){
            if(mazzo[i].valore==contatore)
                SetColor(4);
            std::cout<<mazzo[i].valore<<" "<<mazzo[i].seme<<"   (3)"<<std::endl;
        }

        if(mazzo[i].valore==contatore){
            WINNING=0;
            break;
        }else if(contatore==3){
            contatore=0;
        }
        contatore++;
    }
return WINNING;
}

//ESTRAZIONE CARTE RALLENTATA E RESTITUZIONE RISULTATO//
bool Game_Extraction_slowed(card mazzo[]){
    bool WINNING=1;
    SetColor(9);
    std::cout<<"GAME START"<<std::endl<<std::endl;
    int contatore=1;

    SetColor(2);
    for(int i=NUMERO_CARTE-1;i>=0;i--){
        
        if(contatore==1){
            Sleep(1500);
            if(mazzo[i].valore==contatore)
                SetColor(4);
            std::cout<<mazzo[i].valore<<" "<<mazzo[i].seme<<"   (1)"<<std::endl;
        }
        if(contatore==2){
            Sleep(1500);
            if(mazzo[i].valore==contatore)
                SetColor(4);
            std::cout<<mazzo[i].valore<<" "<<mazzo[i].seme<<"   (2)"<<std::endl;
        }
        if(contatore==3){
            Sleep(1500);
            if(mazzo[i].valore==contatore)
                SetColor(4);
            std::cout<<mazzo[i].valore<<" "<<mazzo[i].seme<<"   (3)"<<std::endl;
        }

        if(mazzo[i].valore==contatore){
            WINNING=0;
            SetColor(7);
            break;
        }else if(contatore==3){
            contatore=0;
        }
        contatore++;
    }
return WINNING;
}

//ESECUZIONE IN BASE ALLA MODALITA' SCELTA//
void Game_Mode(int mode){
    bool WINNING;
    int game_played=1;
    if(mode==1){
            SetColor(11);
            std::cout<<"Starting automatic game"<<std::endl;
            card *mazzo = Load_Deck_norm(deck);
            std::cout<<"Deck shuffling"<<std::endl;
            Sleep(1000);
            Deck_Shuffling_norm(mazzo);
            WINNING = Game_Extraction_auto(mazzo);

            while(WINNING==0){
                SetColor(11);
                std::cout<<std::endl<<"Deck RE-shuffling"<<std::endl;
                Sleep(1000);
                system("cls");
                SetColor(8);
                std::cout<<"Try number #";
                SetColor(6);
                std::cout<<game_played+1;
                Deck_Shuffling_norm(mazzo);
                game_played++;
                WINNING = Game_Extraction_auto(mazzo);
            }
        } //fine casistica 1 (AUTOMATIC GAME)

    if(mode==2){
        SetColor(11);
            std::cout<<"Starting One-shot game"<<std::endl;
            card *mazzo = Load_Deck_norm(deck);
            std::cout<<"Deck shuffling"<<std::endl;
            Sleep(1000);
            Deck_Shuffling_norm(mazzo);
            WINNING = Game_Extraction_slowed(mazzo);
        } //fine casistica 2 (ONE-SHOT GAME)

    if(mode==999){
            SetColor(8);
            std::cout<<"OPERATOR MODE"<<std::endl;
            std::cout<<"Initializing deck's loading"<<std::endl;
            card *mazzo = Load_Deck_op(deck);
            Print_Deck(mazzo); //TESTING//
            std::cout<<"Deck shuffling"<<std::endl;
            Deck_Shuffling_op(mazzo);
            Print_Deck(mazzo); //TESTING//
            WINNING = Game_Extraction_auto(mazzo);
        } //fine ccasistica 999 (OPERATOR MODE)

    Check_Win(WINNING, game_played, mode);
}


#endif // GAME_H