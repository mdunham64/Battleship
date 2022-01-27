//
// Created by MacGyver on 4/15/2020.
//

#ifndef BATTLESHIP2312_PLAYER_H
#define BATTLESHIP2312_PLAYER_H


#include "board.h"

class player : public board {
private:
    string name;
public:
    player(string _name);
    string getName(){return name;}
    void roundhit(string cpuBoard[10][10], string playerguessBoard[10][10],string location);
    void shipsunk(string Board[10][10]);
    void computerroundhit(string pBoard[10][10], string cguessBoard[10][10]);
};


#endif //BATTLESHIP2312_PLAYER_H
