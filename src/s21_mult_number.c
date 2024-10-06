#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = OK;
  if (!s21_is_correct_matrix(A) || s21_is_null(result)) {
    code = INCORRECT_MATRIX;
  } else if ((code = s21_create_matrix(A->rows, A->columns, result)) == OK) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->columns; n++) {
        result->matrix[m][n] = number * A->matrix[m][n];
      }
    }
  }
  return code;
}
