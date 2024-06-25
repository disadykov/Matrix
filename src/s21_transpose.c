#include "s21_matrix.h"

/// @brief Транспонирование матрицы (Транспонирование матрицы А заключается в
/// замене строк этой матрицы ее столбцами с сохранением их номеров.)
/// @param A - структура матрицы из хедера
/// @param result - структура матрицы из хедера (записываем результат
/// транспонирования матрицы)
/// @return - MATRIX_OK = 0,MATRIX_INCORRECT = 1
int s21_transpose(matrix_t *A, matrix_t *result) {
  int err_flag = MATRIX_OK;
  if (checkMatrix(A) || !result) {
    err_flag = MATRIX_INCORRECT;
  } else {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }

  return err_flag;
}
