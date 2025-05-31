#ifndef MATRIXOP_H
#define MATRIXOP_H
#include <stdexcept>

// Ejercicio B3
class IMatrix {
public:
    virtual ~IMatrix() = default;
    virtual double determinant() const = 0;
};

class MatrixOp : public IMatrix {
   public:
   double determinant() const override;
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

    const double* data() const { return data_; }
    int size() const { return rows_ * cols_; }


   private:
    int rows_, cols_;
    double* data_;
};

    //Ejercicicio B2
    template<typename T>
    T maxValue(const T *arr, int n) {
    if (n <= 0) throw std::invalid_argument("Array vacío");

    T max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

#endif  // MATRIXOP_H