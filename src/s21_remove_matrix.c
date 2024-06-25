#include "s21_matrix.h"

/// @brief удаление матрицы (освобождение памяти) и зануление структуры
/// @param A - структура матрицы из хедера
void s21_remove_matrix(matrix_t *A) {
  if (!checkMatrix(A)) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}
