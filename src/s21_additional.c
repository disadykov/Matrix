#include "s21_matrix.h"

/// @brief проверка матрицы на корректность, чтобы не проводить действий
/// (удаление и т.п.) с некорректной матрицей
/// @param *matrix - структура матрицы из хедера
/// @return MATRIX_OK = 0, MATRIX_INCORRECT = 1 (error)
int checkMatrix(matrix_t *matrix) {
  int err_flag = MATRIX_OK;
  if (!matrix || matrix->rows <= 0 || matrix->columns <= 0)
    err_flag = MATRIX_INCORRECT;
  return err_flag;
}

/// @brief Проверка что строки и столбцы матрицы одинакового размера + доп.
/// проверка что параметры матрицы корректны
/// @param A - структура матрицы из хедера
/// @param B - структура матрицы из хедера
/// @return - если матрицы разного размера то возвращаем FAILURE, иначе SUCCESS
int sizeMatrixCheck(matrix_t *A, matrix_t *B) {
  int check_status = MATRIX_OK;
  if (!A || !B || A->rows != B->rows || A->columns != B->columns) {
    check_status = MATRIX_INCORRECT;
  }
  return check_status;
}