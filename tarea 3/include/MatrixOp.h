#ifndef MATRIXOP_H
#define MATRIXOP_H

class MatrixOp {
   public:
    MatrixOp(int rows, int cols);
    ~MatrixOp();
    void add(const MatrixOp* other, MatrixOp* result) const;

    void set(int i, int j, double v);
    double get(int i, int j) const;

    int getRows() const;
    int getCols() const;

    // Puntero a funcion A3
    using OpFunc = double (*)(double, double);

    // Ejercicio A3
    void apply(const MatrixOp* A, const MatrixOp* B, MatrixOp* out, OpFunc op) const;

    //Ejercicio A4
    void forEachDiagonal(void (MatrixOp::*fn)(int, int) const) const;

    void printAt(int i, int j) const;

    //Ejercicio B1
     MatrixOp operator+(const MatrixOp &other) const;

    // Resta elemento a elemento: devuelve una nueva matriz
    MatrixOp operator-(const MatrixOp &other) const;

   private:
    int rows_, cols_;
    double* data_;
};

#endif  // MATRIXOP_H