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
    MatrixTemplate<int> MatB(100,2);
    MatB=MatA.transpose();
    MatB.print();


}