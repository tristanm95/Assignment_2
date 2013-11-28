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
	int *placementp = NULL;
	int *placementX = NULL;
	int *placementY = NULL;
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
	
	for(i = 0; i < (numRowsInBoard - 1); i ++)
	{
		if(connectNBoard[i][columnChosen] == 'B' && playerID == 1))
		{
			placementp = connectNBoard[i][columnChosen];
			break;
		}
		if(connectNBoard[i][columnChosen] == 'R' && playerID == 2))
		{
			placementp = connectNBoard[i][columnChosen];
			break;
		}
		
	}
	
	//Horizontal Checker to the right of columnChosen
	for(i = (placementp + 1); i < (numRowsInBoard - 1); i++)
	{
		if(i == 'B' && playerID == 2)
		{
			afterCount += 1;
		}
		else if(i == 'R' && playerID == 1)
		{
			afterCount += 1;
		}
		else
		{
			break;
		}
	}
	
	//Horizontal Checker to the left of columnChosen
	for(i = (placementp - 1); i > 0; i--)
	{
		if(i == 'B' && playerID == 2)
		{
			beforeCount += 1;
		}
		else if(i == 'R' && playerID == 1)
		{
			beforeCount += 1;
		}
		else
		{
			break;
		}
	}
	
	if((beforeCount + afterCount + 1) >= numConnect)
	{
		return true;
	}
	
	for(i = 0; i < numRowsInBoard; i++)
	{
		for(j = 0; j < numRowsInBoard; j++)
		{
			if(connectNBoard[i][columnChosen] == 'B' && playerID == 1))
			{
				placementp = connectNBoard[i][columnChosen];
				break;
			}
			if(connectNBoard[i][columnChosen] == 'R' && playerID == 2))
			{
				placementp = connectNBoard[i][columnChosen];
				break;
			}
		}
	}
	//Diagonal Checker to the top right of columnChosen
	do
	{
		i = placementp;
		j = placementp;
		if(connectNBoard[i+1][j+1] == 'R' && playerID == 2)
		{
			afterCount += 1;
			j++;
			i++;
		}
		else if(connectNBoard[i+1][j+1] == 'B' && playerID == 1)
		{
			afterCount += 1;
			j++;
			i++;
		}
		else
		{
			i++;
			j++;
			break;
		}
	}
	while(j < numRowsInBoard && i < numRowsInboard);
	
	//Diagonal Checker to the bottom left of columnChosen
	do
	{
		if(connectNBoard[i-1][j-1] == 'R' && playerID == 2)
		{
			beforeCount += 1;
			j--;
			i--;
		}
		else if(connectNBoard[i-1][j-1] == 'B' && playerID == 1)
		{
			beforeCount += 1;
			j--;
			i--;
		}
		else
		{
			j--;
			i--;
			break;
		}
	}
	while(j > 0 && i > 0);
	
	if(beforeCount + afterCount + 1 >= numConnect)
	{
		return true;
	}
	
	//Diagonal Checker to the bottom right of columnChosen
	do
	{
		if(connectNBoard[i-1][j+1] == 'R' && playerID == 2)
		{
			beforeCount += 1;
			j++;
			i--;
		}
		else if(connectNBoard[i-1][j+1] == 'B' && playerID == 1)
		{
			beforeCount += 1;
			j++;
			i--;
		}
		else
		{

			break;
		}
	}
	while(j < numRowsInBoard && i > 0);
	
	//Diagonal CHecker to the top left of oclumnChosen
	do
	{
		if(connectNBoard[i+1][j-1] == 'R' && playerID == 2)
		{
			beforeCount += 1;
			j--;
			i++;
		}
		else if(connectNBoard[i+1][j-1] == 'B' && playerID == 1)
		{
			beforeCount += 1;
			j--;
			i++;
		}
		else
		{

			break;
		}
	}
	while(j < numRowsInBoard && i > 0);
	
	if((beforeCount + afterCount + 1) >= numConnect)
	{
		return true;
	}

}
