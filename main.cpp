#include "iostream"
#include "MatrixTemplate.h"
int main() {
    MatrixTemplate<float> MatA(2,3);
    MatA.setValue(1,1,1);
    MatA.setValue(1,2,2);
    MatA.setValue(1,3,5.12);
    MatA.setValue(2,1,12);
    MatA.setValue(2,2,7);
    MatA.setValue(2,3,1);
    MatrixTemplate<float>MatB(2,2);
    MatrixTemplate<float>MatC(1,1);
    MatB=3*MatA;
    MatA.print();
    MatB.print();
    if(MatA==MatB)
        std::cout<<"abs";
    else std::cout<<"cds";



}