#include "s21_matrix.h"

/// @brief Минор матрицы и матрица алгебраических дополнений. Минором M(i,j)
/// называется определитель (n-1)-го порядка, полученный вычёркиванием из
/// матрицы A i-й строки и j-го столбца. Алгебраическим дополнением элемента
/// матрицы  является значение минора умноженное на -1^(i+j). Информация по
/// алгоритму поиска с сайта
/// https://ru.onlinemschool.com/math/library/matrix/minors/
/// @param A - структура матрицы из хедера
/// @param result - структура матрицы из хедера (формируем матрицу
/// алгебраических дополнений)
/// @return - MATRIX_OK = 0, MATRIX_INCORRECT = 1, MATRIX_CALC_ERR = 2 - ошибка
/// вычислений
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err_flag = MATRIX_OK;
  if (checkMatrix(A) || !result || (A->rows == 1 && A->columns == 1)) {
    err_flag = MATRIX_INCORRECT;
  } else {
    if (A->columns != A->rows) {
      err_flag = MATRIX_CALC_ERR;
    } else {
      matrix_t minor_matrix;  // матрица для миноров
      double determinant_minor = 0;  // определитель матрицы миноров
      int row_countA, column_countA;  // счетчики обхода по строкам и столбцам
      int m_rows, m_columns;  // счетчики строк и столбцов в матрице миноров

      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);
          row_countA = 0;
          m_rows = 0;
          while (row_countA < A->rows) {
            if (row_countA == i) {
              row_countA++;
              continue;
            }
            column_countA = 0;
            m_columns = 0;
            while (column_countA < A->columns) {
              if (column_countA == j) {
                column_countA++;
                continue;
              }
              minor_matrix.matrix[m_rows][m_columns] =
                  A->matrix[row_countA][column_countA];
              m_columns++;
              column_countA++;
            }
            m_rows++;
            row_countA++;
          }
          determinant_minor = 0;
          s21_determinant(&minor_matrix, &determinant_minor);
          result->matrix[i][j] = pow(-1, (i + j)) * determinant_minor;
          s21_remove_matrix(&minor_matrix);
        }
      }
    }
  }

  return err_flag;
}
