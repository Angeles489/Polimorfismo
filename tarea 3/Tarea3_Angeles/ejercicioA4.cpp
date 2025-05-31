#include "MatrixOp.h"
#include <iostream>
using namespace std;

int main() {
    MatrixOp Diagonal(3, 3);

    // Asignar valores a la matriz (por ejemplo: M(i,j) = i*10 + j)
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j) {
            M.set(i, j, i * 10 + j);
        }
    }

    cout << "Diagonal principal: ";
    M.forEachDiagonal(&MatrixOp::printAt);

    return 0;
}
