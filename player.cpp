//
// Created by MacGyver on 4/15/2020.
//

#include "player.h"
#include "board.h"
#include <string>
#include <iostream>

using namespace std;


player::player(string _name) {name=_name;}


//below determines where the user will hit based on an input.
void player::roundhit(string cpuBoard[10][10], string playerguessBoard[10][10],string location){
    int x, y;
    //below is changing all string locations of 10, to 0 for use in our convert function. This way it can recognize the 10th row as a char
    if (location == "A10")
        location = "A0";
    if (location == "B10")
        location = "B0";
    if (location == "C10")
        location = "C0";
    if (location == "D10")
        location = "D0";
    if (location == "E10")
        location = "E0";
    if (location == "F10")
        location = "F0";
    if (location == "G10")
        location = "G0";
    if (location == "H10")
        location = "H0";
    if (location == "I10")
        location = "I0";
    if (location == "J10")
        location = "J0";
    Convert(x,y,location);

    if (cpuBoard[y][x]!="_"){//if the location is not empty its a hit
        cout << "Hit!" << endl;
        playerguessBoard[y][x] = "OO"; //change guessing board to reflect a hit
        cpuBoard[y][x] = "OO"; //change ship board to reflect hit
    }
    else{
        cout << "Miss!" << endl;
        playerguessBoard[y][x] = "XX"; //change guess board
    }

}

void player::computerroundhit(string pBoard[10][10], string cguessBoard[10][10]){
    string location;
    int x, y;
    location = randomlocation(); //randomly chooses location hit
    Convert(x,y,location);
    cout << "The computer chooses " << location << endl;

    if (pBoard[y][x]!="_"){ //if location is not empty on board
        cout << "The Computer hit!" << endl;
        cguessBoard[y][x] = "OO"; //reflect hit on computer guessboard
        pBoard[y][x] = "OO"; //reflect hit on player ship board
    }
    else{
        cout << "The Computer Misses!" << endl;
        pBoard[y][x] = "XX";
    }
}

void player::shipsunk(string Board[10][10]){
    //counters for ship values
    int carriercount=0;
    int battleshipcount=0;
    int cruisercount=0;
    int submarinecount=0;
    int destroyercount=0;
    for(int i=0; i < 10; i++)
        for(int j=0; j <10; j++){ //this loop counts all ship spots still on the board
            if (Board[i][j]=="Caarrier"){
                carriercount++;
            }
            if (Board[i][j]=="BBattleship"){
                battleshipcount++;
            }
            if (Board[i][j]=="CCruiser"){
                cruisercount++;
            }
            if (Board[i][j]=="SSubmarine"){
                submarinecount++;
            }
            if (Board[i][j]=="DDestroyer"){
                destroyercount++;
            }
        }
    //the below if statements read out if a ship is no longer on the board (ie the spot is a OO now) it is in fact sunk.
    if(carriercount==0)
        cout << "A Carrier has been sunk so far." << endl;
    if(battleshipcount==0)
        cout << "A Battleship has been sunk so far." << endl;
    if(cruisercount==0)
        cout << "A Cruiser has been sunk so far." << endl;
    if(submarinecount==0)
        cout << "A Submarine has been sunk so far." << endl;
    if(destroyercount==0)
        cout << "A Destroyer has been sunk so far." << endl;
}
