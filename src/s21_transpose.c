#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (!s21_is_correct_matrix(A)) {
    code = INCORRECT_MATRIX;
  } else if ((code = s21_create_matrix(A->columns, A->rows, result)) == OK) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->columns; n++) {
        result->matrix[n][m] = A->matrix[m][n];
      }
    }
  }
  return code;
}