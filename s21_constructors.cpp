#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols): rows_(rows), cols_(cols)
{
    RightSize();
    this->CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
{
    this->CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
{
    this->CopyMatrix(other);
    other.DeleteMatrix();
}

S21Matrix::~S21Matrix()
{
    if (rows_ > 0 && cols_ > 0) {
        for (rows_--; rows_ > 0; rows_--) delete[] matrix_[rows_];
        delete[] matrix_;
        cols_ = 0;
    }
}