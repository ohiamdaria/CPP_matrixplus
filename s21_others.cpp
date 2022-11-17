//
// Created by Dasha Koroleva on 15.11.2022.
//
#include "S21Matrix.h"

void S21Matrix::CopyMatrix(const S21Matrix &other)
{
    KnowSize(other);
    for (int i = 0; i < rows_; i++)
        std::memcpy(matrix_[i], other.matrix_[i],  other.cols_ * sizeof(double));
}

void S21Matrix::CreateMatrix()
{
    RightSize();
    matrix_ = new double *[rows_];
    if (matrix_ == nullptr)
        throw "Error allocate memory";

    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_];
        if (matrix_ == nullptr)
            throw "Error allocate memory";
    }
}

void S21Matrix::DeleteMatrix()
{
    for (int i = 0; i < rows_; i++) {
        delete[] matrix_[i];
    }
    rows_ = 0;
    cols_ = 0;
}

void S21Matrix::Printmatrix() noexcept
{
    for (int i = 0; i < s21GetRows(); i++) {
        for (int j = 0; j < s21GetCols(); j++) {
            std::cout << matrix_[i][j] << ' ';
            std::cout << &matrix_[i][j] << ' ';
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

void S21Matrix::AddMatrix(double x)
{
    for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++)
            this->matrix_[i][j] = x++;

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
void S21Matrix::RightSize(int row, int col) {
    if (row <= 0 || col <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
}

