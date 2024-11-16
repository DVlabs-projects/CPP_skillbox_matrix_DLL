#pragma once
#include <matrixlib/export.h>

#ifdef MATH_DOUBLE_PRECISION_DEFINE
    typedef double real;
#else
    typedef float real;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct Matrix Matrix;

// Обертка конструктора с параметрами
Matrix* MATRIXLIB_EXPORT math_createMatrix(int rows, int cols);

// Обертка деструктора
void MATRIXLIB_EXPORT math_deleteMatrix(Matrix* M);

// Обертка оператора доступа к элементам матрицы (получение)
real MATRIXLIB_EXPORT math_get(const Matrix* M, int row, int col);

// Обертка оператора доступа к элементам матрицы (запись)
void MATRIXLIB_EXPORT math_set(Matrix* M, int row, int col, real val);

// Обертка оператора вывода элементов матрицы в консоль
void MATRIXLIB_EXPORT math_print(const Matrix* M);

// Обертка оператора ввода элементов матрицы в консоль
void MATRIXLIB_EXPORT math_input(Matrix* M);

/// Обертка оператора сложения матриц
Matrix* MATRIXLIB_EXPORT math_add(const Matrix* A, const Matrix* B);

// Обертка оператора вычитания матриц
Matrix* MATRIXLIB_EXPORT math_subtract(const Matrix* A, const Matrix* B);

/// Обертка оператора умножения матриц
Matrix* MATRIXLIB_EXPORT math_dot(const Matrix* A, const Matrix* B);

#ifdef __cplusplus
}
#endif