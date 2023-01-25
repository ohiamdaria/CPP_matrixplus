#include "gtest/gtest.h"
#include "../s21_matrix_oop.h"
#define EPS 1e-6

void S21Matrix::InsertValues(int n, ...) {
    va_list arg_list;
    va_start(arg_list, n);
    for (auto i = 0; i < rows_; i++)
        for (auto j = 0; j < cols_; j++)
                this->matrix_[i][j] = va_arg(arg_list, double);
    va_end(arg_list);
}

TEST(ConstructTest, test1) {
    ASSERT_ANY_THROW(S21Matrix a(-150, 10)); }

TEST(ConstructTest, test2) { ASSERT_ANY_THROW(S21Matrix a(1, -105)); }

TEST(ConstructTest, test3) { ASSERT_NO_THROW(S21Matrix a(1, 0)); }

TEST(ConstructTest, test4) { ASSERT_NO_THROW(S21Matrix a(0, 55)); }

class EqSimple : public ::testing::Test {
protected:
    S21Matrix matrixA {3, 3};
    S21Matrix matrixB {3, 3};
};

TEST_F(EqSimple, A_eq_B) {
    matrixA.AddMatrix(2.1231233);
    matrixB.AddMatrix(2.1231233);
    ASSERT_TRUE(matrixA.EqMatrix(matrixB)); }

TEST_F(EqSimple, operator_eq) {
    matrixA.AddMatrix(2.1231233);
    matrixB.AddMatrix(2.1231233);
    ASSERT_TRUE(matrixA == matrixB);
}

TEST_F(EqSimple, B_eq_A) {
    matrixA.AddMatrix(2.1231233);
    matrixB.AddMatrix(2.1231233);
    ASSERT_TRUE(matrixB.EqMatrix(matrixA)); }

TEST_F(EqSimple, B_neq_A) {
    matrixA.AddMatrix(2.123);
    matrixB.AddMatrix(3.123);
    ASSERT_FALSE(matrixB.EqMatrix(matrixA));
}

TEST_F(EqSimple, Rows) {
    ASSERT_TRUE(matrixB.get_rows() == matrixA.get_rows());
}

TEST_F(EqSimple, Cols) {
    ASSERT_TRUE(matrixB.get_cols() == matrixA.get_cols());
}

class EqSimpleDiffSize : public ::testing::Test {
protected:
    S21Matrix matrixA {1, 3};
    S21Matrix matrixB {3, 1};
};

TEST_F(EqSimpleDiffSize, operator_eq2) { ASSERT_FALSE(matrixA == matrixB); }

TEST_F(EqSimpleDiffSize, A_eq_B2) { ASSERT_FALSE(matrixA.EqMatrix(matrixB)); }

TEST_F(EqSimpleDiffSize, B_eq_A2) { ASSERT_FALSE(matrixB.EqMatrix(matrixA)); }

class EqSimpleDiffAdd : public ::testing::Test {
protected:
    S21Matrix matrixA {3, 3};
    S21Matrix matrixB {3, 3};
};

TEST_F(EqSimpleDiffAdd, operator_eq2) {
    matrixA.AddMatrix(4.1238967);
    matrixB.AddMatrix(2.1238967);
    ASSERT_FALSE(matrixA == matrixB); }

TEST_F(EqSimpleDiffAdd, A_eq_B2) {
    matrixA.AddMatrix(5.1238967);
    matrixB.AddMatrix(2.1238967);
    ASSERT_FALSE(matrixA.EqMatrix(matrixB)); }

TEST_F(EqSimpleDiffAdd, B_eq_A2) {
    matrixA.AddMatrix(0.1238967);
    matrixB.AddMatrix(2.1238967);
    ASSERT_FALSE(matrixB.EqMatrix(matrixA)); }

class EqSimpleEmptyMat : public ::testing::Test {
protected:
    S21Matrix matrixA;
    S21Matrix matrixB{0, 0};
};

TEST_F(EqSimpleEmptyMat, operator_eq) { ASSERT_TRUE(matrixA == matrixB); }

TEST_F(EqSimpleEmptyMat, A_eq_B) { ASSERT_TRUE(matrixA.EqMatrix(matrixB)); }

TEST_F(EqSimpleEmptyMat, B_eq_A) { ASSERT_TRUE(matrixB.EqMatrix(matrixA)); }

TEST(TransposeTest, test1) {
    S21Matrix matrixA(0, 0);
    S21Matrix matrixB(0, 0);

    ASSERT_TRUE(matrixA.Transpose().EqMatrix(matrixB));
}

TEST(TransposeTest, test2) {
    S21Matrix matrixA(1, 1);
    S21Matrix matrixB(1, 1);

    matrixA(0, 0) = 10;
    matrixB(0, 0) = 10;

    ASSERT_TRUE(matrixA.Transpose().EqMatrix(matrixB));
}

TEST(TransposeTest, test3) {
    S21Matrix matrixA(1, 3);
    S21Matrix matrixB(3, 1);

    matrixA(0, 0) = 1;
    matrixA(0, 1) = 2;
    matrixA(0, 2) = 3;

    matrixB(0, 0) = 1;
    matrixB(1, 0) = 2;
    matrixB(2, 0) = 3;

    ASSERT_TRUE(matrixA.Transpose().EqMatrix(matrixB));
}

TEST(TransposeTest, test4) {
    S21Matrix matrixA(3, 3);
    S21Matrix matrixB(3, 3);

    matrixA.InsertValues(9, 0.25, 1.25, 2.25, 3.25, 4.25, 5.25, 6.25, 7.25, 8.25);
    matrixB.InsertValues(9, 0.25, 3.25, 6.25, 1.25, 4.25, 7.25, 2.25, 5.25, 8.25);

    ASSERT_TRUE(matrixA.Transpose().EqMatrix(matrixB));
}

class MulNumber : public ::testing::Test {
protected:
    S21Matrix matrixA = S21Matrix(3, 3);
    S21Matrix matrixB = S21Matrix(3, 3);

    virtual void SetUp() {
        matrixA.InsertValues(9, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25);
        matrixB.InsertValues(9, 1., 1., 1., 1., 1., 1., 1., 1., 1.);
    }
};

TEST_F(MulNumber, test1) {
    matrixA.MulNumber(4);
    ASSERT_TRUE(matrixA.EqMatrix(matrixB));
}

TEST_F(MulNumber, test2) {
    matrixA *= 4;
    ASSERT_TRUE(matrixA.EqMatrix(matrixB));
}

TEST_F(MulNumber, test3) {
    matrixA = matrixA * 4;
    ASSERT_TRUE(matrixA.EqMatrix(matrixB));
}

TEST_F(MulNumber, test4) {
    matrixA = 4 * matrixA;
    ASSERT_TRUE(matrixA.EqMatrix(matrixB));
}

class MulMatrix1x1 : public ::testing::Test {
protected:
    S21Matrix matrixA = S21Matrix(1, 1);
    S21Matrix matrixB = S21Matrix(1, 1);
    S21Matrix matrixC = S21Matrix(1, 1);

    void SetUp() override {
        matrixA(0, 0) = 1;
        matrixB(0, 0) = 10;
        matrixC(0, 0) = 10;
    }
};

TEST_F(MulMatrix1x1, test1) {
    ASSERT_TRUE((matrixA * matrixB).EqMatrix(matrixC));
}

TEST_F(MulMatrix1x1, test2) {
    ASSERT_TRUE((matrixA *= matrixB).EqMatrix(matrixC));
}

class ErrorMulMatrix : public ::testing::Test {
protected:
    S21Matrix matrixA = S21Matrix(1, 2);
    S21Matrix matrixB = S21Matrix(1, 1);
};

TEST_F(ErrorMulMatrix, test1) { ASSERT_ANY_THROW(matrixA * matrixB); }

TEST_F(ErrorMulMatrix, test2) { ASSERT_ANY_THROW(matrixA *= matrixB); }

class MulMatrix2x3 : public ::testing::Test {
protected:
    S21Matrix matrixA = S21Matrix(3, 2);
    S21Matrix matrixB = S21Matrix(2, 3);
    S21Matrix matrixC = S21Matrix(3, 3);

    void SetUp() override {
        matrixA.InsertValues(6, 0., 1., 3., 4., 6., 7.);
        matrixB.InsertValues(6, 9., 8., 7., 6., 5., 4.);
        matrixC.InsertValues(9, 6., 5., 4., 51., 44., 37., 96., 83., 70.);
    }
};

TEST_F(MulMatrix2x3, test1) {
    ASSERT_TRUE((matrixA * matrixB).EqMatrix(matrixC));
}

TEST_F(MulMatrix2x3, test2) {
    ASSERT_TRUE((matrixA *= matrixB).EqMatrix(matrixC));
}

class MulMatrix3x3 : public ::testing::Test {
protected:
    S21Matrix matrixA = S21Matrix(3, 3);
    S21Matrix matrixB = S21Matrix(3, 3);
    S21Matrix matrixC = S21Matrix(3, 3);

    void SetUp() override {
        matrixA.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
        matrixB.InsertValues(9, 9., 8., 7., 6., 5., 4., 3., 2., 1.);
        matrixC.InsertValues(9, 30., 24., 18., 84., 69., 54., 138., 114., 90.);
    }
};

TEST_F(MulMatrix3x3, test1) {
    ASSERT_TRUE((matrixA * matrixB).EqMatrix(matrixC));
}

TEST_F(MulMatrix3x3, test2) {
    ASSERT_TRUE((matrixA *= matrixB).EqMatrix(matrixC));
}

TEST(DetTest, test1) {
    S21Matrix matrix(1, 1);
    matrix(0, 0) = 5;

    ASSERT_TRUE(fabs(matrix.Determinant() - 5) < EPS);
}

TEST(DetTest, test2) {
    S21Matrix matrix(3, 3);
    matrix.InsertValues(9, 0.25, 1.25, 2.25, 3.25, 10., 5.25, 6.25, 7.25, 8.25);

    ASSERT_TRUE(fabs(matrix.Determinant() + 69) < EPS);
}

TEST(ErrorDetTest, test1) {
    S21Matrix matrix(0, 0);

    ASSERT_ANY_THROW((void)matrix.Determinant());
}

TEST(ErrorDetTest, test2) {
    S21Matrix matrix(3, 2);

    ASSERT_ANY_THROW((void)matrix.Determinant());
}

TEST(ComplementsTest, test1) {
    S21Matrix matrixA(3, 3);
    S21Matrix matrixB(3, 3);
    matrixA.InsertValues(9, 5., -1., 1., 2., 3., 4., 1., 0., 3.);
    matrixB.InsertValues(9, 9., -2., -3., 3., 14., -1., -7., -18., 17.);

    ASSERT_TRUE(matrixA.CalcComplements().EqMatrix(matrixB));
}

TEST(ComplementsTest, test2) {
    S21Matrix matrixA(1, 1);
    S21Matrix matrixB(1, 1);

    matrixA(0, 0) = 5;
    matrixB(0, 0) = 5;

    ASSERT_TRUE(matrixA.CalcComplements().EqMatrix(matrixB));
}

TEST(ComplementsTest, test3) {
    S21Matrix matrixA(0, 0);
    S21Matrix matrixB(0, 0);

    ASSERT_TRUE(matrixA.CalcComplements().EqMatrix(matrixB));
}

TEST(ErrorComplementsTest, test1) {
    S21Matrix matrix(2, 1);
    ASSERT_ANY_THROW((void)matrix.CalcComplements());
}

class SumMatrix1 : public ::testing::Test {
protected:
    S21Matrix matrixA = S21Matrix(3, 3);
    S21Matrix matrixB = S21Matrix(3, 3);
    S21Matrix matrixC = S21Matrix(3, 3);

    void SetUp() override {
        matrixA.InsertValues(9, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
        matrixB.InsertValues(9, 1., 1., 1., 1., 1., 1., 1., 1., 1.);
        matrixC.InsertValues(9, 1., 1., 1., 1., 1., 1., 1., 1., 1.);
    }
};

TEST_F(SumMatrix1, test1) {
    matrixA += matrixB;
    ASSERT_TRUE(matrixA.EqMatrix(matrixC));
}

TEST_F(SumMatrix1, test2) {
    ASSERT_TRUE((matrixA + matrixB).EqMatrix(matrixC));
}

TEST(SumErrorTest, test1) {
    S21Matrix matrixA = S21Matrix(2, 3);
    S21Matrix matrixB = S21Matrix(3, 3);
    ASSERT_ANY_THROW(matrixA + matrixB);
}

class SubMatrix1 : public ::testing::Test {
protected:
    S21Matrix matrixA = S21Matrix(3, 3);
    S21Matrix matrixB = S21Matrix(3, 3);
    S21Matrix matrixC = S21Matrix(3, 3);

    void SetUp() override {
        matrixA.InsertValues(9, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
        matrixB.InsertValues(9, 1., 1., 1., 1., 1., 1., 1., 1., 1.);
        matrixC.InsertValues(9, -1., -1., -1., -1., -1., -1., -1., -1., -1.);
    }
};

TEST_F(SubMatrix1, test1) {
    matrixA -= matrixB;
    ASSERT_TRUE(matrixA.EqMatrix(matrixC));
}

TEST_F(SubMatrix1, test2) {
    ASSERT_TRUE((matrixA - matrixB).EqMatrix(matrixC));
}

TEST(SubErrorTest, test1) {
    S21Matrix matrixA = S21Matrix(2, 3);
    S21Matrix matrixB = S21Matrix(3, 3);
    ASSERT_ANY_THROW(matrixA - matrixB);
}

TEST(InverseTest, test1) {
    S21Matrix matrixA(1, 1);
    S21Matrix matrixB(1, 1);

    matrixA(0, 0) = 1.25;
    matrixB(0, 0) = 0.8;

    ASSERT_TRUE(matrixA.InverseMatrix().EqMatrix(matrixB));
}

TEST(InverseTest, test2) {
    S21Matrix matrixA(3, 3);
    S21Matrix matrixB(3, 3);
    matrixA.InsertValues(9, 2., 5., 7., 6., 3. ,4., 5., -2., -3.);
    matrixB.InsertValues(9, 1., -1., 1., -38., 41., -34., 27., -29., 24.);

    ASSERT_TRUE(matrixA.InverseMatrix().EqMatrix(matrixB));
}

TEST(ErrorInverseTest, test1) {
    S21Matrix matrixA(1, 3);

    ASSERT_ANY_THROW((void)matrixA.InverseMatrix());
}

TEST(ErrorInverseTest, test2) {
    S21Matrix matrixA(0, 0);
    S21Matrix matrixB(0, 0);

    ASSERT_ANY_THROW((void)matrixA.InverseMatrix());
}

TEST(ErrorInverseTest, test3) {
    S21Matrix matrixA(2, 2);
    matrixA.AddMatrix(0.0);
    ASSERT_ANY_THROW((void)matrixA.InverseMatrix());
}

TEST(ErrorAny, test1) {
    S21Matrix matrix(1, 1);

    ASSERT_ANY_THROW(matrix(0, 1));
}

TEST(ErrorAny, test2) {
    S21Matrix matrix(1, 1);

    ASSERT_ANY_THROW(matrix(-1, -1));
}

TEST(ErrorAny, test3) {
    S21Matrix matrix(1, 1);

    ASSERT_ANY_THROW(matrix(1, 1));
}

TEST(ErrorAny, test4) {
    const S21Matrix matrix(1, 1);

    ASSERT_ANY_THROW(matrix(0, 1));
}

TEST(ErrorAny, test5) {
    const S21Matrix matrix(1, 1);

    ASSERT_ANY_THROW(matrix(-1, -1));
}

TEST(ErrorAny, test6) {
    const S21Matrix matrix(1, 1);

    ASSERT_ANY_THROW(matrix(1, 1));
}

TEST(Any, test1) {
    S21Matrix matrixA(2, 2);
    matrixA.InsertValues(4, 1., 2., 3., 4.);
    S21Matrix matrixB(0, 0);

    S21Matrix matrixC = matrixA;

    matrixB = matrixA;

    ASSERT_TRUE(matrixC.EqMatrix(matrixB));
    matrixB(0, 0) = 11;
    ASSERT_TRUE(matrixA.EqMatrix(matrixC));
}


TEST(EqMatrix, Test_1) {
    S21Matrix a(3, 3), b(3, 3);
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    b.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    EXPECT_TRUE(a == b);
}

TEST(EqMatrix, Test_2) {
    S21Matrix a(3, 3), b(4, 3);
    EXPECT_FALSE(a == b);
}

TEST(EqMatrix, Test_3) {
    S21Matrix a(3, 3), b(3, 3);
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    b.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 1.);
    EXPECT_FALSE(a == b);
}

TEST(SumMatrix, Test_1) {
    S21Matrix a, c;
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    S21Matrix b(a);
    c.InsertValues(9, 1. * 2, 2. * 2, 3. * 2, 4. * 2, 5. * 2, 6. * 2, 7. * 2,
                      8. * 2, 9. * 2);
    a = a + b;
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(SumMatrix, Test_2) {
    S21Matrix a(1, 1), c(1, 1);
    a.InsertValues(1, 1.);
    S21Matrix b(a);
    c.InsertValues(1, 1. * 2);
    a += b;
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(SumMatrix, Test_3) {
    S21Matrix a(3, 3), b(4, 3);
    EXPECT_ANY_THROW({ a.SumMatrix(b); });
}

TEST(SumMatrix, Test_4) {
    S21Matrix a(3, 3), b(3, 4);
    EXPECT_ANY_THROW({ a + b; });
}

TEST(SubMatrix, Test_1) {
    S21Matrix a, c;
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    S21Matrix b = a;
    c.InsertValues(9, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
    a -= b;
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(SubMatrix, Test_2) {
    S21Matrix a(1, 1), c(1, 1);
    a.InsertValues(1, 1.);
    S21Matrix b(a);
    c.InsertValues(1, 0.);
    a = a - b;
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(SubMatrix, Test_3) {
    S21Matrix a(3, 3), b(4, 3);
    EXPECT_ANY_THROW({ a - b; });
}

TEST(SubMatrix, Test_4) {
    S21Matrix a(3, 3), b(3, 4);
    EXPECT_ANY_THROW({ a.SubMatrix(b); });
}

TEST(MulNumber2, Test_1) {
    S21Matrix a{3, 3}, c{3, 3};
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    c.InsertValues(9, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
    a = a * 0.;
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(MulNumber2, Test_2) {
    S21Matrix a(2, 2), c(2, 2);
    a.InsertValues(4, 1., 2., 3., 4.);
    c.InsertValues(4, 1. * 2., 2. * 2., 3. * 2., 4. * 2.);
    a *= 2.;
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(MulNumber2, Test_3) {
    S21Matrix a(2, 2), c(2, 2);
    a.InsertValues(4, 1., 2., 3., 4.);
    EXPECT_NO_THROW({ a * 1.5; });
}

TEST(MulMatrix, Test_1) {
    S21Matrix a(3, 2), b(2, 4), c(3, 4);
    a.InsertValues(6, 1., 2., 3., 4., 5., 6.);
    b.InsertValues(8, 1., 2., 3., 4., 5., 6., 7., 8.);
    c.InsertValues(12, 11., 14., 17., 20., 23., 30., 37., 44., 35., 46., 57.,
                      68.);
    a *= b;
    std::cout << std::endl;
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(MulMatrix, Test_2) {
    S21Matrix a(2, 2), b(2, 2), c(2, 2);
    a.InsertValues(4, 1., 2., 3., 4.);
    b.InsertValues(4, 5., 6., 7., 8.);
    c.InsertValues(4, 19., 22., 43., 50.);
    a = a * b;
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(MulMatrix, Test_3) {
    S21Matrix a(3, 3), b(4, 3);
    EXPECT_ANY_THROW({ a *b; });
}

TEST(Transpose, Test_1) {
    S21Matrix a(3, 2), c(2, 3);
    a.InsertValues(6, 1., 2., 3., 4., 5., 6.);
    c.InsertValues(6, 1., 3., 5., 2., 4., 6.);
    a = a.Transpose();
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(CalcComplements, Test_1) {
    S21Matrix a(4, 4), c(4, 4);
    a.InsertValues(16, 1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 1., 1., 13.,
                      14., 1., 1.);
    c.InsertValues(16, -4., 4., -28., 24., 4., -4., 12., -8., -52., 48., 60.,
                      -56., 36., -32., -44., 40.);
    a = a.CalcComplements();
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(CalcComplements, Test_2) {
    S21Matrix a(1, 1), c(1, 1);
    c.InsertValues(1, 1.);
    a = c.CalcComplements();
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(CalcComplements, Test_3) {
    S21Matrix a(3, 4);
    EXPECT_ANY_THROW({ a.CalcComplements(); });
}

TEST(Determinant, Test_1) {
    S21Matrix a(1, 1);
    a.InsertValues(1, 1.);
    double determinant = a.Determinant();
    EXPECT_DOUBLE_EQ(determinant, 1.);
}

TEST(Determinant, Test_2) {
    S21Matrix a(3, 4);
    EXPECT_ANY_THROW({ a.Determinant(); });
}

TEST(InverseMatrix, Test_1) {
    S21Matrix a{3, 3}, c{3, 3};
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 1.);
    c.InsertValues(9, (-43. / 24.), (11. / 12.), (-1. / 8.), (19. / 12.),
                      (-5. / 6.), (1. / 4.), (-1. / 8.), (1. / 4.), (-1. / 8.));
    a = a.InverseMatrix();
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(InverseMatrix, Test_2) {
    S21Matrix a{3, 3};
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    EXPECT_ANY_THROW({ a.InverseMatrix(); });
}

TEST(InverseMatrix, Test_3) {
    S21Matrix a(1, 1);
    S21Matrix c(1, 1);
    a.InsertValues(1, 1.);
    c.InsertValues(1, 1.);
    a = a.InverseMatrix();
    EXPECT_TRUE(a.EqMatrix(c));
}

TEST(Index, Test_1) {
    S21Matrix a{3, 3};
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    EXPECT_DOUBLE_EQ(a(0, 0), 1.);
    EXPECT_ANY_THROW({ a(3, 2); });
    EXPECT_ANY_THROW({ a(2, 3); });
}

TEST(Index2, Test_1) {
    S21Matrix a{3, 3};
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    EXPECT_DOUBLE_EQ(a(0, 0), 1.);
    EXPECT_ANY_THROW({ a(3, 2); });
    EXPECT_ANY_THROW({ a(2, 3); });
}


TEST(GetRows, Test_1) {
    S21Matrix a(2, 2);
    EXPECT_EQ(a.get_rows(), 2);
}

TEST(GetCols, Test_1) {
    S21Matrix a(2, 2);
    EXPECT_EQ(a.get_cols(), 2);
}



TEST(SetCols, Test_1) {
    S21Matrix a(3, 1), c(3, 2), d(3, 3);
    a.AddMatrix(9.876654);
    c.AddMatrix(9.876654);
    a.set_cols(2);
    EXPECT_FALSE(a == c);
    EXPECT_EQ(a.get_cols(), 2);
    a.set_cols(3);
    a.AddMatrix(111.4567);
    d.AddMatrix(111.4567);
    EXPECT_TRUE(a == d);
    EXPECT_EQ(a.get_cols(), 3);
}

TEST(SetRows, Test_1) {
    S21Matrix a(3, 3), c(2, 3), d(3, 3);
    a.InsertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
    c.InsertValues(9, 1., 2., 3., 4., 5., 6.);
    a.set_rows(2);
    EXPECT_TRUE(a == c);
    EXPECT_EQ(a.get_rows(), 2);

    a.set_rows(3);
    d.InsertValues(9, 1., 2., 3., 4., 5., 6., 0., 0., 0.);
    EXPECT_TRUE(a == d);
    EXPECT_EQ(a.get_rows(), 3);
}

TEST(ConstructorMove, Test_1) {
    S21Matrix a{2, 4};
    a.InsertValues(8, 1., 2., 3., 4., 5., 6., 7., 8.);
    S21Matrix c = a;
    std::cout << c.get_cols();
    S21Matrix b = (S21Matrix &&)a;
////    EXPECT_EQ(a.get_cols(), 0);
//    EXPECT_TRUE(b.EqMatrix(c));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}