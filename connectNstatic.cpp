// Creation date: November 20th, 2013
// Last modified: November 30th, 2013
// Authors: Tristian May, Jason Park, Danielle Sinha, Frank Su


#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// Gobal constants, used as min and max size of the game board. 
const int MAX_ARRAY_SIZE = 25;
const int MIN_ARRAY_SIZE = 8; 

// Prototypes of the staticFunctions

bool MakeMove (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int columnChosen);
bool DisplayBoard (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);
bool IntializeBoard(int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);
bool CheckWinner (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int numConnect, int columnChosen, int playerID);


int main()
{
  const int minRowsToWin = 4;
  // Array set up for connectNboard
  int connectNArray[MAX_ARAY_SIZE][MAX_ARRAY_SIZE] = {0};
  
  // Initialize and declare variables
  int numRows = 0;
  int numToConnect = 0;
  
  // First prompt
  // Size of board
  // Number in a row ro win
  do
  {
    cout << "Please enter the correct size of the board between " << MIN_ARRAY_SIZE << " <= numRows <= " << MAX_ARRAY_SIZE << " ";
    cin >> numRows;
  }while (( numRows < MIN_ARRAY_SIZE ) || ( numRows > MAX_ARRAY_SIZE ));
  
  do
  {
    cout << "Please enter the number of game pieces in a row needed to win the game";
    cin >> numToConnect;
    
  }while ( !(minRowsToWin <= numToConnect) || !(numToConnect <= numRows - minRowsToWin));
  
  if (!(InitializeBoard(connectNArray,numRows)));
  {
    exit(1);
  }
  
  return 0; 
}

// Definitions of staticFunctions

bool MakeMove (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int columnChosen)
{
  // If the move is not legal, then print a line of text to the screen "Illegal move"
  
  // Print a line of text tot he screen that says "Red has moved" or "Black has moved"
}
bool DisplayBoard (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
  
}
bool IntializeBoard(int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
  
}
bool CheckWinner (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int numConnect, int columnChosen, int playerID)
{
  
}
