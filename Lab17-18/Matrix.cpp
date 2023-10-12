#include "Matrix.h"
#include <iostream>
#include <iomanip>

void Matrix::InitByOtherMatrix(const Matrix& other)
{
	rowsCount_ = other.rowsCount_;
	colsCount_ = other.colsCount_;

	cells_ = new float* [rowsCount_];

	for (size_t i = 0; i < rowsCount_; i++)
	{
		cells_[i] = new float[colsCount_];

		for (size_t j = 0; j < colsCount_; j++)
		{
			cells_[i][j] = other.cells_[i][j];
		}
	}
}

Matrix Matrix::CreateMatrixWithOperation(const Matrix& other, std::function<float(float, float)> operation) const
{
	float** temp = new float* [rowsCount_];

	for (size_t i = 0; i < rowsCount_; i++)
	{
		temp[i] = new float[colsCount_];

		for (size_t j = 0; j < colsCount_; j++)
		{
			temp[i][j] = operation(cells_[i][j], other.cells_[i][j]);
		}
	}

	return Matrix(temp, rowsCount_, colsCount_);
}

Matrix Matrix::CreateMatrixWithOperation(std::function<float(float)> operation) const
{
	float** temp = new float* [rowsCount_];

	for (size_t i = 0; i < rowsCount_; i++)
	{
		temp[i] = new float[colsCount_];

		for (size_t j = 0; j < colsCount_; j++)
		{
			temp[i][j] = operation(cells_[i][j]);
		}
	}

	return Matrix(temp, rowsCount_, colsCount_);
}


Matrix::Matrix() : cells_(nullptr),
				   rowsCount_(0), 
				   colsCount_(0)
{
}

Matrix::Matrix(size_t rowsCount, size_t colsCount)
{
	rowsCount_ = rowsCount;
	colsCount_ = colsCount;

	cells_ = new float* [rowsCount_];

	for (size_t i = 0; i < rowsCount_; i++)
	{
		cells_[i] = new float[colsCount_] {};
	}
}

Matrix::Matrix(float** cells, size_t rowsCount, size_t colsCount)
{
	cells_ = new float* [rowsCount];
	rowsCount_ = rowsCount;
	colsCount_ = colsCount;

	for (size_t i = 0; i < rowsCount; i++)
	{
		cells_[i] = new float[colsCount];

		for (size_t j = 0; j < colsCount; j++)
		{
			cells_[i][j] = cells[i][j];
		}
	}
}



Matrix::Matrix(const Matrix& matrix)
{
	InitByOtherMatrix(matrix);
}


Matrix::~Matrix()
{
	for (size_t i = 0; i < rowsCount_; i++)
	{
		delete[] cells_[i];
	}

	delete[] cells_;
}


void Matrix::Print() const
{
	for (size_t i = 0; i < rowsCount_; i++)
	{
		for (size_t j = 0; j < colsCount_; j++)
		{
			std::cout << std::setw(3) << cells_[i][j] << " ";
		}

		std::cout << '\n';
	}

	std::cout << std::endl;
}

Matrix Matrix::operator=(const Matrix& other)
{
	InitByOtherMatrix(other);

	return *this;
}


Matrix Matrix::operator+(const Matrix& other) const
{
	return CreateMatrixWithOperation(other, [](float cell1, float cell2)
		{
			return cell1 + cell2;
		});
}

Matrix Matrix::operator-(const Matrix& other) const
{
	return CreateMatrixWithOperation(other, [](float cell1, float cell2)
		{
			return cell1 - cell2;
		});
}

Matrix Matrix::operator*(const Matrix& other) const
{
	float** temp = new float* [rowsCount_] { };

	for (size_t i = 0; i < rowsCount_; i++)
	{
		temp[i] = new float[colsCount_] { };

		for (size_t j = 0; j < colsCount_; j++)
		{
			for (size_t k = 0; k < colsCount_; k++)
			{
				temp[i][j] += cells_[i][k] * other.cells_[k][j];
			}
		}
	}

	return Matrix(temp, rowsCount_, colsCount_);
}

Matrix Matrix::operator/(const Matrix& other) const 
{
	return CreateMatrixWithOperation(other, [](float cell1, float cell2)
		{
			return cell1 / cell2;
		});
}


Matrix Matrix::operator*(float scalar) const
{
	return CreateMatrixWithOperation([scalar](float cell)
		{
			return cell * scalar;
		});
}

Matrix Matrix::operator/(float scalar) const
{
	return CreateMatrixWithOperation([scalar](float cell)
		{
			return cell / scalar;
		});
}


Matrix& Matrix::operator+=(const Matrix& other)
{
	*this = *this + other;
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	*this = *this - other;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	*this = *this * other;
	return *this;
}

Matrix& Matrix::operator/=(const Matrix& other)
{
	*this = *this / other;
	return *this;
}


Matrix& Matrix::operator*=(float scalar)
{
	*this = *this * scalar;
	return *this;
}

Matrix& Matrix::operator/=(float scalar)
{
	*this = *this / scalar;
	return *this;
}


bool Matrix::operator==(const Matrix& other) const
{
	for (size_t i = 0; i < rowsCount_; i++)
	{
		for (size_t j = 0; j < colsCount_; j++)
		{
			if (cells_[i][j] != other.cells_[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
	return !(*this == other);
}

float Matrix::operator ()(size_t rowIndex, size_t colIndex) const 
{
	return cells_[rowIndex][colIndex];
}

float& Matrix::operator ()(size_t rowIndex, size_t colIndex) 
{
	return cells_[rowIndex][colIndex];
}

Matrix Matrix::operator!() const
{
	Matrix result(rowsCount_, colsCount_);

	for (size_t i = 0; i < rowsCount_; i++)
	{
		for (size_t j = 0; j < colsCount_; j++)
		{
			result.cells_[i][j] = cells_[j][i];
		}
	}

	return result;
}

Matrix Matrix::operator&(const Matrix& other) const
{
	return CreateMatrixWithOperation(other, [](float cell1, float cell2)
		{
			return cell1 * cell2;
		});
}

Matrix Matrix::operator%(int rem) const
{
	return CreateMatrixWithOperation([rem](float cell)
		{
			return (int)cell % rem;
		});
}
