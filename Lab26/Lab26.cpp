#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using std::vector;

// ОДНОМЕРНЫЕ МАССИВЫ
//В одномерном массиве, состоящем из n вещественных
//элементов
//1) вычислить сумму элементов массива, расположенных после первого
//положительного элемента;
//2) преобразовать массив таким образом, чтобы сначала располагались
//все элементы, целая часть которых лежит в интервале[а, b], а
//потом – все остальные;
//3) упорядочить элементы массива по возрастанию, используя
//линейную сортировку;
//4) найти заданный элемент в упорядоченном массиве, используя
//бинарный метод поиска.

// ДВУМЕРНЫЕ МАССИВЫ
//1) Уплотнить заданную матрицу, удаляя из нее строки и столбцы,
//заполненные нулями.
//2) Найти номер первой из строк, содержащих хотя бы один
//положительный элемент.


void OneD()
{
	const int N = 7;
	vector<double> v{ 1, 2, 3, 4, 5, 6, 7, };

	std::cout << "Исходный массив: ";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << " ";
	}
	std::cout << '\n';

	// 1) вычислить сумму элементов массива, расположенных после первого
	//положительного элемента;
	double sum = 0; 
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] > 0)
		{
			sum = std::accumulate(v.begin() + i, v.end(), 0.0);
			break;
		}
	}
	std::cout << "Сумма элементов, расположенных после первого положительного элемента: " << sum << '\n';

	//2) преобразовать массив таким образом, чтобы сначала располагались
	//все элементы, целая часть которых лежит в интервале[а, b], а
	//потом – все остальные;
	int a = 3;
	int b = 5;
	if (a > b)
	{
		std::swap(a, b);
	}

	std::cout << "Границы: [" << a << ';' << b << "]\n";

	int minIndex = 0;
	int maxIndex = 0;

	for (size_t i = 0; i < v.size(); i++)
	{
		if (floor(v[i]) <= a)
		{
			minIndex = i;
		}
		if (floor(v[i]) <= b)
		{
			maxIndex = i;
		}
	}
	vector<double> v2(N);

	std::copy(&v[minIndex], &v[maxIndex + 1], &v2[0]);
	std::copy(&v[0], &v[minIndex], &v2[maxIndex - minIndex + 1]);
	std::copy(v.begin() + maxIndex + 1, v.end(), &v2[maxIndex + 1]);

	std::cout << "Преобразованный массив: ";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v2[i] << " ";
	}
	std::cout << '\n';

	//3) упорядочить элементы массива по возрастанию, используя
	//линейную сортировку;
	std::sort(v.begin(), v.end());

	//4) найти заданный элемент в упорядоченном массиве, используя
	//бинарный метод поиска.
	double elementToFind = 5.0;
	std::cout << "Найти элемент: " << elementToFind << '\n';
	bool isFound = std::binary_search(v.begin(), v.end(), 5.0);
	if (isFound)
	{
		std::cout << "Элемент " << elementToFind << " был найден";
	}
	else
	{
		std::cout << "Элемент " << elementToFind << " не был найден";
	}

	std::cout << '\n';
	std::cout << '\n';
}

void TwoD()
{
	//1) Уплотнить заданную матрицу, удаляя из нее строки и столбцы,
	//заполненные нулями.
	size_t rowsCount = 3;
	size_t colsCount = 3;
	vector<vector<double>> matrix{ {-1, -2, 0}, {0, 0, 0}, {7, 8, 0} };
	
	std::cout << "Исходная матрица: \n";
	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < colsCount; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	

	// Удаление нулевых строк
	for (size_t i = 0; i < rowsCount; i++)
	{
		bool isZeroRow = true;

		for (size_t j = 0; j < colsCount; j++)
		{
			if (matrix[i][j] != 0)
			{
				isZeroRow = false;
				break;
			}
		}
		if (isZeroRow)
		{
			matrix.erase(matrix.begin() + i);
			i--;
			rowsCount--;
		}
	}

	// Удаление нулевых столбцов
	for (size_t i = 0; i < colsCount; i++)
	{
		bool isZeroCol = true;
		for (size_t j = 0; j < rowsCount; j++)
		{
			if (matrix[j][i] != 0)
			{
				isZeroCol = false;
				break;
			}
		}
		if (isZeroCol)
		{
			for (size_t j = 0; j < rowsCount; j++)
			{
				matrix[j].erase(matrix[j].begin() + i);
			}
			i--;
			colsCount--;
		}
	}

	std::cout << "Матрица с удалёнными нулевыми строками и столбцами: \n";
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';


	//2) Найти номер первой из строк, содержащих хотя бы один
	//положительный элемент.
	bool isPositiveElementWasFound = false;
	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < colsCount; j++)
		{
			if (matrix[i][j] > 0)
			{
				std::cout << "Номер первой из строк, содержащих хотя бы один положительный элемент: " << i << "\n";
				isPositiveElementWasFound = true;
				break;
			}
		}
	}

	if (!isPositiveElementWasFound)
	{
		std::cout << "Не была найдена ни одна строка, содержащая хотя бы один положительный элемент\n";
	}
}


int main()
{
	OneD();
	TwoD();

	system("pause");
}
