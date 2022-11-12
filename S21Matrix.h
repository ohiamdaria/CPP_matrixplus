//
// Created by Gloria Gideon on 11/8/22.
//

#ifndef UNTITLED_S21MATRIX_H
#define UNTITLED_S21MATRIX_H

#include <iostream>
#include <cmath>

class S21Matrix {

private:
    int rows_ = 0, cols_ = 0;
    double **matrix_ = nullptr;

public:

    const int s21GetRows() { return rows_; }
    const int s21GetCols() { return cols_; }
    void s21SetRow(int row) { rows_ = row; }
    void s21SetCols(int col) { cols_ = col; }

    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();
    S21Matrix S21Resize(int rows, int cols);

    void AddMatrix(double x);

    bool EqMatrix(const S21Matrix& other);

    void SumMatrix(const S21Matrix& other);

    void SubMatrix(const S21Matrix& other);

    void MulNumber(const double num);

    void MulMatrix(const S21Matrix& other);

    S21Matrix Transpose();

    void Submatrix(const S21Matrix& other, int rows_copy, int columns_copy);

    S21Matrix CalcComplements();

    double Determinant();

    S21Matrix InverseMatrix();

    S21Matrix Minor();

    void KnowSize(const S21Matrix& other);
    void KnowSquare();
    void RightSize();

    virtual void operator=(S21Matrix m1)
    {
        for (int i = 0; i < s21GetCols(); i++)
            for (int j = 0; j < s21GetRows(); j++) {
                matrix_[i][j] = m1.matrix_[i][j];
            }
    }

    virtual double operator()(int i, int j)
    {
        return matrix_[i][j];
    }

    void MergeMatrix(const S21Matrix& other, int sign);
    void Printmatrix();

//    friend S21Matrix operator+(S21Matrix &m1, S21Matrix &m2);
//    S21Matrix operator-(S21Matrix &m1, S21Matrix &m2);
//    S21Matrix operator*(S21Matrix &m1, S21Matrix &m2);
//    S21Matrix operator*(S21Matrix &m1, double num);
//    bool operator==(S21Matrix &m1, S21Matrix &m2);
//    void operator+=(S21Matrix &m1, S21Matrix &m2);
//    void operator-=(S21Matrix &m1, S21Matrix &m2);
//    void operator*=(S21Matrix &m1, S21Matrix &m2);
//    void operator*=(S21Matrix &m1, double num);

};

S21Matrix operator+(S21Matrix &m1, S21Matrix &m2);
S21Matrix operator-(S21Matrix &m1, S21Matrix &m2);
S21Matrix operator*(S21Matrix &m1, S21Matrix &m2);
S21Matrix operator*(S21Matrix &m1, double num);
bool operator==(S21Matrix &m1, S21Matrix &m2);
void operator+=(S21Matrix &m1, S21Matrix &m2);
void operator-=(S21Matrix &m1, S21Matrix &m2);
void operator*=(S21Matrix &m1, S21Matrix &m2);
void operator*=(S21Matrix &m1, double num);


#endif //UNTITLED_S21MATRIX_H
