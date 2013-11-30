#include <iostream>
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
	int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = {0};

	//initialize and declare variables
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
	//first prompt
	do
	{
		cout << "Please enter the size of the board" << endl;
		cout << MIN_ARRAY_SIZE << " <= numRows <= " << MAX_ARRAY_SIZE << ": ";
		cin.clear();
		cin.sync();
	}
	while ((!(cin >> numRows)) || ( numRows < MIN_ARRAY_SIZE ) || ( numRows > MAX_ARRAY_SIZE ) );

	do
	{
		cout << "Please enter the number of pieces in a row to win" << endl;
		cout << minRowsToWin << " <= numToConnect <= numRows - 4: ";
		cin.clear();
		cin.sync();

	}while (  !(cin >> numToConnect)|| !(minRowsToWin <= numToConnect) || !(numToConnect <= numRows - minRowsToWin));

	cout << endl;

	if (!(IntializeBoard(connectNBoard,numRows)))
	{
		exit(1);  
	}

	cout << "Red goes first\n";
	playerID = 1;

	for(turnIndex = 0; turnIndex < (numRows * numRows); turnIndex++)
	{
		cin.clear();
		cin.sync();
		cout << endl;

		if(!(DisplayBoard(connectNBoard, numRows)))
		{
			cerr << "ERROR: COULD NOT DISPLAY BOARD";
			exit (2);
		}

		cout << "Enter the column number you wish to place piece within ";
		cin >> colChosen;

		while(!(MakeMove(connectNBoard, numRows, playerID, colChosen)) && forfeitIndex < 3)
		{
			forfeitIndex += 1;
			cin.clear();
			cin.sync();
			cin >> colChosen;
		}

		if(forfeitIndex >= 3 && playerID == 1)
		{
			cout << "Red has forfeited their move";
			playerID = 2;
			forfeitIndex = 0;
			continue;
		}
	
		if(forfeitIndex >= 3 && playerID == 2)
		{
			cout << "Black has forfeited their move";
			playerID = 1;
			forfeitIndex = 0;
			continue;
		}

		forfeitIndex = 0;

		if(CheckWinner(connectNBoard, numRows, numToConnect, colChosen, playerID))
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


		if (playerID == 1)
		{
			playerID = 2;
		}
		else
		{
			playerID = 1;
		}
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

	cout << endl << setw(3) << left << " ";

	for (i = 0; i < numRowsInBoard; i++)
	{
		cout << setw(3) << right << i;
	}
	cout << endl;

	for (i = 0; i < numRowsInBoard; i++)
	{
		cout << left << setw(3) << left << i;

		for (j = 0; j < numRowsInBoard; j++)
		{
			if ( (j % (numRowsInBoard + 1)) == numRowsInBoard)
			{
				cout << endl;
			}
			if (connectNBoard[i][j] == 1)//R, 2 = B
			{
				cout << setw(3) << right << "R";
			}
			else if (connectNBoard[i][j] == 2)
			{
				cout << setw(3) << right << "B"; 
			}
			else 
			{
				cout << setw(3) << right << "o";
			}
		}
		cout << endl;
	}
	cout << endl;
	return true;
}

bool MakeMove (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int columnChosen)
{
	int i = 0;
	int j = 0;

	if (columnChosen < 0 || (columnChosen > numRowsInBoard))
	{
		cout << endl << "Illegal Move" << endl;
		cout << "That column is not on the board: try again" << endl << endl;
		cout << "Enter the column number where you want to put your piece" << endl;
		cout << "Column number should be >=0 and <= " << numRowsInBoard - 1 << " ";
		return false;
	}
	
	//checking to see if the column has been all filled
	if(connectNBoard[0][columnChosen] != 0)
	{
		cout << endl << "Illegal Move" << endl;
		cout << "Column " << columnChosen << " is already completely full try again" << endl << endl;
		cout << "Enter column number where you want to put your piece" << endl;
		cout << "Column number should be >= 0 and <= " << numRowsInBoard - 1 << " ";
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
			}
			else 
			{
				return false;
			}
		}
	}

	return false;
}


bool CheckWinner (int connectNBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int numConnect, int columnChosen, int playerID)
{
	int afterCount = 0;
	int beforeCount = 0;
	int vertLOC = 0;

	int i = 0;
	int j = 0;
	int k = 0;

	if ((columnChosen < 0) || (columnChosen > numRowsInBoard -1))
	{
		cerr << "ERROR: invalid column chosen, cannot check for winner";
		return false;
	}

	//This for loop determines the row that the last piece was placed and stores it
	//into vertLOC
	for (i = 0; i < numRowsInBoard; i++)
	{
		if ((connectNBoard[i][columnChosen] == 1) && (playerID == 1))
		{
			vertLOC = i;
			break;
		}
		else if ((connectNBoard[i][columnChosen] == 2) && (playerID == 2))
		{
			vertLOC = i;
			break;
		}
		else if ((connectNBoard[i][columnChosen] != 0))
		{
			break;
		}else
		{
			continue;	
		}
	}

	//Counts the number of pieces of a certain player below the piece that was placed
	for(i = vertLOC + 1; i < numRowsInBoard; i++)
	{
		if((connectNBoard[i][columnChosen] == 2) && (playerID == 2))
		{
			beforeCount += 1;
		}
		else if((connectNBoard[i][columnChosen] == 1) && (playerID == 1))
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

	//Adds the beforeCount and the actual location and check if it's greater than numConnect
	if ( (beforeCount + 1) >= numConnect )
	{      
		return true;
	}
	
	//Resets the values of beforeCount to 0
	beforeCount = 0;
	afterCount = 0;

	//Counts the pieces of the current player to the right of the most recently placed piece
	//Adds that value to afterCount
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

	//Counts the pieces of the current player to the left of the most recently placed piece
	//Adds that value to beforeCount
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

	//Adds both afterCount and beforeCount and 1
	//If this value is greater than numConnect, return true
	if((beforeCount + afterCount + 1) >= numConnect)
	{
		return true;
	}

	//Resets the values of k, beforeCount and afterCount
	beforeCount = 0;
	afterCount = 0;
	k = 0;


	//Counts the number of pieces of the given player to the bottom right of the piece
	//Adds this value to afterCount
	//k is used to move the column of the board to the right by 1 each time around the loop
	for(i = vertLOC + 1; i < numRowsInBoard; i++)
	{
		k += 1;
		for(j = columnChosen + k; j < numRowsInBoard; j++)
		{
			if((connectNBoard[i][j] == 1) && (playerID == 1))
			{
				afterCount += 1;
				break;
			}
			else if((connectNBoard[i][j] == 2) && (playerID == 2))
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

	//resets the value of k
	k = 0;

	//Counts the number of pieces of the given player to the top left, and adds them to beforeCount
	//k is used to move the location of the board column to the left by one each time
	//around the loop
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

	//Compares the sum of beforeCount, afterCount and 1 to numConnect
	//If it is greater or equal to numConnect, return true
	if(beforeCount + afterCount + 1 >= numConnect)
	{
		return true;
	}

	//Resets all values to 0
	beforeCount = 0;
	afterCount = 0;
	k = 0;

	//Counts the number of pieces of the given player, to the top right and adds them to afterCount
	//k is used to move the location of the board column to the right by one each time
	//around the loop
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

	//Counts the number of pieces of the given player, to the bottom left and adds them to beforeCount
	//k is used to move the location of the board column to the left by one each time
	//around the loop
	for(i = vertLOC + 1; i < numRowsInBoard; i++)
	{
		k += 1;
		for(j = columnChosen - k; j > 0; j--)
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

	//Compares the sum of beforeCount, afterCount, 1 to numConnect
	//If they are greater than numConnect, return true
	if((beforeCount + afterCount + 1) >= numConnect)
	{
		return true;
	}

	return false;
}
