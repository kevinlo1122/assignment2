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
void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],

	int numRowsInBoard);

void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],

	int numRowsInBoard);

int CountJumps(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],

	int numRowsInBoard, int player, int xLocArray[], int yLocArray[]);

bool CheckList(int inArray1[], int inArray2[], int xIndex, int yIndex);

int CountMove1Squares(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],

	int numRowsInBoard, int player, int xLocArray[], int yLocArray[]);

bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],

	int numRowsInBoard, int player, int xLoc, int yLoc);

bool IsJump(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],

	int numRowsInBoard, int player, int xLoc, int yLoc);

bool MakeMove(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],

	int numRowsInBoard, int player, int fromSquareNum,

	int toSquareNum, bool &jumped);

bool CheckWin(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

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

int CountJumps(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLocArray[], int yLocArray[])
{	
	int numJumps = 0;
	int index;
	int xIndex;
	int yIndex;

	for (index = 0; index < numRowsInBoard ; index++)
	{
		yLocArray[index] = -1;
		xLocArray[index] = -1;
	}

	for (xIndex = 0; xIndex < numRowsInBoard; xIndex++)
	{
		for (yIndex = 0; yIndex < NumRowsInBoard; yIndex++)
		{
			if (CMCheckersBoard[xIndex][yIndex] == 0)
			{
				continue;
			}
			
			if ( IsJump( CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
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

int CountMove1Squares(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLocArray[], int yLocArray[])
{	
	int numMove1Square = 0;
	int index;
	int xIndex;
	int yIndex;

	for (index = 0; index < numRowsInBoard ; index++)
	{
		yLocArray[index] = -1;
		xLocArray[index] = -1;
	}

	for (xIndex = 0; xIndex < numRowsInBoard; xIndex++)
	{
		for (yIndex = 0; yIndex < NumRowsInBoard; yIndex++)
		{
			if (CMCheckersBoard[xIndex][yIndex] == 0)
			{
				continue;
			}
			
			if ( IsJump( IsMove1Square[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
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
=======
void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
	int i = 0;
	int j = 0;
	int boardPosition = 0;
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
				CMCheckersBoard[i][j] = boardPosition;
				cout << setw(4) << CMCheckersBoard[i][j];
				boardPosition++;
			}
		}
	}

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
	char character;
	if (player == WHITEPLAYER)
	{
		for (rowFrom = 0; rowFrom < numRowsInBoard; rowFrom++)
		{
			if (fromSquareNum >= numRowsFrom && fromSquareNum < minusNumRowsFrom)
			{
				break;
			}
			numRowsFrom += 10;
			minusNumRowsFrom += 10;
		}
		column_From = rowFrom * numRowsInBoard;
		minusNumColumnsFrom = column_From + minusNum;

		for (column_From = rowFrom * numRowsInBoard; column_From <= minusNumColumnsFrom; column_From++)
		{
			if (fromSquareNum == column_From)
			{
				break;
			}
			columnFrom++;
		}
		xDistanceFrom = columnFrom;
		yDistanceFrom = rowFrom;

		for (rowTo = 0; rowTo < numRowsInBoard; rowTo++)
		{
			if (toSquareNum >= numRowsTo && toSquareNum < minusNumRowsTo)
			{
				break;
			}
			numRowsTo += 10;
			minusNumRowsTo += 10;
		}
		column_To = rowTo * numRowsInBoard;
		minusNumColumnsTo = column_To + minusNum;

		for (column_To = rowTo * numRowsInBoard; column_To <= minusNumColumnsTo; column_To++)
		{
			if (toSquareNum == column_To)
			{
				break;
			}
			columnTo++;
		}
		xDistanceTo = columnTo;
		yDistanceTo = rowTo;

		xDistance = abs(xDistanceTo - xDistanceFrom);
		yDistance = abs(yDistanceTo - yDistanceFrom);

		if ((xDistance == 2 && yDistance == 2) || (xDistance == minusNum - 1 && yDistance == 2))//moved 2 squares
		{
			if (column_From == minusNumColumnsFrom || column_From == minusNumColumnsFrom - 1 || column_From == rowFrom * numRowsInBoard || column_From == rowFrom * numRowsInBoard + 1) 
			{
				if ((column_From == minusNumColumnsFrom) && (xDistance == minusNum - 1 && yDistance == 2))
				{
					if ((yDistanceTo - yDistanceFrom) > 0)
					{
						if (CMCheckersBoard[rowFrom + 1][columnFrom - minusNum] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						else if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE))
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom + 1][columnFrom - minusNum] = 0;
					}
					else if ((yDistanceTo - yDistanceFrom) < 0)
					{
						if (CMCheckersBoard[rowFrom - 1][columnFrom - minusNum] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom - 1][columnFrom - minusNum] = 0;
					}
					jumped = true;
					temp = CMCheckersBoard[rowFrom][columnFrom];
					CMCheckersBoard[rowFrom][columnFrom] = 0;
					CMCheckersBoard[rowTo][columnTo] = temp;

					if (CMCheckersBoard[rowTo][columnTo] == WHITEMULE && rowTo == 0)
					{
						CMCheckersBoard[rowTo][columnTo] = WHITEKING;
						cout << "White has created a Mule King, Red wins the game" << endl;
						cout << "Enter any character to terminate the game then press the enter key";
						cin >> character;
						exit(0);

					}
					else if (CMCheckersBoard[rowTo][columnTo] == WHITESOLDIER && rowTo == 0)
					{
						move = true;
						return move;
					}
					move = true;
					return move;
				}
				else if ((column_From == minusNumColumnsFrom - 1) && (xDistance == minusNum - 1 && yDistance == 2))
				{
					if ((yDistanceTo - yDistanceFrom) > 0)
					{
						if (CMCheckersBoard[rowFrom + 1][columnFrom + 1] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						else if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE))
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom + 1][columnFrom + 1] = 0;
					}
					else if ((yDistanceTo - yDistanceFrom) < 0)
					{
						if (CMCheckersBoard[rowFrom - 1][columnFrom + 1] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom - 1][columnFrom + 1] = 0;
					}
					jumped = true;
					temp = CMCheckersBoard[rowFrom][columnFrom];
					CMCheckersBoard[rowFrom][columnFrom] = 0;
					CMCheckersBoard[rowTo][columnTo] = temp;

					if (CMCheckersBoard[rowTo][columnTo] == WHITEMULE && rowTo == 0)
					{
						CMCheckersBoard[rowTo][columnTo] = WHITEKING;
						cout << "White has created a Mule King, Red wins the game" << endl;
						cout << "Enter any character to terminate the game then press the enter key";
						cin >> character;
						exit(0);
					}
					else if (CMCheckersBoard[rowTo][columnTo] == WHITESOLDIER && rowTo == 0)
					{
						move = true;
						return move;
					}
					move = true;
					return move;
				}
				else if ((column_From == rowFrom * numRowsInBoard) && (xDistance == minusNum - 1 && yDistance == 2))
				{
					if ((yDistanceTo - yDistanceFrom) > 0)
					{
						if (CMCheckersBoard[rowFrom + 1][columnFrom + minusNum] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						else if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE))
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom + 1][columnFrom + minusNum] = 0;
					}
					else if ((yDistanceTo - yDistanceFrom) < 0)
					{
						if (CMCheckersBoard[rowFrom - 1][columnFrom + minusNum] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom - 1][columnFrom + minusNum] = 0;
					}
					jumped = true;
					temp = CMCheckersBoard[rowFrom][columnFrom];
					CMCheckersBoard[rowFrom][columnFrom] = 0;
					CMCheckersBoard[rowTo][columnTo] = temp;

					if (CMCheckersBoard[rowTo][columnTo] == WHITEMULE && rowTo == 0)
					{
						CMCheckersBoard[rowTo][columnTo] = WHITEKING;
						cout << "White has created a Mule King, Red wins the game" << endl;
						cout << "Enter any character to terminate the game then press the enter key";
						cin >> character;
						exit(0);
					}
					else if (CMCheckersBoard[rowTo][columnTo] == WHITESOLDIER && rowTo == 0)
					{
						move = true;
						return move;
					}
					move = true;
					return move;
				}
				else if ((column_From == rowFrom * numRowsInBoard) + 1 && (xDistance == minusNum - 1 && yDistance == 2))
				{
						
					if ((yDistanceTo - yDistanceFrom) > 0)
					{
						if (CMCheckersBoard[rowFrom + 1][columnFrom + 1] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						else if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE))
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom + 1][columnFrom + 1] = 0;
					}
					else if ((yDistanceTo - yDistanceFrom) < 0)
					{
						if (CMCheckersBoard[rowFrom - 1][columnFrom + 1] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom - 1][columnFrom + 1] = 0;
					}
					jumped = true;
					temp = CMCheckersBoard[rowFrom][columnFrom];
					CMCheckersBoard[rowFrom][columnFrom] = 0;
					CMCheckersBoard[rowTo][columnTo] = temp;

					if (CMCheckersBoard[rowTo][columnTo] == WHITEMULE && rowTo == 0)
					{
						CMCheckersBoard[rowTo][columnTo] = WHITEKING;
						cout << "White has created a Mule King, Red wins the game" << endl;
						cout << "Enter any character to terminate the game then press the enter key";
						cin >> character;
						exit(0);
					}
					else if (CMCheckersBoard[rowTo][columnTo] == WHITESOLDIER && rowTo == 0)
					{
						move = true;
						return move;
					}
					move = true;
					return move;
				}
			}
			else
			{
				if ((yDistanceTo - yDistanceFrom) > 0 && (xDistanceTo - xDistanceFrom) > 0)
				{
					if (CMCheckersBoard[rowFrom + 1][columnFrom + 1] == 0)
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					else if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE))
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					CMCheckersBoard[rowFrom + 1][columnFrom + 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) > 0 && (xDistanceTo - xDistanceFrom) < 0)
				{
					if (CMCheckersBoard[rowFrom + 1][columnFrom - 1] == 0)
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					else if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE))
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					CMCheckersBoard[rowFrom + 1][columnFrom - 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0 && (xDistanceTo - xDistanceFrom) > 0)
				{
					if (CMCheckersBoard[rowFrom - 1][columnFrom + 1] == 0)
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					CMCheckersBoard[rowFrom - 1][columnFrom + 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0 && (xDistanceTo - xDistanceFrom) < 0)
				{
					if (CMCheckersBoard[rowFrom - 1][columnFrom - 1] == 0)
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					CMCheckersBoard[rowFrom - 1][columnFrom - 1] = 0;
				}
				jumped = true;
				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == WHITEMULE && rowTo == 0)
				{
					CMCheckersBoard[rowTo][columnTo] = WHITEKING;
					cout << "White has created a Mule King, Red wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == WHITESOLDIER && rowTo == 0)
				{
					move = true;
					return move;
				}
				move = true;
				return move;
			}
		}
		else if ((xDistance == 1 && yDistance == 1) || (xDistance == minusNum && yDistance == 1))//moved 1 square
		{
			if ((column_From == minusNumColumnsFrom) && (xDistance == minusNum && yDistance == 1))
			{
				if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE) && (yDistanceTo - yDistanceFrom) > 0)
				{
					cerr << "Error: illegal move" << endl;
					return move;
				}

				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == WHITEMULE && rowTo == 0)
				{
					CMCheckersBoard[rowTo][columnTo] = WHITEKING;
					cout << "White has created a Mule King, Red wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == WHITESOLDIER && rowTo == 0)
				{
					move = true;
					return move;
				}
				move = true;
				return move;
			}
			else if ((column_From == rowFrom * numRowsInBoard) && (xDistance == minusNum && yDistance == 1))
			{
				if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE) && (yDistanceTo - yDistanceFrom) > 0)
				{
					cerr << "Error: illegal move" << endl;
					return move;
				}

				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == WHITEMULE && rowTo == 0)
				{
					CMCheckersBoard[rowTo][columnTo] = WHITEKING;
					cout << "White has created a Mule King, Red wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == WHITESOLDIER && rowTo == 0)
				{
					move = true;
					return move;
				}
				move = true;
				return move;
			}
			else
			{
				if ((CMCheckersBoard[rowFrom][columnFrom] == WHITESOLDIER || CMCheckersBoard[rowFrom][columnFrom] == WHITEMULE) && (yDistanceTo - yDistanceFrom) > 0)
				{
					cerr << "Error: illegal move" << endl;
					return move;
				}

				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == WHITEMULE && rowTo == 0)
				{
					CMCheckersBoard[rowTo][columnTo] = WHITEKING;
					cout << "White has created a Mule King, Red wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == WHITESOLDIER && rowTo == 0)
				{
					move = true;
					return move;
				}
				move = true;
				return move;
			}
		}
		else
		{
			cerr << "Error: illegal move" << endl;
			return move;
		}
		
		return move;
		
	}
	else if (player == REDPLAYER)
	{
		for (rowFrom = 0; rowFrom < numRowsInBoard; rowFrom++)
		{
			if (fromSquareNum >= numRowsFrom && fromSquareNum < minusNumRowsFrom)
			{
				break;
			}
			numRowsFrom += 10;
			minusNumRowsFrom += 10;
		}
		column_From = rowFrom * numRowsInBoard;
		minusNumColumnsFrom = column_From + minusNum;

		for (column_From = rowFrom * numRowsInBoard; column_From <= minusNumColumnsFrom; column_From++)
		{
			if (fromSquareNum == column_From)
			{
				break;
			}
			columnFrom++;
		}
		xDistanceFrom = columnFrom;
		yDistanceFrom = rowFrom;


		/*for (columnFrom = 0; columnFrom < numRowsInBoard; columnFrom++)
		{
			if (fromSquareNum >= numColumnsFrom && fromSquareNum < minusNumColumnsFrom)
			{
				break;
			}
			numColumnsFrom += 10;
			minusNumColumnsFrom += 10;
		}
		xDistanceFrom = rowFrom + 1;
		yDistanceFrom = columnFrom + 1;*/

		for (rowTo = 0; rowTo < numRowsInBoard; rowTo++)
		{
			if (toSquareNum >= numRowsTo && toSquareNum < minusNumRowsTo)
			{
				break;
			}
			numRowsTo += 10;
			minusNumRowsTo += 10;
		}
		column_To = rowTo * numRowsInBoard;
		minusNumColumnsTo = column_To + minusNum;

		for (column_To = rowTo * numRowsInBoard; column_To <= minusNumColumnsTo; column_To++)
		{
			if (toSquareNum == column_To)
			{
				break;
			}
			columnTo++;
		}
		xDistanceTo = columnTo;
		yDistanceTo = rowTo;

		xDistance = abs(xDistanceTo - xDistanceFrom);
		yDistance = abs(yDistanceTo - yDistanceFrom);

		if ((xDistance == 2 && yDistance == 2) || (xDistance == minusNum - 1 && yDistance == 2))//moved 2 squares
		{
			if (column_From == minusNumColumnsFrom || column_From == minusNumColumnsFrom - 1 || column_From == rowFrom * numRowsInBoard || column_From == rowFrom * numRowsInBoard + 1)
			{
				if ((column_From == minusNumColumnsFrom) && (xDistance == minusNum - 1 && yDistance == 2))
				{
					if ((yDistanceTo - yDistanceFrom) > 0)
					{
						if (CMCheckersBoard[rowFrom + 1][columnFrom - minusNum] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom + 1][columnFrom - minusNum] = 0;
					}
					else if ((yDistanceTo - yDistanceFrom) < 0)
					{
						if (CMCheckersBoard[rowFrom - 1][columnFrom - minusNum] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						else if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE))
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom - 1][columnFrom - minusNum] = 0;
					}
					jumped = true;
					temp = CMCheckersBoard[rowFrom][columnFrom];
					CMCheckersBoard[rowFrom][columnFrom] = 0;
					CMCheckersBoard[rowTo][columnTo] = temp;

					if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == 0)
					{
						CMCheckersBoard[rowTo][columnTo] = REDKING;
						cout << "Red has created a Mule King,  White wins the game" << endl;
						cout << "Enter any character to terminate the game then press the enter key";
						cin >> character;
						exit(0);
					}
					else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == 0)
					{
						move = true;
						return move;
					}
					move = true;
					return move;
				}
				else if ((column_From == minusNumColumnsFrom - 1) && (xDistance == minusNum - 1 && yDistance == 2))
				{
					if ((yDistanceTo - yDistanceFrom) > 0)
					{
						if (CMCheckersBoard[rowFrom + 1][columnFrom + 1] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom + 1][columnFrom + 1] = 0;
					}
					else if ((yDistanceTo - yDistanceFrom) < 0)
					{
						if (CMCheckersBoard[rowFrom - 1][columnFrom + 1] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						else if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE))
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom - 1][columnFrom + 1] = 0;
					}
					jumped = true;
					temp = CMCheckersBoard[rowFrom][columnFrom];
					CMCheckersBoard[rowFrom][columnFrom] = 0;
					CMCheckersBoard[rowTo][columnTo] = temp;

					if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == 0)
					{
						CMCheckersBoard[rowTo][columnTo] = REDKING;
						cout << "Red has created a Mule King,  White wins the game" << endl;
						cout << "Enter any character to terminate the game then press the enter key";
						cin >> character;
						exit(0);
					}
					else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == 0)
					{
						move = true;
						return move;
					}
					move = true;
					return move;
				}
				else if ((column_From == rowFrom * numRowsInBoard) && (xDistance == minusNum - 1 && yDistance == 2))
				{
					if ((yDistanceTo - yDistanceFrom) > 0)
					{
						if (CMCheckersBoard[rowFrom + 1][columnFrom + minusNum] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom + 1][columnFrom + minusNum] = 0;
					}
					else if ((yDistanceTo - yDistanceFrom) < 0)
					{
						if (CMCheckersBoard[rowFrom - 1][columnFrom + minusNum] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						else if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE))
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom - 1][columnFrom + minusNum] = 0;
					}
					jumped = true;
					temp = CMCheckersBoard[rowFrom][columnFrom];
					CMCheckersBoard[rowFrom][columnFrom] = 0;
					CMCheckersBoard[rowTo][columnTo] = temp;

					if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == 0)
					{
						CMCheckersBoard[rowTo][columnTo] = REDKING;
						cout << "Red has created a Mule King,  White wins the game" << endl;
						cout << "Enter any character to terminate the game then press the enter key";
						cin >> character;
						exit(0);
					}
					else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == 0)
					{
						move = true;
						return move;
					}
					move = true;
					return move;
				}
				else if ((column_From == rowFrom * numRowsInBoard + 1) && (xDistance == minusNum - 1 && yDistance == 2))
				{
						
					if ((yDistanceTo - yDistanceFrom) > 0)
					{
						if (CMCheckersBoard[rowFrom + 1][columnFrom + 1] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom + 1][columnFrom + 1] = 0;
					}
					else if ((yDistanceTo - yDistanceFrom) < 0)
					{
						if (CMCheckersBoard[rowFrom - 1][columnFrom + 1] == 0)
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						else if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE))
						{
							cerr << "Error: illegal move" << endl;
							return move;
						}
						CMCheckersBoard[rowFrom - 1][columnFrom + 1] = 0;
					}
					jumped = true;
					temp = CMCheckersBoard[rowFrom][columnFrom];
					CMCheckersBoard[rowFrom][columnFrom] = 0;
					CMCheckersBoard[rowTo][columnTo] = temp;

					if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == 0)
					{
						CMCheckersBoard[rowTo][columnTo] = REDKING;
						cout << "Red has created a Mule King,  White wins the game" << endl;
						cout << "Enter any character to terminate the game then press the enter key";
						cin >> character;
						exit(0);
					}
					else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == 0)
					{
						move = true;
						return move;
					}
					move = true;
					return move;
				}
			}
			else
			{
				if ((yDistanceTo - yDistanceFrom) > 0 && (xDistanceTo - xDistanceFrom) > 0)
				{
					if (CMCheckersBoard[rowFrom + 1][columnFrom + 1] == 0)
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					CMCheckersBoard[rowFrom + 1][columnFrom + 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) > 0 && (xDistanceTo - xDistanceFrom) < 0)
				{
					if (CMCheckersBoard[rowFrom + 1][columnFrom - 1] == 0)
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					CMCheckersBoard[rowFrom + 1][columnFrom - 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0 && (xDistanceTo - xDistanceFrom) > 0)
				{
					if (CMCheckersBoard[rowFrom - 1][columnFrom + 1] == 0)
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					else if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE))
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					CMCheckersBoard[rowFrom - 1][columnFrom + 1] = 0;
				}
				else if ((yDistanceTo - yDistanceFrom) < 0 && (xDistanceTo - xDistanceFrom) < 0)
				{
					if (CMCheckersBoard[rowFrom - 1][columnFrom - 1] == 0)
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					else if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE))
					{
						cerr << "Error: illegal move" << endl;
						return move;
					}
					CMCheckersBoard[rowFrom - 1][columnFrom - 1] = 0;
				}
				jumped = true;
				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == 0)
				{
					CMCheckersBoard[rowTo][columnTo] = REDKING;
					cout << "Red has created a Mule King,  White wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == 0)
				{
					move = true;
					return move;
				}
				move = true;
				return move;
				

			}
		}
		else if ((xDistance == 1 && yDistance == 1) || (xDistance == minusNum && yDistance == 1))//moved 1 square
		{
			if ((column_From == minusNumColumnsFrom) && (xDistance == minusNum && yDistance == 1))
			{
				if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE) && (yDistanceTo - yDistanceFrom) < 0)
				{
					cerr << "Error: illegal move" << endl;
					return move;
				}

				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == 0)
				{
					CMCheckersBoard[rowTo][columnTo] = REDKING;
					cout << "Red has created a Mule King,  White wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == 0)
				{
					move = true;
					return move;
				}
				move = true;
				return move;
			}
			else if ((column_From == rowFrom * numRowsInBoard) && (xDistance == minusNum && yDistance == 1))
			{
				if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE) && (yDistanceTo - yDistanceFrom) < 0)
				{
					cerr << "Error: illegal move" << endl;
					return move;
				}

				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == 0)
				{
					CMCheckersBoard[rowTo][columnTo] = REDKING;
					cout << "Red has created a Mule King,  White wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == 0)
				{
					move = true;
					return move;
				}
				move = true;
				return move;
			}
			else
			{
				if ((CMCheckersBoard[rowFrom][columnFrom] == REDSOLDIER || CMCheckersBoard[rowFrom][columnFrom] == REDMULE) && (yDistanceTo - yDistanceFrom) < 0)
				{
					cerr << "Error: illegal move" << endl;
					return move;
				}

				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == 0)
				{
					CMCheckersBoard[rowTo][columnTo] = REDKING;
					cout << "Red has created a Mule King,  White wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == 0)
				{
					move = true;
					return move;
				}
				move = true;
				return move;
			}
		}
		else
		{
			cerr << "Error: illegal move" << endl;
			return move;
		}
	}
  
}

bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLoc, int yLoc)
{
	if (player == 1)
	{
		if (xLoc == 0)
		{
			if (CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[xLoc][yLoc] == 3)
			{
				if (CMCheckersBoard[numRowsInBoard -1][yLoc - 1] == 0)
				{
					return true;
				}
		}
		else if (xLoc == numRowsInBoard)
		{
			if (CMCheckersBoard[0][yLoc + 1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[xLoc][yLoc] == 3)
			{
				if (CMCheckersBoard[0][yLoc - 1] == 0)
				{
					return true;
				}
			}
		}
		else if (CMCheckersBoard[xLoc + 1][yLoc + 1] == 0 || CMCheckersBoard[xLoc - 1][yLoc + 1] == 0)
		{
			return true;
		}
		else if (CMCheckersBoard[xLoc][yLoc] == 3)
		{
			if (CMCheckersBoard[xLoc + 1][yLoc - 1] == 0 || CMCheckersBoard[xLoc - 1][yLoc - 1] == 0)
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
			if (CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[xLoc][yLoc] == 3)
			{
				if (CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == numRowsInBoard)
		{
			if (CMCheckersBoard[0][yLoc - 1] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[xLoc][yLoc] == 6)
			{
				if (CMCheckersBoard[0][yLoc + 1] == 0)
				{
					return 0;
				}
			}
		}
		else if (CMCheckersBoard[xLoc + 1][yLoc - 1] == 0 || CMCheckersBoard[xLoc - 1][yLoc - 1] == 0)
		{
			return true;
		}
		else if (CMCheckersBoard[xLoc][yLoc] == 6)
		{
			if (CMCheckersBoard[xLoc + 1][yLoc + 1] == 0 || CMCheckersBoard[xLoc - 1][yLoc + 1] == 0)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

bool IsJump(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE],
	int numRowsInBoard, int player, int xLoc, int yLoc)
{
	if (player == 1)
	{
		if (xLoc == 0)
		{
			if ((CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 4 ||
				CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 5 ||
				CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 6) &&
				CMCheckersBoard[numRowsInBoard - 2][yLoc + 2] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[xLoc][yLoc] == 3)
			{
				if ((CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 4 ||
					CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 5 ||
					CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 6) &&
					CMCheckersBoard[numRowsInBoard - 2][yLoc - 2] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == 1)
		{
			if ((CMCheckersBoard[0][yLoc + 1] == 4 ||
				CMCheckersBoard[0][yLoc + 1] == 5 ||
				CMCheckersBoard[0][yLoc + 1] == 6) &&
				CMCheckersBoard[numRowsInBoard - 1][yLoc + 2] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[xLoc][yLoc] == 3)
			{
				if ((CMCheckersBoard[0][yLoc - 1] == 4 ||
					CMCheckersBoard[0][yLoc - 1] == 5 ||
					CMCheckersBoard[0][yLoc - 1] == 6) &&
					CMCheckersBoard[numRowsInBoard - 1][yLoc - 2] == 0)
				{
					return 0;
				}
			}
		}
		else if (xLoc == numRowsInBoard)
		{
			if ((CMCheckersBoard[0][yLoc + 1] == 4 ||
				CMCheckersBoard[0][yLoc + 1] == 5 ||
				CMCheckersBoard[0][yLoc + 1] == 6) &&
				CMCheckersBoard[1][yLoc + 2] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[xLoc][yLoc] == 3)
			{
				if ((CMCheckersBoard[0][yLoc - 1] == 4 ||
					CMCheckersBoard[0][yLoc - 1] == 5 ||
					CMCheckersBoard[0][yLoc - 1] == 6) &&
					CMCheckersBoard[1][yLoc - 2] == 0)
				{
					return true;
				}
			}
		}
		else if (xLoc == numRowsInBoard - 1)
		{
			if ((CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 4 ||
				CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 5 ||
				CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 6) &&
				CMCheckersBoard[0][yLoc + 2] == 0)
			{
				return true;
			}
			else if (CMCheckersBoard[xLoc][yLoc] == 3)
			{
				if ((CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 4 ||
					CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 5 ||
					CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 6) &&
					CMCheckersBoard[0][yLoc - 2] == 0)
				{
					return true;
				}
			}
		}
		else if (((CMCheckersBoard[xLoc + 1][yLoc + 1] == 4 ||
			CMCheckersBoard[xLoc + 1][yLoc + 1] == 5 ||
			CMCheckersBoard[xLoc + 1][yLoc + 1] == 6) &&
			CMCheckersBoard[xLoc + 2][yLoc + 2] == 0) ||
			((CMCheckersBoard[xLoc - 1][yLoc + 1] == 4 ||
				CMCheckersBoard[xLoc - 1][yLoc + 1] == 5 ||
				CMCheckersBoard[xLoc - 1][yLoc + 1] == 6) &&
				CMCheckersBoard[xLoc - 2][yLoc + 2] == 0))
		{
			return true;
		}
		else if (CMCheckersBoard[xLoc][yLoc] == 3)
		{
			if (((CMCheckersBoard[xLoc + 1][yLoc - 1] == 4 ||
				CMCheckersBoard[xLoc + 1][yLoc - 1] == 5 ||
				CMCheckersBoard[xLoc + 1][yLoc - 1] == 6) &&
				CMCheckersBoard[xLoc + 2][yLoc - 2] == 0) ||
				((CMCheckersBoard[xLoc - 1][yLoc - 1] == 4 ||
					CMCheckersBoard[xLoc - 1][yLoc - 1] == 5 ||
					CMCheckersBoard[xLoc - 1][yLoc - 1] == 6) &&
					CMCheckersBoard[xLoc - 2][yLoc - 2] == 0))
			{
				return true;
			}
			else
			{
				return false;
			}
			if (player == 2)
			{
				if (xLoc == 0)
				{
					if ((CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 1 ||
						CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 2 ||
						CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 3) &&
						CMCheckersBoard[numRowsInBoard - 2][yLoc - 2] == 0)
					{
						return true;
					}
					else if (CMCheckersBoard[xLoc][yLoc] == 6)
					{
						if ((CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 1 ||
							CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 2 ||
							CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 3) &&
							CMCheckersBoard[numRowsInBoard - 2][yLoc + 2] == 0)
						{
							return true;
						}
					}
				}
				else if (xLoc == 1)
				{
					if ((CMCheckersBoard[0][yLoc - 1] == 1 ||
						CMCheckersBoard[0][yLoc - 1] == 2 ||
						CMCheckersBoard[0][yLoc - 1] == 3) &&
						CMCheckersBoard[numRowsInBoard - 1][yLoc - 2] == 0)
					{
						return true;
					}
					else if (CMCheckersBoard[xLoc][yLoc] == 6)
					{
						if ((CMCheckersBoard[0][yLoc + 1] == 1 ||
							CMCheckersBoard[0][yLoc + 1] == 2 ||
							CMCheckersBoard[0][yLoc + 1] == 3) &&
							CMCheckersBoard[numRowsInBoard - 1][yLoc + 2] == 0)
						{
							return 0;
						}
					}
				}
				else if (xLoc == numRowsInBoard)
				{
					if ((CMCheckersBoard[0][yLoc - 1] == 1 ||
						CMCheckersBoard[0][yLoc - 1] == 2 ||
						CMCheckersBoard[0][yLoc - 1] == 3) &&
						CMCheckersBoard[1][yLoc - 2] == 0)
					{
						return true;
					}
					else if (CMCheckersBoard[xLoc][yLoc] == 6)
					{
						if ((CMCheckersBoard[0][yLoc + 1] == 1 ||
							CMCheckersBoard[0][yLoc + 1] == 2 ||
							CMCheckersBoard[0][yLoc + 1] == 3) &&
							CMCheckersBoard[1][yLoc + 2] == 0)
						{
							return true;
						}
					}
				}
				else if (xLoc == numRowsInBoard - 1)
				{
					if ((CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 1 ||
						CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 2 ||
						CMCheckersBoard[numRowsInBoard - 1][yLoc - 1] == 3) &&
						CMCheckersBoard[0][yLoc - 2] == 0)
					{
						return true;
					}
					else if (CMCheckersBoard[xLoc][yLoc] == 6)
					{
						if ((CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 1 ||
							CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 2 ||
							CMCheckersBoard[numRowsInBoard - 1][yLoc + 1] == 3) &&
							CMCheckersBoard[0][yLoc + 2] == 0)
						{
							return true;
						}
					}
				}
				else if (((CMCheckersBoard[xLoc + 1][yLoc - 1] == 1 ||
					CMCheckersBoard[xLoc + 1][yLoc - 1] == 2 ||
					CMCheckersBoard[xLoc + 1][yLoc - 1] == 3) &&
					CMCheckersBoard[xLoc + 2][yLoc - 2] == 0) ||
					((CMCheckersBoard[xLoc - 1][yLoc - 1] == 1 ||
						CMCheckersBoard[xLoc - 1][yLoc - 1] == 2 ||
						CMCheckersBoard[xLoc - 1][yLoc - 1] == 3) &&
						CMCheckersBoard[xLoc - 2][yLoc - 2] == 0))
				{
					return true;
				}
				else if (CMCheckersBoard[xLoc][yLoc] == 6)
				{
					if (((CMCheckersBoard[xLoc + 1][yLoc + 1] == 1 ||
						CMCheckersBoard[xLoc + 1][yLoc + 1] == 2 ||
						CMCheckersBoard[xLoc + 1][yLoc + 1] == 3) &&
						CMCheckersBoard[xLoc + 2][yLoc + 2] == 0) ||
						((CMCheckersBoard[xLoc - 1][yLoc + 1] == 1 ||
							CMCheckersBoard[xLoc - 1][yLoc + 1] == 2 ||
							CMCheckersBoard[xLoc - 1][yLoc + 1] == 3) &&
							CMCheckersBoard[xLoc - 2][yLoc + 2] == 0))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}
		}
	}
}

bool CheckWin(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard)
{
	int i;
	int j;
	int whiteNotMules;
	int whiteMules;
	int redNotMules;
	int redMules;

	for (i = 0; i < numRowsInBoard; i++)
	{
		for (j = 0; j < numRowsInBoard; j++)
		{
			if (CMCheckersBoard[i][j] == 1||CMCheckersBoard[i][j]==3)
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
	
	
//main function
int main()
{
	//declaring variables
	int numOfTries = 0; //counter for error in selecting size of board
	int turn = 0;
	string EndGame; //holding character to end the game
	int MovePositionInitial = 0;
	int MovePositionFinal = 0;
	int ArrayRow = 0;
	int ArrayColumn = 0;
	int numRowsInBoard = 0;
	int sizeBoard = 0;
	sizeBoard = (numRowsInBoard * numRowsInBoard);
	int myCMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };
	int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };

	int xIndicesMove[MAX_PIECES];
	int yIndicesMove[MAX_PIECES];

	int xIndicesJump[MAX_PIECES];
	int yIndicesJump[MAX_PIECES];


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
	cout << endl << endl;
	/*
	//for each turn: check if the player has legal move, NEED TO FIX TURN SYSTEM
	while (true)
	{
		CountJumps(); //this will tell how many checkers are avalible to move
		CountMove1Squares(); //this tells how many Mules and Soldiers can be moved and how many kings can be moved
		//if there is no possible moves (return values are 0)
		if (CountJumps() = 0 && CountMove1Squares() = 0) //white wins (player 2 as 0 moves)
		{
			cout << "Red is unable to move." << endl << "GAME OVER, White has won." << endl << "Enter any character to close the game." << endl;
			getline(cin, EndGame);
			if (!EndGame.empty())
			{
				return 0;
			}
		}
		if (CountJumps() = 0 && CountMove1Squares() = 0) //red wins (player 1 has 0 moves)
		{
			cout << "Red is unable to move." << endl << "GAME OVER, White has won." << endl << "Enter any character to close the game." << endl;
			getline(cin, EndGame);
			if (!EndGame.empty())
			{
				return 0;
			}
		}
	}
	*/
	
	while (true) //FOR WHITE PLAYER
	{
		if (turn == 0)
		{
			cout << "White takes a turn" << endl;
			turn = 1;
		}
		cout << "Enter the square number of the checker you want to move" << endl;
		cin >> MovePositionInitial;
		ArrayRow = MovePositionInitial / numRowsInBoard;
		ArrayColumn = MovePositionInitial % numRowsInBoard;

		while (cin.fail()) //not an integer
		{
			cout << "ERROR: You did not enter an integer" << endl << "Try again" << endl;
			cin.clear();
			cin.ignore();
			cin >> MovePositionInitial;
		}
		if (MovePositionInitial > sizeBoard || MovePositionInitial < 0)
		{
			cout << "ERROR: That square is not on the board." << endl << "Try again" << endl;
			continue;
		}
		if (CMCheckersBoard[ArrayRow][ArrayColumn] == 0)
		{
			cout << "ERROR: That square is empty." << endl << "Try again" << endl;
			continue;
		}
		if (CMCheckersBoard[ArrayRow][ArrayColumn] == 4 || CMCheckersBoard[ArrayRow][ArrayColumn] == 5 || CMCheckersBoard[ArrayRow][ArrayColumn] == 6)
		{
			cout << "ERROR: That square contrains an oppenent's checker." << endl << "Try again" << endl;
			continue;
		}

	}
	
	while (true) //FOR RED PLAYER
	{
		for (int red = 0; red < 1, red++;)
		{
			cout << "Red takes a turn" << endl;
		}
		cin >> MovePositionInitial;
		ArrayRow = MovePositionInitial / numRowsInBoard;
		ArrayColumn = MovePositionInitial % numRowsInBoard;
		while (cin.fail()) //not an integer
		{
			cout << "ERROR: You did not enter an integer" << endl << "Try again" << endl;
			cin.clear();
			cin.ignore();
			cin >> MovePositionInitial;
		}
		if (MovePositionInitial > sizeBoard || MovePositionInitial < 0)
		{
			cout << "ERROR: That square is not on the board." << endl << "Try again" << endl;
			continue;
		}
		if (CMCheckersBoard[ArrayRow][ArrayColumn] == 0)
		{
			cout << "ERROR: That square is empty." << endl << "Try again" << endl;
			continue;
		}
		if (CMCheckersBoard[ArrayRow][ArrayColumn] == 1 || CMCheckersBoard[ArrayRow][ArrayColumn] == 2 || CMCheckersBoard[ArrayRow][ArrayColumn] == 3)
		{
			cout << "ERROR: That square contrains an oppenent's checker." << endl << "Try again" << endl;
			continue;
		}

	}

	return 0;
}
