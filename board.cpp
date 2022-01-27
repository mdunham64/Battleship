//
// Created by MacGyver on 4/13/2020.
//

#include "board.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


void board::ReadFile(board *&Records, int &Size)
{
    try {//tries to import the csv file and set the objects with their respective ship detail
        ifstream in("ship_placement1_good.csv"); //change this line to access other ship layouts
        while (!in.eof()) {
            getline(in, Records[Size].TypeOfShip, ',');
            getline(in, Records[Size].Location, ',');
            in >> Records[Size].HorizOrVert;
            Size++;
        }
        Size--;
        throw Size; //I throw size to make sure there is an adequate amount of ships in the csv, further error checking happens in the place ships
    }

    catch( int Size){
        if(Size<5){
            cout << "Error in inputfile. Not enough ships to be placed..." << endl;
            exit(1);
        }
    }
}
char board::genRandomOrient(char array[]){ //function that returns a random char between V or H
    return array[rand()%2];
}
char board::genRandomLocation(char array[]){ //function that returns a random char between 1-9
    return array[rand() % 9];
}
string board::randomlocation(){
    char x[] = "ABCDEFGHIJ";
    char y[] = "123456789";
    string Xloc,Yloc;
    stringstream convertx,converty; //these two are used to convert the chars to strings, used below
    convertx << (genRandomLocation(x));
    convertx >> Xloc;
    converty << (genRandomLocation(y));
    converty >> Yloc;
    string newlocation;
    newlocation = Xloc+Yloc; //combines the two randomized strings to get a location string.
    return newlocation;
}
string board::randomorientation(){
    char alphanum[] = "HV";
    stringstream convert; //same concept as the random location function, changes char to string
    string randomorientation;
    convert << (genRandomOrient(alphanum));
    convert >> randomorientation;
    return randomorientation;
}
void board::CPUReadFile(board *&CPURecords, int &Size)
{ //uses above random functions to randomly place ships, error checking happens in the place functions
    CPURecords[0].TypeOfShip="Caarrier";
    CPURecords[0].Location=randomlocation();
    CPURecords[0].HorizOrVert=randomorientation();
    CPURecords[1].TypeOfShip="BBattleship";
    CPURecords[1].Location=randomlocation();
    CPURecords[1].HorizOrVert=randomorientation();
    CPURecords[2].TypeOfShip="CCruiser";
    CPURecords[2].Location=randomlocation();
    CPURecords[2].HorizOrVert=randomorientation();
    CPURecords[3].TypeOfShip="SSubmarine";
    CPURecords[3].Location=randomlocation();
    CPURecords[3].HorizOrVert=randomorientation();
    CPURecords[4].TypeOfShip="DDestroyer";
    CPURecords[4].Location=randomlocation();
    CPURecords[4].HorizOrVert=randomorientation();
}
//below is a function used to print object information for testing purposes.
void board::PrintFile(board *Records, int Size){
    for(int i=0; i < Size; i++){
        cout << Records[i].TypeOfShip << " ";
        cout << Records[i].Location << " ";
        cout << Records[i].HorizOrVert << " ";
    }
}
//below converts the string location into array locations.
void board::Convert(int &x, int &y, string Location) {
    switch (Location[0]) {
        case 'A':
            x = 0;
            break;
        case 'B':
            x = 1;
            break;
        case 'C':
            x = 2;
            break;
        case 'D':
            x = 3;
            break;
        case 'E':
            x = 4;
            break;
        case 'F':
            x = 5;
            break;
        case 'G':
            x = 6;
            break;
        case 'H':
            x = 7;
            break;
        case 'I':
            x = 8;
            break;
        case 'J':
            x = 9;
            break;
        default: //invalid location error check, will exit game.
            cout << "Invalid Location. The game will now Exit." << endl;
            exit(1);
    }
    switch (Location[1])
    {
        case '1':
            y = 0;
            break;
        case '2':
            y = 1;
            break;
        case '3':
            y = 2;
            break;
        case '4':
            y = 3;
            break;
        case '5':
            y = 4;
            break;
        case '6':
            y = 5;
            break;
        case '7':
            y = 6;
            break;
        case '8':
            y = 7;
            break;
        case '9':
            y = 8;
            break;
        case '0': //this case in particular is addressed in the player round turn, converting all string values of "10" or 0.
            y = 9;
            break;
        default: //invalid location check, will exit the game.
            cout << "Invalid Location. The game will now Exit." << endl;
            exit(1);
    }
}
//the below function makes the board look proper, and prints it out
void board::printBoard(string Board[10][10], int gridsize) {
    cout << "  A  B  C  D  E  F  G  H  I  J" << endl;
    for (int i = 0; i < gridsize; i++)
    { cout << i+1 << " ";
        for (int j = 0; j < gridsize; j++)
        {
            if (Board[i][j] == "_")
            {
                cout << Board[i][j] << "  ";
            }
            else if (Board[i][j][0] != ' ')
            {
                cout << Board[i][j][1] << "  ";
            }
            else if (Board[i][j][1] != ' ')
            {
                cout << Board[i][j][1] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

//base board creation, fills a 2D array with "_"
void board::createBoard(string Board[10][10], int boardSize){
    for(int i=0; i < boardSize; i++){
        for (int j=0; j<boardSize;j++){
            Board[i][j]="_";
        }
    }
}

void board::PlaceOnBoardCarrier(string playBoard[10][10],board Records[]) {

    int x, y;
    Convert(x, y, Records[0].Location); //converts the location string to a 2D array location
    for (int i = 0; i < 5; i++) {
        if (Records[0].HorizOrVert == "V") {//if its vertical
            if(y<6) //this makes sure the full ship can be placed on the board without wrapping to the next line
                playBoard[y + i][x] = "aa";
            else{
                cout << "Error in inputfile, carrier line." << endl;
                exit(1);
            }
        } else { //if its horizontal
            if(x<6) //makes sure the full ship can be placed without wrapping.
                playBoard[y][x + i] = "aa";
            else{
                cout << "Error in inputfile, carrier line." << endl;
                exit(1);
            }
        }
    }
}

//See carrier for more information, same principles apply with changed values for battleship
void board::PlaceOnBoardBattleship(string playBoard[10][10],board Records[]) {
    int x, y;
    Convert(x, y, Records[1].Location);
    for (int i = 0; i < 4; i++) {
        if (Records[1].HorizOrVert == "V") {
            if(y<7)
                playBoard[y + i][x] = "BB";
            else{
                cout << "Error in inputfile, Battleship line." << endl;
                exit(1);
            }
        } else {
            if(x<7)
                playBoard[y][x + i] = "BB";
            else{
                cout << "Error in inputfile, Battleship line." << endl;
                exit(1);
            }
        }
    }
}

//See carrier for more information, same principles apply with changed values for Cruiser
void board::PlaceOnBoardCruiser(string playBoard[10][10], board Records[]) {
    int x, y;
    Convert(x, y, Records[2].Location);
    for (int i = 0; i < 3; i++) {//CRUISER PLACEMENT
        if (Records[2].HorizOrVert == "V") {
            if(y<8)
                playBoard[y + i][x] = "CC";
            else{
                cout << "Error in inputfile, Cruiser line." << endl;
                exit(1);
            }
        } else {
            if(x<8)
                playBoard[y][x + i] = "CC";
            else{
                cout << "Error in inputfile, Cruiser line." << endl;
                exit(1);
            }
        }
    }
}

//See carrier for more information, same principles apply with changed values for Submarine
void board::PlaceOnBoardSubmarine(string playBoard[10][10],board Records[]) {
    int x, y;
    Convert(x, y, Records[3].Location);
    for (int i = 0; i < 3; i++) {//SUBMARINE PLACEMENT
        if (Records[3].HorizOrVert == "V") {
            if(y<8)
                playBoard[y + i][x] = "SS";
            else{
                cout << "Error in inputfile, Submarine line." << endl;
                exit(1);
            }
        } else {
            if(x<8)
                playBoard[y][x + i] = "SS";
            else{
                cout << "Error in inputfile, Submarine line." << endl;
                exit(1);
            }
        }
    }
}

//See carrier for more information, same principles apply with changed values for Destroyer
void board::PlaceOnBoardDestroyer(string playBoard[10][10], board Records[]){
    int x, y;
    Convert(x, y, Records[4].Location);
    for(int i=0; i<2; i++){//DESTROYER PLACEMENT
        if(Records[4].HorizOrVert == "V"){
            if(y<9)
                playBoard[y + i][x] = "DD";
            else{
                cout << "Error in inputfile, Destroyer line." << endl;
                exit(1);
            }
        }
        else{
            if(x<9)
                playBoard[y][x + i] = "DD";
            else{
                cout << "Error in inputfile, Destroyer line." << endl;
                exit(1);
            }
        }
    }
}


void board::CPUPlaceOnBoardCarrier(string playBoard[10][10],board Records[]) {

    int x, y;
    Convert(x, y, Records[0].Location); //converts the string location to a 2D array location
            if (Records[0].HorizOrVert == "V") { //if vertical
                //if the board is blank (ie "_") or if the ship will not fit on the board without wrapping.
                if (playBoard[y][x] == "_" && playBoard[y+1][x]=="_" && playBoard[y+2][x]=="_" && playBoard[y+3][x]=="_" && playBoard[y+4][x]=="_" && y<5) {
                    playBoard[y][x] = Records[0].TypeOfShip;
                    playBoard[y+1][x] = Records[0].TypeOfShip;
                    playBoard[y+2][x] = Records[0].TypeOfShip;
                    playBoard[y+3][x] = Records[0].TypeOfShip;
                    playBoard[y+4][x] = Records[0].TypeOfShip;
                } else {//else we must choose another randomlocation and run the function again.
                    Records[0].Location = randomlocation();
                    CPUPlaceOnBoardCarrier(playBoard, Records);
                }
            }
             else {//if horizontal
                 //if the board is blank (ie "_") or if the ship will not fit on the board without wrapping.
                if (playBoard[y][x] == "_" && playBoard[y][x+1]=="_" && playBoard[y][x+2]=="_" && playBoard[y][x+3]=="_" && playBoard[y][x+4]=="_" && x<5) {
                    playBoard[y][x] = Records[0].TypeOfShip;
                    playBoard[y][x+1] = Records[0].TypeOfShip;
                    playBoard[y][x+2] = Records[0].TypeOfShip;
                    playBoard[y][x+3] = Records[0].TypeOfShip;
                    playBoard[y][x+4] = Records[0].TypeOfShip;
                }else {//else we must choose another randomlocation and run the function again.
                    Records[0].Location = randomlocation();
                    CPUPlaceOnBoardCarrier(playBoard, Records);
                }
            }


}

//see CPU Carrier placement for more information. Same principles apply, but with changed values for Battleship
void board::CPUPlaceOnBoardBattleship(string playBoard[10][10],board Records[]) {

    int x, y;
    Convert(x, y, Records[1].Location);//CARRIER PLACEMENT
        if (Records[1].HorizOrVert == "V") {
            if (playBoard[y][x] == "_" && playBoard[y+1][x]=="_" && playBoard[y+2][x]=="_" && playBoard[y+3][x]=="_" && y<6) {
                playBoard[y][x] = Records[1].TypeOfShip;
                playBoard[y+1][x] = Records[1].TypeOfShip;
                playBoard[y+2][x] = Records[1].TypeOfShip;
                playBoard[y+3][x] = Records[1].TypeOfShip;

            } else {
                Records[1].Location = randomlocation();
                CPUPlaceOnBoardBattleship(playBoard, Records);
            }
        }
        else {
            if (playBoard[y][x] == "_" && playBoard[y][x+1]=="_" && playBoard[y][x+2]=="_" && playBoard[y][x+3]=="_" && x<6) {
                playBoard[y][x] = Records[1].TypeOfShip;
                playBoard[y][x+1] = Records[1].TypeOfShip;
                playBoard[y][x+2] = Records[1].TypeOfShip;
                playBoard[y][x+3] = Records[1].TypeOfShip;
            }else {
                Records[1].Location = randomlocation();
                CPUPlaceOnBoardBattleship(playBoard, Records);
            }
        }
}

//see CPU Carrier placement for more information. Same principles apply, but with changed values for Cruiser
void board::CPUPlaceOnBoardCruiser(string playBoard[10][10], board Records[]) {

    int x, y;
    Convert(x, y, Records[2].Location);//CARRIER PLACEMENT
        if (Records[2].HorizOrVert == "V") {
            if (playBoard[y][x] == "_" && playBoard[y+1][x]=="_" && playBoard[y+2][x]=="_" && y<7) {
                playBoard[y][x] = Records[2].TypeOfShip;
                playBoard[y+1][x] = Records[2].TypeOfShip;
                playBoard[y+2][x] = Records[2].TypeOfShip;
            } else {
                Records[2].Location = randomlocation();
                CPUPlaceOnBoardCruiser(playBoard, Records);
            }
        }
        else {
            if (playBoard[y][x] == "_" && playBoard[y][x+1]=="_" && playBoard[y][x+2]=="_" && x<7) {
                playBoard[y][x] = Records[2].TypeOfShip;
                playBoard[y][x+1] = Records[2].TypeOfShip;
                playBoard[y][x+2] = Records[2].TypeOfShip;
            }else {
                Records[2].Location = randomlocation();
                CPUPlaceOnBoardCruiser(playBoard, Records);
            }
        }
}

//see CPU Carrier placement for more information. Same principles apply, but with changed values for Submarine
void board::CPUPlaceOnBoardSubmarine(string playBoard[10][10],board Records[]) {

    int x, y;
    Convert(x, y, Records[3].Location);//CARRIER PLACEMENT
        if (Records[3].HorizOrVert == "V") {
            if (playBoard[y][x] == "_" && playBoard[y+1][x]=="_" && playBoard[y+2][x]=="_" && y<7) {
                playBoard[y][x] = Records[3].TypeOfShip;
                playBoard[y+1][x] = Records[3].TypeOfShip;
                playBoard[y+2][x] = Records[3].TypeOfShip;
            } else {
                Records[3].Location = randomlocation();
                CPUPlaceOnBoardSubmarine(playBoard, Records);
            }
        }
        else {
            if (playBoard[y][x] == "_" && playBoard[y][x+1]=="_" && playBoard[y][x+2]=="_" && x<7) {
                playBoard[y][x] = Records[3].TypeOfShip;
                playBoard[y][x+1] = Records[3].TypeOfShip;
                playBoard[y][x+2] = Records[3].TypeOfShip;
            }else {
                Records[3].Location = randomlocation();
                CPUPlaceOnBoardSubmarine(playBoard, Records);
            }
        }
}

//see CPU Carrier placement for more information. Same principles apply, but with changed values for Destroyer
void board::CPUPlaceOnBoardDestroyer(string playBoard[10][10], board Records[]){

    int x, y;
    Convert(x, y, Records[4].Location);//CARRIER PLACEMENT
        if (Records[4].HorizOrVert == "V") {
            if (playBoard[y][x] == "_" && playBoard[y+1][x]=="_" && y<8) {
                playBoard[y][x] = Records[4].TypeOfShip;
                playBoard[y+1][x] = Records[4].TypeOfShip;
            } else {
                Records[4].Location = randomlocation();
                CPUPlaceOnBoardDestroyer(playBoard, Records);
            }
        }
        else {
            if (playBoard[y][x] == "_" && playBoard[y][x+1]=="_" && x<8) {
                playBoard[y][x] = Records[4].TypeOfShip;
                playBoard[y][x+1] = Records[4].TypeOfShip;
            }else {
                Records[4].Location = randomlocation();
                CPUPlaceOnBoardDestroyer(playBoard, Records);
            }
        }
}

//set the board imported, to the board for the class
void board::setshipboard(string board[10][10]){
    for (int i=0; i< 10; i++)
        for (int j=0; j < 10 ; j++)
            shipboard[i][j] = board[i][j];
}







