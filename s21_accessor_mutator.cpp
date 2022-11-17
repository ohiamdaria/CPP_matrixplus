#include "S21Matrix.h"

void S21Matrix::s21SetRows(int row)
{
    RightSize(row, cols_);
    S21Resize(row, cols_);
}

void S21Matrix::s21SetCols(int col)
{
    RightSize(rows_, col);
    S21Resize(rows_, col);
}

void S21Matrix::S21Resize(int rows, int cols)
{
    RightSize();
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