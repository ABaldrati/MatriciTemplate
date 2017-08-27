//
// Created by A_Bal on 24/08/2017.
//

#ifndef MATRICITEMPLATE_MATRIXTEMPLATE_H
#define MATRICITEMPLATE_MATRIXTEMPLATE_H

#include <iostream>
#include <stdexcept>

template<typename T>
class MatrixTemplate {
public:
    MatrixTemplate(int r, int c) : rows(r), columns(c) {
        if (r<1)
            rows=1;
        if (c<1)
            columns=1;
        buffer = new T[rows * columns];
        for(int i=0;i<rows*columns;i++)
            buffer[i]=0;
    }

    ~MatrixTemplate() {
        delete[] buffer;
    }

    MatrixTemplate(const MatrixTemplate &rh) {
        rows = rh.rows;
        columns = rh.columns;
        buffer = new T[rows * columns];
        for (int i = 0; i < rows * columns; i++)
            buffer[i] = rh.buffer[i];
    }

    MatrixTemplate &operator=(const MatrixTemplate &rh) {
        if (&rh == this)
            return *this;
        rows = rh.rows;
        columns = rh.columns;
        delete[]buffer;
        buffer = new T[rows * columns];
        for (int i = 0; i < rows * columns; i++)
            buffer[i] = rh.buffer[i];
        return *this;
    }


    MatrixTemplate &operator+=(const MatrixTemplate &rh){
        if (rows!=rh.rows || columns!=rh.columns)
            throw std::logic_error(
                    "Nell'operazione di somma righe e colonne degli addenti devono essere dello stesso numero");
        for (int i = 0; i < rows * columns; i++)
            buffer[i] = buffer[i] + rh.buffer[i];
        return *this;
    }

    MatrixTemplate operator+(const MatrixTemplate &rh) const {
        if (rows != rh.rows || columns != rh.columns)
            throw std::logic_error(
                    "Nell'operazione di somma righe e colonne degli addenti devono essere dello stesso numero");
        MatrixTemplate<T> tmp(rows, columns);
        for (int i = 0; i < rh.rows * rh.columns; i++)
            tmp.buffer[i] = buffer[i] + rh.buffer[i];
        return tmp;
    }

    MatrixTemplate operator*(const MatrixTemplate &rh) const {
        if (columns != rh.rows)
            throw std::logic_error(
                    "Nell'operazione di prodotto le colonne del primo fattore devono essere lo stesso numero delle ricghe del seocndo fattore");
        MatrixTemplate<T> tmp(rows, rh.columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rh.columns; j++) {
                tmp.buffer[i * rh.columns + j] = 0;
                for (int h = 0; h < columns; h++)
                    tmp.buffer[i * rh.columns + j] += buffer[i * columns + h] * rh.buffer[h * rh.columns + j];
            }
        return tmp;
    }


    bool operator==(const MatrixTemplate &rh) const {
        if (rows != rh.rows || columns != rh.columns)
            return false;
        for (int i = 0; i < rows * columns; i++) {
            if (buffer[i] != rh.buffer[i])
                return false;
        }
        return true;
    }


    MatrixTemplate transpose() const {
        MatrixTemplate<T> tmp(columns, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                tmp.buffer[tmp.columns * j + i] = buffer[columns * i + j];
        return tmp;
    }


    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << buffer[columns * (i) + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    T getValue(int i, int j) const {
        if (i > rows|| i<1 || j<1  || j > columns)
            throw std::out_of_range("Elemento non presente nella matrice");
        return buffer[columns * (i - 1) + j - 1];
    }

    void setValue(int i, int j, const T &value) const {
        if (i > rows || j > columns)
            throw std::out_of_range("Elemento non presente nella matrice");
        buffer[columns * (i - 1) + j - 1] = value;
    }

    MatrixTemplate selectRow(int i) {
        if (i > rows || i<1)
            throw std::out_of_range("Riga non presente nella matrice");
        MatrixTemplate<T> tmp(1, columns);
        for (int j = 0; j < columns; j++)
            tmp.buffer[j] = buffer[columns * (i - 1) + j];
        return tmp;
    }

    MatrixTemplate selectColumns(int j) {
        if (j > rows || j<1)
            throw std::out_of_range("Colonna non presente nella matrice");
        MatrixTemplate<T> tmp(rows, 1);
        for (int i = 0; i < rows; i++)
            tmp.buffer[i] = buffer[j - 1 + columns * i];
        return tmp;
    }

    int getRows(){
        return rows;
    }

    int getColumns(){
        return columns;
    }

    static MatrixTemplate<T> identity(int x){
        MatrixTemplate<T> tmp(x,x);
        for(int i=0;i<=x;i++)
            tmp.setValue(i,i,1);
        return tmp;
    }

private:
    int rows, columns;
    T *buffer;
};


#endif //MATRICITEMPLATE_MATRIXTEMPLATE_H
