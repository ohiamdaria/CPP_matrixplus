//
// Created by Gloria Gideon on 11/8/22.
//

#include "S21Matrix.h"

S21Matrix::S21Matrix() {
    matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols)
{
    s21SetRow(rows);
    s21SetCols(cols);
    matrix_ = new double *[rows];
    for (int i = 0; i < rows; i++) {
        matrix_[i] = new double[cols];
    }
}

S21Matrix::S21Matrix(const S21Matrix& other)
{
    s21SetRow(other.rows_);
    s21SetCols(other.cols_);
    matrix_ = new double *[other.rows_];
    for (int i = 0; i < other.rows_; i++) {
        matrix_[i] = new double[other.cols_];
    }
    for (int i = 0; i < other.rows_; i++)
        for (int j = 0; j < other.cols_; j++) {
            matrix_[i][j] = other.matrix_[i][j];
    }

}

void S21Matrix::S21Resize(int rows, int cols)
{
    S21Matrix result (rows, cols);
    for (int i = 0; i < rows; i++) {
        if (i < s21GetRows())
            for (int j = 0; j < cols; j++) {
                if (j < s21GetCols())
                    result.matrix_[i][j] = matrix_[i][j];
                else {
                    result.matrix_[i][j] = 0.0;
                }
            }
        else
            for (int j = 0; j < cols; j++) {
                result.matrix_[i][j] = 0.0;
            }
    }
    (*this) = result;
}

S21Matrix::~S21Matrix()
{
    for (int i = s21GetRows() - 1; i >= 0; i--) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    s21SetRow(0);
    s21SetCols(0);
    matrix_ = nullptr;
}

void S21Matrix::Printmatrix()
{
    for (int i = 0; i < s21GetRows(); i++) {
        for (int j = 0; j < s21GetCols(); j++) {
            std::cout << matrix_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void S21Matrix::MergeMatrix(const S21Matrix &other, int sign)
{
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++) {
            matrix_[i][j] = other.matrix_[i][j] * sign;
        }
}

S21Matrix operator+(S21Matrix &m1, S21Matrix &m2)
{
    S21Matrix res (m1.s21GetRows(), m1.s21GetCols());
    res.MergeMatrix(m1, 1);
    res.SumMatrix(m2);
    return res;
}

S21Matrix operator-(S21Matrix &m1, S21Matrix &m2)
{
    S21Matrix res (m1.s21GetRows(), m1.s21GetCols());
    res.MergeMatrix(m1, 1);
    res.SubMatrix(m2);
    return res;
}

S21Matrix operator*(S21Matrix &m1, S21Matrix &m2)
{
    S21Matrix res (m1.s21GetRows(), m1.s21GetCols());
    res.MergeMatrix(m1, 1);
    res.MulMatrix(m2);
    return res;
}

S21Matrix operator*(S21Matrix &m1, double num)
{
    S21Matrix res (m1.s21GetRows(), m1.s21GetCols());
    res.MergeMatrix(m1, 1);
    res.MulNumber(num);
    return res;
}

bool operator==(S21Matrix &m1, S21Matrix &m2)
{
    bool status = m1.EqMatrix(m2);
    return status;
}

void operator+=(S21Matrix &m1, S21Matrix &m2)
{
    m1.SumMatrix(m2);
}

void operator-=(S21Matrix &m1, S21Matrix &m2)
{
    m1.SubMatrix(m2);
}

void operator*=(S21Matrix &m1, S21Matrix &m2)
{
    m1.MulMatrix(m2);
}

void operator*=(S21Matrix &m1, double num)
{
    m1.MulNumber(num);
}


void S21Matrix::AddMatrix(double x)
{
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++) {
            matrix_[i][j] = x;
        }
}

void S21Matrix::KnowSize(const S21Matrix& other)
{
    if (s21GetRows() != other.rows_ || s21GetCols() != other.cols_)
        throw "Different size of matrices";
}

void S21Matrix::KnowSquare()
{
    if ((s21GetRows() != s21GetCols()) && s21GetRows() > 0)
        throw "Rows and cols aren't identical";
}

void S21Matrix::RightSize() {
    if (s21GetRows() < 0 ||  s21GetCols() < 0)
        throw "Wring size of matrix";
}


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


S21Matrix S21Matrix::InverseMatrix()
{
    KnowSquare();
    double status = Determinant();

    S21Matrix result(s21GetRows(), s21GetCols());
    result = Minor();
    result = result.Transpose();
    result.MulNumber((double) 1 / status);

    return result;
}






