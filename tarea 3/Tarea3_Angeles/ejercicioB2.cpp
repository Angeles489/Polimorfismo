#include <iostream>

#include "MatrixOp.h"

using namespace std;

   double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}


int main() {
// Ejercicio B2
    cout << "\nEjercicio B2: Valor máximo en matriz\n";
    MatrixOp M(3, 3);
    
    double maxElem = maxValue<double>(M.data(), M.size());
    cout << "Máximo elemento de M: " << maxElem << "\n";

    return 0;  // Indicar que el programa terminó correctamente
}