#include <iostream>
#include "board.h"
#include "player.h"
#include <string>
#include <vector>
#include <ctime>


using namespace std;

int main() {
    //below sets up the seed for a random number generator
    long seed = time(nullptr);
    srand(seed);
    int Size = 0;
    //name input for player class
    string setname;
    //this creates an array of objects (for board) so we can place our ships.
    board *Records = new board[100];
    cout << "Enter your name please: ";
    cin >> setname;
    //create player object.
    player player1("mac");
    //reads in the file and sets the object array for ships
    player1.ReadFile(Records,Size);
    //pshipboard is the player's ship board.
    string pshipBoard[10][10];
    int gridsize = 10;
    //the below function calls create the board, place all ships on the board, then sets the shipboard.
    player1.createBoard(pshipBoard,gridsize);
    player1.PlaceOnBoardCarrier(pshipBoard,Records);
    player1.PlaceOnBoardBattleship(pshipBoard,Records);
    player1.PlaceOnBoardCruiser(pshipBoard,Records);
    player1.PlaceOnBoardSubmarine(pshipBoard,Records);
    player1.PlaceOnBoardDestroyer(pshipBoard,Records);
    player1.setshipboard(pshipBoard);
    cout << endl;

    //same setup as before, but with the computer.
    player computer("computer");
    string cshipBoard[10][10];
    board *CPURecords = new board[100];
    computer.createBoard(cshipBoard,gridsize);
    computer.CPUReadFile(CPURecords,Size);
    computer.CPUPlaceOnBoardCarrier(cshipBoard,CPURecords);
    computer.CPUPlaceOnBoardBattleship(cshipBoard,CPURecords);
    computer.CPUPlaceOnBoardCruiser(cshipBoard,CPURecords);
    computer.CPUPlaceOnBoardSubmarine(cshipBoard,CPURecords);
    computer.CPUPlaceOnBoardDestroyer(cshipBoard,CPURecords);
    computer.setshipboard(cshipBoard);
    cout << endl;

    cout << "The computer has finished setting its board." << endl;
    cout << "LETS PLAY!" << endl;
    cout << endl;

    //below is a boolean to loop the game until a winner is announced.
    bool game = true;
    string pguessBoard[10][10];
    player1.createBoard(pguessBoard,gridsize);
    string cguessBoard[10][10];
    computer.createBoard(cguessBoard,gridsize);


    while(game) {//everything below is one turn of play. It will be looped until all ships have been destroyed.
        string newlocation;
        cout << "Your ship Board" << endl;
        player1.printBoard(pshipBoard, gridsize);
        cout << endl;
        cout << "Your guessing Board" << endl;
        player1.printBoard(pguessBoard, gridsize);
        cout << "Please enter where you want to hit(ex. A4). You may enter Q if you wish to surrender: " << endl;
        cin >> newlocation;
        //this checks to see if the hit location is a Q then displays the ship board for the CPU and the player's guessing board
        if (newlocation == "Q") {
            cout << player1.getName() << " has quit the game..." << endl;
            cout << "Your ending guess board:" << endl;
            player1.printBoard(pguessBoard, gridsize);
            cout << endl;
            cout << "The computers Ship board:" << endl;
            computer.printBoard(cshipBoard, gridsize);
            break;
        }
            player1.roundhit(cshipBoard, pguessBoard, newlocation);
            player1.shipsunk(cshipBoard);
            //the below counters keep track of the ships sunk, and who wins the game at the end
            int ccounter = 0;
            int pcounter = 0;
            cout << endl;
            cout << "The computer will take its turn now..." << endl;

            computer.computerroundhit(pshipBoard, cguessBoard);
            cout << endl;
            //from here below is a check to see if the game has ended.
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++) {
                    if (pshipBoard[i][j] == "OO")
                        ccounter++; //this tally's up the computers hits
                }
            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 10; j++) {
                    if (cshipBoard[i][j] == "OO")
                        pcounter++; //this tally's up the players hits
                }
            if (pcounter == 17) { //if the player hit 17 times (all ship locations) the user wins
                cout << player1.getName() << " Wins!" << endl;
                break;
            }
            if (ccounter == 17) { //same as above but for the computer
                cout << "The Computer wins!" << endl;
                break;
            }
    }
    return 0;
}