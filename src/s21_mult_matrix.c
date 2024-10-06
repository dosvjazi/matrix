#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (!s21_is_correct_matrix(A) || !s21_is_correct_matrix(B)) {
    code = INCORRECT_MATRIX;
  } else if (!s21_is_compatible(A, B)) {
    code = CALCULATION_ERROR;
  } else if ((code = s21_create_matrix(A->rows, B->columns, result)) == OK) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < B->columns; n++) {
        for (int l = 0; l < A->columns; l++) {
          result->matrix[m][n] += A->matrix[m][l] * B->matrix[l][n];
        }
      }
    }
  }
  return code;
}