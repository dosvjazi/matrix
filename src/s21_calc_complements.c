#include "s21_matrix.h"

int s21_calc_complements_handle(matrix_t *A, matrix_t *result) {
  int code = OK;
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      matrix_t minor;
      double determinant = 0;
      if ((code = s21_minor(m, n, A, &minor)) == OK) {
        if ((code = s21_determinant(&minor, &determinant)) == OK) {
          result->matrix[m][n] = pow(-1, m + n) * determinant;
        }
      }
      s21_remove_matrix(&minor);
    }
  }
  return code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (!s21_is_correct_matrix(A)) {
    code = INCORRECT_MATRIX;
  } else if ((code = s21_create_matrix(A->rows, A->columns, result)) == OK) {
    code = s21_calc_complements_handle(A, result);
  }
  return code;
}