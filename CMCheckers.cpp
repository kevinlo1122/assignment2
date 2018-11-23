#include <iostream>
#include <iomanip>
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
		for (j = 0; j < numRowsInBoard; i++)
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







//main function
int main()
{
	//declaring variables
	int numOfTries = 0; //counter for error in selecting size of board
	string endgame; //holding character to end the game
	int numRowsInBoard = 0;
	int myCMCheckersBoard[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];

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
		cout << "Enter the number of squares along each edge of the board: ";
		cin >> numRowsInBoard;
		if (cin.fail())
		{
			cerr << "ERROR: Board size is not an integer" << endl;
			cout << "8 <= number of squares <= 18" << endl;
			cin.clear();
			cin.ignore();
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
		if (!(numRowsInBoard % 2 == 0))
		{
			cerr << "ERROR: Board size is odd." << endl;
			cout << "8 <= number of squares <= 18" << endl;
			continue;
		}
		else
		{
			break;
		}	
	}

	//InitializeBoard();
	//DisplayBoard();
	/*
	//for each turn: check if the player has legal move
	CountJumps(); //this will tell how many checkers are avalible to move
	CountMove1Squares(); (this tells how many Mules and Soldiers can be moved and how many kings can be moved)
	//if there is no possible moves (return values are 0)
	//if red wins =
	cout << "White is unable to move." << endl << "GAME OVER, Red has won." << endl << "Enter any character to close the game."
	//if white wins = 
	cout << "Red is unable to move." << endl << "GAME OVER, White has won." << endl << "Enter any character to close the game."
	//user presses any character to end the game
	getline(cin, endgame);
	if (!endgame.empty())
	{
		return 0;
	}
	*/


	return 0;
}
