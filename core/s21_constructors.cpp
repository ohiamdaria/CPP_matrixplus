#include "../s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(1), cols_(1), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols): rows_(rows), cols_(cols)
{
    RightSize();
    this->CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other): rows_(other.rows_), cols_(other.cols_)
{
    this->CreateMatrix();
    this->CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
        : rows_(other.rows_), cols_(other.cols_)
{
    RightSize();
    *this = std::move(other);
}

S21Matrix::~S21Matrix()
{
    this->DeleteMatrix();
}
