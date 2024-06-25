#include "s21_matrix.h"

/// @brief Обратная матрица. Матрицу A в степени -1 называют обратной к
/// квадратной матрице А, если произведение этих матриц равняется единичной
/// матрице. Обратной матрицы не существует, если определитель равен 0.
/// Алгоритма вычисления обратной матрицы с помощью союзной матрицы взят с сайта
/// https://ru.onlinemschool.com/math/library/matrix/inverse/
/// @param A - структура матрицы из хедера
/// @param result - структура матрицы из хедера (записываем обратную матрицу)
/// @return - MATRIX_OK = 0, MATRIX_INCORRECT = 1, MATRIX_CALC_ERR = 2 - ошибка
/// вычислений
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err_flag = MATRIX_OK;
  if (checkMatrix(A) || !result) {
    err_flag = MATRIX_INCORRECT;
  } else {
    double determinant = 0;  // определитель матрицы
    s21_determinant(A, &determinant);
    if (determinant == 0) {
      err_flag = MATRIX_CALC_ERR;
    } else {
      if ((1 == A->rows) && (1 == A->columns)) {
        // частный случай (матрица с 1 элементом)
        s21_create_matrix(1, 1, result);
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
      } else {
        // вычисляем матрицу алгебраиических дополнений
        matrix_t calc_matrix = {NULL, 0, 0};
        s21_calc_complements(A, &calc_matrix);

        // транспонируем найденную матрицу алг. дополнений
        matrix_t transponse_calc = {NULL, 0, 0};
        s21_transpose(&calc_matrix, &transponse_calc);

        s21_mult_number(&transponse_calc, 1.0 / determinant, result);
        s21_remove_matrix(&calc_matrix);
        s21_remove_matrix(&transponse_calc);
      }
    }
  }

  return err_flag;
}
