#include <iomanip>
#include <string>
#include <cmath>

include namespace std;

//Global Variable Added
const int MAX_ARRAY_SIZE = 25;


//prototypes of the staticFunctions

bool MakeMove (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int columnChosen);
bool DisplayBoard (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);
bool intializeBoard(int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);
bool CheckWinner (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int numConnect, int columnChosen, int playerID);

//Definitions of staticFunctions

bool MakeMove (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int columnChosen)
{
  //if the move is not legal, then print a line of text to the screen "Illegal move"
  
  //print a line of text tot he screen that says "Red has moved" or "Black has moved"
}
bool DisplayBoard (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
  
}
bool intializeBoard(int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
  
}
bool CheckWinner (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int numConnect, int columnChosen, int playerID)
{
  
}

