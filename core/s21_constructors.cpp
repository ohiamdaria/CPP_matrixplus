#include "../s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

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
    if (rows_ > 0 && cols_ > 0) {
        for (rows_--; rows_ > 0; rows_--) delete[] matrix_[rows_];
        delete[] matrix_;
    }

}
