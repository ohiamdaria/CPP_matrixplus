//
// Created by Gloria Gideon on 11/8/22.
//

#include "S21Matrix.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols)
{
    if (rows_ <= 0 || cols_ <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
    this->rows_ = rows;
    this->cols_ = cols;
    matrix_ = new double *[rows];
    for (int i = 0; i < rows; i++) {
        matrix_[i] = new double[cols];
    }
}

S21Matrix S21Matrix::operator=(S21Matrix &other)
{
    this->CopyMatrix(other);
    return (*this);
}

S21Matrix S21Matrix::operator=(S21Matrix &&other)
{
    this->CopyMatrix(other);
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
    return (*this);
}


S21Matrix::S21Matrix(const S21Matrix& other)
{
    this->CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_)
{
    other.DeleteMatrix();
}

void S21Matrix::CopyMatrix(const S21Matrix &other)
{
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->matrix_ = new double *[other.rows_];
    for (int i = 0; i < other.rows_; i++) {
        this->matrix_[i] = new double[other.cols_];
    }
    for (int i = 0; i < other.rows_; i++)
        for (int j = 0; j < other.cols_; j++) {
            this->matrix_[i][j] = other.matrix_[i][j];
        }
}

void S21Matrix::DeleteMatrix()
{
    for (int i = s21GetRows() - 1; i >= 0; i--) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
}

void S21Matrix::s21SetRows(int row)
{
    if (row <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
    S21Resize(row, cols_);
}

void S21Matrix::s21SetCols(int col)
{
    if (col <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
    S21Resize(rows_, col);
}

void S21Matrix::S21Resize(int rows, int cols)
{
    if (rows_ <= 0 || cols_ <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
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
    rows_ = 0;
    cols_ = 0;
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

S21Matrix S21Matrix::operator+(const S21Matrix &other) const
{
    S21Matrix res {*this};
    res.SumMatrix(other);
    return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const
{
    S21Matrix res {*this};
    res.SubMatrix(other);
    return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const
{
    S21Matrix res {*this};
    res.MulMatrix(other);
    return res;
}

S21Matrix S21Matrix::operator*(double num) const
{
    S21Matrix res {*this};
    res.MulNumber(num);
    return res;
}

bool S21Matrix::operator==(const S21Matrix &other) noexcept
{
    bool status = this->EqMatrix(other);
    return status;
}

void S21Matrix::operator+=(const S21Matrix &other)
{
   this->SumMatrix(other);
}

void S21Matrix::operator-=(const S21Matrix &other)
{
    this->SubMatrix(other);
}

void S21Matrix::operator*=(const S21Matrix &other)
{
    this->MulMatrix(other);
}

void S21Matrix::operator*=(double num)
{
    this->MulNumber(num);
}


void S21Matrix::AddMatrix(double x)
{
    for (int i = 0; i < s21GetRows(); i++)
        for (int j = 0; j < s21GetCols(); j++) {
            matrix_[i][j] = i + j;
        }
}

void S21Matrix::KnowSize(const S21Matrix& other)
{
    if (s21GetRows() != other.rows_ || s21GetCols() != other.cols_)
        throw std::logic_error(
                "Different size of matrices");
}

void S21Matrix::KnowSquare()
{
    if (s21GetRows() != s21GetCols())
        throw std::logic_error(
                "It's not a square matrix");
}

void S21Matrix::RightSize() {
    if (rows_ <= 0 || cols_ <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
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






