#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//gobal constants, used as min and max size of the game board. 
const int MAX_ARRAY_SIZE = 25;
const int MIN_ARRAY_SIZE = 8; 

//prototypes of the staticFunctions

bool MakeMove (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int columnChosen);
bool DisplayBoard (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);
bool IntializeBoard(int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);
bool CheckWinner (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int numConnect, int columnChosen, int playerID);


int main()
{
  const int minRowsToWin = 4;
  //array set up for connectNboard
  int connectNArray[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {0};
  
  //initialize and declare variables
  int numRows = 0;
  int numToConnect = 0;
  
  //first prompt
  do
  {
    cout << "Please enter the correct size of the board between " << MIN_ARRAY_SIZE << " <= numRows <= " << MAX_ARRAY_SIZE << " ";
        cin.clear();
        cin.sync();
  }while ((!(cin >> numRows)) || ( numRows < MIN_ARRAY_SIZE ) || ( numRows > MAX_ARRAY_SIZE ) );
  
  do
  {
    cout << "Please enter the number of game pieces in a row needed to win the game";
    cin.clear();
        cin.sync();
    
  }while (  !(cin >> numToConnect)|| !(minRowsToWin <= numToConnect) || !(numToConnect <= numRows - minRowsToWin));
  
  if (!(IntializeBoard(connectNArray,numRows)))
  {
        exit(1);  
  }

  return 0; 
}

//Definitions of staticFunctions

bool IntializeBoard(int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
	int i = 0;
	int j = 0;

	for ( i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		for ( j = 0; j < MAX_ARRAY_SIZE; j++)
		{
			connectNBoard[i][j] = 0;

			if((connectNBoard[i][j] < 0) || (connectNBoard[i][j] > 2))
			{
				cerr << "The board was not initialized";
				return false;
			}
		}
		
	}
	return true;
}

bool DisplayBoard (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
	int i = 0;
	int j = 0;

	cout << endl << setw(3) << " ";
	for (i = 0; i < numRowsInBoard; i++)
	{
		cout << setw(3) << i;
	}
	cout << endl;

	for (i = 0; i < numRowsInBoard; i++)
	{
		cout << left << setw(3) << i;
		for (j = 0; j < numRowsInBoard; j++)
		{
			if ( (j % (numRowsInBoard + 1)) == numRowsInBoard)
			{
				cout << endl;
			}
			if (connectNBoard[i][j] == 1)//R, 2 = B
			{
				cout << setw(3) << right << "R";
			}else if (connectNBoard[i][j] == 2)
			{
				cout << setw(3) << right << "B"; 
			}else 
			{
				cout << setw(3) << right << "o";
			}
		}
	}
	return true;
}

bool MakeMove (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int columnChosen)
{
	//red must go first
	int i = 0;
	int j= 0;
	
	if (columnChosen < 0 || (columnChosen > numRowsInBaord))
	{
		cerr << "Illegal Move";
		return false;
	}

	for (i = (numRowsInBoard - 1); i >= 0; i--)
	{
		if (connectNBoard[i][columnChosen] == 0)
		{
			if (player == 1)
			{
				connectNBoard[i][columnChosen] = 1;
				cout << "Red has moved";
				return true;
			}else if (player == 2)
			{
				connectNBoard[i][columnChosen] = 2;
				cout << "Black has moved";
				return true;
			}else 
			{
				return false;
			}
		}
	}
		
	return true;
}


bool CheckWinner (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int numConnect, int columnChosen, int playerID)
{

	return true;
}
