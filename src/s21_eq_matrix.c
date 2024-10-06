#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;
  if (!s21_is_correct_matrix(A) || !s21_is_correct_matrix(B) ||
      !s21_is_eq_size(A, B)) {
    code = FAILURE;
  } else {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->columns; n++) {
        if (fabs(A->matrix[m][n] - B->matrix[m][n]) >= PRECISION) {
          code = FAILURE;
        }
      }
    }
  }
  return code;
}