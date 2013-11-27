#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

include namespace std;

bool InitializeBoard(int** connectNBoard,  int numRowsInBoard);
bool MakeMove(int** connectNBoard, int numRowsInBoard,  int player, int columnChosen);
bool DisplayBoard( int** connectNBoard,  int numRowsInBoard);
bool CheckWinner( int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int player );


bool InitializeBoard(int** connectNBoard,  int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	
	for(i = 0; i < numRowsInBoard; i++)
	{
		for(j = 0; j < numRowsInBoard; j++)
		{
			if(!(connectNBoard[i][j] = 'o'))
			{
				cerr << "The board was not initialized";
				return false;
			}
		}
	}


	return true;
}

bool MakeMove(int** connectNBoard, int numRowsInBoard,  int playeID, int columnChosen)
{
	int i = 0;
	int j = 0;
	
	if(columnChosen < 0 || columnChosen > numRowsInBoard)
	{
		cout << "Illegal Move" << endl;
		return false;
	}
	
	if(connectNBoard[columnChosen][0] != 'o')
	{
		cout << "Illegal Move" << endl
		return false;
	}
	
	for(i = (numRowsInBoard - 1); i >= 0; i--)
	{
		if(connectNBoard[i][columnChosen] == 'o')
		{
			if(playeID == 1)
			{
				connectNBoard[i][columnChosen] = 'R';
				cout << "Red has moved";
				return true;
			}
			else if(playeID == 2)
			{
				connectNBoard[i][columnChosen] = 'B';
				cout << "Black has moved";
				return true;
			}
			else
			{
				cerr << "Something went wrong in the MakeMove function";
				return false;
			}
			
		}
	}
	
	return false;
}

bool DisplayBoard( int** connectNBoard,  int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	
	for(i = 0; i < numRowsInBoard; i++)
	{
		cout << setw(3) << right << i;
	}
	cout << endl
	
	for(i = 0; i < numRowsInBoard; i++)
	{
		cout << setw(3) << right << i;
		for(j = 0; j < numRowsInboard)
		{
			cout << setw(3) << right << connectNBoard[i][j];
		}
	}
	return true;
}

bool CheckWinner(int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int playerID)
{
	int afterCount = 0;
	int beforeCount = 0;
	int vertCount = 0;
	int i = 0;
	int j = 0;
	
	if(columnChosen > (numRowsInBoard + 1) || columnChosen < 0)
	{
		cerr << "ERROR: invalid column chosen, cannot check for winner";
		return false;
	}
	
	//Vertical Checker
	for(i = (numRowsInBoard - 1); i > 0; i++)
	{
		if(connectNBoard[i][columnChosen] != 'o')
		{
			vertCount++;
		}
		if(vertCount >= numConnect)
		{
			return true;
		}
	}
	
	//Horizontal Checker to the right of columnChosen
	
	//Horizontal Checker to the left of columnChosen
	
	//Diagonal Checker to the top right of columnChosen
	
	//Diagonal Checker to the bottom left of columnChosen
	
	//Diagonal Checker to the bottom right of columnChosen
	
	//Diagonal CHecker to the top left of oclumnChosen

}
