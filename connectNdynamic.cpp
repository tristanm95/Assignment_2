#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

include namespace std;

bool InitializeBoard(int **connectNBoard,  int numRowsInBoard );
bool MakeMove(int **connectNBoard, int numRowsInBoard,  int player, int columnChosen);
bool DisplayBoard(int **connectNBoard,  int numRowsInBoard);
bool CheckWinner(int **connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int player );

int main()
{
	char **connectNBoardpp;
	int i = 0;
	int j = 0;
	int numRows = 0;
	int numConnect = 0;
	int numToConnect = 0;
	int playerID = 0;
	int forfeitIndex = 0;
	int turnIndex = 0;
	
	
	do
	{
		cout << "Please enter the size of the board" << endl;
		cout << "8 <= numRows <= 25";
	}
	while(!(cin >> numRows) || !(8 <= numRows && numRows <= 25));
	
	do
	{
		cout << "Please enter the number of pieces in a row to win" << endl;
		cout << "4 <= numToConnect <= numRows - 4";
	}
	while(!(cin >> numToConnect) || !(4 <= numToConnect <= (numRows - 4)));
	
	connectNBoardpp = new int* [numRows];
	
	for(index = 0; index < numRows; index++)
	{
		*(connectNBoardpp + index) = new int [numRows];
	}
	
	if(!(InitializeBoard(connecNBoardpp, numRows))
	{
		exit(1)
	}
	
	
	//Put this into a loop
	for(turnIndex = 0; turnIndex < 99999999999999; turnIndex ++)
	{

		if(!(MakeMove(connectNBoardpp, numRows, playerID, columnChosen)))
		{
			forfeitIndex++;
			if(forfeitIndex <= 3)
			{
				if(playerID == 1)
				{
					cout << "Red has forfeited a turn" << endl;
					continue;
				}
				if(playerID == 2)
				{
					cout << "Black has forfeited a turn" << endl;
					continue;
				}
			}
		}
		
		if(CheckWinner(connectNBoardpp, numRows, numToConnect, columnChosen, playerID))
		{
			if(playerID == 1)
			{
				cout << "Red has won";
				break;
			}
			if(playerID == 2)
			{
				cout << " Black has won";
				break;
			}
		}
		
		if(!(DisplayBoard(connectNBoardpp, numRows)))
		{
			cerr << "Could not display board";
			exit(2);
		}
	}
	
	
	for(i = 0; i < numRows; i++)
	{
		delete [] connectNBoardpp[i];
		connectNBoard[i] = NULL;
	}
	
	delete [] connectNBoardpp;
	return 0;
}
