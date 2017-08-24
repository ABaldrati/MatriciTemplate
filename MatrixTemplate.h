//
// Created by A_Bal on 24/08/2017.
//

#ifndef MATRICITEMPLATE_MATRIXTEMPLATE_H
#define MATRICITEMPLATE_MATRIXTEMPLATE_H

template <typename T>
class MatrixTemplate {
public:
    MatrixTemplate(int r, int c):rows(r), columns(c){
        buffer=new T[r*c];
    }

    ~MatrixTemplate(){
        delete [] buffer;
    }

    MatrixTemplate& operator+=(const MatrixTemplate& rh){
        for(int i=0;i<rows*columns;i++)
            buffer[i]=buffer[i]+rh.buffer[i];
        return *this;
    }

    MatrixTemplate& operator+(const MatrixTemplate& lh, const MatrixTemplate& rh){
        //TODO righe e colonne devono essere uguali
        buffer=new T[lh.rows*lh.columns];
        for(int i=0;i<rh.rows*rh.columns;i++)
            buffer[i]=rh.buffer[i]+lh.buffer[i];
        return *this;
    }

    MatrixTemplate& operator*(const MatrixTemplate& lh, const MatrixTemplate& rh){
        //TODO lh.colum==rh.rows
        buffer=new T[lh.rows*rh.columns];
        for(int i=0;i<lh.rows;i++)
            for(int j=0;j<rh.columns;j++){
                buffer[i+rh.columns]=0;
                for(int h=0;h<lh.columns;h++)
                    buffer[i+rh.columns]+=lh.buffer[i*lh.columns+h]*rh.buffer[h*rh.columns+j];
            }
        return *this;
    }

    MatrixTemplate& transpose(const MatrixTemplate& rh){
        buffer=new T[rh.columns*rh.rows];
        for(int i=0;i<rh.rows;i++)
            for(int j=0;j<rh.columns;j++)
                buffer[rh.columns*i+j]=rh.buffer[rh.columns*j+i];
        return *this;
    }


private:
    int rows, columns;
    T* buffer;
};


#endif //MATRICITEMPLATE_MATRIXTEMPLATE_H
