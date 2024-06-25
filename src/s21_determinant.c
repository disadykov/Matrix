#include "s21_matrix.h"

/// @brief Определитель матрицы. Определитель (детерминант) - это число, которое
/// ставят в соответствие каждой квадратной матрице и вычисляют из элементов по
/// специальным формулам. Tip: определитель может быть вычислен только для
/// квадратной матрицы. Определитель матрицы равен сумме произведений элементов
/// строки (столбца) на соответствующие алгебраические дополнения. (все
/// математические формулы вычисления определителя и алгоритм нахождения
/// определителя произвольного порядка использованы с сайта
/// https://ru.onlinemschool.com/math/library/matrix/determinant/#h8)
/// @param A - структура матрицы из хедера
/// @param result - хранит значение определителя матрицы, если определителя нет
/// имеет значение = 0
/// @return - MATRIX_OK = 0, MATRIX_INCORRECT = 1, MATRIX_CALC_ERR = 2 - ошибка
/// вычислений
int s21_determinant(matrix_t *A, double *result) {
  int err_flag = MATRIX_OK;
  if (checkMatrix(A) || !result) {
    err_flag = MATRIX_INCORRECT;
  } else {
    if (A->columns != A->rows) {
      err_flag = MATRIX_CALC_ERR;
    } else {
      matrix_t tmp_matrix;  // новая временная матрица внутри рекурсии
      double tmp_determinant = 0;  // новый детерминант внутри рекурсии
      int tmp_column_matrixA;  // временный столбец матрицы А в рекурсии
      int tmp_column_fix;  // фиксация столбца
      *result = 0;
      if (A->rows == 1) {
        // если матрица 1x1, то определитель равен единственному элементу
        *result = A->matrix[0][0];
      } else if (A->rows == 2) {
        // Определитель матрицы 2х2
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[1][0] * A->matrix[0][1];
      } else {
        for (int i = 0; i < A->columns; i++) {
          // создаем матрицу с уменьшением строк и столбцов на 1
          s21_create_matrix(A->rows - 1, A->columns - 1, &tmp_matrix);
          for (int k = 1, l = 0; k < A->rows; k++, l++) {
            tmp_column_matrixA = 0;
            tmp_column_fix = 0;
            while (tmp_column_matrixA < A->columns) {
              if (tmp_column_matrixA == i) {
                tmp_column_matrixA++;
                continue;
              }
              tmp_matrix.matrix[l][tmp_column_fix] =
                  A->matrix[k][tmp_column_matrixA];
              tmp_column_fix++;
              tmp_column_matrixA++;
            }
          }
          s21_determinant(&tmp_matrix, &tmp_determinant);
          *result += pow(-1.0, i) * A->matrix[0][i] * tmp_determinant;
          s21_remove_matrix(&tmp_matrix);  // очищаем память для tmp
        }
      }
    }
  }

  return err_flag;
}
