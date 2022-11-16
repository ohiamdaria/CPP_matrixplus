//
// Created by Dasha Koroleva on 15.11.2022.
//

#include "S21Matrix.h"

S21Matrix::S21Matrix() : rows_(1), cols_(1), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols): rows_(rows), cols_(cols)
{
    if (rows <= 0 || cols <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
    matrix_ = new double *[rows * cols]();
}

S21Matrix::S21Matrix(const S21Matrix& other): rows_(other.rows_), cols_(other.cols_)
{
    matrix_ = new double *[other.rows_ * other.cols_]();
    std::memcpy(matrix_, other.matrix_,  other.rows_ * other.cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
        : rows_(other.rows_), cols_(other.cols_)
{
    delete [] matrix_;
    matrix_ = new double *[other.rows_ * other.cols_]();
    std::memcpy(matrix_, other.matrix_,  other.rows_ * other.cols_ * sizeof(double));
    delete [] other.matrix_;
}

S21Matrix::~S21Matrix()
{
    this->DeleteMatrix();
}
