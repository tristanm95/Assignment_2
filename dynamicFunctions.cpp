#include <iomanip>
#include <string>
#include <cmath>

include namespace std;

bool InitializeBoard(int** connectNBoard,  int numRowsInBoard);
bool MakeMove(int** connectNBoard, int numRowsInBoard,  int player, int columnChosen);
bool DisplayBoard( int** connectNBoard,  int numRowsInBoard);
bool CheckWinner( int** connectNBoard, int numRowsInBoard, int numConnect, int columnChosen, int player );

int main()
{
	return 0;
}

bool InitializeBoard(int** connectNBoard,  int numRowsInBoard)
{
	int index = 0;
	int columnIndex = 0;

	int *startBoardp = NULL;
	int *endBoardp = NULL;

	connectNBoard = new (nothrow) int[numRowsInBoard];
	if(connectNBoard == NULL)
	{
		return(false);
	}

	for(index = 0; index < numRowsInBoard; index++)
	{
		*(connectNBoard + index) = 0;
	}
	return(true);
}

bool MakeMove(int** connectNBoard, int numRowsInBoard,  int playeID, int columnChosen)
{
	int index = 0;
	int playerOutput = 0;

	if(playeID = 0)
	{
		output = 1;
	}
	else
	{
		output = 2;
	}

	if(columnChosen > numRowsInBoard || columnChosen < 0)
	{
		cout << "Illegal move";
	}
	
	else if(*(connectNBoard + columnChosen) == 1 || *(connectNBoard + columnChosen) == 2)
	{
		cout << "Illegal move";
	}

	else
	{
		cout << "Something went wrong";
	}

	for(index = 0; index < numRowsInBoard; index++)
	{
		if(*((connectNBoard + columnChosen) * (numRowsInBoard - index)) != 0)
		{
			continue;
		}
		if(*((connectNBoard + columnChosen) * (numRowsInBoard - index)) += 0)
		{
			*((connectNBoard + columnChosen) * (numRowsInBoard - index)) = playerOutput;
			break;
		}
	}

