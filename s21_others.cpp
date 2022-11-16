//
// Created by Dasha Koroleva on 15.11.2022.
//
#include "S21Matrix.h"

void S21Matrix::CopyMatrix(const S21Matrix &other)
{
    this->DeleteMatrix(); // здесь нужно удаление?????? ИЛИ НЕТ
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
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
}



void S21Matrix::Printmatrix() noexcept
{
    for (int i = 0; i < s21GetRows(); i++) {
        for (int j = 0; j < s21GetCols(); j++) {
            std::cout << *this(i, j) << ' ';
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
            matrix_[0][j] = x * j;
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
