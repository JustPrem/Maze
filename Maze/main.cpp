#include <iostream>
using namespace std;

enum Direction
{
	North,
	East,
	South,
	West,
};

Direction direction = Direction::North;
int maze[10][10] = {
	{1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 1, 1, 1, 0, 0},
	{1, 1, 1, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

int pos[2] = { 0, 0 };
bool possibleDirections[4] = {false, false, false, false}; // 0 = North, 1 = East, 2 = South, 3 = West.

/* Checks if theres a Room in the specific position. */
bool CheckDoor(int x, int y)
{
	if (maze[x][y] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Check if Position is going out of bounds. */
bool CheckLimit(int i)
{
	if (i < 0 || i > 9)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/* Check if the Player reached the finish. */
bool CheckFinish()
{
	if (pos[0] == 9 && pos[1] == 9)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/* Make string into lower-case. */
string ToLower(string initString)
{
	string tempString;
	for (auto i : initString)
	{
		tempString += tolower(i);
	}
	return tempString;
}

int main()
{
	while (CheckFinish())
	{
		string userInput = "";

		while (userInput == "")
		{
			system("CLS");

			/* Prints the Map. 
			for (int x = 0; x < 10; x++)
			{
				for (int y = 0; y < 10; y++)
				{
					if (pos[0] == x && pos[1] == y)
					{
						cout << "X ";
					}
					else
					{
						cout << maze[x][y] << " ";
					}
				}
				cout << endl;
			}*/

			/* Check Possible Directions. */
			{
				/* North */
				if (CheckLimit(pos[0] - 1) && CheckDoor(pos[0] - 1, pos[1]))
				{
					possibleDirections[0] = true;
				}
				else
				{
					possibleDirections[0] = false;
				}

				/* East */
				if (CheckLimit(pos[1] + 1) && CheckDoor(pos[0], pos[1] + 1))
				{
					possibleDirections[1] = true;
				}
				else
				{
					possibleDirections[1] = false;
				}

				/* South */
				if (CheckLimit(pos[0] + 1) && CheckDoor(pos[0] + 1, pos[1]))
				{
					possibleDirections[2] = true;
				}
				else
				{
					possibleDirections[2] = false;
				}

				/* West */
				if (CheckLimit(pos[1] - 1) && CheckDoor(pos[0], pos[1] - 1))
				{
					possibleDirections[3] = true;
				}
				else
				{
					possibleDirections[3] = false;
				}
			}

			/* Offer Possible Directions. */
			cout << endl << "These are your Options: " << endl << endl;

			for (int i = 0; i < sizeof(possibleDirections) / sizeof(*possibleDirections); i++)
			{
				switch (i)
				{
					case 0:
					{
						if (possibleDirections[0])
						{
							cout << "- North" << endl;
						}
						break;
					}
					case 1:
					{
						if (possibleDirections[1])
						{
							cout << "- East" << endl;
						}
						break;
					}
					case 2:
					{
						if (possibleDirections[2])
						{
							cout << "- South" << endl;
						}
						break;
					}
					case 3:
					{
						if (possibleDirections[3])
						{
							cout << "- West" << endl;
						}
						break;
					}
				}
			}

			cout << endl;

			/* Ask for Choice of Direction. */
			cout << "Please Choose Your Direction: ";
			cin >> userInput;

			if (ToLower(userInput) == "north" && possibleDirections[0])
			{
				direction = Direction::North;
				break;
			}
			else if (ToLower(userInput) == "east" && possibleDirections[1])
			{
				direction = Direction::East;
				break;
			}
			else if (ToLower(userInput) == "south" && possibleDirections[2])
			{
				direction = Direction::South;
				break;
			}
			else if (ToLower(userInput) == "west" && possibleDirections[3])
			{
				direction = Direction::West;
				break;
			}
			else
			{
				userInput = "";
			}
		}

		switch (direction)
		{
			case Direction::North:
			{
				pos[0] -= 1;
				break;
			}
			case Direction::East:
			{
				pos[1] += 1;
				break;
			}
			case Direction::South:
			{
				pos[0] += 1;
				break;
			}
			case Direction::West:
			{
				pos[1] -= 1;
				break;
			}
		}
	}

	system("CLS");
	cout << "Congratulations on Completing the Maze!" << endl << endl;
	system("Pause");
}