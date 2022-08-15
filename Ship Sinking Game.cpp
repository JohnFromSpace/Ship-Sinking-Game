#include <ctime>
#include <iostream>

const int elements = 20;
const int rows = 20;

int maxShips = 7;

int matrix[rows][elements];


//hides the position of the ship
void Clear()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			matrix[i][j] = 0;
		}
	}

}

//shows the position of the ship
void Show()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
	}
		
}

//self-explanatory
int NumberOfShips()
{
	int numberOfShips = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			if(matrix[i][j] == 1)
				numberOfShips++;
		}
	}

	return numberOfShips;
}


void SetShips()
{
	int shipSet = 0;

	while (shipSet < maxShips)
	{
		int x = rand() % rows;
		int y = rand() % elements;
	
		if (matrix[x][y] != 1)
		{
			shipSet++;
			matrix[x][y] = 1;
		}
	}
}


bool Attack(int x, int y)
{
	if (matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}

	return false;
}

int main()
{
	srand(time(NULL));
	Clear();
	SetShips();
	int position1, position2;
	char prompt{};

	std::cout << "You have a 20x20 grid. That means you won't be able to strike any ship at a "<< std::endl;
	std::cout << "coordinations of (20+;20+) or one's with negative values. " << std::endl;
	std::cout << "The coordinates are with natural numbers as parameters." << std::endl;

	while (1)
	{
		std::cout << "Input the location of the ship you want to hit!" << std::endl;
		std::cin >> position1 >> position2;
		if (Attack(position1, position2))
		{
			std::cout << "You got me!" << std::endl;
		}
		else
		{
			std::cout << "You missed!" << std::endl;
		}

		std::cout << "Number of ships left: " << NumberOfShips() << std::endl;
		
		std::cout << "Do you want to surrender? (y/n)?";
		std::cin >> prompt;

		if (prompt == 'y')
		{
			break;
		}
	}

	std::cout << "Game Over!" << std::endl;
	Show();
	system("pause");
	return 0;
}









