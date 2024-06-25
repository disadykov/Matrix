#include "s21_matrix.h"

/// @brief Функция умножения матрицы на число
/// @param A - структура матрицы из хедера
/// @param number - число на которое нужно умножить элементы матрицы
/// @param result - структура матрицы из хедера (записываем результат)
/// @return - MATRIX_OK = 0, MATRIX_INCORRECT = 1, MATRIX_CALC_ERR = 2 - ошибка
/// вычислений (например умножние матрицы на бесконечность)
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err_flag = MATRIX_OK;
  if (checkMatrix(A) || !result) {
    err_flag = MATRIX_INCORRECT;
  } else {
    if (__builtin_isnan(number) || __builtin_isinf(number)) {
      err_flag = MATRIX_CALC_ERR;
    } else {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }

  return err_flag;
}
