#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ < 0 || cols_ < 0)
    throw std::out_of_range("Incorrect input. Values must be greater than 0");
  this->CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  *this = other;
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
    *this = other;
}

S21Matrix::~S21Matrix() noexcept {
  if (rows_ > 0 && cols_ > 0) {
    std::cout << rows_ << ' ' << cols_;
    for (rows_--; rows_ >= 0; rows_--) delete[] matrix_[rows_];
    delete[] matrix_;
  }
  matrix_ = nullptr;
  cols_ = 0;
  rows_ = 0;
}

int S21Matrix::get_rows() const noexcept { return rows_; }

int S21Matrix::get_cols() const noexcept { return cols_; }

void S21Matrix::set_rows(int row) {
  Resize(row, cols_);
  this->rows_ = row;
}

void S21Matrix::set_cols(int col) {
  Resize(rows_, col);
  this->cols_ = col;
}

void S21Matrix::Resize(int rows, int cols) {
  S21Matrix result(rows, cols);
  for (int i = 0; i < rows; i++) {
    if (i < get_rows())
      for (int j = 0; j < cols; j++) {
        if (j < get_cols())
          result.matrix_[i][j] = matrix_[i][j];
        else {
          result.matrix_[i][j] = 0.0;
        }
      }
    else {
      for (int j = 0; j < cols; j++) {
        result.matrix_[i][j] = 0.0;
      }
    }
  }
  *this = std::move(result);
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  if ((rows_ != other.rows_) || (cols_ != other.cols_)) return false;
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-6) {
        std::cout << '0';
        return false;
      }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  KnowSize(other);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      matrix_[i][j] = other.matrix_[i][j] + matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  KnowSize(other);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = matrix_[i][j] * num;
}

double S21Matrix::Simple_mul(const S21Matrix &other, int current_row,
                             int current_column) {
  double result = 0.0;
  for (int j = 0; j < cols_; j++) {
    result =
        matrix_[current_row][j] * other.matrix_[j][current_column] + result;
  }
  return result;
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_)
    throw std::logic_error("Different size of matrices");
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < other.cols_; j++) {
      result.matrix_[i][j] = Simple_mul(other, i, j);
    }
  this->CopyMatrix(result);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < cols_; i++)
    for (int j = 0; j < rows_; j++)
      result.matrix_[i][j] = matrix_[j][i];
  return result;
}

void S21Matrix::CropMatrix(const S21Matrix &other, int rows_copy,
                           int columns_copy) {
  int subi = 0;
  for (int i = 0; i < rows_; i++) {
    int subj = 0;
    if (i == rows_copy) {
      continue;
    }
    for (int j = 0; j < cols_; j++) {
      if (j == columns_copy) {
        continue;
      }
      other.matrix_[subi][subj] = matrix_[i][j];
      subj++;
    }
    subi++;
  }
}

double S21Matrix::MainDeterminant() {
  double result = 0.0;
  if (rows_ == 1) {
    return matrix_[0][0];
  } else if (rows_ == 2) {
    return result =
               matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
  } else {
    for (int x = 0; x < rows_; ++x) {
      S21Matrix copy(rows_ - 1, cols_ - 1);
      CropMatrix(copy, 0, x);
      result += (x % 2 == 0 ? 1 : -1) * matrix_[0][x] * copy.MainDeterminant();
      copy.DeleteMatrix();
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ <= 0 || cols_ <= 0)
    throw std::out_of_range("Incorrect input. Values must be greater than 0");
  KnowSquare();
  return this->MainDeterminant();
}

S21Matrix S21Matrix::Minor() {
  S21Matrix minor_matrix(rows_, cols_);
  if (rows_ == cols_ && rows_ == 1)
    minor_matrix.matrix_[0][0] = matrix_[0][0];
  else {
    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) {
        S21Matrix copy(rows_ - 1, cols_ - 1);
        CropMatrix(copy, i, j);
        minor_matrix.matrix_[i][j] =
            (((i + j)) % 2 == 0 ? 1 : -1) * copy.MainDeterminant();
        copy.DeleteMatrix();
      }
  }

  return minor_matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  KnowSquare();
  *this = Minor();
  return (*this);
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (fabs(det) < 1e-7)
    throw std::logic_error("Determinant must be greater than 0.0");

  S21Matrix result(rows_, cols_);
  result = Minor();
  result = result.Transpose();
  if (rows_ == cols_ && cols_ == 1)
    result.matrix_[0][0] = 1.0 / det;
  else
    result.MulNumber((double)1.0 / det);

  return result;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other)  // копирование
{
  if (this == &other) return (*this);
  this->CopyMatrix(other);
  return (*this);
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept  // перемещение
{
  if (this != &other) {
      std::swap(rows_, other.rows_);
      std::swap(cols_, other.cols_);
      std::swap(matrix_, other.matrix_);
  }
  return (*this);
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix res{*this};
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix res{*this};
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix res{*this};
  res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(double num) const {
  S21Matrix res{*this};
  res.MulNumber(num);
  return res;
}

S21Matrix operator*(const double num, const S21Matrix &my) {
  S21Matrix res{my};
  res.MulNumber(num);
  return res;
}

bool S21Matrix::operator==(const S21Matrix &other) noexcept {
  bool status = this->EqMatrix(other);
  return status;
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
  this->SumMatrix(other);
  return (*this);
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
  this->SubMatrix(other);
  return (*this);
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
  this->MulMatrix(other);
  return (*this);
}

void S21Matrix::operator*=(double num) {
  this->MulNumber(num);
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  this->CreateMatrix();
  for (int i = 0; i < rows_; i++)
    std::memcpy(matrix_[i], other.matrix_[i], other.cols_ * sizeof(double));
}

void S21Matrix::CreateMatrix() {
  matrix_ = new double *[rows_];
  if (matrix_ == 0) throw "Error allocate memory";

  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    if (matrix_ == 0) {
        this->DeleteMatrix();
        throw "Error allocate memory";
    }
  }
}

void S21Matrix::DeleteMatrix() {
  if (rows_ > 0 && cols_ > 0) {
    for (int i = rows_ - 1; i >= 0; i--) delete[] matrix_[i];
    delete[] matrix_;
  }
  matrix_ = nullptr;
  cols_ = 0;
}

//void S21Matrix::Printmatrix() noexcept {
//  for (int i = 0; i < rows_; i++) {
//    for (int j = 0; j < cols_; j++) {
//      std::cout << matrix_[i][j] << ' ';
//    }
//    std::cout << '\n';
//  }
//}

void S21Matrix::AddMatrix(double x) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = x + i * j;
}

void S21Matrix::KnowSize(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::logic_error("Different size of matrices");
}

void S21Matrix::KnowSquare() {
  if (rows_ != cols_)
    throw std::logic_error("It's not a square matrix");
}
