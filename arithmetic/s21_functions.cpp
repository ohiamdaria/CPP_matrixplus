//
// Created by Dasha Koroleva on 15.11.2022.
//
#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other)
{
    KnowSize(other);
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++)
            if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7)
                return false;
    return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other)
{
    KnowSize(other);
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++)
            matrix_[i][j] = other.matrix_[i][j] + matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix& other)
{
    KnowSize(other);
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++)
            matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num)
{
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++)
            matrix_[i][j] = matrix_[i][j] * num;
}

void S21Matrix::MulMatrix(const S21Matrix& other)
{
    KnowSize(other);
    for (int i = 0; i < s21GetCols(); i++)
        for (int j = 0; j < s21GetRows(); j++) {
            matrix_[i][j] = matrix_[i][j] * other.matrix_[i][j];
        }
}

S21Matrix S21Matrix::Transpose()
{
    KnowSquare();
    S21Matrix result( s21GetRows(), s21GetCols());
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++)
            result.matrix_[i][j] = matrix_[j][i];
    return result;
}

void S21Matrix::Submatrix(const S21Matrix& other, int rows_copy, int columns_copy) {
    int subi = 0;
    for (int i = 0; i < s21GetRows(); i++) {
        int subj = 0;
        if (i == rows_copy) {
            continue;
        }
        for (int j = 0; j < s21GetCols(); j++) {
            if (j == columns_copy) {
                continue;
            }
            other.matrix_[subi][subj] = matrix_[i][j];
            subj++;
        }
        subi++;
    }
}


double S21Matrix::Determinant()
{
    KnowSquare();
    double result = 0.0;
    if (s21GetRows() == 1) {
        return matrix_[0][0];
    } else if (s21GetRows() == 2) {
        return result = matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
    } else {
        for (int x = 0; x < s21GetRows(); ++x) {
            S21Matrix copy(s21GetRows() - 1, s21GetCols() - 1);
            Submatrix(copy, 0, x);
            result += (x % 2 == 0 ? 1 : -1) * matrix_[0][x] * copy.Determinant();
        }
    }
    return result;
}

S21Matrix S21Matrix::Minor() {
    S21Matrix minor_matrix(s21GetRows(), s21GetCols());
    for (int i = 0; i < s21GetRows(); ++i)
        for (int j = 0; j < s21GetCols(); ++j) {
            S21Matrix copy(s21GetRows() - 1, s21GetCols() - 1);
            Submatrix(copy, i, j);
            minor_matrix.matrix_[i][j] = (((i + j)) % 2 == 0 ? 1 : -1) * copy.Determinant();
        }
    return minor_matrix;
}


S21Matrix S21Matrix::CalcComplements()
{
    KnowSquare();
    S21Matrix result( s21GetRows(), s21GetCols());
    for (int i = 0; i < s21GetRows(); ++i)
        for (int j = 0; j < s21GetCols(); ++j) {
            S21Matrix copy( s21GetRows() - 1, s21GetCols() - 1);
            Submatrix(copy, i, j);
            result.matrix_[i][j] = (((i + j)) % 2 == 0 ? 1 : -1) *
                                   copy.Determinant();
        }
    return result;
}


S21Matrix S21Matrix::InverseMatrix() // проверочки надо вставить
{
    KnowSquare();
    double status = Determinant();

    S21Matrix result(s21GetRows(), s21GetCols());
    result = Minor();
    result = result.Transpose();
    result.MulNumber((double) 1 / status);

    return result;
}