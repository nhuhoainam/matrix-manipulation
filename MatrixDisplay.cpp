#include <iostream>

#include "Matrix.h"
#include "MatrixDisplay.h"

using std::cin;
using std::cout;
using std::endl;

void Display(Matrix const &A) {
    for (int i = 0; i < A.height; i++) {
        for (int j = 0; j < A.width; j++)
            cout << A.matrix[i][j] << ' ';
        cout << endl;
    }
}

std::istream& operator >> (std::istream &is, Matrix &A) {
    cout << "Enter matrix entries: ";
    for (int i = 0; i < A.height; i++)
        for (int j = 0; j < A.width; j++)
            is >> A.matrix[i][j];
    return is;
}

std::ostream& operator << (std::ostream &os, Matrix const &A) {
    for (int i = 0; i < A.height; i++) {
        os << (!i ? upperLeft : (i == A.height-1 ? lowerLeft: vertical)) << ' ';
        for (int j = 0; j < A.width; j++) 
            os << A.matrix[i][j] << ' ';
        os << (!i ? upperRight : (i == A.height-1 ? lowerRight: vertical)) << endl;
    }
    return os;
}