#include <iostream>

#include "MatrixOp.h"

using namespace std;


int main() {
   try {
        MatrixOp A(2, 2);
        MatrixOp B(2, 2);
        MatrixOp C(2, 2);  // Resultado

        // Inicializar A
        A.set(0, 0, 1.0);
        A.set(0, 1, 2.0);
        A.set(1, 0, 3.0);
        A.set(1, 1, 4.0);

        // Inicializar B
        B.set(0, 0, 10.0);
        B.set(0, 1, 20.0);
        B.set(1, 0, 30.0);
        B.set(1, 1, 40.0);

        // Sumar A + B → C
        A.add(&B, &C);

        // Imprimir C
        cout << "Resultado de A + B:" << endl;
        for (int i = 0; i < C.getRows(); ++i) {
            for (int j = 0; j < C.getCols(); ++j) {
                cout << C.get(i, j) << " ";
            }
            cout << endl;
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
