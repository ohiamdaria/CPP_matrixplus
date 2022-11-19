//
// Created by stf20 on 26.10.2022.
//

#ifndef CPP1_S21_MATRIXPLUS_S21_MATRIX_H
#define CPP1_S21_MATRIXPLUS_S21_MATRIX_H

#include <iostream>
#include <cmath>
#include <stdexcept>

#define EPS (1e-6)


class S21Matrix {

private:
    int rows_, cols_;
    double **matrix_;

public:

     int s21GetRows() { return rows_; }
     int s21GetCols() { return cols_; }
    void s21SetRows(int row);
    void s21SetCols(int col);

    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other) noexcept;
    ~S21Matrix();

    void CreateMatrix();

    void S21Resize(int rows, int cols);

    void AddMatrix(double x);

    void CopyMatrix(const S21Matrix &other);

    void DeleteMatrix();

    bool EqMatrix(const S21Matrix& other);

    void SumMatrix(const S21Matrix& other);

    void SubMatrix(const S21Matrix& other);

    void Submatrix(const S21Matrix& other, int rows_copy, int columns_copy);

    void MulMatrix(const S21Matrix& other);

    void MulNumber(const double num);

    S21Matrix Transpose();

    S21Matrix CalcComplements();

    double Determinant();

    S21Matrix InverseMatrix();

    S21Matrix Minor();

    void KnowSize(const S21Matrix& other);
    void KnowSquare();
    void RightSize();
    void RightSize(int row, int col);

    double &operator()(int i, int j)
    {
        return matrix_[i][j];
    };

    void MergeMatrix(const S21Matrix& other, int sign);
    void Printmatrix() noexcept;

    S21Matrix &operator=(S21Matrix &&other) noexcept; // оператор присваивания перемещением
    S21Matrix &operator=(const S21Matrix &other); // оператор присваивания копированием

    S21Matrix operator+(const S21Matrix &other) const;
    S21Matrix operator-(const S21Matrix &other) const;
    S21Matrix operator*(const S21Matrix &other) const;
    S21Matrix operator*(const double num) const;
    bool operator==(const S21Matrix &other) noexcept;
    S21Matrix operator+=(const S21Matrix &other);
    S21Matrix operator-=(const S21Matrix &other);
    S21Matrix operator*=(const S21Matrix &other);
    S21Matrix operator*=(double num);

};



S21Matrix operator*(const double num, const S21Matrix &my);


#endif  // CPP1_S21_MATRIXPLUS_S21_MATRIX_H
