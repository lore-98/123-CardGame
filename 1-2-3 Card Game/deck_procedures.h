//HEADER PER LE PROCEDURE RELATIVE AL DECK//
#ifndef DECKPROC_H
#define DECKPROC_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "deck_definition.h"
#include "card_definition.h"
#include "utils.h"
#include "time.h"


//CARICAMENTO DEL DECK NORMAL MODE//
card* Load_Deck_norm(card deck[]){

    for(int i=1;i<=NUMERO_CARTE;i++){
        card newcard;
        if(i<=13){
            newcard.seme="Cuori";
            newcard.valore=i;
        }
        if(i>13 && i<=26){
            newcard.seme="Quadri";
            newcard.valore=i-13; 
        }
        if(i>26 && i<=39){
            newcard.seme="Fiori";
            newcard.valore=i-26; 
        }
        if(i>39 && i<=NUMERO_CARTE){
            newcard.seme="Picche";
            newcard.valore=i-39; 
        }
    deck[i-1]=newcard;
    }

    return deck;
}

//CARICAMENTO DEL DECK OPERATOR MODE//
card* Load_Deck_op(card deck[]){

    std::cout<<"Loading deck"<<std::endl;
    for(int i=1;i<=NUMERO_CARTE;i++){
        card newcard;
        if(i<=13){
            newcard.seme="Cuori";
            newcard.valore=i;
        }
        if(i>13 && i<=26){
            newcard.seme="Quadri";
            newcard.valore=i-13; 
        }
        if(i>26 && i<=39){
            newcard.seme="Fiori";
            newcard.valore=i-26; 
        }
        if(i>39 && i<=NUMERO_CARTE){
            newcard.seme="Picche";
            newcard.valore=i-39; 
        }
    deck[i-1]=newcard;
    }
    std::cout<<"Deck loaded SUCCESSFULLY"<<std::endl;

    return deck;
}

//MESCOLAMENTO DEL DECK NORMAL MODE//
void Deck_Shuffling_norm(card deck[]){

    card temp;
    srand(time(NULL)); //inizializzazione del seme
    int times = rand() % 1000;
    for (int i=0;i<times;i++){
        int random_index1 = rand() % (NUMERO_CARTE-1); //indice ottenuto randomicamente
        int random_index2 = rand() % (NUMERO_CARTE-1); //indice ottenuto randomicamente
        temp = deck[random_index1];
        deck[random_index1] = deck[random_index2];
        deck[random_index2] = temp;
    }
}

//MESCOLAMENTO DEL DECK OPERATOR MODE//
void Deck_Shuffling_op(card deck[]){

    std::cout<<"Shuffling"<<std::endl;
    card temp;
    srand(time(NULL)); //inizializzazione del seme
    int times = rand() % 1000;
    SetColor(7);
    std::cout<<"times : "<<times<<std::endl;
    SetColor(8);
    for (int i=0;i<times;i++){
        int random_index1 = rand() % (NUMERO_CARTE-1); //indice ottenuto randomicamente
        int random_index2 = rand() % (NUMERO_CARTE-1); //indice ottenuto randomicamente
        temp = deck[random_index1];
        deck[random_index1] = deck[random_index2];
        deck[random_index2] = temp;
    }
    std::cout<<"Deck shuffled SUCCESSFULLY"<<std::endl;
}

//TESTING: STAMPA DEL DECK//
void Print_Deck(card deck[]){
    SetColor(7);
    int card_counter=0;
    std::cout<<"TESTING: Deck's printing"<<std::endl<<std::endl;
    
    for(int i=0;i<NUMERO_CARTE;i++){
        std::cout<<deck[i].valore<<" "<<deck[i].seme<<std::endl;
        card_counter++;
    }
    std::cout<<"# Cards : "<<card_counter<<std::endl;
    SetColor(8);
}

#endif // DECKPROC_H