#include <iostream>
#include <locale>

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif
    extern Matrix* __declspec(dllimport) math_createMatrix(int, int);
    extern void __declspec(dllimport) math_deleteMatrix(Matrix *);
    extern double __declspec(dllimport) math_get(Matrix *, int, int);
    extern void __declspec(dllimport) math_set(Matrix *, int, int, double);
    extern Matrix* __declspec(dllimport) math_add(Matrix *, Matrix *);
    extern void __declspec(dllimport) math_print(Matrix *);
#ifdef __cplusplus
}
#endif

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    //Создаем первую матрицу
    Matrix *m = math_createMatrix(3, 3);

    math_set(m, 0, 0, 1.);
    math_set(m, 1, 1, 1.);

    std::cout << "Матрица m:" << std::endl;
    math_print(m);
    
    //Создаем вторую матрицу
    Matrix *m1 = math_createMatrix(3, 3);

    math_set(m1, 0, 0, 5.);
    math_set(m1, 1, 1, 5.);

    std::cout << "Матрица m1:" << std::endl;
    math_print(m1);

    Matrix *m2 = math_add(m, m1);
    std::cout << "Сумма матриц m и m1:" << std::endl;
    math_print(m2);

    // Вызываем деструктор
    math_deleteMatrix(m);
    math_deleteMatrix(m1);
    math_deleteMatrix(m2);

    return 0;
}