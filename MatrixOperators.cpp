#include <cmath>

#include "Matrix.h"

Matrix::Matrix() {
    width = 0, height = 0;
    matrix = nullptr;
}

Matrix::Matrix(int h, int w) {
    width = w, height = h;
    matrix = new double*[h];
    for (int i = 0; i < h; i++)
        matrix[i] = new double[w];
    for (int i = 0; i < height; i++) 
        for (int j = 0; j < width; j++)
            matrix[i][j] = 0;
}

Matrix::~Matrix() {
    for (int i = 0; i < height; i++)
        delete [] matrix[i];
    delete [] matrix;
}

bool Matrix::operator == (Matrix const &other) {
    if (!isSameSize(*this, other))
        return false;
    for (int i = 0; i < height; i++) 
        for (int j = 0; j < width; j++)
            if (matrix[i][j] != other.matrix[i][j])
                return false;
    return true;
}

Matrix Matrix::operator + (Matrix const &other) {
    if (!isSameSize(*this, other))
        return Matrix();
    Matrix res(height, width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            res.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
    return res;
}

Matrix Matrix::operator - (Matrix const &other) {
    if (!isSameSize(*this, other))
        return Matrix();
    Matrix res(height, width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            res.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
    return res;
}

Matrix Matrix::operator - () {
    Matrix res(height, width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            res.matrix[i][j] = -matrix[i][j];
    return res;
}

Matrix operator * (const double &x, Matrix const &A) {
    Matrix res(A.height, A.width);
    for (int i = 0; i < A.height; i++)
        for (int j = 0; j < A.width; j++)
            res.matrix[i][j] = x * A.matrix[i][j];
    return res;
}

Matrix operator * (Matrix const &A, const double &x) {
    return operator*(x, A);
}

Matrix Matrix::operator * (Matrix const &other) {
    if (!isMultiplicable(*this, other))
        return Matrix();
    Matrix res(height, other.width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < other.width; j++)
            for (int k = 0; k < width; k++)
                res.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
    return res;
}

Matrix transpose(Matrix const &A) {
    Matrix res(A.width, A.height);
    for (int i = 0; i < A.height; i++)
        for (int j = 0; j < A.width; j++)
            res.matrix[j][i] = A.matrix[i][j];
    return res;
}