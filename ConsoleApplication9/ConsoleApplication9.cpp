#include <iostream>
void showArray(int* arr, int size);
int countNegatives(int** arr, int rows, int columns);
int* convertArray(int** arr, int rows, int columns, int negatives);
void fillArray(int** arr, int rows, int columns);
int main()
{
	int rows, columns, negatives;
	std::cout << "Write amount of rows: ";
	std::cin >> rows;
	std::cout << "Write amount of columns: ";
	std::cin >> columns;
	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[columns];
	fillArray(arr, rows, columns);
	negatives = countNegatives(arr, rows, columns);
	showArray(convertArray(arr, rows, columns, negatives), negatives);

}
void showArray(int* arr, int size)
{
	std::cout << "Your array: ";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
}
int countNegatives(int** arr, int rows, int columns)
{
	int negativeCounter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (arr[i][j] < 0)
				negativeCounter++;
		}
	}
	return negativeCounter;
}
int* convertArray(int** arr, int rows, int columns, int negatives)
{
	int* negativeArr = new int[negatives];
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (arr[i][j] < 0)
			{
				negativeArr[counter] = arr[i][j];
				counter++;
			}
		}
	}
	return negativeArr;
}
void fillArray(int** arr, int rows, int columns)
{
	std::cout << "Fill array:" << std::endl;
	for (int i = 0; i < rows; i++)
	{
		std::cout << "Row " << i + 1 << " : ";
		for (int j = 0; j < columns; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}