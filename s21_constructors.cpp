//
// Created by Dasha Koroleva on 15.11.2022.
//

#include "S21Matrix.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
    this->rows_ = rows;
    this->cols_ = cols;
    matrix_ = new double *[rows];
    for (int i = 0; i < rows; i++) {
        matrix_[i] = new double[cols];
    }
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

S21Matrix::~S21Matrix()
{
    this->DeleteMatrix();
}
