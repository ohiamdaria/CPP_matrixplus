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

    const int s21GetRows() { return rows_; }
    const int s21GetCols() { return cols_; }
    void s21SetRows(int row);
    void s21SetCols(int col);

    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other) noexcept;
    ~S21Matrix();

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


//    // Оператор присваивания копированием (copy assignment)
//    RFive& operator=(const RFive& other)
//    {
//        if (this == &other)
//            return *this;
//
//        char* tmp_cstring = new char[std::strlen(other.cstring) + 1];
//        std::strcpy(tmp_cstring, other.cstring);
//        delete[] cstring;
//        cstring = tmp_cstring;
//        return *this;
//    }
//
//    // Оператор присваивания перемещением (move assignment)
//    RFive& operator=(RFive&& other) noexcept
//    {
//        if (this == &other)
//            return *this;
//
//        delete[] cstring;
//        cstring = other.cstring;
//        other.cstring = nullptr;
//        return *this;
//    }


    virtual double operator()(int i, int j)
    {
        return matrix_[i][j];
    };

    void MergeMatrix(const S21Matrix& other, int sign);
    void Printmatrix();

    S21Matrix operator=(S21Matrix &other);
    S21Matrix operator=(S21Matrix &&other);
    S21Matrix operator+(const S21Matrix &other) const;
    S21Matrix operator-(const S21Matrix &other) const;
    S21Matrix operator*(const S21Matrix &other) const;
    S21Matrix operator*(double num) const;
    bool operator==(const S21Matrix &other) noexcept;
    void operator+=(const S21Matrix &other);
    void operator-=(const S21Matrix &other);
    void operator*=(const S21Matrix &other);
    void operator*=(double num);

};

bool operator==(S21Matrix &m1, S21Matrix &m2);
void operator+=(S21Matrix &m1, S21Matrix &m2);
void operator-=(S21Matrix &m1, S21Matrix &m2);
void operator*=(S21Matrix &m1, S21Matrix &m2);
void operator*=(S21Matrix &m1, double num);


#endif //UNTITLED_S21MATRIX_H
