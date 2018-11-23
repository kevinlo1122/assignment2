#include <iostream>
#include <iomanip>
#include <string>
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
					cout << "WS  ";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 2)
				{
					cout << "WM  ";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 3)
				{
					cout << "WK  ";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 4)
				{
					cout << "RS  ";
					boardPosition++;
				}
				else if (CMCheckersBoard[i][j] == 5)
				{
					cout << "RM  ";
					boardPosition++;
				}
				else
				{
					cout << "RK  ";
					boardPosition++;
				}
			}
			else
			{
				CMCheckersBoard[i][j] = boardPosition;
				cout << CMCheckersBoard[i][j] << "  ";
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





//main function
int main()
{
	//declaring variables
	int numOfTries = 0; //counter for error in selecting size of board
	string EndGame; //holding character to end the game
	int MovePositionInitial = 0;
	int MovePositionFinal = 0;
	int numRowsInBoard = 0;
	int sizeBoard = 0;
	sizeBoard = (numRowsInBoard * numRowsInBoard);
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

	InitializeBoard();
	CheckList();
	DisplayBoard();

	//for each turn: check if the player has legal move
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
		
		//if there is possible moves
		//asks what is the position of the checker the player wants to move
		cout << "Enter the square number of the checker you want to move" << endl;
		
		
		while (true) //section not complete
		{
			cin >> MovePositionInitial;
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
			else
			{
				break;
			}
			
		}
		



	return 0;
}
