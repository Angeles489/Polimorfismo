#include "MatrixOp.h"
#include <iostream>
using namespace std;

int main() {
    MatrixOp DiagonalM(3, 3);

    // Asignar valores a la matriz (por ejemplo: M(i,j) = i*10 + j)
    for (int i = 0; i < DiagonalM.getRows(); ++i) {
        for (int j = 0; j < DiagonalM.getCols(); ++j) {
            DiagonalM.set(i, j, i * 10 + j);
        }
    }

    cout << "Diagonal principal: ";
    DiagonalM.forEachDiagonal(&MatrixOp::printAt);

    return 0;
}
