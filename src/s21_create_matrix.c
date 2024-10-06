#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int code = OK;
  if (s21_is_incorrect_size(rows, columns) || s21_is_null(result)) {
    if (!s21_is_null(result)) {
      result->rows = 0;
      result->columns = 0;
      result->matrix = NULL;
    }
    code = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double*));
    if (!(code = s21_is_null(result->matrix))) {
      for (int m = 0; m < rows; m++) {
        result->matrix[m] = calloc(columns, sizeof(double));
        code = result->matrix[m] == NULL ? INCORRECT_MATRIX : code;
      }
    }
  }
  if (code == INCORRECT_MATRIX) s21_remove_matrix(result);
  return code;
}
