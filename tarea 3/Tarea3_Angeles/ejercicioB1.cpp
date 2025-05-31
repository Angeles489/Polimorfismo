#include <iostream>
#include "MatrixOp.h"

int main() {
      cout << "Ejercicio B1: Sobrecarga de operador +." << endl;
    MatrixOp A_S(2, 2);
    MatrixOp B_S(2, 2);

// Inicializar A y B con valores de ejemplo
A_S.set(0, 0, 1);
A_S.set(0, 1, 2);
A_S.set(1, 0, 3);
A_S.set(1, 1, 4);

B_S.set(0, 0, 5);
B_S.set(0, 1, 6);
B_S.set(1, 0, 7);
B_S.set(1, 1, 8);

// Realizar suma y resta
MatrixOp C_S = A_S + B_S;
MatrixOp D_S = A_S - B_S;

// Mostrar algunos resultados
std::cout << "C[0,0] = " << C_S.get(0, 0) << "\n";  
std::cout << "D[1,1] = " << D_S.get(1, 1) << "\n";  

    return 0;
}
