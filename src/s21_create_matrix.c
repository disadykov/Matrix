#include "s21_matrix.h"

/// @brief
/// @param rows - кол-во строк
/// @param columns - кол - во столбцов
/// @param result - matrix_t структура
/// @return MATRIX_OK = 0,MATRIX_INCORRECT = 1, MATRIX_CALC_ERR = 2
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err_flag = MATRIX_OK;

  if (!result || rows <= 0 || columns <= 0) {
    err_flag = MATRIX_INCORRECT;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
    }
  }

  return err_flag;
}
