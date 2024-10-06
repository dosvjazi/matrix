#include "s21_matrix.h"

void s21_cofactor(double **matrix, double **temp, int p, int q, int size) {
  int i = 0, j = 0;
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      if (row != p && col != q) {
        temp[i][j++] = matrix[row][col];
        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

int s21_determinant_of_matrix(double **matrix, int size) {
  int determinant = 0;
  if (size == 1) {
    determinant = matrix[0][0];
  } else {
    matrix_t temp;
    s21_create_matrix(size, size, &temp);
    int sign = 1;
    for (int i = 0; i < size; i++) {
      s21_cofactor(matrix, temp.matrix, 0, i, size);
      determinant += sign * matrix[0][i] *
                     s21_determinant_of_matrix(temp.matrix, size - 1);
      sign = -sign;
    }
    s21_remove_matrix(&temp);
  }
  return determinant;
}

int s21_determinant(matrix_t *A, double *result) {
  int code = OK;
  if (!s21_is_correct_matrix(A)) {
    code = INCORRECT_MATRIX;
  } else if (!s21_is_square(A)) {
    code = CALCULATION_ERROR;
  } else {
    *result = s21_determinant_of_matrix(A->matrix, A->rows);
  }
  return code;
}