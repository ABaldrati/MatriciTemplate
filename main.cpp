#include <iostream>
#include "MatrixTemplate.h"


int main() {
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
    MatA.print();
    MatrixTemplate<int> MatB(MatA.selectRow(2));
    MatB.print();


}