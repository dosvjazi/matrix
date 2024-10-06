#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (!s21_is_correct_matrix(A)) {
    code = INCORRECT_MATRIX;
  } else if (!s21_is_square(A)) {
    code = CALCULATION_ERROR;
  } else {
    double determinant = 0.0;
    code = s21_determinant(A, &determinant);
    if (code != OK || determinant == 0) {
      code = CALCULATION_ERROR;
    } else {
      matrix_t complements;
      if ((code = s21_calc_complements(A, &complements)) == OK) {
        matrix_t transpose;
        if ((code = s21_transpose(&complements, &transpose)) == OK) {
          s21_mult_number(&transpose, 1 / determinant, result);
        }
        s21_remove_matrix(&transpose);
      }
      s21_remove_matrix(&complements);
    }
  }
  return code;
}