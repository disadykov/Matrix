#include "s21_matrix.h"

/// @brief Умножение матриц одинакового размера. Произведением матрицы A = m × k
/// на матрицу B = k × n называется матрица C = m × n = A × B размера m × n,
/// элементы которой определяются равенством C(i,j) = A(i,1) × B(1,j) + A(i,2) ×
/// B(2,j) + … + A(i,k) × B(k,j)
/// @param A - структура матрицы из хедера
/// @param B - структура матрицы из хедера
/// @param result - структура матрицы из хедера (записываем результат)
/// @return MATRIX_OK = 0, MATRIX_INCORRECT = 1, MATRIX_CALC_ERR = 2 - ошибка
/// вычислений (например число строк одной матрицы не равно числу строк второй)
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err_flag = MATRIX_OK;
  if (checkMatrix(A) || checkMatrix(B) || !result) {
    err_flag = MATRIX_INCORRECT;
  } else {
    if (A->columns != B->rows) {
      err_flag = MATRIX_CALC_ERR;
    } else {
      s21_create_matrix(A->rows, B->columns, result);
      double result_item;  // элемент результируещей матрицы
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result_item = 0;
          for (int k = 0; k < A->columns; k++) {
            result_item += A->matrix[i][k] * B->matrix[k][j];
          }
          result->matrix[i][j] = result_item;
        }
      }
    }
  }

  return err_flag;
}
