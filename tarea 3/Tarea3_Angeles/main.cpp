/**
 * @file main.cpp
 * @brief Punto de entrada del programa.
 * @date YYYY-MM-DD
 */

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
    cout << "Inicio del programa." << endl;

    // Ejercicio A1
    cout << "Ejercicio A1: Creacion de una matriz." << endl;
    MatrixOp M(3, 3);

    // Mostrar todos los elementos de la matriz
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j) {
            cout << M.get(i, j) << " ";
        }
        cout << endl;
    }

    // Mostrar el número de filas y columnas
    cout << "Numero de filas: " << M.getRows() << endl;
    cout << "Numero de columnas: " << M.getCols() << endl;

    //Ejercicio A2
    cout << "Ejercicio A2: Suma de matrices." << endl;
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
    cout << "Fin del programa." << endl;

    // Ejercicio A3
    cout << "Ejercicio A3: Aplicacion de operacion en matrices." << endl;
// Definir operaciones
    // Crear matrices A, B y resultados C y D
MatrixOp A(3, 3);
MatrixOp B(3, 3);
MatrixOp C(3, 3);  // Resultado de A - B
MatrixOp D(3, 3);  // Resultado de A * B

// Llenar A y B con algunos valores de ejemplo
for (int i = 0; i < A.getRows(); ++i) {
    for (int j = 0; j < A.getCols(); ++j) {
        A.set(i, j, i + j);  // Por ejemplo: A(i,j) = i + j
        B.set(i, j, i * j);  // Por ejemplo: B(i,j) = i * j
    }
}

// Aplicar las operaciones
A.apply(&A, &B, &C, sub);
A.apply(&A, &B, &D, mul);

// Imprimir resultados
cout << "\nMatriz C = A - B\n";
for (int i = 0; i < C.getRows(); ++i) {
    for (int j = 0; j < C.getCols(); ++j) {
        cout << C.get(i, j) << " ";
    }
    cout << endl;
}

cout << "\nMatriz D = A * B\n";
for (int i = 0; i < D.getRows(); ++i) {
    for (int j = 0; j < D.getCols(); ++j) {
        cout << D.get(i, j) << " ";
    }
    cout << endl;
}


    return 0;  // Indicar que el programa terminó correctamente
}