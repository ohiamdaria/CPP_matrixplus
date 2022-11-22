#include "s21_matrix_oop.h"

void S21Matrix::s21SetRows(int row)
{
    S21Resize(row, cols_);
    this->rows_ = row;
}

void S21Matrix::s21SetCols(int col)
{
    S21Resize(rows_, col);
    this->cols_ = col;
}

void S21Matrix::S21Resize(int rows, int cols)
{
    S21Matrix result (rows, cols);
    for (int i = 0; i < rows; i++) {
        if (i < s21GetRows())
            for (int j = 0; j < cols; j++) {
                if (j < s21GetCols())
                    result.matrix_[i][j] = this->matrix_[i][j];
                else {
                    result.matrix_[i][j] = 0.0;
                }
            }
        else
        {
            for (int j = 0; j < cols; j++) {
                result.matrix_[i][j] = 0.0;
            }
        }
    }
    (*this) = result;
}
