#pragma once

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
};

Matrix operator * (const double &x, Matrix const &A);
Matrix operator * (Matrix const &A, const double &x);
bool isSameSize(Matrix const &A, Matrix const &B);
bool isMultiplicable(Matrix const &A, Matrix const &B);