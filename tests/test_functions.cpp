#include "gtest/gtest.h"
#include "../s21_matrix_oop.h"

void S21Matrix::S21insertValues(int n, ...) {
    va_list arg_list;
    va_start(arg_list, n);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (i * cols_ + j < n) {
                this->matrix_[i][j] = va_arg(arg_list, double);
            } else {
                this->matrix_[i][j] = 0;
            }
        }
    }
    va_end(arg_list);
}

//TEST(ConstructTest, test1) {
//    ASSERT_ANY_THROW(S21Matrix a(-100, 10)); }
//
//TEST(ConstructTest, test2) { ASSERT_ANY_THROW(S21Matrix a(100, -100)); }
//
//TEST(ConstructTest, test3) { ASSERT_NO_THROW(S21Matrix a(1, 0)); }
//
//TEST(ConstructTest, test4) { ASSERT_NO_THROW(S21Matrix a(0, 100)); }
//
////TEST(ConstructTest, test5) {
////    S21Matrix m {3, 3};
////    ASSERT_NO_THROW(S21Matrix n = std::move(m));// constr move
////}
//
//class EqSimple : public ::testing::Test {
//protected:
//    S21Matrix matrixA {3, 3};
//    S21Matrix matrixB {3, 3};
//};
//
//TEST_F(EqSimple, A_eq_B) {
//    matrixA.AddMatrix(2.1231233);
//    matrixB.AddMatrix(2.1231233);
//    ASSERT_TRUE(matrixA.EqMatrix(matrixB)); }
//
//TEST_F(EqSimple, operator_eq) {
//    matrixA.AddMatrix(2.1231233);
//    matrixB.AddMatrix(2.1231233);
//    ASSERT_TRUE(matrixA == matrixB);
//}
//
//TEST_F(EqSimple, B_eq_A) {
//    matrixA.AddMatrix(2.1231233);
//    matrixB.AddMatrix(2.1231233);
//    matrixA.Printmatrix();
//    matrixB.Printmatrix();
//    ASSERT_TRUE(matrixB.EqMatrix(matrixA)); }
//
//TEST_F(EqSimple, B_neq_A) {
//    matrixA.AddMatrix(2.123);
//    matrixB.AddMatrix(3.123);
//    ASSERT_FALSE(matrixB.EqMatrix(matrixA));
//}
//
//TEST_F(EqSimple, Rows) {
//    ASSERT_TRUE(matrixB.s21GetRows() == matrixA.s21GetRows());
//}
//
//TEST_F(EqSimple, Cols) {
//    ASSERT_TRUE(matrixB.s21GetCols() == matrixA.s21GetCols());
//}
//
//class EqSimple2 : public ::testing::Test {
//protected:
//    S21Matrix matrixA {1, 3};
//    S21Matrix matrixB {3, 1};
//};
//
//TEST_F(EqSimple2, operator_eq2) { ASSERT_FALSE(matrixA == matrixB); }
//
//TEST_F(EqSimple2, A_eq_B2) { ASSERT_FALSE(matrixA.EqMatrix(matrixB)); }
//
//TEST_F(EqSimple2, B_eq_A2) { ASSERT_FALSE(matrixB.EqMatrix(matrixA)); }
//
//class EqSimple3 : public ::testing::Test {
//protected:
//    S21Matrix matrixA {3, 3};
//    S21Matrix matrixB {3, 3};
//};
//
//TEST_F(EqSimple3, operator_eq2) {
//    matrixA.AddMatrix(4.1238967);
//    matrixB.AddMatrix(2.1238967);
//    ASSERT_FALSE(matrixA == matrixB); }
//
//TEST_F(EqSimple3, A_eq_B2) {
//    matrixA.AddMatrix(5.1238967);
//    matrixB.AddMatrix(2.1238967);
//    ASSERT_FALSE(matrixA.EqMatrix(matrixB)); }
//
//TEST_F(EqSimple3, B_eq_A2) {
//    matrixA.AddMatrix(0.1238967);
//    matrixB.AddMatrix(2.1238967);
//    ASSERT_FALSE(matrixB.EqMatrix(matrixA)); }
//
//class EqSimple4 : public ::testing::Test {
//protected:
//    S21Matrix matrixA;
//    S21Matrix matrixB{0, 0};
//};
//
//TEST_F(EqSimple4, operator_eq) { ASSERT_TRUE(matrixA == matrixB); }
//
//TEST_F(EqSimple4, A_eq_B) { ASSERT_TRUE(matrixA.EqMatrix(matrixB)); }
//
//TEST_F(EqSimple4, B_eq_A) { ASSERT_TRUE(matrixB.EqMatrix(matrixA)); }
//
//TEST(TransposeTest, test1) {
//    S21Matrix matrixA(0, 0);
//    S21Matrix matrixB(0, 0);
//
//    ASSERT_TRUE(matrixA.Transpose().EqMatrix(matrixB));
//}
//
//TEST(TransposeTest, test2) {
//    S21Matrix matrixA(1, 1);
//    S21Matrix matrixB(1, 1);
//
//    matrixA(0, 0) = 10;
//    matrixB(0, 0) = 10;
//
//    ASSERT_TRUE(matrixA.Transpose().EqMatrix(matrixB));
//}
//
//TEST(TransposeTest, test3) {
//    S21Matrix matrixA(1, 3);
//    S21Matrix matrixB(3, 1);
//
//    matrixA(0, 0) = 1;
//    matrixA(0, 1) = 2;
//    matrixA(0, 2) = 3;
//
//    matrixB(0, 0) = 1;
//    matrixB(1, 0) = 2;
//    matrixB(2, 0) = 3;
//
//    ASSERT_TRUE(matrixA.Transpose().EqMatrix(matrixB));
//}
//
//TEST(TransposeTest, test4) {
//    S21Matrix matrixA(3, 3);
//    S21Matrix matrixB(3, 3);
//
//    matrixA(0, 0) = 0.25;
//    matrixA(0, 1) = 1.25;
//    matrixA(0, 2) = 2.25;
//    matrixA(1, 0) = 3.25;
//    matrixA(1, 1) = 4.25;
//    matrixA(1, 2) = 5.25;
//    matrixA(2, 0) = 6.25;
//    matrixA(2, 1) = 7.25;
//    matrixA(2, 2) = 8.25;
//
//    matrixB(0, 0) = 0.25;
//    matrixB(1, 0) = 1.25;
//    matrixB(2, 0) = 2.25;
//    matrixB(0, 1) = 3.25;
//    matrixB(1, 1) = 4.25;
//    matrixB(2, 1) = 5.25;
//    matrixB(0, 2) = 6.25;
//    matrixB(1, 2) = 7.25;
//    matrixB(2, 2) = 8.25;
//
//    ASSERT_TRUE(matrixA.Transpose().EqMatrix(matrixB));
//}
//
//class MulNumber : public ::testing::Test {
//protected:
//    S21Matrix matrixA = S21Matrix(3, 3);
//    S21Matrix matrixB = S21Matrix(3, 3);
//
//    virtual void SetUp() {
//        matrixA(0, 0) = 0.25;
//        matrixA(0, 1) = 0.25;
//        matrixA(0, 2) = 0.25;
//        matrixA(1, 0) = 0.25;
//        matrixA(1, 1) = 0.25;
//        matrixA(1, 2) = 0.25;
//        matrixA(2, 0) = 0.25;
//        matrixA(2, 1) = 0.25;
//        matrixA(2, 2) = 0.25;
//
//        matrixB(0, 0) = 1.0;
//        matrixB(0, 1) = 1.0;
//        matrixB(0, 2) = 1.0;
//        matrixB(1, 0) = 1.0;
//        matrixB(1, 1) = 1.0;
//        matrixB(1, 2) = 1.0;
//        matrixB(2, 0) = 1.0;
//        matrixB(2, 1) = 1.0;
//        matrixB(2, 2) = 1.0;
//    }
//};
//
//TEST_F(MulNumber, test1) {
//    matrixA.MulNumber(4);
//    ASSERT_TRUE(matrixA.EqMatrix(matrixB));
//}
//
//TEST_F(MulNumber, test2) {
//    matrixA *= 4;
//    ASSERT_TRUE(matrixA.EqMatrix(matrixB));
//}
//
//TEST_F(MulNumber, test3) {
//    matrixA = matrixA * 4;
//    ASSERT_TRUE(matrixA.EqMatrix(matrixB));
//}
//
//TEST_F(MulNumber, test4) {
//    matrixA = 4 * matrixA;
//    ASSERT_TRUE(matrixA.EqMatrix(matrixB));
//}
//
//class MulMatrix1x1 : public ::testing::Test {
//protected:
//    S21Matrix matrixA = S21Matrix(1, 1);
//    S21Matrix matrixB = S21Matrix(1, 1);
//    S21Matrix matrixC = S21Matrix(1, 1);
//
//    void SetUp() override {
//        matrixA(0, 0) = 1;
//        matrixB(0, 0) = 10;
//        matrixC(0, 0) = 10;
//    }
//};
//
//TEST_F(MulMatrix1x1, test1) {
//    ASSERT_TRUE((matrixA * matrixB).EqMatrix(matrixC));
//}
//
//TEST_F(MulMatrix1x1, test2) {
//    ASSERT_TRUE((matrixA *= matrixB).EqMatrix(matrixC));
//}
//
//class ErrorMulMatrix : public ::testing::Test {
//protected:
//    S21Matrix matrixA = S21Matrix(1, 2);
//    S21Matrix matrixB = S21Matrix(1, 1);
//};
//
//TEST_F(ErrorMulMatrix, test1) { ASSERT_ANY_THROW(matrixA * matrixB); }
//
//TEST_F(ErrorMulMatrix, test2) { ASSERT_ANY_THROW(matrixA *= matrixB); }
//
//class MulMatrix2x3 : public ::testing::Test {
//protected:
//    S21Matrix matrixA = S21Matrix(3, 2);
//    S21Matrix matrixB = S21Matrix(2, 3);
//    S21Matrix matrixC = S21Matrix(3, 3);
//
//    void SetUp() override {
//        matrixA(0, 0) = 0;
//        matrixA(0, 1) = 1;
//        matrixA(1, 0) = 3;
//        matrixA(1, 1) = 4;
//        matrixA(2, 0) = 6;
//        matrixA(2, 1) = 7;
//
//        matrixB(0, 0) = 9;
//        matrixB(0, 1) = 8;
//        matrixB(0, 2) = 7;
//        matrixB(1, 0) = 6;
//        matrixB(1, 1) = 5;
//        matrixB(1, 2) = 4;
//
//        matrixC(0, 0) = 6;
//        matrixC(0, 1) = 5;
//        matrixC(0, 2) = 4;
//        matrixC(1, 0) = 51;
//        matrixC(1, 1) = 44;
//        matrixC(1, 2) = 37;
//        matrixC(2, 0) = 96;
//        matrixC(2, 1) = 83;
//        matrixC(2, 2) = 70;
//    }
//};
//
//TEST_F(MulMatrix2x3, test1) {
//    ASSERT_TRUE((matrixA * matrixB).EqMatrix(matrixC));
//}
//
//TEST_F(MulMatrix2x3, test2) {
//    ASSERT_TRUE((matrixA *= matrixB).EqMatrix(matrixC));
//}
//
//class MulMatrix3x3 : public ::testing::Test {
//protected:
//    S21Matrix matrixA = S21Matrix(3, 3);
//    S21Matrix matrixB = S21Matrix(3, 3);
//    S21Matrix matrixC = S21Matrix(3, 3);
//
//    void SetUp() override {
//        matrixA(0, 0) = 1;
//        matrixA(0, 1) = 2;
//        matrixA(0, 2) = 3;
//        matrixA(1, 0) = 4;
//        matrixA(1, 1) = 5;
//        matrixA(1, 2) = 6;
//        matrixA(2, 0) = 7;
//        matrixA(2, 1) = 8;
//        matrixA(2, 2) = 9;
//
//        matrixB(0, 0) = 9;
//        matrixB(0, 1) = 8;
//        matrixB(0, 2) = 7;
//        matrixB(1, 0) = 6;
//        matrixB(1, 1) = 5;
//        matrixB(1, 2) = 4;
//        matrixB(2, 0) = 3;
//        matrixB(2, 1) = 2;
//        matrixB(2, 2) = 1;
//
//        matrixC(0, 0) = 30;
//        matrixC(0, 1) = 24;
//        matrixC(0, 2) = 18;
//        matrixC(1, 0) = 84;
//        matrixC(1, 1) = 69;
//        matrixC(1, 2) = 54;
//        matrixC(2, 0) = 138;
//        matrixC(2, 1) = 114;
//        matrixC(2, 2) = 90;
//    }
//};
//
//TEST_F(MulMatrix3x3, test1) {
//    ASSERT_TRUE((matrixA * matrixB).EqMatrix(matrixC));
//}
//
//TEST_F(MulMatrix3x3, test2) {
//    ASSERT_TRUE((matrixA *= matrixB).EqMatrix(matrixC));
//}
//
//TEST(DetTest, test1) {
//    S21Matrix matrix(1, 1);
//    matrix(0, 0) = 5;
//
//    ASSERT_TRUE(fabs(matrix.Determinant() - 5) < EPS);
//}
//
//TEST(DetTest, test2) {
//    S21Matrix matrix(3, 3);
//
//    matrix(0, 0) = 0.25;
//    matrix(0, 1) = 1.25;
//    matrix(0, 2) = 2.25;
//    matrix(1, 0) = 3.25;
//    matrix(1, 1) = 10;
//    matrix(1, 2) = 5.25;
//    matrix(2, 0) = 6.25;
//    matrix(2, 1) = 7.25;
//    matrix(2, 2) = 8.25;
//
//    ASSERT_TRUE(fabs(matrix.Determinant() + 69) < EPS);
//}
//
//TEST(ErrorDetTest, test1) {
//    S21Matrix matrix(0, 0);
//
//    ASSERT_ANY_THROW((void)matrix.Determinant());
//}
//
//TEST(ErrorDetTest, test2) {
//    S21Matrix matrix(3, 2);
//
//    ASSERT_ANY_THROW((void)matrix.Determinant());
//}
//
//TEST(ComplementsTest, test1) {
//    S21Matrix matrixA(3, 3);
//    S21Matrix matrixB(3, 3);
//
//    matrixA(0, 0) = 5;
//    matrixA(0, 1) = -1;
//    matrixA(0, 2) = 1;
//    matrixA(1, 0) = 2;
//    matrixA(1, 1) = 3;
//    matrixA(1, 2) = 4;
//    matrixA(2, 0) = 1;
//    matrixA(2, 1) = 0;
//    matrixA(2, 2) = 3;
//
//    matrixB(0, 0) = 9;
//    matrixB(0, 1) = -2;
//    matrixB(0, 2) = -3;
//    matrixB(1, 0) = 3;
//    matrixB(1, 1) = 14;
//    matrixB(1, 2) = -1;
//    matrixB(2, 0) = -7;
//    matrixB(2, 1) = -18;
//    matrixB(2, 2) = 17;
//
//    ASSERT_TRUE(matrixA.CalcComplements().EqMatrix(matrixB));
//}
//
//TEST(ComplementsTest, test2) {
//    S21Matrix matrixA(1, 1);
//    S21Matrix matrixB(1, 1);
//
//    matrixA(0, 0) = 5;
//    matrixB(0, 0) = 5;
//
//    ASSERT_TRUE(matrixA.CalcComplements().EqMatrix(matrixB));
//}
//
//TEST(ComplementsTest, test3) {
//    S21Matrix matrixA(0, 0);
//    S21Matrix matrixB(0, 0);
//
//    ASSERT_TRUE(matrixA.CalcComplements().EqMatrix(matrixB));
//}
//
//TEST(ErrorComplementsTest, test1) {
//    S21Matrix matrix(2, 1);
//    ASSERT_ANY_THROW((void)matrix.CalcComplements());
//}
//
//class SumMatrix1 : public ::testing::Test {
//protected:
//    S21Matrix matrixA = S21Matrix(3, 3);
//    S21Matrix matrixB = S21Matrix(3, 3);
//    S21Matrix matrixC = S21Matrix(3, 3);
//
//    void SetUp() override {
//        matrixA(0, 0) = 0;
//        matrixA(0, 1) = 0;
//        matrixA(0, 2) = 0;
//        matrixA(1, 0) = 0;
//        matrixA(1, 1) = 0;
//        matrixA(1, 2) = 0;
//        matrixA(2, 0) = 0;
//        matrixA(2, 1) = 0;
//        matrixA(2, 2) = 0;
//
//        matrixB(0, 0) = 1;
//        matrixB(0, 1) = 1;
//        matrixB(0, 2) = 1;
//        matrixB(1, 0) = 1;
//        matrixB(1, 1) = 1;
//        matrixB(1, 2) = 1;
//        matrixB(2, 0) = 1;
//        matrixB(2, 1) = 1;
//        matrixB(2, 2) = 1;
//
//        matrixC(0, 0) = 1;
//        matrixC(0, 1) = 1;
//        matrixC(0, 2) = 1;
//        matrixC(1, 0) = 1;
//        matrixC(1, 1) = 1;
//        matrixC(1, 2) = 1;
//        matrixC(2, 0) = 1;
//        matrixC(2, 1) = 1;
//        matrixC(2, 2) = 1;
//    }
//};
//
//TEST_F(SumMatrix1, test1) {
//    matrixA += matrixB;
//    ASSERT_TRUE(matrixA.EqMatrix(matrixC));
//}
//
//TEST_F(SumMatrix1, test2) {
//    ASSERT_TRUE((matrixA + matrixB).EqMatrix(matrixC));
//}
//
//TEST(SumErrorTest, test1) {
//    S21Matrix matrixA = S21Matrix(2, 3);
//    S21Matrix matrixB = S21Matrix(3, 3);
//    ASSERT_ANY_THROW(matrixA + matrixB);
//}
//
//class SubMatrix1 : public ::testing::Test {
//protected:
//    S21Matrix matrixA = S21Matrix(3, 3);
//    S21Matrix matrixB = S21Matrix(3, 3);
//    S21Matrix matrixC = S21Matrix(3, 3);
//
//    void SetUp() override {
//        matrixA(0, 0) = 0;
//        matrixA(0, 1) = 0;
//        matrixA(0, 2) = 0;
//        matrixA(1, 0) = 0;
//        matrixA(1, 1) = 0;
//        matrixA(1, 2) = 0;
//        matrixA(2, 0) = 0;
//        matrixA(2, 1) = 0;
//        matrixA(2, 2) = 0;
//
//        matrixB(0, 0) = 1;
//        matrixB(0, 1) = 1;
//        matrixB(0, 2) = 1;
//        matrixB(1, 0) = 1;
//        matrixB(1, 1) = 1;
//        matrixB(1, 2) = 1;
//        matrixB(2, 0) = 1;
//        matrixB(2, 1) = 1;
//        matrixB(2, 2) = 1;
//
//        matrixC(0, 0) = -1;
//        matrixC(0, 1) = -1;
//        matrixC(0, 2) = -1;
//        matrixC(1, 0) = -1;
//        matrixC(1, 1) = -1;
//        matrixC(1, 2) = -1;
//        matrixC(2, 0) = -1;
//        matrixC(2, 1) = -1;
//        matrixC(2, 2) = -1;
//    }
//};
//
//TEST_F(SubMatrix1, test1) {
//    matrixA -= matrixB;
//    ASSERT_TRUE(matrixA.EqMatrix(matrixC));
//}
//
//TEST_F(SubMatrix1, test2) {
//    ASSERT_TRUE((matrixA - matrixB).EqMatrix(matrixC));
//}
//
//TEST(SubErrorTest, test1) {
//    S21Matrix matrixA = S21Matrix(2, 3);
//    S21Matrix matrixB = S21Matrix(3, 3);
//    ASSERT_ANY_THROW(matrixA - matrixB);
//}
//
//TEST(InverseTest, test1) {
//    S21Matrix matrixA(1, 1);
//    S21Matrix matrixB(1, 1);
//
//    matrixA(0, 0) = 1.25;
//    matrixB(0, 0) = 0.8;
//
//    ASSERT_TRUE(matrixA.InverseMatrix().EqMatrix(matrixB));
//}
//
//TEST(InverseTest, test2) {
//    S21Matrix matrixA(3, 3);
//    S21Matrix matrixB(3, 3);
//
//    matrixA(0, 0) = 2;
//    matrixA(0, 1) = 5;
//    matrixA(0, 2) = 7;
//    matrixA(1, 0) = 6;
//    matrixA(1, 1) = 3;
//    matrixA(1, 2) = 4;
//    matrixA(2, 0) = 5;
//    matrixA(2, 1) = -2;
//    matrixA(2, 2) = -3;
//
//    matrixB(0, 0) = 1;
//    matrixB(0, 1) = -1;
//    matrixB(0, 2) = 1;
//    matrixB(1, 0) = -38;
//    matrixB(1, 1) = 41;
//    matrixB(1, 2) = -34;
//    matrixB(2, 0) = 27;
//    matrixB(2, 1) = -29;
//    matrixB(2, 2) = 24;
//
//    ASSERT_TRUE(matrixA.InverseMatrix().EqMatrix(matrixB));
//}
//
//TEST(ErrorInverseTest, test1) {
//    S21Matrix matrixA(1, 3);
//
//    ASSERT_ANY_THROW((void)matrixA.InverseMatrix());
//}
//
//TEST(ErrorInverseTest, test2) {
//    S21Matrix matrixA(0, 0);
//    S21Matrix matrixB(0, 0);
//
//    ASSERT_ANY_THROW((void)matrixA.InverseMatrix());
//}
//
//TEST(ErrorInverseTest, test3) {
//    S21Matrix matrixA(2, 2);
//    matrixA.S21insertValues(4, 0., 0., 0., 0);
//    ASSERT_ANY_THROW((void)matrixA.InverseMatrix());
//}
//
//TEST(ErrorAny, test1) {
//    S21Matrix matrix(1, 1);
//
//    ASSERT_ANY_THROW(matrix(0, 1));
//}
//
//TEST(ErrorAny, test2) {
//    S21Matrix matrix(1, 1);
//
//    ASSERT_ANY_THROW(matrix(-1, -1));
//}
//
//TEST(ErrorAny, test3) {
//    S21Matrix matrix(1, 1);
//
//    ASSERT_ANY_THROW(matrix(1, 1));
//}
//
//TEST(ErrorAny, test4) {
//    const S21Matrix matrix(1, 1);
//
//    ASSERT_ANY_THROW(matrix(0, 1));
//}
//
//TEST(ErrorAny, test5) {
//    const S21Matrix matrix(1, 1);
//
//    ASSERT_ANY_THROW(matrix(-1, -1));
//}
//
//TEST(ErrorAny, test6) {
//    const S21Matrix matrix(1, 1);
//
//    ASSERT_ANY_THROW(matrix(1, 1));
//}
//
//TEST(Any, test1) {
//    S21Matrix matrixA(2, 2);
//    matrixA(0, 0) = 1;
//    matrixA(0, 1) = 2;
//    matrixA(1, 0) = 3;
//    matrixA(1, 1) = 4;
//    S21Matrix matrixB(0, 0);
//
//    S21Matrix matrixC = matrixA;
//
//    matrixB = matrixA;
//
//    ASSERT_TRUE(matrixC.EqMatrix(matrixB));
//    matrixB(0, 0) = 11;
//    ASSERT_TRUE(matrixA.EqMatrix(matrixC));
//}
//
//
//TEST(EqMatrix, Test_1) {
//    S21Matrix a(3, 3), b(3, 3);
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    b.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    EXPECT_TRUE(a == b);
//}
//
//TEST(EqMatrix, Test_2) {
//    S21Matrix a(3, 3), b(4, 3);
//    EXPECT_FALSE(a == b);
//}
//
//TEST(EqMatrix, Test_3) {
//    S21Matrix a(3, 3), b(3, 3);
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    b.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 1.);
//    EXPECT_FALSE(a == b);
//}
//
//TEST(SumMatrix, Test_1) {
//    S21Matrix a, c;
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    S21Matrix b(a);
//    c.S21insertValues(9, 1. * 2, 2. * 2, 3. * 2, 4. * 2, 5. * 2, 6. * 2, 7. * 2,
//                      8. * 2, 9. * 2);
//    a = a + b;
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(SumMatrix, Test_2) {
//    S21Matrix a(1, 1), c(1, 1);
//    a.S21insertValues(1, 1.);
//    S21Matrix b(a);
//    c.S21insertValues(1, 1. * 2);
//    a += b;
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(SumMatrix, Test_3) {
//    S21Matrix a(3, 3), b(4, 3);
//    EXPECT_ANY_THROW({ a.SumMatrix(b); });
//}
//
//TEST(SumMatrix, Test_4) {
//    S21Matrix a(3, 3), b(3, 4);
//    EXPECT_ANY_THROW({ a + b; });
//}
//
//TEST(SubMatrix, Test_1) {
//    S21Matrix a, c;
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    S21Matrix b = a;
//    c.S21insertValues(9, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
//    a -= b;
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(SubMatrix, Test_2) {
//    S21Matrix a(1, 1), c(1, 1);
//    a.S21insertValues(1, 1.);
//    S21Matrix b(a);
//    c.S21insertValues(1, 0.);
//    a = a - b;
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(SubMatrix, Test_3) {
//    S21Matrix a(3, 3), b(4, 3);
//    EXPECT_ANY_THROW({ a - b; });
//}
//
//TEST(SubMatrix, Test_4) {
//    S21Matrix a(3, 3), b(3, 4);
//    EXPECT_ANY_THROW({ a.SubMatrix(b); });
//}
//
//TEST(MulNumber2, Test_1) {
//    S21Matrix a{3, 3}, c{3, 3};
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    c.S21insertValues(9, 0., 0., 0., 0., 0., 0., 0., 0., 0.);
//    a = a * 0.;
//    a.Printmatrix();
//    std::cout<<std::endl;
//    c.Printmatrix();
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(MulNumber2, Test_2) {
//    S21Matrix a(2, 2), c(2, 2);
//    a.S21insertValues(4, 1., 2., 3., 4.);
//    c.S21insertValues(4, 1. * 2., 2. * 2., 3. * 2., 4. * 2.);
//    a *= 2.;
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(MulNumber2, Test_3) {
//    S21Matrix a(2, 2), c(2, 2);
//    a.S21insertValues(4, 1., 2., 3., 4.);
//    EXPECT_NO_THROW({ a * 1.5; });
//}
//
//TEST(MulMatrix, Test_1) {
//    S21Matrix a(3, 2), b(2, 4), c(3, 4);
//    a.S21insertValues(6, 1., 2., 3., 4., 5., 6.);
//    b.S21insertValues(8, 1., 2., 3., 4., 5., 6., 7., 8.);
//    c.S21insertValues(12, 11., 14., 17., 20., 23., 30., 37., 44., 35., 46., 57.,
//                      68.);
//    a *= b;
//    a.Printmatrix();
//    std::cout << std::endl;
//    c.Printmatrix();
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(MulMatrix, Test_2) {
//    S21Matrix a(2, 2), b(2, 2), c(2, 2);
//    a.S21insertValues(4, 1., 2., 3., 4.);
//    b.S21insertValues(4, 5., 6., 7., 8.);
//    c.S21insertValues(4, 19., 22., 43., 50.);
//    a = a * b;
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(MulMatrix, Test_3) {
//    S21Matrix a(3, 3), b(4, 3);
//    EXPECT_ANY_THROW({ a *b; });
//}
//
//TEST(Transpose, Test_1) {
//    S21Matrix a(3, 2), c(2, 3);
//    a.S21insertValues(6, 1., 2., 3., 4., 5., 6.);
//    c.S21insertValues(6, 1., 3., 5., 2., 4., 6.);
//    a = a.Transpose();
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(CalcComplements, Test_1) {
//    S21Matrix a(4, 4), c(4, 4);
//    a.S21insertValues(16, 1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 1., 1., 13.,
//                      14., 1., 1.);
//    c.S21insertValues(16, -4., 4., -28., 24., 4., -4., 12., -8., -52., 48., 60.,
//                      -56., 36., -32., -44., 40.);
//    a = a.CalcComplements();
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(CalcComplements, Test_2) {
//    S21Matrix a(1, 1), c(1, 1);
//    c.S21insertValues(1, 1.);
//    a = c.CalcComplements();
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(CalcComplements, Test_3) {
//    S21Matrix a(3, 4);
//    EXPECT_ANY_THROW({ a.CalcComplements(); });
//}
//
//TEST(Determinant, Test_1) {
//    S21Matrix a(1, 1);
//    a.S21insertValues(1, 1.);
//    double determinant = a.Determinant();
//    EXPECT_DOUBLE_EQ(determinant, 1.);
//}
//
//TEST(Determinant, Test_2) {
//    S21Matrix a(3, 4);
//    EXPECT_ANY_THROW({ a.Determinant(); });
//}
//
//TEST(InverseMatrix, Test_1) {
//    S21Matrix a{3, 3}, c{3, 3};
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 1.);
//    c.S21insertValues(9, (-43. / 24.), (11. / 12.), (-1. / 8.), (19. / 12.),
//                      (-5. / 6.), (1. / 4.), (-1. / 8.), (1. / 4.), (-1. / 8.));
//    a = a.InverseMatrix();
//    a.Printmatrix();
//    std::cout << std::endl;
//    c.Printmatrix();
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(InverseMatrix, Test_2) {
//    S21Matrix a{3, 3};
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    EXPECT_ANY_THROW({ a.InverseMatrix(); });
//}
//
//TEST(InverseMatrix, Test_3) {
//    S21Matrix a(1, 1);
//    S21Matrix c(1, 1);
//    a.S21insertValues(1, 1.);
//    c.S21insertValues(1, 1.);
//    a = a.InverseMatrix();
//    EXPECT_TRUE(a.EqMatrix(c));
//}
//
//TEST(Index, Test_1) {
//    S21Matrix a{3, 3};
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    EXPECT_DOUBLE_EQ(a(0, 0), 1.);
//    EXPECT_ANY_THROW({ a(3, 2); });
//    EXPECT_ANY_THROW({ a(2, 3); });
//}
//
//TEST(Index2, Test_1) {
//    S21Matrix a{3, 3};
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    EXPECT_DOUBLE_EQ(a(0, 0), 1.);
//    EXPECT_ANY_THROW({ a(3, 2); });
//    EXPECT_ANY_THROW({ a(2, 3); });
//}
//
//
//TEST(GetRows, Test_1) {
//    S21Matrix a(2, 2);
//    EXPECT_EQ(a.s21GetRows(), 2);
//}
//
//TEST(GetCols, Test_1) {
//    S21Matrix a(2, 2);
//    EXPECT_EQ(a.s21GetCols(), 2);
//}
//
//
//
//TEST(SetCols, Test_1) {
//    S21Matrix a(3, 1), c(3, 2), d(3, 3);
//    a.AddMatrix(9.876654);
//    c.AddMatrix(9.876654);
//    a.s21SetCols(2);
//    EXPECT_FALSE(a == c);
//    EXPECT_EQ(a.s21GetCols(), 2);
//    a.s21SetCols(3);
//    a.AddMatrix(111.4567);
//    d.AddMatrix(111.4567);
//    EXPECT_TRUE(a == d);
//    EXPECT_EQ(a.s21GetCols(), 3);
//}
//
//TEST(SetRows, Test_1) {
//    S21Matrix a(3, 3), c(2, 3), d(3, 3);
//    a.S21insertValues(9, 1., 2., 3., 4., 5., 6., 7., 8., 9.);
//    c.S21insertValues(9, 1., 2., 3., 4., 5., 6.);
//    a.s21SetRows(2);
//    EXPECT_TRUE(a == c);
//    EXPECT_EQ(a.s21GetRows(), 2);
//
//    a.s21SetRows(3);
//    d.S21insertValues(9, 1., 2., 3., 4., 5., 6., 0., 0., 0.);
//    EXPECT_TRUE(a == d);
//    EXPECT_EQ(a.s21GetRows(), 3);
//}
//
//TEST(ConstructorMove, Test_1) {
//    S21Matrix a{2, 4};
//    a.S21insertValues(8, 1., 2., 3., 4., 5., 6., 7., 8.);
//    S21Matrix c = a;
//    S21Matrix b = a;
////    EXPECT_EQ(a.s21GetCols(), 0);
//    EXPECT_TRUE(b.EqMatrix(c));
//}
//
//int main(int argc, char **argv) {
//
//
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}


class AccessorsMutators : public ::testing::Test {
protected:
    S21Matrix M43, M44, M34, M33;

    void SetUp() override {
        M43.s21SetRows(4);
        M43.s21SetCols(3);
        M43(0,0) =  1; M43(0,1) =  2; M43(0,2) =  3;
        M43(1,0) =  4; M43(1,1) =  5; M43(1,2) =  6;
        M43(2,0) =  7; M43(2,1) =  8; M43(2,2) =  9;
        M43(3,0) = 10; M43(3,1) = 11; M43(3,2) = 12;

        M44.s21SetRows(4);
        M44.s21SetCols(4);
        M44(0,0) = 1; M44(0,1) = 2; M44(0,2) = 3; M44(0,3) = 1;
        M44(1,0) = 4; M44(1,1) = 5; M44(1,2) = 6; M44(1,3) = 1;
        M44(2,0) = 7; M44(2,1) = 8; M44(2,2) = 9; M44(2,3) = 1;
        M44(3,0) = 1; M44(3,1) = 1; M44(3,2) = 1; M44(3,3) = 1;

        M34.s21SetRows(3);
        M34.s21SetCols(4);
        M34(0,0) = 1; M34(0,1) =  2; M34(0,2) =  3; M34(0,3) =  4;
        M34(1,0) = 5; M34(1,1) =  6; M34(1,2) =  7; M34(1,3) =  8;
        M34(2,0) = 9; M34(2,1) = 10; M34(2,2) = 11; M34(2,3) = 12;

        M33.s21SetRows(3);
        M33.s21SetCols(3);
        M33(0,0) = 1; M33(0,1) = 2; M33(0,2) = 3;
        M33(1,0) = 4; M33(1,1) = 5; M33(1,2) = 6;
        M33(2,0) = 7; M33(2,1) = 8; M33(2,2) = 9;
    }
};


TEST_F(AccessorsMutators, test_getters) {
    EXPECT_TRUE(M33.s21GetCols() == 3);
    EXPECT_TRUE(M33.s21GetRows() == 3);
}

TEST_F(AccessorsMutators, test_set_rows_4_3) {
    M43.s21SetRows(3);
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            EXPECT_TRUE(M43(i,j) == i*3 + j + 1);
        }
    }
}

TEST_F(AccessorsMutators, test_set_rows_4_5) {
    M43.s21SetRows(5);
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 3; j++) {
            EXPECT_TRUE(M43(i, j) == i*3 + j + 1);
        }
    }
    for (auto j = 0; j < 3; j++) {
        EXPECT_TRUE(M43(4,j) == 0);
    }
}

TEST_F(AccessorsMutators, test_set_rows_4_6) {
    M43.s21SetRows(6);
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 3; j++) {
            EXPECT_TRUE(M43(i, j) == i*3 + j + 1);
        }
    }
    for (auto j = 0; j < 3; j++) {
        EXPECT_TRUE(M43(4,j) == 0);
    }
    for (auto j = 0; j < 3; j++) {
        EXPECT_TRUE(M43(5,j) == 0);
    }
}

TEST_F(AccessorsMutators, test_set_rows_err) {
    EXPECT_ANY_THROW(M33.s21SetRows(-1));
}

TEST_F(AccessorsMutators, test_set_cols_3_2) {
    M43.s21SetCols(2);
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 2; j++) {
            EXPECT_TRUE(M43(i,j) == i * 3 + j + 1);
        }
    }
}

TEST_F(AccessorsMutators, test_set_cols_3_4) {
    M43.s21SetCols(4);
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 3; j++) {
            EXPECT_TRUE(M43(i, j) == i * 3 + j + 1);
        }
    }
    for (auto i = 0; i < 4; i++) {
        EXPECT_TRUE(M43(i, 3) == 0);
    }
}

TEST_F(AccessorsMutators, test_set_cols_3_5) {
    M43.s21SetCols(5);
    for (auto i = 0; i < 4; i++) {
        for (auto j = 0; j < 3; j++) {
            EXPECT_TRUE(M43(i, j) == i * 3 + j + 1);
        }
    }
    for (auto i = 0; i < 4; i++) {
        EXPECT_TRUE(M43(i, 3) == 0);
    }
    for (auto i = 0; i < 4; i++) {
        EXPECT_TRUE(M43(i, 4) == 0);
    }
}

TEST_F(AccessorsMutators, test_set_cols_err) {
    EXPECT_ANY_THROW(M33.s21SetCols(-1));
}

//TEST(Constructors, test_noarg) {
//    S21Matrix M;
//    EXPECT_TRUE(M.s21GetCols() == 0);
//    EXPECT_TRUE(M.s21GetRows() == 0);
//}
//
//
//TEST(Constructors, test_noarg_const) {
//    const S21Matrix M;
//    EXPECT_TRUE(M.s21GetCols() == 0);
//    EXPECT_TRUE(M.s21GetRows() == 0);
//}
//
//
//
//TEST(Constructors, test_twoarg_err) {
//    EXPECT_ANY_THROW(S21Matrix M(-1, -1));
//}
//
//TEST(Constructors, test_twoarg_00) {
//    S21Matrix M(0, 0);
//    EXPECT_TRUE(M.s21GetRows() == 0);
//    EXPECT_TRUE(M.s21GetCols() == 0);
//}
//
//TEST(Constructors, test_copy) {
//    S21Matrix other;
//    other.s21SetCols(1);
//    other.s21SetRows(1);
//    S21Matrix* M = new S21Matrix(other);
//    EXPECT_TRUE(M->s21GetRows() == 1);
//    EXPECT_TRUE(M->s21GetCols() == 1);
//    EXPECT_TRUE((*M)(0, 0) == 0);
//    delete M;
//}
//
//TEST(Constructors, test_copy_2) {
//    S21Matrix other;
//    other.s21SetCols(3);
//    other.s21SetRows(2);
//    S21Matrix M(other);
//    EXPECT_TRUE(M.s21GetRows() == 2);
//    EXPECT_TRUE(M.s21GetCols() == 3);
//    for (auto i = 0; i < 2; i++) {
//        for (auto j = 0; j < 3; j++) {
//            EXPECT_TRUE(M(i, j) == 0);
//        }
//    }
//}
//
//TEST(Constructors, test_move) {
//    S21Matrix other;
//    other.s21SetRows(1);
//    other.s21SetCols(3);
//    other(0, 2) = 2;
//    S21Matrix M = std::move(other);
//    EXPECT_TRUE(M.s21GetRows() == 1);
//    EXPECT_TRUE(M.s21GetCols() == 3);
//
//    EXPECT_TRUE(M(0, 0) == 0);
//    EXPECT_TRUE(M(0, 2) == 2);
//}
//
//TEST(Constructors, test_move_const) {
//    S21Matrix other;
//    other.s21SetRows(1);
//    other.s21SetCols(3);
//    other(0, 2) = 2;
//    const S21Matrix M = std::move(other);
//    EXPECT_TRUE(M.s21GetRows() == 1);
//    EXPECT_TRUE(M.s21GetCols() == 3);
//
//    EXPECT_TRUE(M(0, 0) == 0);
//    EXPECT_TRUE(M(0, 2) == 2);
//}
//
//
//TEST(OperOverloads, test_op_plus) {
//    S21Matrix M(4, 4), K(4, 4), R(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 1; M(0, 2) = 1; M(0, 3) = 1;
//    M(1, 0) = 1; M(1, 1) = 1; M(1, 2) = 1; M(1, 3) = 1;
//    M(2, 0) = 1; M(2, 1) = 1; M(2, 2) = 1; M(2, 3) = 1;
//    M(3, 0) = 1; M(3, 1) = 1; M(3, 2) = 1; M(3, 3) = 1;
//
//    K(0, 0) = 3; K(0, 1) = 3; K(0, 2) = 3; K(0, 3) = 3;
//    K(1, 0) = 3; K(1, 1) = 3; K(1, 2) = 3; K(1, 3) = 3;
//    K(2, 0) = 3; K(2, 1) = 3; K(2, 2) = 3; K(2, 3) = 3;
//    K(3, 0) = 3; K(3, 1) = 3; K(3, 2) = 3; K(3, 3) = 3;
//
//    R(0, 0) = 4; R(0, 1) = 4; R(0, 2) = 4; R(0, 3) = 4;
//    R(1, 0) = 4; R(1, 1) = 4; R(1, 2) = 4; R(1, 3) = 4;
//    R(2, 0) = 4; R(2, 1) = 4; R(2, 2) = 4; R(2, 3) = 4;
//    R(3, 0) = 4; R(3, 1) = 4; R(3, 2) = 4; R(3, 3) = 4;
//
//    EXPECT_TRUE(R.EqMatrix(M + K));
//}
//
//TEST(OperOverloads, test_op_plus_err) {
//    S21Matrix M(3, 4), K(4, 4);
//    EXPECT_ANY_THROW(EXPECT_TRUE(M.EqMatrix(M + K)));
//}
//
//TEST(OperOverloads, test_op_minus) {
//    S21Matrix M(4, 4), K(4, 4), R(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 1; M(0, 2) = 1; M(0, 3) = 1;
//    M(1, 0) = 1; M(1, 1) = 1; M(1, 2) = 1; M(1, 3) = 1;
//    M(2, 0) = 1; M(2, 1) = 1; M(2, 2) = 1; M(2, 3) = 1;
//    M(3, 0) = 1; M(3, 1) = 1; M(3, 2) = 1; M(3, 3) = 1;
//
//    K(0, 0) = 3; K(0, 1) = 3; K(0, 2) = 3; K(0, 3) = 3;
//    K(1, 0) = 3; K(1, 1) = 3; K(1, 2) = 3; K(1, 3) = 3;
//    K(2, 0) = 3; K(2, 1) = 3; K(2, 2) = 3; K(2, 3) = 3;
//    K(3, 0) = 3; K(3, 1) = 3; K(3, 2) = 3; K(3, 3) = 3;
//
//    R(0, 0) = -2; R(0, 1) = -2; R(0, 2) = -2; R(0, 3) = -2;
//    R(1, 0) = -2; R(1, 1) = -2; R(1, 2) = -2; R(1, 3) = -2;
//    R(2, 0) = -2; R(2, 1) = -2; R(2, 2) = -2; R(2, 3) = -2;
//    R(3, 0) = -2; R(3, 1) = -2; R(3, 2) = -2; R(3, 3) = -2;
//
//    EXPECT_TRUE(R.EqMatrix(M - K));
//}
//
//TEST(OperOverloads, test_op_minus_err) {
//    S21Matrix M(3, 4), K(4, 4);
//    EXPECT_ANY_THROW(EXPECT_TRUE(M.EqMatrix(M - K)));
//}
//
//TEST(OperOverloads, test_op_mul) {
//    S21Matrix M(3, 2), K(2, 3), R(3, 3);
//
//    M(0, 0) = 2; M(0, 1) = 2;
//    M(1, 0) = 2; M(1, 1) = 2;
//    M(2, 0) = 2; M(2, 1) = 2;
//
//    K(0, 0) = 3; K(0, 1) = 3; K(0, 2) = 3;
//    K(1, 0) = 3; K(1, 1) = 3; K(1, 2) = 3;
//
//    R(0, 0) = 12; R(0, 1) = 12; R(0, 2) = 12;
//    R(1, 0) = 12; R(1, 1) = 12; R(1, 2) = 12;
//    R(2, 0) = 12; R(2, 1) = 12; R(2, 2) = 12;
//
//    EXPECT_TRUE((M * K).s21GetRows() == 3);
//    EXPECT_TRUE((M * K).s21GetCols() == 3);
//    EXPECT_TRUE(R.EqMatrix(M * K));
//}
//
//TEST(OperOverloads, test_op_mul_err) {
//    S21Matrix M(3, 2), K(3, 3);
//    EXPECT_ANY_THROW(EXPECT_TRUE((M * K).s21GetRows() == 3));
//}
//
//TEST(OperOverloads, test_op_mul_num) {
//    S21Matrix M(3, 3), R(3, 3);
//
//    M(0, 0) = 12; M(0, 1) = 12; M(0, 2) = 12;
//    M(1, 0) = 12; M(1, 1) = 12; M(1, 2) = 12;
//    M(2, 0) = 12; M(2, 1) = 12; M(2, 2) = 12;
//
//    R(0, 0) = 36; R(0, 1) = 36; R(0, 2) = 36;
//    R(1, 0) = 36; R(1, 1) = 36; R(1, 2) = 36;
//    R(2, 0) = 36; R(2, 1) = 36; R(2, 2) = 36;
//
//    EXPECT_TRUE(R.EqMatrix(M * 3));
//    EXPECT_TRUE(R.EqMatrix(3 * M));
//}
//
//TEST(OperOverloads, test_op_equal) {
//    S21Matrix M(4, 4);
//    S21Matrix K(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 2; M(0, 2) = 3; M(0, 3) = 1;
//    M(1, 0) = 4; M(1, 1) = 5; M(1, 2) = 6; M(1, 3) = 1;
//    M(2, 0) = 7; M(2, 1) = 8; M(2, 2) = 9; M(2, 3) = 1;
//    M(3, 0) = 10; M(3, 1) = 11; M(3, 2) = 12; M(3, 3) = 1;
//
//    K(0, 0) = 1; K(0, 1) = 2; K(0, 2) = 3; K(0, 3) = 1;
//    K(1, 0) = 4; K(1, 1) = 5; K(1, 2) = 6; K(1, 3) = 1;
//    K(2, 0) = 7; K(2, 1) = 8; K(2, 2) = 9; K(2, 3) = 1;
//    K(3, 0) = 10; K(3, 1) = 11; K(3, 2) = 12; K(3, 3) = 1;
//
//    EXPECT_TRUE(M == K);
//}
//
//TEST(OperOverloads, test_op_assign) {
//    S21Matrix M(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 2; M(0, 2) = 3; M(0, 3) = 1;
//    M(1, 0) = 4; M(1, 1) = 5; M(1, 2) = 6; M(1, 3) = 1;
//    M(2, 0) = 7; M(2, 1) = 8; M(2, 2) = 9; M(2, 3) = 1;
//    M(3, 0) = 10; M(3, 1) = 11; M(3, 2) = 12; M(3, 3) = 1;
//
//    S21Matrix K;
//    K = M;
//    EXPECT_TRUE(M == K);
//
//    S21Matrix N(6, 6);
//    N = M;
//    EXPECT_TRUE(M == N);
//}
//
//TEST(OperOverloads, test_op_assign_self) {
//    S21Matrix M(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 2; M(0, 2) = 3; M(0, 3) = 1;
//    M(1, 0) = 4; M(1, 1) = 5; M(1, 2) = 6; M(1, 3) = 1;
//    M(2, 0) = 7; M(2, 1) = 8; M(2, 2) = 9; M(2, 3) = 1;
//    M(3, 0) = 10; M(3, 1) = 11; M(3, 2) = 12; M(3, 3) = 1;
//
//    M = M;
//
//    EXPECT_TRUE(M == M);
//}
//
//TEST(OperOverloads, test_op_assign_move) {
//    S21Matrix M(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 2; M(0, 2) = 3; M(0, 3) = 1;
//    M(1, 0) = 4; M(1, 1) = 5; M(1, 2) = 6; M(1, 3) = 1;
//    M(2, 0) = 7; M(2, 1) = 8; M(2, 2) = 9; M(2, 3) = 1;
//    M(3, 0) = 10; M(3, 1) = 11; M(3, 2) = 12; M(3, 3) = 1;
//
//    S21Matrix N = M;
//    S21Matrix K = std::move(M);
//    EXPECT_TRUE(K(1, 1) == 5);
//    M.Printmatrix();
//    std::cout<< M.s21GetRows() << ' ' << M.s21GetCols() << std::endl;
//    K.Printmatrix();
//    std::cout<< K.s21GetRows() << ' ' << K.s21GetCols() << std::endl;
//    EXPECT_TRUE(N == K);
//}
//
//TEST(OperOverloads, test_op_addition_assignment) {
//    S21Matrix M(4, 4), K(4, 4), R(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 1; M(0, 2) = 1; M(0, 3) = 1;
//    M(1, 0) = 1; M(1, 1) = 1; M(1, 2) = 1; M(1, 3) = 1;
//    M(2, 0) = 1; M(2, 1) = 1; M(2, 2) = 1; M(2, 3) = 1;
//    M(3, 0) = 1; M(3, 1) = 1; M(3, 2) = 1; M(3, 3) = 1;
//
//    K(0, 0) = 3; K(0, 1) = 3; K(0, 2) = 3; K(0, 3) = 3;
//    K(1, 0) = 3; K(1, 1) = 3; K(1, 2) = 3; K(1, 3) = 3;
//    K(2, 0) = 3; K(2, 1) = 3; K(2, 2) = 3; K(2, 3) = 3;
//    K(3, 0) = 3; K(3, 1) = 3; K(3, 2) = 3; K(3, 3) = 3;
//
//    R(0, 0) = 4; R(0, 1) = 4; R(0, 2) = 4; R(0, 3) = 4;
//    R(1, 0) = 4; R(1, 1) = 4; R(1, 2) = 4; R(1, 3) = 4;
//    R(2, 0) = 4; R(2, 1) = 4; R(2, 2) = 4; R(2, 3) = 4;
//    R(3, 0) = 4; R(3, 1) = 4; R(3, 2) = 4; R(3, 3) = 4;
//
//    EXPECT_TRUE(R.EqMatrix(M += K));
//}
//
//TEST(OperOverloads, test_op_sub_assignment) {
//    S21Matrix M(4, 4), K(4, 4), R(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 1; M(0, 2) = 1; M(0, 3) = 1;
//    M(1, 0) = 1; M(1, 1) = 1; M(1, 2) = 1; M(1, 3) = 1;
//    M(2, 0) = 1; M(2, 1) = 1; M(2, 2) = 1; M(2, 3) = 1;
//    M(3, 0) = 1; M(3, 1) = 1; M(3, 2) = 1; M(3, 3) = 1;
//
//    K(0, 0) = 3; K(0, 1) = 3; K(0, 2) = 3; K(0, 3) = 3;
//    K(1, 0) = 3; K(1, 1) = 3; K(1, 2) = 3; K(1, 3) = 3;
//    K(2, 0) = 3; K(2, 1) = 3; K(2, 2) = 3; K(2, 3) = 3;
//    K(3, 0) = 3; K(3, 1) = 3; K(3, 2) = 3; K(3, 3) = 3;
//
//    R(0, 0) = 4; R(0, 1) = 4; R(0, 2) = 4; R(0, 3) = 4;
//    R(1, 0) = 4; R(1, 1) = 4; R(1, 2) = 4; R(1, 3) = 4;
//    R(2, 0) = 4; R(2, 1) = 4; R(2, 2) = 4; R(2, 3) = 4;
//    R(3, 0) = 4; R(3, 1) = 4; R(3, 2) = 4; R(3, 3) = 4;
//
//    EXPECT_TRUE(M.EqMatrix(R -= K));
//}
//
//TEST(OperOverloads, test_op_mul_assignment) {
//    S21Matrix M(3, 2), K(2, 3), R(3, 3);
//
//    M(0, 0) = 2; M(0, 1) = 2;
//    M(1, 0) = 2; M(1, 1) = 2;
//    M(2, 0) = 2; M(2, 1) = 2;
//
//    K(0, 0) = 3; K(0, 1) = 3; K(0, 2) = 3;
//    K(1, 0) = 3; K(1, 1) = 3; K(1, 2) = 3;
//
//    R(0, 0) = 12; R(0, 1) = 12; R(0, 2) = 12;
//    R(1, 0) = 12; R(1, 1) = 12; R(1, 2) = 12;
//    R(2, 0) = 12; R(2, 1) = 12; R(2, 2) = 12;
//
//    EXPECT_TRUE((M * K).s21GetRows() == 3);
//    EXPECT_TRUE((M * K).s21GetCols() == 3);
//    EXPECT_TRUE(R.EqMatrix(M *= K));
//}
//
//TEST(OperOverloads, test_op_mul_assignment_num) {
//    S21Matrix M(3, 3), R(3, 3);
//
//    M(0, 0) = 12; M(0, 1) = 12; M(0, 2) = 12;
//    M(1, 0) = 12; M(1, 1) = 12; M(1, 2) = 12;
//    M(2, 0) = 12; M(2, 1) = 12; M(2, 2) = 12;
//
//    R(0, 0) = 36; R(0, 1) = 36; R(0, 2) = 36;
//    R(1, 0) = 36; R(1, 1) = 36; R(1, 2) = 36;
//    R(2, 0) = 36; R(2, 1) = 36; R(2, 2) = 36;
//
//    EXPECT_TRUE(R.EqMatrix(M *= 3));
//}
//
//TEST(OperOverloads, test_op_paren) {
//    S21Matrix M(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 2; M(0, 2) = 3; M(0, 3) = 1;
//    M(1, 0) = 4; M(1, 1) = 5; M(1, 2) = 6; M(1, 3) = 1;
//    M(2, 0) = 7; M(2, 1) = 8; M(2, 2) = 9; M(2, 3) = 1;
//    M(3, 0) = 10; M(3, 1) = 11; M(3, 2) = 12; M(3, 3) = 1;
//
//    EXPECT_TRUE(M(2, 2) == 9);
//}
//
//TEST(OperOverloads, test_op_paren_err) {
//    S21Matrix M(4, 4);
//
//    M(0, 0) = 1; M(0, 1) = 2; M(0, 2) = 3; M(0, 3) = 1;
//    M(1, 0) = 4; M(1, 1) = 5; M(1, 2) = 6; M(1, 3) = 1;
//    M(2, 0) = 7; M(2, 1) = 8; M(2, 2) = 9; M(2, 3) = 1;
//    M(3, 0) = 10; M(3, 1) = 11; M(3, 2) = 12; M(3, 3) = 1;
//
//    EXPECT_ANY_THROW(EXPECT_TRUE(M(4, 2) == 9));
//}
//
//TEST(OperOverloads, test_op_paren_err_const) {
//    const S21Matrix M(4, 4);
//
//    EXPECT_ANY_THROW(EXPECT_TRUE(M(4, 2) == 9));
//}
//
