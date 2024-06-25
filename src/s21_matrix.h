#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#define MATRIX_OK 0         // Нет ошибок
#define MATRIX_INCORRECT 1  // Ошибка, некорректная матрица
#define MATRIX_CALC_ERR 2  // Ошибка вычисления
#define SUCCESS 1          // Сравнение матриц ОК
#define FAILURE 0          // Сравнение матриц !ОК
#define PRECISION 1e-7  // для сравнения знаков после запятой
#define SIGNIFICANT_DIGITS 1e7  // отсечка по значащим цифрам в 7 знаков

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Дополнительные функции
int checkMatrix(matrix_t *matrix);  // Проверка матрицы на корректность
int sizeMatrixCheck(matrix_t *A, matrix_t *B);  // Проверка размера матриц

#endif  // SRC_S21_MATRIX_H_