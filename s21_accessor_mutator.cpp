//
// Created by Dasha Koroleva on 15.11.2022.
//
#include "S21Matrix.h"

void S21Matrix::s21SetRows(int row)
{
    if (row <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
    S21Resize(row, cols_);
}

void S21Matrix::s21SetCols(int col)
{
    if (col <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
    S21Resize(rows_, col);
}

void S21Matrix::S21Resize(int rows, int cols)
{
    if (rows_ <= 0 || cols_ <= 0)
        throw std::out_of_range(
                "Incorrect input. Values must be greater than 0");
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