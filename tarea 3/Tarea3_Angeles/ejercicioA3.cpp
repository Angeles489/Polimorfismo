#include <iostream>
#include "MatrixOp.h"

using namespace std;

// Funciones auxiliares requeridas por apply
double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

int main() {
    MatrixOp A(2, 2);
    MatrixOp B(2, 2);
    MatrixOp C(2, 2); // Resultado de A - B
    MatrixOp D(2, 2); // Resultado de A * B

    // Inicializamos A y B manualmente
    A.set(0, 0, 1); A.set(0, 1, 2);
    A.set(1, 0, 3); A.set(1, 1, 4);

    B.set(0, 0, 5); B.set(0, 1, 6);
    B.set(1, 0, 7); B.set(1, 1, 8);

    // Aplicamos operaciones
    A.apply(&A, &B, &C, sub);
    A.apply(&A, &B, &D, mul);

    // Imprimimos resultados
    cout << "C = A - B:" << endl;
    for (int i = 0; i < C.getRows(); ++i) {
        for (int j = 0; j < C.getCols(); ++j) {
            cout << C.get(i, j) << " ";
        }
        cout << endl;
    }

    cout << "D = A * B:" << endl;
    for (int i = 0; i < D.getRows(); ++i) {
        for (int j = 0; j < D.getCols(); ++j) {
            cout << D.get(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
