#include "s21_matrix_oop.h"

S21Matrix &S21Matrix::operator=(const S21Matrix &other) // копирование
{
    if (this == &other)
        return (*this);

    this->CopyMatrix(other);
    return (*this);
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept // перемещение
{
    if (this == &other)
        return (*this);
    this->CopyMatrix(other);
    other.DeleteMatrix();
    return (*this);

}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const
{
    S21Matrix res {*this};
    res.SumMatrix(other);
    return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const
{
    S21Matrix res {*this};
    res.SubMatrix(other);
    return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const
{
    S21Matrix res {*this};
    res.MulMatrix(other);
    return res;
}

S21Matrix S21Matrix::operator*(double num) const
{
    S21Matrix res {*this};
    res.MulNumber(num);
    return res;
}

S21Matrix operator*(const double num, const S21Matrix &my) // как вызвать конструктор копирования и конструктор перемещения???
{
    S21Matrix res {my};
    res.MulNumber(num);
    return res;
}

bool S21Matrix::operator==(const S21Matrix &other) noexcept
{
    bool status = this->EqMatrix(other);
    return status;
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other)
{
    this->SumMatrix(other);
    return (*this);
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other)
{
    this->SubMatrix(other);
    return (*this);
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other)
{
    this->MulMatrix(other);
    return (*this);
}

S21Matrix S21Matrix::operator*=(double num)
{
    this->MulNumber(num);
    return (*this);
}