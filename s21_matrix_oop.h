#ifndef CPP1_S21_MATRIXPLUS_S21_MATRIX_H
#define CPP1_S21_MATRIXPLUS_S21_MATRIX_H

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

  double Simple_mul(const S21Matrix &other, int current_row,
                  int current_column);


 public:
  int get_rows() const noexcept;
  int get_cols() const noexcept;
  void set_rows(int row);
  void set_cols(int col);

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other) noexcept;
  ~S21Matrix() noexcept;

  void CreateMatrix();

  void Resize(int rows, int cols);

  void AddMatrix(double x);

  void CopyMatrix(const S21Matrix &other);

  void DeleteMatrix();

  bool EqMatrix(const S21Matrix &other);

  void SumMatrix(const S21Matrix &other);

  void SubMatrix(const S21Matrix &other);

  void CropMatrix(const S21Matrix &other, int rows_copy, int columns_copy);

  void MulMatrix(const S21Matrix &other);

  void MulNumber(const double num);

  S21Matrix Transpose();

  S21Matrix CalcComplements();

  double Determinant();

  S21Matrix InverseMatrix();

  S21Matrix Minor();
  double MainDeterminant();

  void KnowSize(const S21Matrix &other);
  void KnowSquare();

  void InsertValues(int n, ...);

  double &operator()(int i, int j) {
    if (i >= rows_ || j >= cols_ || i < 0 || j < 0)
      throw std::logic_error("Out of matrix range");
    return matrix_[i][j];
  };

  const double &operator()(const int i, const int j) const {
    if (i >= rows_ || j >= cols_ || i < 0 || j < 0)
      throw std::logic_error("Out of matrix range");
    return matrix_[i][j];
  };

  S21Matrix &operator=(
      S21Matrix &&other) noexcept;  // оператор присваивания перемещением
  S21Matrix &operator=(
      const S21Matrix &other);  // оператор присваивания копированием

  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double num) const;
  friend S21Matrix operator*(const double num, const S21Matrix &my);
  bool operator==(const S21Matrix &other) noexcept;
  S21Matrix operator+=(const S21Matrix &other);
  S21Matrix operator-=(const S21Matrix &other);
  S21Matrix operator*=(const S21Matrix &other);
  void operator*=(double num);
};



#endif  // CPP1_S21_MATRIXPLUS_S21_MATRIX_H
