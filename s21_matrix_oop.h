#ifndef CPP1_S21_MATRIXPLUS_S21_MATRIX_H
#define CPP1_S21_MATRIXPLUS_S21_MATRIX_H

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstring>

#define EPS (1e-6)


class S21Matrix {

private:
    int rows_, cols_;
    double **matrix_;

public:

     int s21GetRows() const noexcept;
     int s21GetCols() const noexcept;
    void s21SetRows(int row);
    void s21SetCols(int col);

    S21Matrix();
    S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other) noexcept;
    ~S21Matrix() noexcept;

    void CreateMatrix();

    void S21Resize(int rows, int cols);

    void AddMatrix(double x);

    void CopyMatrix(const S21Matrix &other);

    void DeleteMatrix();

    bool EqMatrix(const S21Matrix& other);

    void SumMatrix(const S21Matrix& other);

    void SubMatrix(const S21Matrix& other);

    void CropMatrix(const S21Matrix& other, int rows_copy, int columns_copy);

    void MulMatrix(const S21Matrix& other);

    void MulNumber(const double num);

    S21Matrix Transpose();

    S21Matrix CalcComplements();

    double Determinant();

    S21Matrix InverseMatrix();

    S21Matrix Minor();
    double MainDeterminant();

    void KnowSize(const S21Matrix& other);
    void KnowSquare();

    void S21insertValues(int n, ...);
    double Simple_mul(const S21Matrix& other,
                                  int current_row,  int current_column);
    double &operator()(int i, int j)
    {
        if (i >= rows_ || j >= cols_ || i < 0 || j < 0)
            throw std::logic_error(
                    "Out of matrix range");
        return matrix_[i][j];
    };

    const double &operator()(const int i, const int j) const
    {
        if (i >= rows_ || j >= cols_ || i < 0 || j < 0)
            throw std::logic_error(
                    "Out of matrix range");
        return matrix_[i][j];
    };

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
