//
// Created by alberto on 29/08/17.
//

#include "MatrixTemplate.h"


template <>
bool isEqual<float>(const MatrixTemplate<float>&lh,const MatrixTemplate<float>&rh){
    for (int i = 0; i < lh.getRow() * lh.getColumn(); i++) {
        if (fabsf(lh.getBuffer()[i] - rh.getBuffer()[i]) > FLT_EPSILON)
            return false;
    }
    return true;
}

template<>
bool isEqual<double>(const MatrixTemplate<double>&lh,const MatrixTemplate<double>&rh){
    for (int i = 0; i < lh.getRow() * lh.getColumn(); i++) {
        if (fabs(lh.getBuffer()[i] - rh.getBuffer()[i]) > FLT_EPSILON)
            return false;
    }
    return true;
}