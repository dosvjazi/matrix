#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

START_TEST(create_matrix0) {
  matrix_t A;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(create_matrix1) {
  matrix_t A;
  int rows = 4, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(create_matrix2) {
  matrix_t A;
  int rows = 1, columns = 1;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(create_matrix3) {
  matrix_t A;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(create_matrix4) {
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, NULL);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
}

START_TEST(create_matrix5) {
  matrix_t A;
  int rows = 2, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(remove_matrix0) {
  matrix_t A;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
  ck_assert_msg(A.matrix == NULL, "Failed: remove. Code: %d", code);
}

START_TEST(remove_matrix1) {
  matrix_t A;
  int rows = 4, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
  ck_assert_msg(A.matrix == NULL, "Failed: remove. Code: %d", code);
}

START_TEST(remove_matrix2) {
  matrix_t A;
  int rows = 1, columns = 1;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
  ck_assert_msg(A.matrix == NULL, "Failed: remove. Code: %d", code);
}

START_TEST(remove_matrix3) {
  matrix_t A;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
  ck_assert_msg(A.matrix == NULL, "Failed: remove. Code: %d", code);
}

START_TEST(remove_matrix4) {
  matrix_t A;
  int rows = 2, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  s21_remove_matrix(&A);
  ck_assert_msg(A.matrix == NULL, "Failed: remove. Code: %d", code);
}

START_TEST(eq_matrix0) {
  matrix_t A, B;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_eq_matrix(&A, &B);
  ck_assert_msg(code == SUCCESS, "Failed: eq. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix1) {
  matrix_t A, B;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  code = s21_eq_matrix(&A, &B);
  ck_assert_msg(code == FAILURE, "Failed: eq. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix2) {
  matrix_t A, B;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows - 1, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_eq_matrix(&A, &B);
  ck_assert_msg(code == FAILURE, "Failed: eq. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix3) {
  matrix_t A;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_eq_matrix(&A, NULL);
  ck_assert_msg(code == FAILURE, "Failed: eq. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(eq_matrix4) {
  matrix_t A, B;
  int rows = 2, columns = 1;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_eq_matrix(&A, &B);
  ck_assert_msg(code == SUCCESS, "Failed: eq. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(sum_matrix0) {
  matrix_t A, B, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_sum_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: sum. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(sum_matrix1) {
  matrix_t A, B, R;
  int rows = 4, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_sum_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: sum. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(sum_matrix2) {
  matrix_t A, B, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;
  code = s21_sum_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: sum. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 6, "Failed: sum. Number: %f", R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 8, "Failed: sum. Number: %f", R.matrix[0][1]);
  ck_assert_msg(R.matrix[1][0] == 10, "Failed: sum. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 12, "Failed: sum. Number: %f",
                R.matrix[1][1]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(sum_matrix3) {
  matrix_t A, B, R;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_sum_matrix(&A, &B, &R);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: sum. Code: %d", code);
}

START_TEST(sum_matrix4) {
  matrix_t A, B, R;
  int rows1 = 2, columns1 = 3;
  int rows2 = 2, columns2 = 4;
  int code = s21_create_matrix(rows1, columns1, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows2, columns2, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_sum_matrix(&A, &B, &R);
  ck_assert_msg(code == CALCULATION_ERROR, "Failed: sum. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(sum_matrix5) {
  matrix_t A, B, R;
  int rows = 1, columns = 1;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = INFINITY;
  code = s21_sum_matrix(&A, &B, &R);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: sum. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(sum_matrix6) {
  matrix_t A, B, R;
  int rows = 3, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;
  code = s21_sum_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: sum. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 2, "Failed: sum. Number: %f", R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 2, "Failed: sum. Number: %f", R.matrix[0][1]);
  ck_assert_msg(R.matrix[0][2] == 3, "Failed: sum. Number: %f", R.matrix[0][2]);
  ck_assert_msg(R.matrix[1][0] == 2, "Failed: sum. Number: %f", R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 4, "Failed: sum. Number: %f", R.matrix[1][1]);
  ck_assert_msg(R.matrix[1][2] == 5, "Failed: sum. Number: %f", R.matrix[1][2]);
  ck_assert_msg(R.matrix[2][0] == 3, "Failed: sum. Number: %f", R.matrix[2][0]);
  ck_assert_msg(R.matrix[2][1] == 4, "Failed: sum. Number: %f", R.matrix[2][1]);
  ck_assert_msg(R.matrix[2][2] == 7, "Failed: sum. Number: %f", R.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(sub_matrix0) {
  matrix_t A, B, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_sub_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: sub. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(sub_matrix1) {
  matrix_t A, B, R;
  int rows = 4, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_sub_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: sub. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(sub_matrix2) {
  matrix_t A, B, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;
  code = s21_sub_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: sub. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == -4, "Failed: sub. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == -4, "Failed: sub. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[1][0] == -4, "Failed: sub. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == -4, "Failed: sub. Number: %f",
                R.matrix[1][1]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(sub_matrix3) {
  matrix_t A, B, R;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_sub_matrix(&A, &B, &R);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: sub. Code: %d", code);
}

START_TEST(sub_matrix4) {
  matrix_t A, B, R;
  int rows1 = 2, columns1 = 3;
  int rows2 = 2, columns2 = 4;
  int code = s21_create_matrix(rows1, columns1, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows2, columns2, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_sub_matrix(&A, &B, &R);
  ck_assert_msg(code == CALCULATION_ERROR, "Failed: sub. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(sub_matrix5) {
  matrix_t A, B, R;
  int rows = 3, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 3;
  B.matrix[2][1] = 4;
  B.matrix[2][2] = 1;
  code = s21_sub_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: sub. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 0, "Failed: sub. Number: %f", R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 2, "Failed: sub. Number: %f", R.matrix[0][1]);
  ck_assert_msg(R.matrix[0][2] == 3, "Failed: sub. Number: %f", R.matrix[0][2]);
  ck_assert_msg(R.matrix[1][0] == -2, "Failed: sub. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 4, "Failed: sub. Number: %f", R.matrix[1][1]);
  ck_assert_msg(R.matrix[1][2] == 5, "Failed: sub. Number: %f", R.matrix[1][2]);
  ck_assert_msg(R.matrix[2][0] == -3, "Failed: sub. Number: %f",
                R.matrix[2][0]);
  ck_assert_msg(R.matrix[2][1] == -4, "Failed: sub. Number: %f",
                R.matrix[2][1]);
  ck_assert_msg(R.matrix[2][2] == 5, "Failed: sub. Number: %f", R.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(mult_number0) {
  matrix_t A, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_mult_number(&A, 0, &R);
  ck_assert_msg(code == OK, "Failed: mult_number. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

START_TEST(mult_number1) {
  matrix_t A, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  code = s21_mult_number(&A, 2, &R);
  ck_assert_msg(code == OK, "Failed: mult_number. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 2, "Failed: mult_number. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 4, "Failed: mult_number. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[1][0] == 6, "Failed: mult_number. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 8, "Failed: mult_number. Number: %f",
                R.matrix[1][1]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

START_TEST(mult_number2) {
  matrix_t A, R;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_mult_number(&A, 2, &R);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: mult_number. Code: %d",
                code);
  s21_remove_matrix(&A);
}

START_TEST(mult_number3) {
  int code = s21_mult_number(NULL, 2, NULL);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: mult_number. Code: %d",
                code);
}

START_TEST(mult_number4) {
  matrix_t A, R;
  int rows = 3, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 3;
  A.matrix[2][2] = 4;
  code = s21_mult_number(&A, 2, &R);
  ck_assert_msg(code == OK, "Failed: mult_number. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 2, "Failed: mult_number. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 4, "Failed: mult_number. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[0][2] == 6, "Failed: mult_number. Number: %f",
                R.matrix[0][2]);
  ck_assert_msg(R.matrix[1][0] == 0, "Failed: mult_number. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 8, "Failed: mult_number. Number: %f",
                R.matrix[1][1]);
  ck_assert_msg(R.matrix[1][2] == 4, "Failed: mult_number. Number: %f",
                R.matrix[1][2]);
  ck_assert_msg(R.matrix[2][0] == 4, "Failed: mult_number. Number: %f",
                R.matrix[2][0]);
  ck_assert_msg(R.matrix[2][1] == 6, "Failed: mult_number. Number: %f",
                R.matrix[2][1]);
  ck_assert_msg(R.matrix[2][2] == 8, "Failed: mult_number. Number: %f",
                R.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

START_TEST(mult_matrix0) {
  matrix_t A, B, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_mult_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: mult_matrix. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}
START_TEST(mult_matrix1) {
  matrix_t A, B, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_mult_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: mult_matrix. Code: %d", code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(mult_matrix2) {
  matrix_t A, B, R;
  int rows = 4, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_mult_matrix(&A, &B, &R);
  ck_assert_msg(code == CALCULATION_ERROR, "Failed: mult_matrix. Code: %d",
                code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(mult_matrix3) {
  matrix_t A, B, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 6;
  B.matrix[1][0] = 7;
  B.matrix[1][1] = 8;
  code = s21_mult_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: mult_matrix. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 19, "Failed: mult_matrix. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 22, "Failed: mult_matrix. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[1][0] == 43, "Failed: mult_matrix. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 50, "Failed: mult_matrix. Number: %f",
                R.matrix[1][1]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(mult_matrix4) {
  int code = s21_mult_matrix(NULL, NULL, NULL);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: mult_matrix. Code: %d",
                code);
}

START_TEST(mult_matrix5) {
  matrix_t A, B;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_create_matrix(rows, columns, &B);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_mult_matrix(&A, &B, NULL);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: mult_matrix. Code: %d",
                code);
  s21_remove_matrix(&A);
}

START_TEST(mult_matrix6) {
  matrix_t A, B, R;
  int rows = 3, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_create_matrix(columns, rows, &B);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;
  code = s21_mult_matrix(&A, &B, &R);
  ck_assert_msg(code == OK, "Failed: mult_matrix. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 9, "Failed: mult_matrix. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 11, "Failed: mult_matrix. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[0][2] == 17, "Failed: mult_matrix. Number: %f",
                R.matrix[0][2]);
  ck_assert_msg(R.matrix[1][0] == 12, "Failed: mult_matrix. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 13, "Failed: mult_matrix. Number: %f",
                R.matrix[1][1]);
  ck_assert_msg(R.matrix[1][2] == 22, "Failed: mult_matrix. Number: %f",
                R.matrix[1][2]);
  ck_assert_msg(R.matrix[2][0] == 15, "Failed: mult_matrix. Number: %f",
                R.matrix[2][0]);
  ck_assert_msg(R.matrix[2][1] == 15, "Failed: mult_matrix. Number: %f",
                R.matrix[2][1]);
  ck_assert_msg(R.matrix[2][2] == 27, "Failed: mult_matrix. Number: %f",
                R.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
}

START_TEST(transpose0) {
  matrix_t A, R;
  int rows = 1, columns = 1;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_transpose(&A, &R);
  ck_assert_msg(code == OK, "Failed: transose. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 0, "Failed: transpose. Number: %f",
                R.matrix[0][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

START_TEST(transpose1) {
  matrix_t A;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_transpose(&A, NULL);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: transose. Code: %d", code);
}

START_TEST(transpose2) {
  matrix_t A, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  code = s21_transpose(&A, &R);
  ck_assert_msg(code == OK, "Failed: transose. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 1, "Failed: transpose. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 3, "Failed: transpose. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[1][0] == 2, "Failed: transpose. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 4, "Failed: transpose. Number: %f",
                R.matrix[1][1]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

START_TEST(transpose3) {
  matrix_t A, R;
  int rows = 1, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  code = s21_transpose(&A, &R);
  ck_assert_msg(code == OK, "Failed: transose. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 1, "Failed: transpose. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[1][0] == 2, "Failed: transpose. Number: %f",
                R.matrix[1][0]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

START_TEST(transpose4) {
  matrix_t A, R;
  int rows = 3, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  code = s21_transpose(&A, &R);
  ck_assert_msg(code == OK, "Failed: transpose. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 1, "Failed: transpose. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 2, "Failed: transpose. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[0][2] == 3, "Failed: transpose. Number: %f",
                R.matrix[0][2]);
  ck_assert_msg(R.matrix[1][0] == 4, "Failed: transpose. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 5, "Failed: transpose. Number: %f",
                R.matrix[1][1]);
  ck_assert_msg(R.matrix[1][2] == 6, "Failed: transpose. Number: %f",
                R.matrix[1][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

START_TEST(calc_complements0) {
  matrix_t A, R;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_calc_complements(&A, &R);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: calc_complements. Code: %d",
                code);
  s21_remove_matrix(&A);
}

START_TEST(calc_complements1) {
  matrix_t A, R;
  int rows = 3, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  code = s21_calc_complements(&A, &R);
  ck_assert_msg(code == OK, "Failed: calc_complements. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 0, "Failed: calc_complements. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 10, "Failed: calc_complements. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[0][2] == -20, "Failed: calc_complements. Number: %f",
                R.matrix[0][2]);
  ck_assert_msg(R.matrix[1][0] == 4, "Failed: calc_complements. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == -14, "Failed: calc_complements. Number: %f",
                R.matrix[1][1]);
  ck_assert_msg(R.matrix[1][2] == 8, "Failed: calc_complements. Number: %f",
                R.matrix[1][2]);
  ck_assert_msg(R.matrix[2][0] == -8, "Failed: calc_complements. Number: %f",
                R.matrix[2][0]);
  ck_assert_msg(R.matrix[2][1] == -2, "Failed: calc_complements. Number: %f",
                R.matrix[2][1]);
  ck_assert_msg(R.matrix[2][2] == 4, "Failed: calc_complements. Number: %f",
                R.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

START_TEST(determinant0) {
  matrix_t A;
  double det;
  int rows = 1, columns = 1;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_determinant(&A, &det);
  ck_assert_msg(code == OK, "Failed: determinant. Code: %d", code);
  ck_assert_msg(det == 0, "Failed: determinant. Number: %f", det);
  s21_remove_matrix(&A);
}

START_TEST(determinant1) {
  matrix_t A;
  double det;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  code = s21_determinant(&A, &det);
  ck_assert_msg(code == OK, "Failed: determinant. Code: %d", code);
  ck_assert_msg(det == 3, "Failed: determinant. Number: %f", det);
  s21_remove_matrix(&A);
}

START_TEST(determinant2) {
  matrix_t A;
  double det;
  int rows = 0, columns = 0;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: create. Code: %d", code);
  code = s21_determinant(&A, &det);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: determinant. Code: %d",
                code);
}

START_TEST(determinant3) {
  matrix_t A;
  double det;
  int rows = 1, columns = 1;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  code = s21_determinant(&A, &det);
  ck_assert_msg(code == OK, "Failed: determinant. Code: %d", code);
  ck_assert_msg(det == 1, "Failed: determinant. Number: %f", det);
  s21_remove_matrix(&A);
}

START_TEST(determinant4) {
  matrix_t A;
  double det;
  int rows = 1, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_determinant(&A, &det);
  ck_assert_msg(code == CALCULATION_ERROR, "Failed: determinant. Code: %d",
                code);
  s21_remove_matrix(&A);
}

START_TEST(determinant5) {
  matrix_t A;
  double determinant;
  int rows = 3, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  code = s21_determinant(&A, &determinant);
  ck_assert_msg(code == OK, "Failed: determinant. Code: %d", code);
  ck_assert_msg(determinant == 0, "Failed: determinant. Number: %f",
                determinant);
  s21_remove_matrix(&A);
}

START_TEST(inverse_matrix0) {
  matrix_t A, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_inverse_matrix(&A, &R);
  ck_assert_msg(code == CALCULATION_ERROR, "Failed: inverse. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(inverse_matrix1) {
  matrix_t A, R;
  int rows = 1, columns = 1;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_inverse_matrix(&A, &R);
  ck_assert_msg(code == CALCULATION_ERROR, "Failed: inverse. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(inverse_matrix2) {
  matrix_t A, R;
  int rows = 2, columns = 2;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 2;
  code = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(code, OK);
  ck_assert_msg(code == OK, "Failed: inverse. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == -2, "Failed: inverse. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == 3, "Failed: inverse. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[1][0] == 3, "Failed: inverse. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == -4, "Failed: inverse. Number: %f",
                R.matrix[1][1]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
START_TEST(inverse_matrix3) {
  matrix_t A, R;
  int rows = 2, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  code = s21_inverse_matrix(&A, &R);
  ck_assert_msg(code == CALCULATION_ERROR, "Failed: inverse. Code: %d", code);
  s21_remove_matrix(&A);
}

START_TEST(inverse_matrix4) {
  matrix_t R;
  int code = s21_inverse_matrix(NULL, &R);
  ck_assert_msg(code == INCORRECT_MATRIX, "Failed: inverse. Code: %d", code);
}

START_TEST(inverse_matrix5) {
  matrix_t A, R;
  int rows = 3, columns = 3;
  int code = s21_create_matrix(rows, columns, &A);
  ck_assert_msg(code == OK, "Failed: create. Code: %d", code);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  code = s21_inverse_matrix(&A, &R);
  ck_assert_msg(code == OK, "Failed: inverse. Code: %d", code);
  ck_assert_msg(R.matrix[0][0] == 1, "Failed: inverse. Number: %f",
                R.matrix[0][0]);
  ck_assert_msg(R.matrix[0][1] == -1, "Failed: inverse. Number: %f",
                R.matrix[0][1]);
  ck_assert_msg(R.matrix[0][2] == 1, "Failed: inverse. Number: %f",
                R.matrix[0][2]);
  ck_assert_msg(R.matrix[1][0] == -38, "Failed: inverse. Number: %f",
                R.matrix[1][0]);
  ck_assert_msg(R.matrix[1][1] == 41, "Failed: inverse. Number: %f",
                R.matrix[1][1]);
  ck_assert_msg(R.matrix[1][2] == -34, "Failed: inverse. Number: %f",
                R.matrix[1][2]);
  ck_assert_msg(R.matrix[2][0] == 27, "Failed: inverse. Number: %f",
                R.matrix[2][0]);
  ck_assert_msg(R.matrix[2][1] == -29, "Failed: inverse. Number: %f",
                R.matrix[2][1]);
  ck_assert_msg(R.matrix[2][2] == 24, "Failed: inverse. Number: %f",
                R.matrix[2][2]);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}

Suite *suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("suite");
  tc_core = tcase_create("core");

  tcase_add_test(tc_core, create_matrix0);
  tcase_add_test(tc_core, create_matrix1);
  tcase_add_test(tc_core, create_matrix2);
  tcase_add_test(tc_core, create_matrix3);
  tcase_add_test(tc_core, create_matrix4);
  tcase_add_test(tc_core, create_matrix5);

  tcase_add_test(tc_core, remove_matrix0);
  tcase_add_test(tc_core, remove_matrix1);
  tcase_add_test(tc_core, remove_matrix2);
  tcase_add_test(tc_core, remove_matrix3);
  tcase_add_test(tc_core, remove_matrix4);

  tcase_add_test(tc_core, eq_matrix0);
  tcase_add_test(tc_core, eq_matrix1);
  tcase_add_test(tc_core, eq_matrix2);
  tcase_add_test(tc_core, eq_matrix3);
  tcase_add_test(tc_core, eq_matrix4);

  tcase_add_test(tc_core, sum_matrix0);
  tcase_add_test(tc_core, sum_matrix1);
  tcase_add_test(tc_core, sum_matrix2);
  tcase_add_test(tc_core, sum_matrix3);
  tcase_add_test(tc_core, sum_matrix4);
  tcase_add_test(tc_core, sum_matrix5);
  tcase_add_test(tc_core, sum_matrix6);

  tcase_add_test(tc_core, sub_matrix0);
  tcase_add_test(tc_core, sub_matrix1);
  tcase_add_test(tc_core, sub_matrix2);
  tcase_add_test(tc_core, sub_matrix3);
  tcase_add_test(tc_core, sub_matrix4);
  tcase_add_test(tc_core, sub_matrix5);

  tcase_add_test(tc_core, mult_number0);
  tcase_add_test(tc_core, mult_number1);
  tcase_add_test(tc_core, mult_number2);
  tcase_add_test(tc_core, mult_number3);
  tcase_add_test(tc_core, mult_number4);

  tcase_add_test(tc_core, mult_matrix0);
  tcase_add_test(tc_core, mult_matrix1);
  tcase_add_test(tc_core, mult_matrix2);
  tcase_add_test(tc_core, mult_matrix3);
  tcase_add_test(tc_core, mult_matrix4);
  tcase_add_test(tc_core, mult_matrix5);
  tcase_add_test(tc_core, mult_matrix6);

  tcase_add_test(tc_core, transpose0);
  tcase_add_test(tc_core, transpose1);
  tcase_add_test(tc_core, transpose2);
  tcase_add_test(tc_core, transpose3);
  tcase_add_test(tc_core, transpose4);

  tcase_add_test(tc_core, calc_complements0);
  tcase_add_test(tc_core, calc_complements1);

  tcase_add_test(tc_core, determinant0);
  tcase_add_test(tc_core, determinant1);
  tcase_add_test(tc_core, determinant2);
  tcase_add_test(tc_core, determinant3);
  tcase_add_test(tc_core, determinant4);
  tcase_add_test(tc_core, determinant5);

  tcase_add_test(tc_core, inverse_matrix0);
  tcase_add_test(tc_core, inverse_matrix1);
  tcase_add_test(tc_core, inverse_matrix2);
  tcase_add_test(tc_core, inverse_matrix3);
  tcase_add_test(tc_core, inverse_matrix4);
  tcase_add_test(tc_core, inverse_matrix5);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  SRunner *sr = srunner_create(NULL);
  srunner_add_suite(sr, suite());

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_set_log(sr, "-");
  // CK_SILENT || CK_MINIMAL || CK_NORMAL || CK_VERBOSE
  srunner_run_all(sr, CK_VERBOSE);

  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}