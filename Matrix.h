#pragma once

#include <iostream>

class Matrix {
private:
    double **matrix;
    int width, height;
public:
    Matrix();
    Matrix(int w, int h);
    ~Matrix();
    friend bool isSameSize(Matrix const &A, Matrix const &B);
    bool operator == (Matrix const &other);
    Matrix operator + (Matrix const &other);
    Matrix operator - (Matrix const &other);
    Matrix operator - ();
    friend Matrix operator * (const double &x, Matrix const &A);
    friend Matrix operator * (Matrix const &A, const double &x);
    Matrix operator * (Matrix const &other);
    friend bool isMultiplicable(Matrix const &A, Matrix const &B);
    friend Matrix transpose(Matrix const &A);
    friend std::ostream& operator << (std::ostream& os, Matrix const &A);
    friend std::istream& operator >> (std::istream &is, Matrix &A);
    friend void Display(Matrix const &A);
};

Matrix transpose(Matrix const &A);
Matrix operator * (const double &x, Matrix const &A);
Matrix operator * (Matrix const &A, const double &x);
bool isSameSize(Matrix const &A, Matrix const &B);
bool isMultiplicable(Matrix const &A, Matrix const &B);