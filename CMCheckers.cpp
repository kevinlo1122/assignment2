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

	cout << xDistance << endl;
	cout << yDistance << endl;


	if (player = WHITEPLAYER)
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
/*
else if (player == WHITEPLAYER)
{
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
					CMCheckersBoard[rowFrom + 1][columnFrom - minusNum] = 0;
				}
				jumped = true;
				temp = CMCheckersBoard[rowFrom][columnFrom];
				CMCheckersBoard[rowFrom][columnFrom] = 0;
				CMCheckersBoard[rowTo][columnTo] = temp;

				if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == minusNum)
				{
					CMCheckersBoard[rowTo][columnTo] = REDKING;
					cout << "Red has created a Mule King,  White wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == minusNum)
				{
					move = true;
					return move;
				}
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

				if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == minusNum)
				{
					CMCheckersBoard[rowTo][columnTo] = REDKING;
					cout << "Red has created a Mule King,  White wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == minusNum)
				{
					move = true;
					return move;
				}
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

				if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == minusNum)
				{
					CMCheckersBoard[rowTo][columnTo] = REDKING;
					cout << "Red has created a Mule King,  White wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == minusNum)
				{
					move = true;
					return move;
				}
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

				if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == minusNum)
				{
					CMCheckersBoard[rowTo][columnTo] = REDKING;
					cout << "Red has created a Mule King,  White wins the game" << endl;
					cout << "Enter any character to terminate the game then press the enter key";
					cin >> character;
					exit(0);
				}
				else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == minusNum)
				{
					move = true;
					return move;
				}
				return move;
			}
			else
			{
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
			else
			{
				return move;
			}
			jumped = true;
			temp = CMCheckersBoard[rowFrom][columnFrom];
			CMCheckersBoard[rowFrom][columnFrom] = 0;
			CMCheckersBoard[rowTo][columnTo] = temp;

			if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == minusNum)
			{
				CMCheckersBoard[rowTo][columnTo] = REDKING;
				cout << "Red has created a Mule King,  White wins the game" << endl;
				cout << "Enter any character to terminate the game then press the enter key";
				cin >> character;
				exit(0);
			}
			else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == minusNum)
			{
				move = true;
				return move;
			}
			return move;


		}
		return move;
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

			if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == minusNum)
			{
				CMCheckersBoard[rowTo][columnTo] = REDKING;
				cout << "Red has created a Mule King,  White wins the game" << endl;
				cout << "Enter any character to terminate the game then press the enter key";
				cin >> character;
				exit(0);
			}
			else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == minusNum)
			{
				move = true;
				return move;
			}
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

			if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == minusNum)
			{
				CMCheckersBoard[rowTo][columnTo] = REDKING;
				cout << "Red has created a Mule King,  White wins the game" << endl;
				cout << "Enter any character to terminate the game then press the enter key";
				cin >> character;
				exit(0);
			}
			else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == minusNum)
			{
				move = true;
				return move;
			}
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

			if (CMCheckersBoard[rowTo][columnTo] == REDMULE && rowTo == minusNum)
			{
				CMCheckersBoard[rowTo][columnTo] = REDKING;
				cout << "Red has created a Mule King,  White wins the game" << endl;
				cout << "Enter any character to terminate the game then press the enter key";
				cin >> character;
				exit(0);
			}
			else if (CMCheckersBoard[rowTo][columnTo] == REDSOLDIER && rowTo == minusNum)
			{
				move = true;
				return move;
			}
			return move;
		}
		return move;
	}
	else
	{
		cerr << "Error: illegal move" << endl;
		return move;
	}
	return move;
}
else
{
	return move;
}
}
*/
