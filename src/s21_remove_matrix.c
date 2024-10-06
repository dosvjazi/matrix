#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (!s21_is_null(A)) {
    if (!s21_is_null(A->matrix)) {
      for (int m = 0; m < A->rows; m++) {
        if (!s21_is_null(A->matrix[m])) free(A->matrix[m]);
      }
      free(A->matrix);
    }
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}