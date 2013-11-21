#include <iomanip>
#include <string>
#include <cmath>

include namespace std;

bool InitializeBoard(int** connectNBoard,  int numRowsInBoard);
bool MakeMove(int** connectNBoard, int numRowsInBoard,  int player, int columnChosen);
bool DisplayBoard( int** connectNBoard,  int numRowsInBoard);
bool CheckWinner( int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int player );


bool InitializeBoard(int** connectNBoard,  int numRowsInBoard)
{
	int index = 0;
	int columnIndex = 0;

	int *startBoardp = NULL;
	int *endBoardp = NULL;

	connectNBoard = new (nothrow) int[numRowsInBoard];
	if(connectNBoard == NULL)
	{
		return false;
	}

	for(index = 0; index < numRowsInBoard; index++)
	{
		*(connectNBoard + index) = 0;
	}
	return true;
}

bool MakeMove(int** connectNBoard, int numRowsInBoard,  int playeID, int columnChosen)
{
	int index = 0;
	int playerOutput = 0;
	string playerName = NULL;
	
	if(playeID = 0)
	{
		output = 1;
		playerName = "Red";
	}
	else
	{
		output = 2;
		playerName = "Black";
	}

	if(columnChosen > numRowsInBoard || columnChosen < 0)
	{
		cout << "Illegal move";
		return false;
	}
	
	else if(*(connectNBoard + columnChosen) != 0)
	{
		cout << "Illegal move";
		return false;
	}

	else
	{
		NULL;
	}

	for(index = 0; index < numRowsInBoard; index++)
	{
		if(*((connectNBoard + columnChosen) * (numRowsInBoard - index)) != 0)
		{
			continue;
		}
		if(*((connectNBoard + columnChosen) * (numRowsInBoard - index)) == 0)
		{
			*((connectNBoard + columnChosen) * (numRowsInBoard - index)) = playerOutput;
			break;
		}
		
	}
	cout << playerName << " has moved";
	return true;
}

bool DisplayBoard( int** connectNBoard,  int numRowsInBoard)
{
        int index = 0;
        bool border = false;
        
        if(border == false)
        {
                for(index = 0; index < numRowsInBoard; index++)
                {
                        cout << setw(3) << right << index;
                        border = true;
                }
                continue;
        }
        for(index = 0; index < numRowsInBoard; index++)
        {
                cout << setw(3) << right << index << *(connectNBoard + index);
                if(index%numRowsInBoard - 1 = numRowsInBoard)
                {
                        cout << endl;
                }
        }
        return true;
}

bool CheckWinner(int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int player)
{
	int afterCount = 0;
	int beforeCount = 0;
	int vertCount = 0;
	int index = 0;
	//Add errors below this comment for invalid columns chosen
	//
	//
	
	//Checks to the left of the column chosen
	for(index = numConnect - 1; index >= 0; index--)
	{
		if(*((connectNBoard + columnChosen) * index) != 0)
		{
			beforeCount += 1;
		}
		else
		{
			break;
		}
	}
	
	//Checks to the right of the column chosen
	for(index = 0; index < numConnect; index++)
	{
		if(*((connectNBoard + columnChosen) * index) != 0)
		{
			afterCount += 1;
		}
		else
		{
			break;
		}
	}
	
	//Checks to see if the player has won by row
	if(beforeCount + afterCount + 1 >= numConnect)
	{
		return true;
	}
	
	//Checks below the column to see if 
	for(index = numConnect - 1; index >= 0; index--)
	{
		if(*(connectNBoard + index) != 0)
		{
			vertCount += 0;
		}
		else
		{
			break;
		}
	}
	//Checks to see if the player has won by column
	if(vertCount + 1 >= numConnect)
	{
		return true;
	}
	
	//Another function will go here to check the diagnoal parts
}
