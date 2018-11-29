#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

//global constants
const int MAX_ARRAY_SIZE = 18;
const int MIN_ARRAY_SIZE = 8;
const int MAX_PIECES = 72;
const int NOPLAYER = 0;
const int WHITEWINS = 1;
const int REDWINS = 2;
const int NOONEWINS = 0;
const int WHITESOLDIER = 1;
const int WHITEMULE = 2;
const int WHITEKING = 3;
const int REDSOLDIER = 4;
const int REDMULE = 5;
const int REDKING = 6;
const int WHITEPLAYER = 1;
const int REDPLAYER = 2;

//function prototypes
void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

int CountJumps(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLocArray[], int yLocArray[]);

bool CheckList(int inArray1[], int inArray2[], int xIndex, int yIndex);

int CountMove1Squares(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLocArray[], int yLocArray[]);

bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc);

bool IsJump(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc);

bool MakeMove(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int fromSquareNum, int toSquareNum, bool &jumped);

bool CheckWin(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);


//write function definitions here please
void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < numRowsInBoard; i++)
	{
		for (j = 0; j < numRowsInBoard; j++)
		{
			if ((i == 0) && (j % 2 == 1))
			{
				CMCheckersBoard[i][j] = WHITEMULE;
			}
			else if (i == (numRowsInBoard - 1) && ((j % 2 == 0) || (j % 2 == 2)))
			{
				CMCheckersBoard[i][j] = REDMULE;
			}
			else if ((i % 2 == 1) && (j % 2 == 0 || j % 2 == 2) && (i < numRowsInBoard / 2 - 1))
			{
				CMCheckersBoard[i][j] = WHITESOLDIER;
			}
			else if ((i % 2 == 0) && (j % 2 == 1) && (i < numRowsInBoard / 2 - 1))
			{
				CMCheckersBoard[i][j] = WHITESOLDIER;
			}
			else if ((i % 2 == 0) && (j % 2 == 1) && (i > numRowsInBoard / 2))
			{
				CMCheckersBoard[i][j] = REDSOLDIER;
			}
			else if ((i % 2 == 1) && (j % 2 == 0 || j % 2 == 2) && (i > numRowsInBoard / 2))
			{
				CMCheckersBoard[i][j] = REDSOLDIER;
			}
			else
			{
				CMCheckersBoard[i][j] = NOPLAYER;
			}
		}
	}
	return;
}

int CountJumps(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLocArray[], int yLocArray[])
{
	int numJumps = 0;
	int index;
	int xIndex;
	int yIndex;

	for (index = 0; index < numRowsInBoard; index++)
	{
		yLocArray[index] = -1;
		xLocArray[index] = -1;
	}

	for (xIndex = 0; xIndex < numRowsInBoard; xIndex++)
	{
		for (yIndex = 0; yIndex < numRowsInBoard; yIndex++)
		{
			if (CMCheckersBoard[yIndex][xIndex] == 0)
			{
				continue;
			}

			if (IsJump(CMCheckersBoard,
				numRowsInBoard, player, xIndex, yIndex) == true)
			{
				numJumps++;
				xLocArray[index] = xIndex;
				yLocArray[index] = yIndex;
				index++;
			}
		}
	}
	return numJumps;
}

int CountMove1Squares(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLocArray[], int yLocArray[])
{
	int numMove1Square = 0;
	int index;
	int xIndex;
	int yIndex;

	for (index = 0; index < numRowsInBoard; index++)
	{
		yLocArray[index] = -1;
		xLocArray[index] = -1;
	}

	for (xIndex = 0; xIndex < numRowsInBoard; xIndex++)
	{
		for (yIndex = 0; yIndex < numRowsInBoard; yIndex++)
		{
			if (CMCheckersBoard[yIndex][xIndex] == 0)
			{
				continue;
			}

			if (IsMove1Square(CMCheckersBoard,
				numRowsInBoard, player, xIndex, yIndex) == true)
			{
				numMove1Square++;
				xLocArray[index] = xIndex;
				yLocArray[index] = yIndex;
				index++;
			}
		}
	}
	return numMove1Square;
}

void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	int boardPosition = 0;
	int DisplayCopy[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };
	for (i = 0; i < numRowsInBoard; i++)
	{
		cout << endl << endl;
		for (j = 0; j < numRowsInBoard; j++)
		{
			if (CMCheckersBoard[i][j] != 0)
			{
				if (CMCheckersBoard[i][j] == 1)
				{
					cout << setw(4) << "WS";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 2)
				{
					cout << setw(4) << "WM";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 3)
				{
					cout << setw(4) << "WK";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 4)
				{
					cout << setw(4) << "RS";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 5)
				{
					cout << setw(4) << "RM";
					boardPosition++;
				}
				else
				{
					cout << setw(4) << "RK";
					boardPosition++;
				}
			}
			else
			{
				//DisplayCopy[i][j] = CMCheckersBoard[i][j];
				DisplayCopy[i][j] = boardPosition;
				cout << setw(4) << DisplayCopy[i][j];
				boardPosition++;
			}
		}
	}
	cout << endl << endl;
	return;
}

bool CheckList(int inArray1[], int inArray2[], int xIndex, int yIndex)
{
	int index1 = 0;
	int xposition = -1;
	bool xfound = false;
	int index2 = 0;
	int yposition = -1;
	bool yfound = false;
	bool found = false;
	while (index1 < MAX_PIECES && !xfound)
	{
		if (inArray1[index1] == xIndex)
		{
			xfound = true;
			xposition = index1;
		}
		index1++;
	}
	while (index2 < MAX_PIECES && !yfound)
	{
		if (inArray2[index2] == yIndex)
		{
			yfound = true;
			yposition = index2;
		}
		index2++;
	}
	if (xposition != -1 && yposition != -1)
	{
		found = true;
	}

	return found;
}

bool MakeMove(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int fromSquareNum, int toSquareNum, bool &jumped)
{
	const int minusNum = numRowsInBoard - 1;
	int rowFrom = 0;
	int columnFrom = 0;
	int column_From = 0;
	int minusNumRowsFrom = numRowsInBoard - 1;
	int numRowsFrom = 0;
	int minusNumColumnsFrom = 0;
	int numColumnsFrom = 0;
	int xDistanceFrom = 0;
	int yDistanceFrom = 0;
	int rowTo = 0;
	int columnTo = 0;
	int column_To = 0;
	int minusNumRowsTo = numRowsInBoard - 1;
	int numRowsTo = 0;
	int minusNumColumnsTo = 0;
	int numColumnsTo = 0;
	int xDistanceTo = 0;
	int yDistanceTo = 0;
	int xDistance = 0;
	int yDistance = 0;
	bool move = false;
	jumped = false;
	int temp = 0;
	int dummy1 = 0; //xto
	int dummy2 = 0;//yto

	int dummy3 = 0;//xfrom
	int dummy4 = 0;//yrom
	char character;

	yDistanceTo = toSquareNum / numRowsInBoard;
	xDistanceTo = toSquareNum % numRowsInBoard;

	yDistanceFrom = fromSquareNum / numRowsInBoard;
	xDistanceFrom = fromSquareNum % numRowsInBoard;

	xDistance = abs(xDistanceTo - xDistanceFrom);
	yDistance = abs(yDistanceTo - yDistanceFrom);

	if (player == WHITEPLAYER)
	{
		if ((xDistance == 2 && yDistance == 2) || (xDistance == minusNum - 1 && yDistance == 2))//move 2 squares
		{
			if (IsJump(CMCheckersBoard, numRowsInBoard, player, xDistanceFrom, yDistanceFrom) == false)
			{
				cout << "Error: illegal move" << endl;
				return move;
			}
			else if ((xDistanceFrom == minusNum) && (xDistance == minusNum - 1 && yDistance == 2))
			{
				if ((yDistanceTo - yDistanceFrom) > 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom - minusNum] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0)
				{
					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom - minusNum] = 0;
				}
			}
			else if ((xDistanceFrom == minusNum - 1) && (xDistance == minusNum - 1 && yDistance == 2))
			{
				if ((yDistanceTo - yDistanceFrom) > 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom + 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0)
				{
					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom + 1] = 0;
				}
			}
			else if ((xDistanceFrom == 0) && (xDistance == minusNum - 1 && yDistance == 2))
			{
				if ((yDistanceTo - yDistanceFrom) > 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom + minusNum] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0)
				{
					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom + minusNum] = 0;
				}
			}
			else if ((xDistanceFrom == 1) && (xDistance == minusNum - 1 && yDistance == 2))
			{
				if ((yDistanceTo - yDistanceFrom) > 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom - 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom - 1] = 0;
				}
			}
			else
			{
				if ((yDistanceTo - yDistanceFrom) > 0 && (xDistanceTo - xDistanceFrom) > 0)
				{

					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom + 1] = 0;

				}
				else if ((yDistanceTo - yDistanceFrom) > 0 && (xDistanceTo - xDistanceFrom) < 0)
				{

					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom - 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0 && (xDistanceTo - xDistanceFrom) > 0)
				{

					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom + 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0 && (xDistanceTo - xDistanceFrom) < 0)
				{

					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom - 1] = 0;
				}
			}

			jumped = true;
			temp = CMCheckersBoard[yDistanceFrom][xDistanceFrom];
			CMCheckersBoard[yDistanceFrom][xDistanceFrom] = 0;
			CMCheckersBoard[yDistanceTo][xDistanceTo] = temp;

			if (CMCheckersBoard[yDistanceTo][xDistanceTo] == WHITEMULE && yDistanceTo == minusNum)
			{
				CMCheckersBoard[yDistanceTo][xDistanceTo] = WHITEKING;
				cout << "White has created a Mule King,  Red wins the game" << endl;
				cout << "Enter any character to terminate the game then press the enter key";
				cin >> character;
				exit(0);
			}
			else if (CMCheckersBoard[yDistanceTo][xDistanceTo] == WHITESOLDIER && yDistanceTo == minusNum)
			{
				move = true;
				return move;
			}
			move = true;
			return move;
		}
		else if ((xDistance == 1 && yDistance == 1) || (xDistance == minusNum && yDistance == 1))//moved 1 square
		{
			if (IsMove1Square(CMCheckersBoard, numRowsInBoard, player, xDistanceFrom, yDistanceFrom) == false)
			{
				cout << "Error: illegal move" << endl;
				return move;
			}
			else if ((xDistanceFrom == minusNum) && (xDistance == minusNum && yDistance == 1))
			{


			}
			else if ((xDistanceFrom == 0) && (xDistance == minusNum && yDistance == 1))
			{


			}

			temp = CMCheckersBoard[yDistanceFrom][xDistanceFrom];
			CMCheckersBoard[yDistanceFrom][xDistanceFrom] = 0;
			CMCheckersBoard[yDistanceTo][xDistanceTo] = temp;
			cout << CMCheckersBoard[yDistanceTo][xDistanceTo] << endl;

			if (CMCheckersBoard[yDistanceTo][xDistanceTo] == WHITEMULE && yDistanceTo == minusNum)
			{
				CMCheckersBoard[yDistanceTo][xDistanceTo] = WHITEKING;
				cout << "White has created a Mule King,  Red wins the game" << endl;
				cout << "Enter any character to terminate the game then press the enter key";
				cin >> character;
				exit(0);
			}
			else if (CMCheckersBoard[yDistanceTo][xDistanceTo] == WHITESOLDIER && yDistanceTo == minusNum)
			{
				move = true;
				return move;
			}
			move = true;
			return move;
		}
		else
		{
			cout << "Error: illegal move" << endl;
			return move;
		}
	}
	else if (player == REDPLAYER)
	{
		if ((xDistance == 2 && yDistance == 2) || (xDistance == minusNum - 1 && yDistance == 2))//move 2 squares
		{
			if (IsJump(CMCheckersBoard, numRowsInBoard, player, xDistanceFrom, yDistanceFrom) == false)
			{
				cout << "Error: illegal move" << endl;
				return move;
			}
			else if ((xDistanceFrom == minusNum) && (xDistance == minusNum - 1 && yDistance == 2))
			{
				if ((yDistanceTo - yDistanceFrom) > 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom - minusNum] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0)
				{
					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom - minusNum] = 0;
				}
			}
			else if ((xDistanceFrom == minusNum - 1) && (xDistance == minusNum - 1 && yDistance == 2))
			{
				if ((yDistanceTo - yDistanceFrom) > 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom + 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0)
				{
					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom + 1] = 0;
				}
			}
			else if ((xDistanceFrom == 0) && (xDistance == minusNum - 1 && yDistance == 2))
			{
				if ((yDistanceTo - yDistanceFrom) > 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom + minusNum] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0)
				{
					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom + minusNum] = 0;
				}
			}
			else if ((xDistanceFrom == 1) && (xDistance == minusNum - 1 && yDistance == 2))
			{
				if ((yDistanceTo - yDistanceFrom) > 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom - 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0)
				{
					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom - 1] = 0;
				}
			}
			else
			{
				if ((yDistanceTo - yDistanceFrom) > 0 && (xDistanceTo - xDistanceFrom) > 0)
				{

					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom + 1] = 0;

				}
				else if ((yDistanceTo - yDistanceFrom) > 0 && (xDistanceTo - xDistanceFrom) < 0)
				{

					CMCheckersBoard[yDistanceFrom + 1][xDistanceFrom - 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0 && (xDistanceTo - xDistanceFrom) > 0)
				{

					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom + 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0 && (xDistanceTo - xDistanceFrom) < 0)
				{

					CMCheckersBoard[yDistanceFrom - 1][xDistanceFrom - 1] = 0;
				}
			}

			jumped = true;
			temp = CMCheckersBoard[yDistanceFrom][xDistanceFrom];
			CMCheckersBoard[yDistanceFrom][xDistanceFrom] = 0;
			CMCheckersBoard[yDistanceTo][xDistanceTo] = temp;

			if (CMCheckersBoard[yDistanceTo][xDistanceTo] == REDMULE && yDistanceTo == 0)
			{
				CMCheckersBoard[yDistanceTo][xDistanceTo] = REDKING;
				cout << "Red has created a Mule King,  White wins the game" << endl;
				cout << "Enter any character to terminate the game then press the enter key";
				cin >> character;
				exit(0);
			}
			else if (CMCheckersBoard[yDistanceTo][xDistanceTo] == REDSOLDIER && yDistanceTo == 0)
			{
				move = true;
				return move;
			}
			move = true;
			return move;
		}
		else if ((xDistance == 1 && yDistance == 1) || (xDistance == minusNum && yDistance == 1))//moved 1 square
		{
			if (IsMove1Square(CMCheckersBoard, numRowsInBoard, player, xDistanceFrom, yDistanceFrom) == false)
			{
				cout << "Error: illegal move" << endl;
				return move;
			}
			else if ((xDistanceFrom == minusNum) && (xDistance == minusNum && yDistance == 1))
			{


			}
			else if ((xDistanceFrom == 0) && (xDistance == minusNum && yDistance == 1))
			{


			}

			temp = CMCheckersBoard[yDistanceFrom][xDistanceFrom];
			CMCheckersBoard[yDistanceFrom][xDistanceFrom] = 0;
			CMCheckersBoard[yDistanceTo][xDistanceTo] = temp;

			if (CMCheckersBoard[yDistanceTo][xDistanceTo] == REDMULE && yDistanceTo == 0)
			{
				CMCheckersBoard[yDistanceTo][xDistanceTo] = REDKING;
				cout << "Red has created a Mule King,  White wins the game" << endl;
				cout << "Enter any character to terminate the game then press the enter key";
				cin >> character;
				exit(0);
			}
			else if (CMCheckersBoard[yDistanceTo][xDistanceTo] == REDSOLDIER && yDistanceTo == 0)
			{
				move = true;
				return move;
			}
			move = true;
			return move;
		}
		else
		{
			cout << "Error: illegal move" << endl;
			return move;
		}
	}
	else
	{

		return move;
	}
}



bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLoc, int yLoc)
{
	if (player == 1)
	{
		if (xLoc == 0)
		{
			if (CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if (CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 0)
				{
					return true;
				}
			}
			else if (xLoc == numRowsInBoard)
			{
				if (CMCheckersBoard[yLoc + 1][0] == 0)
				{
					return true;
				}
				else if (CMCheckersBoard[yLoc][xLoc] == 3)
				{
					if (CMCheckersBoard[yLoc - 1][0] == 0)
					{
						return true;
					}
				}
			}
		}
		else if (CMCheckersBoard[yLoc + 1][xLoc + 1] == 0 || CMCheckersBoard[yLoc + 1][xLoc - 1] == 0)
		{
			return true;
		}
		else if (CMCheckersBoard[yLoc][xLoc] == 3)
		{
			if (CMCheckersBoard[yLoc - 1][xLoc + 1] == 0 || CMCheckersBoard[yLoc - 1][xLoc - 1] == 0)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else if (player == 2)
	{


		if (xLoc == 0)
		{
			if (CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if (CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == numRowsInBoard)
		{
			if (CMCheckersBoard[yLoc - 1][0] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if (CMCheckersBoard[yLoc + 1][0] == 0)
				{
					return true;
				}
			}
		}
		else if (CMCheckersBoard[yLoc - 1][xLoc + 1] == 0 || CMCheckersBoard[yLoc - 1][xLoc - 1] == 0)
		{
			return true;
		}
		else if (CMCheckersBoard[yLoc][xLoc] == 6)
		{
			if (CMCheckersBoard[yLoc + 1][xLoc + 1] == 0 || CMCheckersBoard[yLoc + 1][xLoc - 1] == 0)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	return false;
}

bool IsJump(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLoc, int yLoc)
{
	if (player == 1)
	{
		if (CMCheckersBoard[yLoc][xLoc] != 1 || CMCheckersBoard[yLoc][xLoc] != 2 || CMCheckersBoard[yLoc][xLoc] != 3)
		{
			return false;
		}
		if (xLoc == 0)
		{
			if ((CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 4 ||
				CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 5 ||
				CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 6) &&
				CMCheckersBoard[yLoc + 2][numRowsInBoard - 2] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if ((CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 4 ||
					CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 5 ||
					CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 6) &&
					CMCheckersBoard[yLoc - 2][numRowsInBoard - 2] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == 1)
		{
			if ((CMCheckersBoard[yLoc + 1][0] == 4 ||
				CMCheckersBoard[yLoc + 1][0] == 5 ||
				CMCheckersBoard[yLoc + 1][0] == 6) &&
				CMCheckersBoard[yLoc + 2][numRowsInBoard - 1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if ((CMCheckersBoard[yLoc - 1][0] == 4 ||
					CMCheckersBoard[yLoc - 1][0] == 5 ||
					CMCheckersBoard[yLoc - 1][0] == 6) &&
					CMCheckersBoard[yLoc - 2][numRowsInBoard - 1] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == numRowsInBoard)
		{
			if ((CMCheckersBoard[yLoc + 1][0] == 4 ||
				CMCheckersBoard[yLoc + 1][0] == 5 ||
				CMCheckersBoard[yLoc + 1][0] == 6) &&
				CMCheckersBoard[yLoc + 2][1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if ((CMCheckersBoard[yLoc - 1][0] == 4 ||
					CMCheckersBoard[yLoc - 1][0] == 5 ||
					CMCheckersBoard[yLoc - 1][0] == 6) &&
					CMCheckersBoard[yLoc - 2][1] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == numRowsInBoard - 1)
		{
			if ((CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 4 ||
				CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 5 ||
				CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 6) &&
				CMCheckersBoard[yLoc + 2][0] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if ((CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 4 ||
					CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 5 ||
					CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 6) &&
					CMCheckersBoard[yLoc - 2][0] == 0)
				{
					return true;
				}
			}
		}
		else if (((CMCheckersBoard[yLoc + 1][xLoc + 1] == 4 ||
			CMCheckersBoard[yLoc + 1][xLoc + 1] == 5 ||
			CMCheckersBoard[yLoc + 1][xLoc + 1] == 6) &&
			CMCheckersBoard[yLoc + 2][xLoc + 2] == 0) ||
			((CMCheckersBoard[yLoc + 1][xLoc - 1] == 4 ||
				CMCheckersBoard[yLoc + 1][xLoc - 1] == 5 ||
				CMCheckersBoard[yLoc + 1][xLoc - 1] == 6) &&
				CMCheckersBoard[yLoc + 2][xLoc - 2] == 0))
		{

			return true;
		}
		else if (CMCheckersBoard[yLoc][xLoc] == 3)
		{
			if (((CMCheckersBoard[yLoc - 1][xLoc + 1] == 4 ||
				CMCheckersBoard[yLoc - 1][xLoc + 1] == 5 ||
				CMCheckersBoard[yLoc - 1][xLoc + 1] == 6) &&
				CMCheckersBoard[yLoc - 2][xLoc + 2] == 0) ||
				((CMCheckersBoard[yLoc - 1][xLoc - 1] == 4 ||
					CMCheckersBoard[yLoc - 1][xLoc - 1] == 5 ||
					CMCheckersBoard[yLoc - 1][xLoc - 1] == 6) &&
					CMCheckersBoard[yLoc - 2][xLoc - 2] == 0))
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	if (player == 2)
	{
		if (CMCheckersBoard[yLoc][xLoc] != 1 || CMCheckersBoard[yLoc][xLoc] != 2 || CMCheckersBoard[yLoc][xLoc] != 3)
		{
			return false;
		}
		if (xLoc == 0)
		{
			if ((CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 1 ||
				CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 2 ||
				CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 3) &&
				CMCheckersBoard[yLoc - 2][numRowsInBoard - 2] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if ((CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 1 ||
					CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 2 ||
					CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 3) &&
					CMCheckersBoard[yLoc + 2][numRowsInBoard - 2] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == 1)
		{
			if ((CMCheckersBoard[yLoc - 1][0] == 1 ||
				CMCheckersBoard[yLoc - 1][0] == 2 ||
				CMCheckersBoard[yLoc - 1][0] == 3) &&
				CMCheckersBoard[yLoc - 2][numRowsInBoard - 1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if ((CMCheckersBoard[yLoc + 1][0] == 1 ||
					CMCheckersBoard[yLoc + 1][0] == 2 ||
					CMCheckersBoard[yLoc + 1][0] == 3) &&
					CMCheckersBoard[yLoc + 2][numRowsInBoard - 1] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == numRowsInBoard)
		{
			if ((CMCheckersBoard[yLoc - 1][0] == 1 ||
				CMCheckersBoard[yLoc - 1][0] == 2 ||
				CMCheckersBoard[yLoc - 1][0] == 3) &&
				CMCheckersBoard[yLoc - 2][1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if ((CMCheckersBoard[yLoc + 1][0] == 1 ||
					CMCheckersBoard[yLoc + 1][0] == 2 ||
					CMCheckersBoard[yLoc + 1][0] == 3) &&
					CMCheckersBoard[yLoc + 2][1] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == numRowsInBoard - 1)
		{
			if ((CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 1 ||
				CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 2 ||
				CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 3) &&
				CMCheckersBoard[yLoc - 2][0] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if ((CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 1 ||
					CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 2 ||
					CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 3) &&
					CMCheckersBoard[yLoc + 2][0] == 0)
				{
					return true;
				}
			}
		}
		else if (((CMCheckersBoard[yLoc - 1][xLoc + 1] == 1 ||
			CMCheckersBoard[yLoc - 1][xLoc + 1] == 2 ||
			CMCheckersBoard[yLoc - 1][xLoc + 1] == 3) &&
			CMCheckersBoard[yLoc - 2][xLoc + 2] == 0) ||
			((CMCheckersBoard[yLoc - 1][xLoc - 1] == 1 ||
				CMCheckersBoard[yLoc - 1][xLoc - 1] == 2 ||
				CMCheckersBoard[yLoc - 1][xLoc - 1] == 3) &&
				CMCheckersBoard[yLoc - 2][xLoc - 2] == 0))
		{

			return true;
		}
		else if (CMCheckersBoard[yLoc][xLoc] == 6)
		{
			if (((CMCheckersBoard[yLoc + 1][xLoc + 1] == 1 ||
				CMCheckersBoard[yLoc + 1][xLoc + 1] == 2 ||
				CMCheckersBoard[yLoc + 1][xLoc + 1] == 3) &&
				CMCheckersBoard[yLoc + 2][xLoc + 2] == 0) ||
				((CMCheckersBoard[yLoc + 1][xLoc - 1] == 1 ||
					CMCheckersBoard[yLoc + 1][xLoc - 1] == 2 ||
					CMCheckersBoard[yLoc + 1][xLoc - 1] == 3) &&
					CMCheckersBoard[yLoc + 2][xLoc - 2] == 0))
			{
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

bool CheckWin(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	int whiteNotMules = 0;
	int whiteMules = 0;
	int redNotMules = 0;
	int redMules = 0;

	for (i = 0; i < numRowsInBoard; i++)
	{
		for (j = 0; j < numRowsInBoard; j++)
		{
			if (CMCheckersBoard[i][j] == 1 || CMCheckersBoard[i][j] == 3)
			{
				whiteNotMules++;
			}
			else if (CMCheckersBoard[i][j] == 2)
			{
				whiteMules++;
			}
			else if (CMCheckersBoard[i][j] == 4 || CMCheckersBoard[i][j] == 6)
			{
				redNotMules++;
			}
			else if (CMCheckersBoard[i][j] == 5)
			{
				redMules++;
			}
		}
	}
	if (whiteMules == 0)
	{
		cout << "The White Player has won the game by losing all of the White Mules";
		return true;
	}
	else if (whiteNotMules == 0)
	{
		cout << "The Red Player has won by capturing all of the white players soldiers and kings";
		return true;
	}
	else if (redMules == 0)
	{
		cout << "The Red Player has won the game by losing all of the Red Mules";
		return true;
	}
	else if (redNotMules == 0)
	{
		cout << "The White Player has won by capturing all of the red players soldiers and kings";
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	//declaring variables
	int numOfTries = 0; //counter for error in selecting size of board
	int numTurn = 0;
	int player = 0;
	int end;
	string EndGame; //holding character to end the game
	int MovePositionInitial = 0;
	int MovePositionFinal = 0;
	int ArrayRowInitial = 0;
	int ArrayColumnInitial = 0;
	int ArrayRowFinal = 0;
	int ArrayColumnFinal = 0;
	int numRowsInBoard = 0;
	int sizeBoard = 0;
	sizeBoard = (numRowsInBoard * numRowsInBoard);
	int myCMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };
	int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };
	int DisplayCopy[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };

	int xIndicesMove[MAX_PIECES];
	int yIndicesMove[MAX_PIECES];

	int xIndicesJump[MAX_PIECES];
	int yIndicesJump[MAX_PIECES];

	int xLocArray[MAX_ARRAY_SIZE];
	int yLocArray[MAX_ARRAY_SIZE];

	bool jumped;
	int xLoc[MAX_ARRAY_SIZE] = { 0 };
	int yLoc[MAX_ARRAY_SIZE] = { 0 };
	int index = 0;


	//getting size of board
	//checking if size is a valid input
	while (numOfTries <= 3)
	{
		if (numOfTries >= 3)
		{
			"ERROR: Too many erros entering the size of the board.";
			return 1;
		}
		numOfTries++;
		cout << "Enter the number of squares along each edge of the board" << endl;
		cin >> numRowsInBoard;
		if (cin.fail())
		{
			cerr << "ERROR: Board size is not an integer" << endl;
			cout << "8 <= number of squares <= 18" << endl;
			cin.clear();
			cin.ignore();
			continue;
		}
		if (!(numRowsInBoard % 2 == 0))
		{
			cerr << "ERROR: Board size is odd." << endl;
			cout << "8 <= number of squares <= 18" << endl;
			continue;
		}
		if (numRowsInBoard > 18)
		{
			cerr << "ERROR: Board size too large." << endl;
			cout << "8 <= number of squares <= 18" << endl;
			continue;
		}
		if (numRowsInBoard < 8)
		{
			cerr << "ERROR: Board size too small." << endl;
			cout << "8 <= number of squares <= 18" << endl;
			continue;
		}
		else
		{
			sizeBoard = (numRowsInBoard * numRowsInBoard);
			break;
		}

	}

	InitializeBoard(CMCheckersBoard, numRowsInBoard);
	DisplayBoard(CMCheckersBoard, numRowsInBoard);

	numTurn = 1;
	while (true)
	{

		if (!(numTurn % 2 == 0))
		{
			player = 1;
			if (CountJumps(CMCheckersBoard, numRowsInBoard, player, xLocArray, yLocArray) == 0 && CountMove1Squares(CMCheckersBoard, numRowsInBoard, player, xLocArray, yLocArray) == 0) //white wins (player 2 as 0 moves)
			{
				cout << "Red is unable to move." << endl << "GAME OVER, White has won." << endl << "Enter any character to close the game." << endl;
				getline(cin, EndGame);
				if (!EndGame.empty())
				{
					return 0;
				}
			}
			cout << "White takes a turn" << endl;
			while (true)  //for white player
			{
				cout << "Enter the square number of the checker you want to move" << endl;
				cin >> MovePositionInitial;
				ArrayRowInitial = MovePositionInitial / numRowsInBoard;
				ArrayColumnInitial = MovePositionInitial % numRowsInBoard;

				if (cin.fail())
				{
					cerr << "ERROR: Board size is not an integer" << endl;
					cout << "8 <= number of squares <= 18" << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
				else if (MovePositionInitial > sizeBoard || MovePositionInitial < 0)
				{
					cout << "ERROR: That square is not on the board." << endl << "Try again" << endl;
					continue;
				}
				else if (CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == REDSOLDIER || CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == REDMULE || CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == REDKING)
				{
					cout << "ERROR: That square contrains an oppenent's checker." << endl << "Try again" << endl;
					continue;
				}
				else if (CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == 0)
				{
					cout << "ERROR: That square is empty." << endl << "Try again" << endl;
					continue;
				}
				else if (!IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayRowInitial, ArrayColumnInitial) && (CountJumps(CMCheckersBoard, numRowsInBoard, player, xLoc, yLoc) > 0))
				{
					cout << "ERROR: You can jump with another checker, you may not move your chosen checker." << endl;
					cout << "You can jump using checkers on the following squares:" << endl;
					cout << "Try again" << endl;
					continue;
				}
				else if (!(IsMove1Square(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial)) && !(IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial))) //cannot jump or move at all
				{

					cout << "ERROR: There is no legal move for this checker." << endl << "Try again" << endl;
					continue;
				}
				else
				{
					break;
				}

			}

			cout << "Enter square number you want to move to:" << endl;
			while (true)
			{
				cin >> MovePositionFinal;
				ArrayRowFinal = MovePositionFinal / numRowsInBoard;
				ArrayColumnFinal = MovePositionFinal % numRowsInBoard;

				if (cin.fail())
				{
					cerr << "ERROR: Board size is not an integer" << endl;
					cout << "8 <= number of squares <= 18" << endl;
					cin.clear();
					cin.ignore();
					continue;
				}

				else if (MovePositionFinal > sizeBoard || MovePositionFinal < 0)
				{
					cout << "ERROR: That square is not on the board." << endl << "Try again" << endl;
					continue;
				}

				else if (CMCheckersBoard[ArrayRowFinal][ArrayRowFinal] != 0) //occupied position
				{
					cout << "ERROR: It is not possible to move to a square that is already occupied." << endl << "Try again" << endl;
					continue;
				}
				else if (IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial) && CMCheckersBoard[yLoc[index]][xLoc[index]] != CMCheckersBoard[ArrayRowFinal][ArrayColumnFinal])//if the chosen square is able to jump someone but choses not to
				{
					cout << "ERROR: You can jump with this checker, you must not move 1 space." << endl << "Try again" << endl;
					continue;
				}
				else
				{
					//MakeMove(CMCheckersBoard, numRowsInBoard, player, MovePositionInitial, MovePositionFinal, jumped);
					//DisplayBoard(CMCheckersBoard, numRowsInBoard);

					if (MakeMove(CMCheckersBoard, numRowsInBoard, player, MovePositionInitial, MovePositionFinal, jumped) == false)
					{
						DisplayBoard(CMCheckersBoard, numRowsInBoard);
						continue;
					

					}
					else
					{
						DisplayBoard(CMCheckersBoard, numRowsInBoard);
						if (jumped == true)
						{
							if (IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnFinal, ArrayRowFinal))
							{
								MovePositionInitial = MovePositionFinal;
								MovePositionFinal = 0;
								cout << "Enter square number you want to move to:" << endl;
								continue;

							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		else
		{
			player = 2;
			if (CountJumps(CMCheckersBoard, numRowsInBoard, player, xLocArray, yLocArray) == 0 && CountMove1Squares(CMCheckersBoard, numRowsInBoard, player, xLocArray, yLocArray) == 0) //white wins (player 2 as 0 moves)
			{
				cout << "White is unable to move." << endl << "GAME OVER, Red has won." << endl << "Enter any character to close the game." << endl;
				getline(cin, EndGame);
				if (!EndGame.empty())
				{
					return 0;
				}
			}
			cout << "Red takes a turn" << endl;
			while (true)  //for red player
			{
				cout << "Enter the square number of the checker you want to move" << endl;
				cin >> MovePositionInitial;
				ArrayRowInitial = MovePositionInitial / numRowsInBoard;
				ArrayColumnInitial = MovePositionInitial % numRowsInBoard;

				if (cin.fail())
				{
					cerr << "ERROR: Board size is not an integer" << endl;
					cout << "8 <= number of squares <= 18" << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
				else if (MovePositionInitial > sizeBoard || MovePositionInitial < 0)
				{
					cout << "ERROR: That square is not on the board." << endl << "Try again" << endl;
					continue;
				}
				else if (CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == WHITESOLDIER || CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == WHITEMULE || CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == WHITEKING)
				{
					cout << "ERROR: That square contrains an oppenent's checker." << endl << "Try again" << endl;
					continue;
				}
				else if (CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == 0)
				{
					cout << "ERROR: That square is empty." << endl << "Try again" << endl;
					continue;
				}
				else if (!IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayRowInitial, ArrayColumnInitial) && (CountJumps(CMCheckersBoard, numRowsInBoard, player, xLoc, yLoc) > 0))
				{
					cout << "ERROR: You can jump with another checker, you may not move your chosen checker." << endl;
					cout << "You can jump using checkers on the following squares:" << endl;
					cout << "Try again" << endl;
					continue;
				}
				else if (!(IsMove1Square(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial)) && !(IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial))) //cannot jump or move at all
				{

					cout << "ERROR: There is no legal move for this checker." << endl << "Try again" << endl;
					continue;
				}
				else
				{
					break;
				}

			}

			cout << "Enter square number you want to move to:" << endl;
			while (true)
			{
				cin >> MovePositionFinal;
				ArrayRowFinal = MovePositionFinal / numRowsInBoard;
				ArrayColumnFinal = MovePositionFinal % numRowsInBoard;

				if (cin.fail())
				{
					cerr << "ERROR: Board size is not an integer" << endl;
					cout << "8 <= number of squares <= 18" << endl;
					cin.clear();
					cin.ignore();
					continue;
				}


				else if (MovePositionFinal > sizeBoard || MovePositionFinal < 0)
				{
					cout << "ERROR: That square is not on the board." << endl << "Try again" << endl;
					continue;
				}

				else if (CMCheckersBoard[ArrayRowFinal][ArrayRowFinal] != 0) //occupied position
				{
					cout << "ERROR: It is not possible to move to a square that is already occupied." << endl << "Try again" << endl;
					continue;
				}
				else if (IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial) && CMCheckersBoard[yLoc[index]][xLoc[index]] != CMCheckersBoard[ArrayRowFinal][ArrayColumnFinal])//if the chosen square is able to jump someone but choses not to
				{
					cout << "ERROR: You can jump with this checker, you must not move 1 space." << endl << "Try again" << endl;
					continue;
				}
				else
				{
					//MakeMove(CMCheckersBoard, numRowsInBoard, player, MovePositionInitial, MovePositionFinal, jumped);
					//DisplayBoard(CMCheckersBoard, numRowsInBoard);

					if (MakeMove(CMCheckersBoard, numRowsInBoard, player, MovePositionInitial, MovePositionFinal, jumped) == false)
					{
						DisplayBoard(CMCheckersBoard, numRowsInBoard);
						continue;
					}
			
					else
					{
						DisplayBoard(CMCheckersBoard, numRowsInBoard);
						if (jumped == true)
						{
							if (IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnFinal, ArrayRowFinal))
							{
								MovePositionInitial = MovePositionFinal;
								MovePositionFinal = 0;
								cout << "Enter square number you want to move to:" << endl;
								continue;

							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		numTurn++;
		if (CheckWin(CMCheckersBoard, numRowsInBoard))
		{
			cout << "Enter any character to terminate the game and then press enter enter key" << endl;
			cin >> end;
			return 0;
		}
		else
		{
			DisplayBoard(CMCheckersBoard, numRowsInBoard);
		}
	}
	return 0;
}
