#include "matrix.h"
#include <iostream>
#include <cmath>

using namespace math;

void math::Matrix::getVec(std::vector<real> &mvec) const
{
    mvec = this->mvec_;
}

int math::Matrix::rows() const
{
    return this->rows_;
}

int math::Matrix::cols() const
{
    return this->cols_;
}

real &Matrix::operator()(int row, int col)
{
    if (row >= this->rows_)
    {
        std::cerr << "Номер строки выходит за пределы" << std::endl;
        // return 0;
    }
    if (col >= this->cols_)
    {
        std::cerr << "Номер столбца выходит за пределы допустимого диапазона" << std::endl;
        // return 0;
    }

    int pos{0};

    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

real Matrix::operator()(int row, int col) const
{
    if (row >= this->rows_)
    {
        std::cerr << "Номер строки выходит за пределы" << std::endl;
    }
    if (col >= this->cols_)
    {
        std::cerr << "Номер столбца выходит за пределы допустимого диапазона" << std::endl;
    }

    int pos{0};

    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

Matrix &math::Matrix::operator+=(const Matrix &M)
{
    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) += M.mvec_.at(i);
    }
    return *this;
}

Matrix &math::Matrix::operator-=(const Matrix &M)
{
    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) -= M.mvec_.at(i);
    }
    return *this;
}

Matrix &math::Matrix::operator*=(const real n)
{
    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) *= n;
    }
    return *this;
}

namespace math
{
    std::ostream &operator<<(std::ostream &out, const Matrix &matrix)
    {
        for (int i = 0; i < matrix.rows_; ++i)
        {
            for (int j = 0; j < matrix.cols_; ++j)
            {
                out << matrix.mvec_.at(matrix.cols_ * i + j) << " ";
            }
            out << std::endl;
        }

        return out;
    }

    std::istream &operator>>(std::istream &in, Matrix &matrix)
    {
        int n(0);
        int m(0);

        in >> n;
        in >> m;

        matrix = Matrix(n, m);

        return in;
    }

    Matrix operator+(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "Операцию сложения выполнить невозможно!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.cols_, A.rows_);

        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            M.mvec_.at(i) = A.mvec_.at(i) + B.mvec_.at(i);
        }

        return M;
    }

    Matrix operator-(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "Операцию вычитания выполнить невозможно!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.cols_, A.rows_);

        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            M.mvec_.at(i) = A.mvec_.at(i) - B.mvec_.at(i);
        }

        return M;
    }

    Matrix operator*(const Matrix &A, const Matrix &B)
    {
        if (A.cols_ != B.rows_)
        {
            std::cerr << "Умножение матриц невозможно!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.rows_, B.cols_);

        for (int pos = 0; pos < M.mvec_.size(); ++pos)
        {
            int row = (int)std::floor(pos / M.cols_);
            int col = pos - row * M.cols_;

            for (int k = 0; k < A.cols_; ++k)
            {
                M.mvec_.at(pos) += A(row, k) * B(k, col);
            }
        }

        return M;
    }
}