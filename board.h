//
// Created by MacGyver on 4/13/2020.
//

#ifndef BATTLESHIP2312_BOARD_H
#define BATTLESHIP2312_BOARD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class board {
protected:
    string TypeOfShip;
    string Location;
    string HorizOrVert;
    string shipboard[10][10];
public:
    void PrintFile(board *Records, int Size);
    void Convert(int &x, int &y, string Location);
    void printBoard(string Board[10][10],int boardSize);
    void createBoard(string Board[10][10], int boardSize);
    void PlaceOnBoardCarrier(string Board[10][10], board Records[]);
    void PlaceOnBoardBattleship(string Board[10][10], board Records[]);
    void PlaceOnBoardCruiser(string Board[10][10], board Records[]);
    void PlaceOnBoardSubmarine(string Board[10][10], board Records[]);
    void PlaceOnBoardDestroyer(string Board[10][10], board Records[]);
    void CPUPlaceOnBoardCarrier(string Board[10][10], board Records[]);
    void CPUPlaceOnBoardBattleship(string playBoard[10][10],board Records[]);
    void CPUPlaceOnBoardCruiser(string playBoard[10][10], board Records[]);
    void CPUPlaceOnBoardSubmarine(string playBoard[10][10],board Records[]);
    void CPUPlaceOnBoardDestroyer(string playBoard[10][10], board Records[]);
    void ReadFile(board *&Records, int &Size);
    void CPUReadFile(board *&CPURecords, int &Size);
    string randomorientation();
    string randomlocation();
    char genRandomLocation(char *array);
    char genRandomOrient(char *array);
    void setshipboard(string board[10][10]);
};


#endif
