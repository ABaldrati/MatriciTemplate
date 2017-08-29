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
bool isEqual(const MatrixTemplate<T>&lh, const MatrixTemplate<T>&rh) {
    for (int i = 0; i < lh.getRow() * lh.getColumn(); i++) {
        if (lh.getBuffer()[i] != rh.getBuffer()[i])
            return false;
    }
    return true;
}

template<>
bool isEqual<float>(const MatrixTemplate<float>&lh,const MatrixTemplate<float>&rh);


template<>
bool isEqual<double>(const MatrixTemplate<double>&lh,const MatrixTemplate<double>&rh);

#endif //MATRICITEMPLATE_UTILSMATRIXTEMPLATE_H
