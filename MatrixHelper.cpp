#include "Matrix.h"

bool isSameSize(Matrix const &A, Matrix const &B) {
    return (A.width == B.width && A.height == B.height);
}

bool isMultiplicable(Matrix const &A, Matrix const &B) {
    return A.width == B.height;
}