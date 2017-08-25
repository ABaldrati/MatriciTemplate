#include <iostream>
#include "MatrixTemplate.h"


int main() {
    MatrixTemplate<int> MatA(2,3);
    MatA.setValue(1,1,1);
    MatA.setValue(1,2,2);
    MatA.setValue(1,3,5);
    MatA.setValue(2,1,12);
    MatA.setValue(2,2,7);
    MatA.setValue(2,3,7);
    MatA.print();
    /*MatrixTemplate<int> MatB(2,3);
    MatB.setValue(1,1,4);
    MatB.setValue(1,2,1);
    MatB.setValue(2,1,5);
    MatB.setValue(2,2,4);
    MatB.setValue(1,3,5);
    MatB.setValue(2,3,3);
    MatB.print();
    MatrixTemplate<int> MatD(2,3);
    MatD.setValue(1,1,2);
    MatD.setValue(1,2,8);
    MatD.setValue(2,1,2);
    MatD.setValue(2,2,1);
    MatD.setValue(1,3,3);
    MatD.setValue(2,3,7);
    MatD.print();
    MatrixTemplate<int> MatC(2,3);
    MatC=MatA+MatB+MatD;
    MatA.print();
    MatB.print();
    MatC.print();*/
    MatrixTemplate<int> MatC(2,3);
    MatC=MatA.transpose();
    MatA.print();
    MatC.print();
    MatrixTemplate<int> MatD(2,2);
    MatD=MatA*MatC;
    MatD.print();
    MatrixTemplate<int> MatE(2,2);
    MatE=MatA.selectColumns(2);
    MatE.print();




}