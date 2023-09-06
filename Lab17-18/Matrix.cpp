#include "Matrix.h"

Matrix::Matrix(float** cells, size_t rowsCount, size_t colsCount)
{
	_cells = new float* [rowsCount];
	_rowsCount = rowsCount;
	_colsCount = colsCount;

	for (size_t i = 0; i < rowsCount; i++)
	{
		_cells[i] = new float[colsCount];

		for (size_t j = 0; j < colsCount; j++)
		{
			_cells[i][j] = cells[i][j];
		}
	}
}
