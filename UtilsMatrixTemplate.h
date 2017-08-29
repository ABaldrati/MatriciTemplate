//
// Created by alberto on 28/08/17.
//

#ifndef MATRICITEMPLATE_UTILSMATRIXTEMPLATE_H
#define MATRICITEMPLATE_UTILSMATRIXTEMPLATE_H

#include "MatrixTemplate.h"
#include <cmath>
#include <cfloat>

template <typename T>
class MatrixTemplate;

template<typename T,typename N>
MatrixTemplate<T> operator*(const N& lh,const MatrixTemplate<T>& rh) {
    static_cast<T>(lh);
    MatrixTemplate<T> retMatrix(rh.getRow(), rh.getColumn());
    retMatrix = rh * lh;
    return retMatrix;
}


template<typename T>
bool isEqual(const T&lh, const T&rh) {
    return lh==rh;
}

template<>
bool isEqual<float>(const float&lh,const float&rh) {
    if (fabsf(lh - rh) > FLT_EPSILON)
        return false;
    else return true;
}


template<>
bool isEqual<double>(const double&lh,const double&rh) {
    if (fabs(lh - rh) > FLT_EPSILON)
        return false;
    else return true;
}
#endif //MATRICITEMPLATE_UTILSMATRIXTEMPLATE_H
