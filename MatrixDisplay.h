#include <string>

#include "Matrix.h"

using std::string;

const string upperRight = "┐";
const string lowerLeft = "└";
const string horizontal = "─";
const string lowerRight = "┘";
const string upperLeft = "┌";
const string vertical = "│";

void displayMatrix(Matrix const &A);
std::istream& operator >> (std::istream &is, Matrix const &A);
std::ostream& operator << (std::ostream& os, Matrix const &A);