#pragma once
#include <vector>
#include <iostream>

namespace math
{
    #ifdef MATH_DOUBLE_PRECISION_DEFINE
        typedef double real;
    #else
        typedef float real;
    #endif

    //Класс матриц
    class Matrix
    {
    protected:
        int cols_; //количество столбцов в матрице
        int rows_; //количество строк в матрице
        //одномерный вектор элементов матрицы
        std::vector<real> mvec_;
    public:
        //конструктор по умолчанию
        Matrix(){};

        //конструктор с параметрами, создает матрицу заполненную нулевыми значениями
        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};
        
        //получить одномерный вектор элементов mvec вектор элементов матрицы
        void getVec(std::vector<real>& mvec) const;

        // количество строк в матрице
        int rows() const;

        // количество столбцов в матрице 
        int cols() const;

        //оператор доступа к элементам матрицы, row номер строки, col номер столбца
        real& operator()(int row, int col);

        //константная версия operator(), row номер строки, col номер столбца
        real operator()(int row, int col) const;

        //оператор сложения матриц A и B
        friend Matrix operator+(const Matrix& A, const Matrix& B);

        //оператор вычитания матриц A и B
        friend Matrix operator-(const Matrix& A, const Matrix& B);

        //оператор умножения матриц A и B
        friend Matrix operator*(const Matrix& A, const Matrix& B);

        //оператор сложения матриц с присваиванием
		Matrix& operator+=(const Matrix& M);

		// оператор вычитания матриц с присваиванием
		Matrix& operator-=(const Matrix& M);

		//оператор умножения матрицы на число с присваиванием
		Matrix& operator*=(const real n);

        //перегрузка оператора вывода для печати элементов матрицы в консоль
        friend std::ostream& operator<< (std::ostream &out, const Matrix &matrix);
        
        //перегрузка оператора ввода размерности матрицы
        friend std::istream& operator>> (std::istream &in, Matrix &matrix);
    };
} // namespace math
