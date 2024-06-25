#include "s21_matrix.h"

/// @brief Сложение матриц одинакового размера
/// @param A - структура матрицы из хедера
/// @param B - структура матрицы из хедера
/// @param result - структура матрицы из хедера (записываем результат)
/// @return MATRIX_OK = 0,MATRIX_INCORRECT = 1
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err_flag = MATRIX_OK;
  if (checkMatrix(A) || checkMatrix(B) || !result) {
    err_flag = MATRIX_INCORRECT;
  } else {
    if ((sizeMatrixCheck(A, B))) {
      err_flag = MATRIX_INCORRECT;
    } else {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }

  return err_flag;
}
