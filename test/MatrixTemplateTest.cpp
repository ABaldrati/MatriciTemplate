#include "gtest/gtest.h"

#include "../MatrixTemplate.h"

TEST(MatrixTemplate,DefaultConstructor){
    MatrixTemplate<int> MatA(4,6);
    ASSERT_EQ(4, MatA.getRow());
    ASSERT_EQ(6, MatA.getColumn());
    ASSERT_EQ(0,MatA.getValue(3,2));
    MatrixTemplate<int> MatB(0,5);
    ASSERT_EQ(1, MatB.getRow());
}


TEST(MatrixTemplate,CopyConstructor){
    MatrixTemplate <float> MatA(2,3);
    MatA.setValue(1,1,0.5);
    MatA.setValue(1,2,1.5);
    MatA.setValue(1,3,4);
    MatA.setValue(2,1,7);
    MatA.setValue(2,3,1.6);
    MatrixTemplate<float> MatB(MatA);
    ASSERT_TRUE(MatA==MatB);
    MatB.setValue(1,1,7);
    ASSERT_FALSE(MatA==MatB);
}

TEST(MatrixTemplate,PlusEqual){
    MatrixTemplate<int> MatA(3,3);
    MatA.setValue(1,1,1);
    MatA.setValue(1,2,2);
    MatA.setValue(1,3,5);
    MatA.setValue(2,1,12);
    MatA.setValue(2,2,7);
    MatA.setValue(2,3,6);
    MatA.setValue(3,1,1);
    MatA.setValue(3,2,1);
    MatA.setValue(3,3,5);
    MatrixTemplate<int> MatB(3,3);
    MatB.setValue(1,2,3);
    MatB.setValue(2,2,4);
    MatB.setValue(2,3,1);
    MatB.setValue(3,1,5);
    MatA+=MatB;
    ASSERT_EQ(5,MatA.getValue(1,2));
    ASSERT_EQ(11,MatA.getValue(2,2));
    ASSERT_EQ(7,MatA.getValue(2,3));
    ASSERT_EQ(6,MatA.getValue(3,1));
    ASSERT_ANY_THROW(MatA.setValue(1,4,2));
}

TEST(MatrixTemplate,OperatorPlus){
    MatrixTemplate<int> MatA(3,3);
    MatA.setValue(1,1,1);
    MatA.setValue(1,2,2);
    MatA.setValue(1,3,5);
    MatA.setValue(2,1,12);
    MatA.setValue(2,2,7);
    MatA.setValue(2,3,6);
    MatA.setValue(3,1,1);
    MatA.setValue(3,2,1);
    MatA.setValue(3,3,5);
    MatrixTemplate<int> MatB(3,4);
    MatrixTemplate<int> MatC(3,3);
    MatC.setValue(1,1,8);
    MatC.setValue(2,1,1);
    MatC.setValue(3,1,3);
    MatC.setValue(3,2,6);
    MatC.setValue(3,3,2);
    MatrixTemplate<int> MatD(1,1);
    MatD=MatA+MatC;
    ASSERT_EQ(9,MatD.getValue(1,1));
    ASSERT_EQ(13,MatD.getValue(2,1));
    ASSERT_EQ(4,MatD.getValue(3,1));
    ASSERT_EQ(7,MatD.getValue(3,2));
    ASSERT_EQ(7,MatD.getValue(3,3));
    ASSERT_ANY_THROW(MatA+MatB);
}

TEST(MatrixTemplate,EqualAndDifferent){
    MatrixTemplate<float> MatA(2,2);
    MatA.setValue(1,1,0.8);
    MatA.setValue(1,2,1.5);
    MatA.setValue(2,1,5);
    MatA.setValue(2,2,0.8);
    MatrixTemplate<float> MatB(2,2);
    MatB.setValue(1,1,0.8);
    MatB.setValue(1,2,1.5);
    MatB.setValue(2,1,5);
    MatB.setValue(2,2,0.8);
    ASSERT_TRUE(MatA==MatB);
    ASSERT_FALSE(MatA!=MatB);
    MatA.setValue(1,1,3.2);
    ASSERT_TRUE(MatA!=MatB);
    ASSERT_FALSE(MatA==MatB);

}

TEST(MatrixTemplate,OperatorProduct){
    MatrixTemplate<int> MatA(2,3);
    MatA.setValue(1,1,1);
    MatA.setValue(1,2,2);
    MatA.setValue(1,3,5);
    MatA.setValue(2,1,12);
    MatA.setValue(2,2,7);
    MatA.setValue(2,3,1);
    MatrixTemplate<int>MatB(2,2);
    MatrixTemplate<int>MatC(3,2);
    MatC.setValue(1,1,3);
    MatC.setValue(1,2,2);
    MatC.setValue(2,1,1);
    MatC.setValue(2,2,5);
    MatC.setValue(3,1,5);
    MatC.setValue(3,2,6);
    ASSERT_ANY_THROW(MatA*MatB);
    MatB=MatA*MatC;
    ASSERT_EQ(30,MatB.getValue(1,1));
    ASSERT_EQ(42,MatB.getValue(1,2));
    ASSERT_EQ(48,MatB.getValue(2,1));
    ASSERT_EQ(65,MatB.getValue(2,2));
    MatB=3*MatA;
    ASSERT_EQ(6,MatB.getValue(1,2));
    ASSERT_EQ(36,MatB.getValue(2,1));
    ASSERT_EQ(21,MatB.getValue(2,2));
}

TEST(MatrixTemplate,Transpose){
    MatrixTemplate<long int> MatA(3,2);
    MatA.setValue(1,1,2);
    MatA.setValue(1,2,5);
    MatA.setValue(2,1,2);
    MatA.setValue(2,2,7);
    MatA.setValue(3,1,1);
    MatA.setValue(3,2,9);
    MatrixTemplate<long int> MatB(MatA.transpose());
    ASSERT_EQ(3, MatB.getColumn());
    ASSERT_EQ(2, MatB.getRow());
    ASSERT_EQ(9,MatB.getValue(2,3));
    ASSERT_EQ(5,MatB.getValue(2,1));
    ASSERT_EQ(7,MatB.getValue(2,2));
}

TEST(MatrixTemplate,SelectColumn){
    MatrixTemplate<char> MatA(3,3);
    MatA.setValue(1,1,3);
    MatA.setValue(1,2,1);
    MatA.setValue(1,3,7);
    MatA.setValue(2,1,9);
    MatA.setValue(2,2,4);
    MatA.setValue(2,3,2);
    MatA.setValue(3,1,8);
    MatA.setValue(3,2,9);
    MatA.setValue(3,3,1);
    MatrixTemplate<char> MatB(MatA.selectColumn(2));
    ASSERT_EQ(1,MatB.getValue(1,1));
    ASSERT_EQ(4,MatB.getValue(2,1));
    ASSERT_EQ(9,MatB.getValue(3,1));
    ASSERT_ANY_THROW(MatA.selectColumn(4));
}

TEST(MatrixTemplate,SelectRow){
    MatrixTemplate<char> MatA(3,3);
    MatA.setValue(1,1,3);
    MatA.setValue(1,2,1);
    MatA.setValue(1,3,7);
    MatA.setValue(2,1,9);
    MatA.setValue(2,2,4);
    MatA.setValue(2,3,2);
    MatA.setValue(3,1,8);
    MatA.setValue(3,2,9);
    MatA.setValue(3,3,1);
    MatrixTemplate<char> MatB(MatA.selectRow(2));
    ASSERT_EQ(9,MatB.getValue(1,1));
    ASSERT_EQ(4,MatB.getValue(1,2));
    ASSERT_EQ(2,MatB.getValue(1,3));
    ASSERT_ANY_THROW(MatA.selectRow(4));
}

TEST(MatrixTemplate,GetValue){
    MatrixTemplate<int> MatA(3,3);
    MatA.setValue(1,1,3);
    MatA.setValue(1,2,1);
    MatA.setValue(1,3,7);
    MatA.setValue(2,1,9);
    MatA.setValue(2,2,4);
    MatA.setValue(2,3,2);
    MatA.setValue(3,1,8);
    MatA.setValue(3,2,9);
    MatA.setValue(3,3,1);
    ASSERT_EQ(9,MatA.getValue(2,1));
    ASSERT_EQ(8,MatA.getValue(3,1));
    ASSERT_ANY_THROW(MatA.getValue(4,1));
}

TEST(MatrixTemplate,SetValue){
    MatrixTemplate<char> MatA(3,3);
    MatA.setValue(1,1,3);
    MatA.setValue(1,2,1);
    MatA.setValue(1,3,7);
    MatA.setValue(2,1,9);
    MatA.setValue(2,2,4);
    MatA.setValue(2,3,2);
    MatA.setValue(3,1,8);
    MatA.setValue(3,2,9);
    MatA.setValue(3,3,1);
    ASSERT_ANY_THROW(MatA.setValue(4,3,1));
}