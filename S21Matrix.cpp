//
// Created by Gloria Gideon on 11/8/22.
//

#include "S21Matrix.h"

S21Matrix::S21Matrix() {
    matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {
    s21SetRow(rows);
    s21SetCols(cols);
    matrix_ = new double *[rows];
    for (int i = 0; i < rows; i++) {
        matrix_[i] = new double[cols];
    }
}

void S21Matrix::Printmatrix(const S21Matrix)
{
    for (int i = 0; i < s21GetCols(); i++) {
        for (int j = 0; j < s21GetRows(); j++) {
            std::cout << matrix_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void S21Matrix::AddMatrix(const S21Matrix, double x) {
    for (int i = 0; i < s21GetCols(); i++)
        for (int j = 0; j < s21GetRows(); j++) {
            matrix_[i][j] = x;
        }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
    bool status = true;
    for (int i = 0; i < s21GetCols(); i++)
        for (int j = 0; j < s21GetRows(); j++)
            if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
                status = false;
                break;
            }
    return status;
}

void S21Matrix::SumMatrix(const S21Matrix& other)
{
    for (int i = 0; i < s21GetCols(); i++)
        for (int j = 0; j < s21GetRows(); j++) {
            matrix_[i][j] = other.matrix_[i][j] + matrix_[i][j];
        }
}

void S21Matrix::SubMatrix(const S21Matrix& other)
{
    for (int i = 0; i < s21GetCols(); i++)
        for (int j = 0; j < s21GetRows(); j++) {
            matrix_[i][j] = other.matrix_[i][j] - matrix_[i][j];
        }
}

void S21Matrix::MulNumber(const double num)
{
    for (int i = 0; i < s21GetCols(); i++)
        for (int j = 0; j < s21GetRows(); j++) {
            matrix_[i][j] = matrix_[i][j] * num;
        }
}

void S21Matrix::MulMatrix(const S21Matrix& other)
{
    for (int i = 0; i < s21GetCols(); i++)
        for (int j = 0; j < s21GetRows(); j++) {
            matrix_[i][j] = matrix_[i][j] * other.matrix_[i][j];
        }
}

S21Matrix S21Matrix::Transpose()
{
    S21Matrix result( s21GetRows(), s21GetCols());
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++)
            result.matrix_[i][j] = matrix_[j][i];
    return result;
}

S21Matrix S21Matrix::CalcComplements()
{

    for (int i = 0; i < s21GetRows(); ++i)
        for (int j = 0; j < s21GetCols(); ++j) {
            S21Matrix copy(s21GetRows() - 1, s21GetCols() - 1);
            submatrix(A, &copy, i, j);
            minor_matrix->matrix[i][j] = ((((i + j)) % 2 == 0 ? 1 : -1) *
                                          counter_determinant(&copy, copy.rows));
            s21_remove_matrix(&copy);
            }
}

