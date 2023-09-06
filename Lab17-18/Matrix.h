#pragma once
class Matrix
{
private:
	float** _cells = nullptr;
	size_t _rowsCount = 0;
	size_t _colsCount = 0;

public:
	Matrix();
	Matrix(float** cells, size_t rowsCount, size_t colsCount);
	Matrix(Matrix& matrix);

	void Print() const;

	Matrix operator =(const Matrix& other);

	Matrix operator +(const Matrix& other) const;
	Matrix operator -(const Matrix& other) const;
	Matrix operator *(const Matrix& other) const;
	Matrix operator /(const Matrix& other) const;
	
	Matrix operator *(int scalar) const;
	Matrix operator /(int scalar) const;

	Matrix operator +=(const Matrix& other);
	Matrix operator -=(const Matrix& other);
	Matrix operator *=(const Matrix& other);
	Matrix operator /=(const Matrix& other);

	Matrix operator *=(int scalar);
	Matrix operator /=(int scalar);

	Matrix operator ==(const Matrix& other) const;
	Matrix operator !=(const Matrix& other) const;

	float operator ()(size_t rowIndex, size_t colIndex) const;
};

