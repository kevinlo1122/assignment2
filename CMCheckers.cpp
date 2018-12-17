#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <string>
#include <windows.h>
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
void setcolor(unsigned short color)                
{                                                 
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void InitializeBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

void DisplayBoard(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);

int CountJumps(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLocArray[], int yLocArray[]);

int CountMove1Squares(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLocArray[], int yLocArray[]);

bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc);

bool IsJump(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc);

bool MakeMove(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int fromSquareNum, int toSquareNum, bool &jumped);

bool CheckWin(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard);


int main()
{
	//declaring variables
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

	setcolor(15);

	//getting size of board
	//checking if size is a valid input
	while (true)
	{
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
		sizeBoard = (numRowsInBoard * numRowsInBoard);
		break;

	}

	InitializeBoard(CMCheckersBoard, numRowsInBoard);
	DisplayBoard(CMCheckersBoard, numRowsInBoard);
	setcolor(15);

	while (true)
	{

		if (numTurn % 2 == 0)
		{
			player = 1;
		}
		else
		{
			player = 2;
		}

		if (player == 1)
		{
			if (CountJumps(CMCheckersBoard, numRowsInBoard, player, xLocArray, yLocArray) == 0 && CountMove1Squares(CMCheckersBoard, numRowsInBoard, player, xLocArray, yLocArray) == 0)
			{
				cout << "Red is unable to move." << endl << "GAME OVER, White has won." << endl << "Enter any character to close the game." << endl;
				cin >> end;
				return 0;
			}
			cout << "White takes a turn" << endl;
		}
		else
		{
			if (CountJumps(CMCheckersBoard, numRowsInBoard, player, xLocArray, yLocArray) == 0 && CountMove1Squares(CMCheckersBoard, numRowsInBoard, player, xLocArray, yLocArray) == 0)
			{
				cout << "White is unable to move." << endl << "GAME OVER, Red has won." << endl << "Enter any character to close the game." << endl;
				cin >> end;
				return 0;
			}
			cout << "Red takes a turn" << endl;
		}


		while (true)
		{
			cout << "Enter the square number of the checker you want to move" << endl;
			cin >> MovePositionInitial;
			ArrayRowInitial = MovePositionInitial / numRowsInBoard;
			ArrayColumnInitial = MovePositionInitial % numRowsInBoard;

			if (cin.fail())
			{
				cerr << "ERROR: not an integer" << endl << "Try again" << endl;
				cin.clear();
				cin.ignore();
				continue;
			}
			if (MovePositionInitial > sizeBoard || MovePositionInitial < 0)
			{
				cout << "ERROR: That square is not on the board." << endl << "Try again" << endl;
				continue;
			}

			if (player == 1)
			{
				if (CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == REDSOLDIER || CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == REDMULE || CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == REDKING)
				{
					cout << "ERROR: That square contrains an oppenent's checker." << endl << "Try again" << endl;
					continue;
				}
			}
			else if (CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == WHITESOLDIER || CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == WHITEMULE || CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == WHITEKING)
			{
				cout << "ERROR: That square contrains an oppenent's checker." << endl << "Try again" << endl;
				continue;
			}


			if (CMCheckersBoard[ArrayRowInitial][ArrayColumnInitial] == 0)
			{
				cout << "ERROR: That square is empty." << endl << "Try again" << endl;
				continue;
			}
			if (IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial) == false && CountJumps(CMCheckersBoard, numRowsInBoard, player, xLoc, yLoc) > 0)
			{
				cout << "ERROR: You can jump with another checker, you may not move your chosen checker." << endl;
				continue;
			}
			else if (!(IsMove1Square(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial)) && !(IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial))) //cannot jump or move at all
			{

				cout << "ERROR: There is no legal move for this checker." << endl << "Try again" << endl;
				continue;
			}

			break;

		}

		

		while (true)
		{
			cout << "Enter square number you want to move to:" << endl;
			cin >> MovePositionFinal;
			if (cin.fail())
			{
				numTurn--;
				break;
			}
			ArrayRowFinal = MovePositionFinal / numRowsInBoard;
			ArrayColumnFinal = MovePositionFinal % numRowsInBoard;

			if (MovePositionFinal > sizeBoard || MovePositionFinal < 0)
			{
				cout << "ERROR: That square is not on the board." << endl << "Try again" << endl;
				continue;
			}

			else if (CMCheckersBoard[ArrayRowFinal][ArrayRowFinal] != 0) //occupied position
			{
				cout << "ERROR: It is not possible to move to a square that is already occupied." << endl << "Try again" << endl;
				continue;
			}
			else if (IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnInitial, ArrayRowInitial) && CMCheckersBoard[yLoc[index]][xLoc[index]] != CMCheckersBoard[ArrayRowFinal][ArrayColumnFinal])
			{
				cout << "ERROR: You can jump with this checker, you must not move 1 space." << endl << "Try again" << endl;
				continue;
			}

			//MakeMove(CMCheckersBoard, numRowsInBoard, player, MovePositionInitial, MovePositionFinal, jumped);
			//DisplayBoard(CMCheckersBoard, numRowsInBoard);

			if (MakeMove(CMCheckersBoard, numRowsInBoard, player, MovePositionInitial, MovePositionFinal, jumped) == false)
			{
				DisplayBoard(CMCheckersBoard, numRowsInBoard);
				setcolor(15);
				continue;
			}

			DisplayBoard(CMCheckersBoard, numRowsInBoard);
			setcolor(15);
			if (jumped == true)
			{
				if (IsJump(CMCheckersBoard, numRowsInBoard, player, ArrayColumnFinal, ArrayRowFinal))
				{
					MovePositionInitial = MovePositionFinal;
					MovePositionFinal = 0;
					continue;

				}
			}

			break;


		}
		numTurn++;
		if (CheckWin(CMCheckersBoard, numRowsInBoard) == true)
		{
			cout << "Enter any character to terminate the game and then press enter enter key" << endl;
			cin >> end;
			return 0;
		}

		DisplayBoard(CMCheckersBoard, numRowsInBoard);
		setcolor(15);
	}
}


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
					setcolor(9);
					cout << setw(4) << "WS";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 2)
				{
					setcolor(9);
					cout << setw(4) << "WM";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 3)
				{
					setcolor(9);
					cout << setw(4) << "WK";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 4)
				{
					setcolor(4);
					cout << setw(4) << "RS";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 5)
				{
					setcolor(4);
					cout << setw(4) << "RM";
					boardPosition++;
				}
				else
				{
					setcolor(4);
					cout << setw(4) << "RK";
					boardPosition++;
				}
			}
			else
			{
				//DisplayCopy[i][j] = CMCheckersBoard[i][j];

				if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
				{
					setcolor(8);
				}
				else
				{
					setcolor(15);
				}
				DisplayCopy[i][j] = boardPosition;
				cout << setw(4) << DisplayCopy[i][j];
				boardPosition++;
			}
		}
	}
	cout << endl << endl;
	return;
}

bool MakeMove(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int fromSquareNum, int toSquareNum, bool &jumped)
{
	const int minusNum = numRowsInBoard - 1;

	int xDistanceFrom = 0;
	int yDistanceFrom = 0;

	int xDistanceTo = 0;
	int yDistanceTo = 0;

	int xDistanceMid = 0;
	int yDistanceMid = 0;

	int xDistance = 0;
	int yDistance = 0;

	jumped = false;
	int temp = 0;

	char character;

	yDistanceTo = toSquareNum / numRowsInBoard;
	xDistanceTo = toSquareNum % numRowsInBoard;

	yDistanceFrom = fromSquareNum / numRowsInBoard;
	xDistanceFrom = fromSquareNum % numRowsInBoard;

	yDistanceMid = (yDistanceFrom + yDistanceTo) / 2;
	xDistanceMid = (xDistanceFrom + xDistanceTo) / 2;

	xDistance = abs(xDistanceTo - xDistanceFrom);
	yDistance = abs(yDistanceTo - yDistanceFrom);

	if (player == WHITEPLAYER)
	{
		if (yDistanceTo < yDistanceFrom&&CMCheckersBoard[yDistanceFrom][xDistanceFrom] != WHITEKING)
		{
			cout << "Error: illegal move" << endl;
			return false;
		}

		if ((xDistance == 2 && yDistance == 2) || (xDistance == minusNum - 1 && yDistance == 2))//move 2 squares
		{

			if (xDistance == minusNum - 1)
			{
				if (xDistanceFrom == 0 || xDistanceFrom == minusNum - 1)
				{
					xDistanceMid = minusNum;
				}
				else
				{
					xDistanceMid = 0;
				}
			}

			if (CMCheckersBoard[yDistanceTo][xDistanceTo] != 0 || (CMCheckersBoard[yDistanceMid][xDistanceMid] != 4 &&
				CMCheckersBoard[yDistanceMid][xDistanceMid] != 5 && CMCheckersBoard[yDistanceMid][xDistanceMid] != 6))
			{
				cout << "Error: illegal move" << endl;
				return false;
			}

			CMCheckersBoard[yDistanceMid][xDistanceMid] = 0;

			jumped = true;
			temp = CMCheckersBoard[yDistanceFrom][xDistanceFrom];
			CMCheckersBoard[yDistanceFrom][xDistanceFrom] = 0;
			CMCheckersBoard[yDistanceTo][xDistanceTo] = temp;


		}
		else if ((xDistance == 1 && yDistance == 1) || (xDistance == minusNum && yDistance == 1))//moved 1 square
		{
			if (IsJump(CMCheckersBoard, numRowsInBoard, player, xDistanceFrom, yDistanceFrom) == true)
			{
				cout << "Error: You must Jump with this piece" << endl;
				return false;
			}
			if (CMCheckersBoard[yDistanceTo][xDistanceTo] != 0)
			{
				cout << "Error: illegal move" << endl;
				return false;
			}


			temp = CMCheckersBoard[yDistanceFrom][xDistanceFrom];
			CMCheckersBoard[yDistanceFrom][xDistanceFrom] = 0;
			CMCheckersBoard[yDistanceTo][xDistanceTo] = temp;
		}

		else
		{
			cout << "Error: illegal move" << endl;
			return false;
		}

		if (CMCheckersBoard[yDistanceTo][xDistanceTo] == WHITEMULE && yDistanceTo == minusNum)
		{
			CMCheckersBoard[yDistanceTo][xDistanceTo] = WHITEKING;
			cout << "White has created a Mule King,  Red wins the game" << endl;
			cout << "Enter any character to terminate the game then press the enter key";
			cin >> character;
			exit(0);
		}
		if (CMCheckersBoard[yDistanceTo][xDistanceTo] == WHITESOLDIER && yDistanceTo == minusNum)
		{
			CMCheckersBoard[yDistanceTo][xDistanceTo] = WHITEKING;
		}

	}


	else
	{
		if (yDistanceTo > yDistanceFrom&&CMCheckersBoard[yDistanceFrom][xDistanceFrom] != REDKING)
		{
			cout << "Error: illegal move" << endl;
			return false;
		}

		if ((xDistance == 2 && yDistance == 2) || (xDistance == minusNum - 1 && yDistance == 2))//move 2 squares
		{
			if (xDistance == minusNum - 1)
			{
				if (xDistanceFrom == 0 || xDistanceFrom == minusNum - 1)
				{
					xDistanceMid = minusNum;
				}
				else
				{
					xDistanceMid = 0;
				}
			}
			if (CMCheckersBoard[yDistanceTo][xDistanceTo] != 0 || (CMCheckersBoard[yDistanceMid][xDistanceMid] != 1 &&
				CMCheckersBoard[yDistanceMid][xDistanceMid] != 2 && CMCheckersBoard[yDistanceMid][xDistanceMid] != 3))
			{
				cout << "Error: illegal move" << endl;
				return false;
			}

			CMCheckersBoard[yDistanceMid][xDistanceMid] = 0;

			jumped = true;
			temp = CMCheckersBoard[yDistanceFrom][xDistanceFrom];
			CMCheckersBoard[yDistanceFrom][xDistanceFrom] = 0;
			CMCheckersBoard[yDistanceTo][xDistanceTo] = temp;


		}
		else if ((xDistance == 1 && yDistance == 1) || (xDistance == minusNum && yDistance == 1))//moved 1 square
		{
			if (IsJump(CMCheckersBoard, numRowsInBoard, player, xDistanceFrom, yDistanceFrom) == true)
			{
				cout << "Error: You must Jump with this piece" << endl;
				return false;
			}
			if (CMCheckersBoard[yDistanceTo][xDistanceTo] != 0)
			{
				cout << "Error: illegal move" << endl;
				return false;
			}


			temp = CMCheckersBoard[yDistanceFrom][xDistanceFrom];
			CMCheckersBoard[yDistanceFrom][xDistanceFrom] = 0;
			CMCheckersBoard[yDistanceTo][xDistanceTo] = temp;
		}

		else
		{
			cout << "Error: illegal move" << endl;
			return false;
		}

		if (CMCheckersBoard[yDistanceTo][xDistanceTo] == REDMULE && yDistanceTo == 0)
		{
			CMCheckersBoard[yDistanceTo][xDistanceTo] = REDKING;
			cout << "Red has created a Mule King,  White wins the game" << endl;
			cout << "Enter any character to terminate the game then press the enter key";
			cin >> character;
			exit(0);
		}
		if (CMCheckersBoard[yDistanceTo][xDistanceTo] == REDSOLDIER && yDistanceTo == 0)
		{
			CMCheckersBoard[yDistanceTo][xDistanceTo] = REDKING;
		}
	}
	return true;
}

bool IsMove1Square(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc)
{
	if (player == 1)
	{
		if (CMCheckersBoard[yLoc][xLoc] != 1 && CMCheckersBoard[yLoc][xLoc] != 2 && CMCheckersBoard[yLoc][xLoc] != 3)
		{
			return false;
		}
		if (xLoc == 0)
		{
			if (CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 0&&yLoc+1!=numRowsInBoard)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if (CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 0 && yLoc - 1 != -1)
				{
					return true;
				}
			}
		}
		if (xLoc == numRowsInBoard-1)
		{
			if (CMCheckersBoard[yLoc + 1][0] == 0 && yLoc + 1 != numRowsInBoard)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if (CMCheckersBoard[yLoc - 1][0] == 0&&yLoc - 1 != -1)
				{
					return true;
				}
			}
		}
		if (((CMCheckersBoard[yLoc + 1][xLoc + 1] == 0&&xLoc+1!=numRowsInBoard) || (CMCheckersBoard[yLoc + 1][xLoc - 1] == 0&&xLoc-1!=-1)) && yLoc + 1 != numRowsInBoard)
		{
			return true;
		}
		if (CMCheckersBoard[yLoc][xLoc] == 3)
		{
			if (((CMCheckersBoard[yLoc - 1][xLoc + 1] == 0&& xLoc + 1 != numRowsInBoard) || (CMCheckersBoard[yLoc - 1][xLoc - 1] == 0&& xLoc - 1 != -1)) && yLoc - 1 != -1)
			{
				return true;
			}
		}
		return false;

	}
	else
	{
		if (CMCheckersBoard[yLoc][xLoc] != 4 && CMCheckersBoard[yLoc][xLoc] != 5 && CMCheckersBoard[yLoc][xLoc] != 6)
		{
			return false;
		}
		if (xLoc == 0)
		{
			if (CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 0 && yLoc - 1 != -1)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if (CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 0 && yLoc + 1 != numRowsInBoard)
				{
					return true;
				}
			}
		}
		if (xLoc == numRowsInBoard-1)
		{
			if (CMCheckersBoard[yLoc - 1][0] == 0 && yLoc - 1 != -1)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if (CMCheckersBoard[yLoc + 1][0] == 0 && yLoc + 1 != numRowsInBoard)
				{
					return true;
				}
			}
		}
		if (((CMCheckersBoard[yLoc - 1][xLoc + 1] == 0&& xLoc + 1 != numRowsInBoard) || (CMCheckersBoard[yLoc - 1][xLoc - 1] == 0&& xLoc - 1 != -1)) && yLoc - 1 != -1)
		{
			return true;
		}
		if (CMCheckersBoard[yLoc][xLoc] == 6)
		{
			if (((CMCheckersBoard[yLoc + 1][xLoc + 1] == 0&& xLoc + 1 != numRowsInBoard) || (CMCheckersBoard[yLoc + 1][xLoc - 1] == 0&& xLoc - 1 != -1)) && yLoc + 1 != numRowsInBoard)
			{
				return true;
			}
		}
		return false;

	}
}

bool IsJump(int CMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE], int numRowsInBoard, int player, int xLoc, int yLoc)
{

	if (player == 1)
	{
		if (CMCheckersBoard[yLoc][xLoc] != 1 && CMCheckersBoard[yLoc][xLoc] != 2 && CMCheckersBoard[yLoc][xLoc] != 3)
		{
			return false;
		}
		if (xLoc == 0)
		{
			if ((CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 4 ||
				CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 5 ||
				CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 6) &&
				CMCheckersBoard[yLoc + 2][numRowsInBoard - 2] == 0&&
				yLoc+2!=numRowsInBoard)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if ((CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 4 ||
					CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 5 ||
					CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 6) &&
					CMCheckersBoard[yLoc - 2][numRowsInBoard - 2] == 0 &&
					yLoc - 2 != -1)
				{
					return true;
				}
			}
		}
		if (xLoc == 1)
		{
			if ((CMCheckersBoard[yLoc + 1][0] == 4 ||
				CMCheckersBoard[yLoc + 1][0] == 5 ||
				CMCheckersBoard[yLoc + 1][0] == 6) &&
				CMCheckersBoard[yLoc + 2][numRowsInBoard - 1] == 0 &&
				yLoc + 2 != numRowsInBoard)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if ((CMCheckersBoard[yLoc - 1][0] == 4 ||
					CMCheckersBoard[yLoc - 1][0] == 5 ||
					CMCheckersBoard[yLoc - 1][0] == 6) &&
					CMCheckersBoard[yLoc - 2][numRowsInBoard - 1] == 0 &&
					yLoc - 2 != -1)
				{
					return true;
				}
			}
		}
		if (xLoc == numRowsInBoard-1)
		{
			if ((CMCheckersBoard[yLoc + 1][0] == 4 ||
				CMCheckersBoard[yLoc + 1][0] == 5 ||
				CMCheckersBoard[yLoc + 1][0] == 6) &&
				CMCheckersBoard[yLoc + 2][1] == 0 &&
				yLoc + 2 != numRowsInBoard)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if ((CMCheckersBoard[yLoc - 1][0] == 4 ||
					CMCheckersBoard[yLoc - 1][0] == 5 ||
					CMCheckersBoard[yLoc - 1][0] == 6) &&
					CMCheckersBoard[yLoc - 2][1] == 0 &&
					yLoc - 2 != -1)
				{
					return true;
				}
			}
		}
		if (xLoc == numRowsInBoard - 2)
		{
			if ((CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 4 ||
				CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 5 ||
				CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 6) &&
				CMCheckersBoard[yLoc + 2][0] == 0 &&
				yLoc + 2 != numRowsInBoard)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 3)
			{
				if ((CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 4 ||
					CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 5 ||
					CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 6) &&
					CMCheckersBoard[yLoc - 2][0] == 0 &&
					yLoc - 2 != -1)
				{
					return true;
				}
			}
		}
		if ((((CMCheckersBoard[yLoc + 1][xLoc + 1] == 4 ||
			CMCheckersBoard[yLoc + 1][xLoc + 1] == 5 ||
			CMCheckersBoard[yLoc + 1][xLoc + 1] == 6) &&
			CMCheckersBoard[yLoc + 2][xLoc + 2] == 0&&
			xLoc+2!=numRowsInBoard)||
			((CMCheckersBoard[yLoc + 1][xLoc - 1] == 4 ||
				CMCheckersBoard[yLoc + 1][xLoc - 1] == 5 ||
				CMCheckersBoard[yLoc + 1][xLoc - 1] == 6) &&
				CMCheckersBoard[yLoc + 2][xLoc - 2] == 0&&
				xLoc-2!=-1)) &&
			yLoc + 2 != numRowsInBoard)
		{
			return true;
		}
		if (CMCheckersBoard[yLoc][xLoc] == 3)
		{
			if ((((CMCheckersBoard[yLoc - 1][xLoc + 1] == 4 ||
				CMCheckersBoard[yLoc - 1][xLoc + 1] == 5 ||
				CMCheckersBoard[yLoc - 1][xLoc + 1] == 6) &&
				CMCheckersBoard[yLoc - 2][xLoc + 2] == 0&&
				xLoc + 2 != numRowsInBoard) ||
				((CMCheckersBoard[yLoc - 1][xLoc - 1] == 4 ||
					CMCheckersBoard[yLoc - 1][xLoc - 1] == 5 ||
					CMCheckersBoard[yLoc - 1][xLoc - 1] == 6) &&
					CMCheckersBoard[yLoc - 2][xLoc - 2] == 0&&
					xLoc - 2 != -1)) &&
				yLoc - 2 != -1)
			{
				return true;
			}
		}

		return false;

	}
	
	else
	{
		if (CMCheckersBoard[yLoc][xLoc] != 4 && CMCheckersBoard[yLoc][xLoc] != 5 && CMCheckersBoard[yLoc][xLoc] != 6)
		{
			return false;
		}
		if (xLoc == 0)
		{
			if ((CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 1 ||
				CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 2 ||
				CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 3) &&
				CMCheckersBoard[yLoc - 2][numRowsInBoard - 2] == 0 &&
				yLoc - 2 != -1)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if ((CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 1 ||
					CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 2 ||
					CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 3) &&
					CMCheckersBoard[yLoc + 2][numRowsInBoard - 2] == 0 &&
					yLoc + 2 != numRowsInBoard)
				{
					return true;
				}
			}
		}
		if (xLoc == 1)
		{
			if ((CMCheckersBoard[yLoc - 1][0] == 1 ||
				CMCheckersBoard[yLoc - 1][0] == 2 ||
				CMCheckersBoard[yLoc - 1][0] == 3) &&
				CMCheckersBoard[yLoc - 2][numRowsInBoard - 1] == 0 &&
				yLoc - 2 != -1)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if ((CMCheckersBoard[yLoc + 1][0] == 1 ||
					CMCheckersBoard[yLoc + 1][0] == 2 ||
					CMCheckersBoard[yLoc + 1][0] == 3) &&
					CMCheckersBoard[yLoc + 2][numRowsInBoard - 1] == 0 &&
					yLoc + 2 != numRowsInBoard)
				{
					return true;
				}
			}
		}
		if (xLoc == numRowsInBoard-1)
		{
			if ((CMCheckersBoard[yLoc - 1][0] == 1 ||
				CMCheckersBoard[yLoc - 1][0] == 2 ||
				CMCheckersBoard[yLoc - 1][0] == 3) &&
				CMCheckersBoard[yLoc - 2][1] == 0 &&
				yLoc - 2 != -1)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if ((CMCheckersBoard[yLoc + 1][0] == 1 ||
					CMCheckersBoard[yLoc + 1][0] == 2 ||
					CMCheckersBoard[yLoc + 1][0] == 3) &&
					CMCheckersBoard[yLoc + 2][1] == 0 &&
					yLoc + 2 != numRowsInBoard)
				{
					return true;
				}
			}
		}
		if (xLoc == numRowsInBoard - 2)
		{
			if ((CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 1 ||
				CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 2 ||
				CMCheckersBoard[yLoc - 1][numRowsInBoard - 1] == 3) &&
				CMCheckersBoard[yLoc - 2][0] == 0 &&
				yLoc - 2 != -1)
			{
				return true;
			}
			if (CMCheckersBoard[yLoc][xLoc] == 6)
			{
				if ((CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 1 ||
					CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 2 ||
					CMCheckersBoard[yLoc + 1][numRowsInBoard - 1] == 3) &&
					CMCheckersBoard[yLoc + 2][0] == 0 &&
					yLoc + 2 != numRowsInBoard)
				{
					return true;
				}
			}
		}
		if ((((CMCheckersBoard[yLoc - 1][xLoc + 1] == 1 ||
			CMCheckersBoard[yLoc - 1][xLoc + 1] == 2 ||
			CMCheckersBoard[yLoc - 1][xLoc + 1] == 3) &&
			CMCheckersBoard[yLoc - 2][xLoc + 2] == 0&&
			xLoc + 2 != numRowsInBoard) ||
			((CMCheckersBoard[yLoc - 1][xLoc - 1] == 1 ||
				CMCheckersBoard[yLoc - 1][xLoc - 1] == 2 ||
				CMCheckersBoard[yLoc - 1][xLoc - 1] == 3) &&
				CMCheckersBoard[yLoc - 2][xLoc - 2] == 0&&
				xLoc - 2 != -1)) &&
			yLoc - 2 != -1)
		{

			return true;
		}
		if (CMCheckersBoard[yLoc][xLoc] == 6)
		{
			if ((((CMCheckersBoard[yLoc + 1][xLoc + 1] == 1 ||
				CMCheckersBoard[yLoc + 1][xLoc + 1] == 2 ||
				CMCheckersBoard[yLoc + 1][xLoc + 1] == 3) &&
				CMCheckersBoard[yLoc + 2][xLoc + 2] == 0&&
				xLoc + 2 != numRowsInBoard) ||
				((CMCheckersBoard[yLoc + 1][xLoc - 1] == 1 ||
					CMCheckersBoard[yLoc + 1][xLoc - 1] == 2 ||
					CMCheckersBoard[yLoc + 1][xLoc - 1] == 3) &&
					CMCheckersBoard[yLoc + 2][xLoc - 2] == 0&&
					xLoc - 2 != -1)) &&
				yLoc + 2 != numRowsInBoard)
			{
				return true;
			}
		}
		return false;
	}
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
