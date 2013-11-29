#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

bool InitializeBoard(int **connectNBoard,  int numRowsInBoard );
bool MakeMove(int **connectNBoard, int numRowsInBoard,  int player, int columnChosen);
bool DisplayBoard(int **connectNBoard,  int numRowsInBoard);
bool CheckWinner(int **connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int player );

int main()
{
	int **connectNBoardpp;
	int i = 0;
	int index = 0;
	int j = 0;
	int numRows = 0;
	int numConnect = 0;
	int numToConnect = 0;
	int playerID = 0;
	int colChosen = 0;
	int forfeitIndex = 0;
	int turnIndex = 0;
	
	
	do
	{
		cout << "Please enter the size of the board" << endl;
		cout << "8 <= numRows <= 25: ";
		cin.clear();
		cin.sync();
	}
	while(!(cin >> numRows) || !(8 <= numRows && numRows <= 25));
	
	do
	{
		cout << "Please enter the number of pieces in a row to win" << endl;
		cout << "4 <= numToConnect <= numRows - 4: ";
		cin.clear();
		cin.sync();
	}
	while(!(cin >> numToConnect) || !(4 <= numToConnect && numToConnect <= (numRows - 4)));
	
	connectNBoardpp = new int* [numRows];
	
	for(index = 0; index < numRows; index++)
	{
		*(connectNBoardpp + index) = new int [numRows];
	}
	
	if(!(InitializeBoard(connectNBoardpp, numRows)))
	{		
		for(i = 0; i < numRows; i++)
		{
			delete [] connectNBoardpp[i];
			connectNBoardpp[i] = NULL;
		}
		
		delete [] connectNBoardpp;
		exit(1);
	}
	
	cout << "Red goes first";
	playerID = 1;

	for(turnIndex = 0; turnIndex < (numRows * numRows); turnIndex++)
	{
		cin.clear();
		cin.sync();
		cout << endl;
		if(!(DisplayBoard(connectNBoardpp, numRows)))
		{
			cerr << "ERROR: COULD NOT DISPLAY BOARD";
			for(i = 0; i < numRows; i++)
			{
				delete [] connectNBoardpp[i];
				connectNBoardpp[i] = NULL;
			}
	
			delete [] connectNBoardpp;
			exit(3);
		}
		cout << "Enter the column number you wish to place a piece within ";
		cin >> colChosen;

		while(!(MakeMove(connectNBoardpp, numRows, playerID, colChosen)) && forfeitIndex < 3)
		{
			forfeitIndex += 1;
			cin.clear();
			cin.sync();
			cin >> colChosen;
		}

		if(forfeitIndex >= 3 && playerID == 1)
		{
			cout << endl << "Red has forfeited their move";
			playerID = 2;
			forfeitIndex = 0;
			continue;
		}
		if(forfeitIndex >= 3 && playerID == 2)
		{
			cout << endl << "Black has forfeited their move";
			playerID = 1;
			forfeitIndex = 0;
			continue;
		}
		forfeitIndex = 0;

		if(CheckWinner(connectNBoardpp, numRows, numToConnect, colChosen, playerID))
		{
			if(playerID == 1)
			{
				cout << endl << "Red has won";
				break;
			}
			if(playerID == 2)
			{
				cout << endl << "Black has won";
				break;
			}
		}
		

		if(playerID == 1)
		{
			playerID = 2;
		}
		else
		{
			playerID = 1;
		}
	}
	
	
	for(i = 0; i < numRows; i++)
	{
		delete [] connectNBoardpp[i];
		connectNBoardpp[i] = NULL;
	}
	
	delete [] connectNBoardpp;
	return 0;
}

bool InitializeBoard(int** connectNBoard,  int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	
	for(i = 0; i < numRowsInBoard; i++)
	{
		for(j = 0; j < numRowsInBoard; j++)
		{
			connectNBoard[i][j] = 0;
			if(connectNBoard[i][j] < 0 || connectNBoard[i][j] > 2)
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
	
	if(columnChosen < 0 || columnChosen >= numRowsInBoard)
	{
		cout << "Illegal Move" << endl;
		cout << "That column is not on the board: try again" << endl;
		cout << "Enter the column number where you want to put your piece" << endl;
		cout << "Column number should be >=0 and <= " << numRowsInBoard - 1 << " " << endl;
		return false;
	}
	
	if(connectNBoard[0][columnChosen] != 0)
	{
		cout << "Illegal Move" << endl;
		cout << "Column" << columnChosen << "is already completely full try again" << endl;
		cout << "Enter column number where you want to put your piece" << endl;
		cout << "Column number should be >= 0 and <= " << numRowsInBoard - 1 << " " << endl;
		return false;
	}
	
	for(i = (numRowsInBoard - 1); i >= 0; i--)
	{
		if(connectNBoard[i][columnChosen] == 0)
		{
			if(playeID == 1)
			{
				connectNBoard[i][columnChosen] = 1;
				cout << "Red has moved";
				return true;
			}
			else if(playeID == 2)
			{
				connectNBoard[i][columnChosen] = 2;
				cout << "Black has moved";
				return true;
			}
			else
			{
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

	cout << endl << setw(3) << " ";

	for(i = 0; i < numRowsInBoard; i++)
	{
		cout << setw(3) << right << i;
	}
	cout << endl;
	
	for(i = 0; i < numRowsInBoard; i++)
	{
		cout << setw(3) << left << i;
		for(j = 0; j < numRowsInBoard; j++)
		{
			if(j%(numRowsInBoard + 1) == numRowsInBoard)
			{
				cout << endl;
			}

			if(connectNBoard[i][j] == 1)
			{
				cout << setw(3) << right << 'R';
			}
			else if(connectNBoard[i][j] == 2)
			{
				cout << setw(3) << right << 'B';
			}
			else
			{
				cout << setw(3) << right << 'o';
			}
		}
		cout << endl;
	}
	cout << endl;
	return true;
}

bool CheckWinner(int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int playerID)
{
	int afterCount = 0;
	int beforeCount = 0;
	int vertLOC = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
	if(columnChosen > (numRowsInBoard + 1) || columnChosen < 0)
	{
		cerr << "ERROR: invalid column chosen, cannot check for winner";
		return false;
	}

	for(i = 0; i < numRowsInBoard; i++)
	{
		if(connectNBoard[i][columnChosen] == 1 && playerID == 1)
		{
			vertLOC = i;
			break;
		}
		else if(connectNBoard[i][columnChosen] == 2 && playerID == 2)
		{
			vertLOC = i;
			break;
		}
		else if(connectNBoard[i][columnChosen] != 0)
		{
			break;
		}
		else
		{
			continue;
		}
		
	}

	//Vertical Checker Below
	for(i = vertLOC + 1; i < numRowsInBoard; i++)
	{
		if(connectNBoard[i][columnChosen] == 2 && playerID == 2)
		{
			beforeCount += 1;
		}
		else if(connectNBoard[i][columnChosen] == 1 && playerID == 1)
		{
			beforeCount += 1;
		}
		else
		{
			break;
		}
	}
	
	
	//Vertical Checker above
	for(i = vertLOC - 1; i >= 0; i--)
	{
		if(connectNBoard[i][columnChosen] == 2 && playerID == 2)
		{
			beforeCount += 1;
		}
		else if(connectNBoard[i][columnChosen] == 1 && playerID == 1)
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
	
	beforeCount = 0;
	afterCount = 0;


	//Horizontal Checker to the right of columnChosen
	for(i = columnChosen + 1; i < numRowsInBoard; i++)
	{
		if(connectNBoard[vertLOC][i] == 2 && playerID == 2)
		{
			afterCount += 1;
		}
		else if(connectNBoard[vertLOC][i] == 1 && playerID == 1)
		{
			afterCount += 1;
		}
		else
		{
			break;
		}
	}
	
	//Horizontal Checker to the left of columnChosen
	for(i = columnChosen - 1; i >= 0; i--)
	{
		if(connectNBoard[vertLOC][i] == 2 && playerID == 2)
		{
			beforeCount += 1;
		}
		else if(connectNBoard[vertLOC][i] == 1 && playerID == 1)
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
	
	beforeCount = 0;
	afterCount = 0;
	k = 0;


	//Diagonal Checker to the bottom right of columnChosen
	for(i = vertLOC + 1; i < numRowsInBoard; i++)
	{
		k += 1;
		for(j = columnChosen + k; j < numRowsInBoard; j++)
		{
			if(connectNBoard[i][j] == 1 && playerID == 1)
			{
				afterCount += 1;
				break;
			}
			else if(connectNBoard[i][j] == 2 && playerID == 2)
			{
				afterCount += 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
	
	k = 0;

	//Diagonal Checker to the top left of columnChosen
	for(i = vertLOC - 1; i >= 0; i--)
	{
		k += 1;
		for(j = columnChosen - k; j >= 0; j--)
		{
			if(connectNBoard[i][j] == 1 && playerID == 1)
			{
				beforeCount += 1;
				break;
			}
			else if(connectNBoard[i][j] == 2 && playerID == 2)
			{
				beforeCount += 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
	
	if(beforeCount + afterCount + 1 >= numConnect)
	{
		return true;
	}

	beforeCount = 0;
	afterCount = 0;
	k = 0;

	//Diagonal Checker to the top right of columnChosen
	for(i = vertLOC - 1; i >= 0; i--)
	{
		k += 1;
		for(j = columnChosen + k; j < numRowsInBoard; j++)
		{
			if(connectNBoard[i][j] == 1 && playerID == 1)
			{
				afterCount += 1;
				break;
			}
			else if(connectNBoard[i][j] == 2 && playerID == 2)
			{
				afterCount += 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
	
	k = 0;

	//Diagonal Checker to the bottom left of columnChosen
	for(i = vertLOC + 1; i < numRowsInBoard; i++)
	{
		k += 1;
		for(j = columnChosen - k; j >= 0; j--)
		{
			if(connectNBoard[i][j] == 1 && playerID == 1)
			{
				beforeCount += 1;
				break;
			}
			else if(connectNBoard[i][j] == 2 && playerID == 2)
			{
				beforeCount += 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
	
	if((beforeCount + afterCount + 1) >= numConnect)
	{
		return true;
	}

}
