#include "s21_matrix.h"

int s21_is_incorrect_size(int rows, int columns) {
  return rows <= 0 || columns <= 0;
}

int s21_is_null(const void *pointer) { return pointer == NULL; }

int s21_is_correct_matrix(matrix_t *A) {
  int code = 1;
  if ((code = !s21_is_null(A) && !s21_is_null(A->matrix)) == 1) {
    if (A->rows <= 0 || A->columns <= 0) code = 0;
    for (int m = 0; m < A->rows; m++) {
      if (s21_is_null(A->matrix[m])) code = 0;
    }
    for (int m = 0; m < A->rows && code == 1; m++) {
      for (int n = 0; n < A->columns && code == 1; n++) {
        double number = A->matrix[m][n];
        if (isinf(number) || isnan(number)) code = 0;
      }
    }
  }
  return code;
}

int s21_is_eq_size(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

int s21_is_compatible(matrix_t *A, matrix_t *B) {
  return A->columns == B->rows;
}

int s21_is_square(matrix_t *A) { return A->rows == A->columns; }

int s21_minor(int row, int column, matrix_t *A, matrix_t *result) {
  int code = OK;
  if ((code = s21_create_matrix(A->rows - 1, A->columns - 1, result)) == OK) {
    for (int m = 0; m < A->rows; m++) {
      int i = m;
      if (m > row) i--;
      for (int n = 0; n < A->columns; n++) {
        int j = n;
        if (n > column) j--;
        if (m != row && n != column) result->matrix[i][j] = A->matrix[m][n];
      }
    }
  }
  return code;
}

int s21_sum_or_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result,
                          int sign) {
  int code = OK;
  if (!s21_is_correct_matrix(A) || !s21_is_correct_matrix(B)) {
    code = INCORRECT_MATRIX;
  } else if (!s21_is_eq_size(A, B)) {
    code = CALCULATION_ERROR;
  } else if ((code = s21_create_matrix(A->rows, A->columns, result)) == OK) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->columns; n++) {
        result->matrix[m][n] = A->matrix[m][n] + sign * B->matrix[m][n];
      }
    }
  }
  return code;
}