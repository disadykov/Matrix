#include "s21_matrix.h"

/// @brief Функция сравнения матриц. Две матрицы A, B совпадают |A = B|, если
/// совпадают их размеры и соответствующие элементы равны, то есть при всех i, j
/// A(i,j) = B(i,j). Сравнение должно происходить вплоть до 7 знака после
/// запятой включительно.
/// @param A - структура матрицы из хедера
/// @param B - структура матрицы из хедера
/// @return - при равенстве возращаем SUCCESS, иначе FAILURE
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int eq_status = SUCCESS;
  if ((sizeMatrixCheck(A, B)) || checkMatrix(A) || checkMatrix(B)) {
    eq_status = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= PRECISION) {
          eq_status = FAILURE;
          break;
        } else {
          double tmp = 0;
          // получаем число после запятой и домножаем на 7 знаков значащих цифры
          double fraction_A = modf(A->matrix[i][j], &tmp) * SIGNIFICANT_DIGITS;
          double fraction_B = modf(B->matrix[i][j], &tmp) * SIGNIFICANT_DIGITS;
          // берем целое число (по факту дробная часть до 7го знака
          // включительно) и проверяем на равенство
          int seven_digits_A = (int)fraction_A;
          int seven_digits_B = (int)fraction_B;
          if (seven_digits_A != seven_digits_B) {
            eq_status = FAILURE;
            break;
          }
        }
      }
      if (!eq_status) break;
    }
  }
  return eq_status;
}