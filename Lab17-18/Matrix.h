#pragma once
#include <functional>

class Matrix
{
private:
	float** cells_;
	size_t rowsCount_;
	size_t colsCount_;

	void InitByOtherMatrix(const Matrix& other);

	/// <summary>
	/// Создание матрицы на основе поэлементной операции над 
	/// элементами данной
	/// и <paramref name="other"/> матриц.
	/// </summary>
	Matrix CreateMatrixWithOperation(const Matrix& other, std::function<float(float, float)> operation) const;

	/// <summary>
	/// Создание матрицы на основе поэлементной
	/// операции над элементами данной матрицы.
	/// </summary>
	Matrix CreateMatrixWithOperation(std::function<float(float)> operation) const;

public:
	/// <summary>
	/// Создание неинициализированной матрицы нулевого размера.
	/// </summary>
	Matrix();

	/// <summary>
	/// Создание пустой матрицы размером <paramref name="rowsCount"/> э
	/// на <paramref name="colsCount"/>.
	/// </summary>
	Matrix(size_t rowsCount, size_t colsCount);

	/// <summary>
	/// Создание матрицы размером <paramref name="rowsCount"/> 
	/// на <paramref name="colsCount"/>
	/// на основе двумерного массива <paramref name="cells" />.
	/// </summary>
	Matrix(float** cells, size_t rowsCount, size_t colsCount);

	Matrix(const Matrix& matrix);

	~Matrix();

	/// <summary>
	/// Вывод матрицы в консоль.
	/// </summary>
	void Print() const;

	Matrix operator =(const Matrix& other);

	Matrix operator +(const Matrix& other) const;
	Matrix operator -(const Matrix& other) const;
	Matrix operator *(const Matrix& other) const;
	Matrix operator /(const Matrix& other) const;
	
	Matrix operator *(int scalar) const;
	Matrix operator /(int scalar) const;

	Matrix& operator +=(const Matrix& other);
	Matrix& operator -=(const Matrix& other);
	Matrix& operator *=(const Matrix& other);
	Matrix& operator /=(const Matrix& other);

	Matrix& operator *=(int scalar);
	Matrix& operator /=(int scalar);

	bool operator ==(const Matrix& other) const;
	bool operator !=(const Matrix& other) const;

	float operator ()(size_t rowIndex, size_t colIndex) const;
	float& operator ()(size_t rowIndex, size_t colIndex);
};