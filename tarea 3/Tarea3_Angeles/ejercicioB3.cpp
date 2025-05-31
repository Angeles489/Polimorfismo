#include <iostream>
#include "MatrixOp.h"

int main() {
    // Crear puntero a IMatrix apuntando a MatrixOp
    IMatrix *mat = new MatrixOp(2, 2);

    // Convertimos a MatrixOp para poder usar set()
    MatrixOp *m = dynamic_cast<MatrixOp*>(mat);
    if (m) {
        m->set(0, 0, 1);
        m->set(0, 1, 2);
        m->set(1, 0, 3);
        m->set(1, 1, 4);
    }

    std::cout << "Determinante: " << mat->determinant() << "\n";

    delete mat;
    return 0;
}
