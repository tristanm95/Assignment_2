//Initialize Libraries
#include <iostream>
#include <iomanip>

using namespace std;
//This program is for the game called connectN. It is played similarily to connect 4, however the board and the number
//needed to connect are customizable by the players.
//
//
//Date: 11/29/2013
//Authors: Tristan May, Frank Su, Jason Park, Danielle Sinha

//Function prototypes for main()
bool InitializeBoard(int **connectNBoard,  int numRowsInBoard );
bool MakeMove(int **connectNBoard, int numRowsInBoard,  int player, int columnChosen);
bool DisplayBoard(int **connectNBoard,  int numRowsInBoard);
bool CheckWinner(int **connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int player );

//Start main program
int main()
{
	//Initialize dynamic array pointer
	int **connectNBoardpp;
	//Initialize counter indexes
	int i = 0;
	int index = 0;
	int j = 0;
	int forfeitIndex = 0;
	int turnIndex = 0;
	//Initialize other variables
	int numRows = 0;
	int numConnect = 0;
	int numToConnect = 0;
	int playerID = 0;
	int colChosen = 0;
	
	//Request from user the size of the board and repeat if it is out of range or an invalid character
	do
	{
		cout << "Please enter the size of the board" << endl;
		cout << "8 <= numRows <= 25: ";
		//Clears the error flag from cin and clears the stream
		cin.clear();
		cin.sync();
	}
	while(!(cin >> numRows) || !(8 <= numRows && numRows <= 25));
	
	//Request from user number of pieces a player must have to win
	do
	{
		cout << "Please enter the number of pieces in a row to win" << endl;
		cout << "4 <= numToConnect <= numRows - 4: ";
		//Clears the error flag from cin and clears the stream
		cin.clear();
		cin.sync();
	}
	while(!(cin >> numToConnect) || !(4 <= numToConnect && numToConnect <= (numRows - 4)));
	
	//Initializes the pointer to an array of pointers that point to the rows
	connectNBoardpp = new int* [numRows];
	
	//Initializes pointers to arrays of the columns into the array of pointers initialized above
	for(index = 0; index < numRows; index++)
	{
		*(connectNBoardpp + index) = new int [numRows];
	}
	
	//If the board does not initialize, exit the program and delete the arrays
	if(!(InitializeBoard(connectNBoardpp, numRows)))
	{	
		cerr << "The board was not initialized" << endl;
		for(i = 0; i < numRows; i++)
		{
			delete [] connectNBoardpp[i];
			connectNBoardpp[i] = NULL;
		}
		
		delete [] connectNBoardpp;
		exit(1);
	}
	
	//Sets the first player to red
	cout << "Red goes first";
	playerID = 1;

	//Begins the actual game, with a maximum turn value of the total amount of space
	//in the board
	for(turnIndex = 0; turnIndex < (numRows * numRows); turnIndex++)
	{
		//Clears the stream and any error flag from cin
		cin.clear();
		cin.sync();
		cout << endl;
		
		//If the display board function fails, exit the program and delete the arrays
		if(!(DisplayBoard(connectNBoardpp, numRows)))
		{
			cerr << "ERROR: COULD NOT DISPLAY BOARD";
			for(i = 0; i < numRows; i++)
			{
				delete [] connectNBoardpp[i];
				connectNBoardpp[i] = NULL;
			}
	
			delete [] connectNBoardpp;
			connectNBoardpp = NULL;
			exit(3);
		}
		
		//Request the column that the piece will be placed
		cout << "Enter the column where you wish to place your piece ";
		cin >> colChosen;

		//If the makeMove function returns false, add to the forfeit index,
		//Clear the stream and cin flag
		//Request to move again, until the forfeit Index reaches 3
		while(!(MakeMove(connectNBoardpp, numRows, playerID, colChosen)) && forfeitIndex < 3)
		{
			forfeitIndex += 1;
			cin.clear();
			cin.sync();
			cin >> colChosen;
		}

		//If the forfeit index is >= 3, switch players from Red to Black
		//Go to the top of the turn loop
		if(forfeitIndex >= 3 && playerID == 1)
		{
			cout << endl << "Red has forfeited their move";
			playerID = 2;
			forfeitIndex = 0;
			continue;
		}
		//If the forfeit index is >= 3, switch players from Black to Red
		//Go to the top of the turn loop
		if(forfeitIndex >= 3 && playerID == 2)
		{
			cout << endl << "Black has forfeited their move";
			playerID = 1;
			forfeitIndex = 0;
			continue;
		}
		//Resets the forfeit index
		forfeitIndex = 0;

		//If the checkWinner function is true, output who has one from the current PlayerID
		//Break out of the turn function
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
		
		//Switch playerID for the next turn
		if(playerID == 1)
		{
			playerID = 2;
		}
		else
		{
			playerID = 1;
		}
	}
	
	//Delete the columns
	//Set the pointers to the columns to NULL
	for(i = 0; i < numRows; i++)
	{
		delete [] connectNBoardpp[i];
		connectNBoardpp[i] = NULL;
	}
	
	//Delete the array that contains the pointers that point to the columns
	delete [] connectNBoardpp;
	//Sets the pointer that points to the array of pointers that point to the columns to NULL
	connectNBoardpp = NULL;
	
	
	return 0;
}

//This function initializes the game board to 0
bool InitializeBoard(int** connectNBoard,  int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	
	//Starts the for loop that will initialize the board
	for(i = 0; i < numRowsInBoard; i++)
	{
		for(j = 0; j < numRowsInBoard; j++)
		{
			//Sets location i,j of the board to 0
			connectNBoard[i][j] = 0;
			
			//if the above statement does not work, output an error message and return false
			if(connectNBoard[i][j] < 0 || connectNBoard[i][j] > 2)
			{
				cerr << "The board was not initialized";
				return false;
			}
		}
	}


	return true;
}

//This function palces the a piece on the board or returns an error message if an illgal column was chosen
bool MakeMove(int** connectNBoard, int numRowsInBoard,  int playeID, int columnChosen)
{
	int i = 0;
	int j = 0;
	
	//Checks to see if the column chosen is within range of the board
	//If it isn't, return an error message and prompt for another choice
	if(columnChosen < 0 || columnChosen >= numRowsInBoard)
	{
		cout << "Illegal Move" << endl;
		cout << "That column is not on the board: try again" << endl;
		cout << "Enter the column number where you want to put your piece" << endl;
		cout << "Column number should be >=0 and <= " << numRowsInBoard - 1 << " " << endl;
		return false;
	}
	
	//Checks to see if the column chosen is already filled
	//If it is, then output a message and request another choice
	if(connectNBoard[0][columnChosen] != 0)
	{
		cout << "Illegal Move" << endl;
		cout << "Column" << columnChosen << "is already completely full try again" << endl;
		cout << "Enter column number where you want to put your piece" << endl;
		cout << "Column number should be >= 0 and <= " << numRowsInBoard - 1 << " " << endl;
		return false;
	}
	
	//Main for loop that will store the piece in the column of the board
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

//This converts the integer array of connectNBoard to letters on the screen
//Prints everything with a width of 3
bool DisplayBoard( int** connectNBoard,  int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	
	//Sets an initial space for the top row of columns numbers
	cout << endl << setw(3) << " ";

	//Prints the top row of numbers of columns
	for(i = 0; i < numRowsInBoard; i++)
	{
		cout << setw(3) << right << i;
	}
	cout << endl;
	
	//Prints in a square array each piece of the board, and sets everything else to 'o'
	//Prints the row number at the beginning of each row
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

//This function will check to see if the current move was a winning move
bool CheckWinner(int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int playerID)
{
	int afterCount = 0;
	int beforeCount = 0;
	int vertLOC = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	
	//If the column chosen is invalid, return false with an error message
	if(columnChosen > (numRowsInBoard - 1) || columnChosen < 0)
	{
		cerr << "ERROR: invalid column chosen, cannot check for winner";
		return false;
	}

	//This for loop determines the row that the last piece was placed and stores it
	//into vertLOC
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

	//Counts the number of pieces of a certain player below the piece that was placed
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

	//Adds the beforeCount and the actual location and check if it's greater than numConnect
	if((beforeCount +  1) >= numConnect)
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
	
	//Compares the sum of beforeCount, afterCount, 1 to numConnect
	//If they are greater than numConnect, return true
	if((beforeCount + afterCount + 1) >= numConnect)
	{
		return true;
	}
	return false;
}
