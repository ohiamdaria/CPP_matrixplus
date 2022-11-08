//
// Created by Gloria Gideon on 11/8/22.
//

#ifndef UNTITLED_S21MATRIX_H
#define UNTITLED_S21MATRIX_H

#include <iostream>
#include <cmath>

class S21Matrix {

private:
    int rows_, cols_;
    double **matrix_;

public:

    int s21GetRows() { return rows_; }
    int s21GetCols() { return cols_; }
    void s21SetRow(int row) { rows_ = row; }
    void s21SetCols(int col) { cols_ = col; }

    S21Matrix();

    S21Matrix(int rows, int cols);

    void AddMatrix(const S21Matrix, double x);

    bool EqMatrix(const S21Matrix& other);

    void SumMatrix(const S21Matrix& other);

    void SubMatrix(const S21Matrix& other);

    void MulNumber(const double num);

    void MulMatrix(const S21Matrix& other);

    S21Matrix Transpose();

    S21Matrix CalcComplements();




    virtual void operator+(S21Matrix &m1)
    {
        for (int i = 0; i < s21GetCols(); i++)
            for (int j = 0; j < s21GetRows(); j++) {
               matrix_[i][j] = m1.matrix_[i][j] + matrix_[i][j];
            }
    }

//    friend S21Matrix operator-(S21Matrix &m1)
//    {
//        S21Matrix result {m1.s21GetRows(), m1.s21GetRows()};
//        for (int i = 0; i < m1.s21GetCols(); i++)
//            for (int j = 0; j < m1.s21GetRows(); j++) {
//                result.matrix_[i][j] = m1.matrix_[i][j] - m2.matrix_[i][j];
//            }
//        return result;
//    }

    friend S21Matrix operator*(S21Matrix &m1, S21Matrix &m2)
    {
        S21Matrix result {m1.s21GetRows(), m1.s21GetRows()};
        for (int i = 0; i < m1.s21GetCols(); i++)
            for (int j = 0; j < m1.s21GetRows(); j++) {
                result.matrix_[i][j] = m1.matrix_[i][j] * m2.matrix_[i][j];
            }
        return result;
    }

    friend S21Matrix operator*(S21Matrix &m1, double num)
    {
        S21Matrix result {m1.s21GetRows(), m1.s21GetRows()};
        for (int i = 0; i < m1.s21GetCols(); i++)
            for (int j = 0; j < m1.s21GetRows(); j++) {
                result.matrix_[i][j] = m1.matrix_[i][j] * num;
            }
        return result;
    }

    friend bool operator==(S21Matrix &m1, S21Matrix &m2)
    {
        bool status = true;
        for (int i = 0; i < m1.s21GetCols(); i++)
            for (int j = 0; j < m1.s21GetRows(); j++)
                if (fabs(m1.matrix_[i][j] - m2.matrix_[i][j]) > 1e-7) {
                    status = false;
                    break;
                }
        return status;
    }

    virtual void operator=( S21Matrix &m1)
    {
        for (int i = 0; i < s21GetCols(); i++)
            for (int j = 0; j < s21GetRows(); j++) {
                matrix_[i][j] = m1.matrix_[i][j];
            }
    }

//    virtual void operator+=( S21Matrix &m1, Sum)
//    {
//        for (int i = 0; i < s21GetCols(); i++)
//            for (int j = 0; j < s21GetRows(); j++) {
//                matrix_[i][j] = m1.matrix_[i][j];
//            }
//    }


    void Printmatrix(const S21Matrix);

};

#endif //UNTITLED_S21MATRIX_H
