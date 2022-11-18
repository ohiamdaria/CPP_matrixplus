#include "s21_matrix_oop.h"

void S21Matrix::s21SetRows(int row)
{
    this->rows_ = row;
    S21Resize(row, cols_);
}

void S21Matrix::s21SetCols(int col)
{
    this->cols_ = col;
    S21Resize(rows_, col);
}

void S21Matrix::S21Resize(int rows, int cols)
{
    RightSize(rows, cols);
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