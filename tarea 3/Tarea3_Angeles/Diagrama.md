```mermaid
classDiagram
    class MatrixOpBase {
        <<abstract>>
        +virtual ~MatrixOpBase()
        +virtual double determinant() const = 0
    }

    class MatrixOp {
        +MatrixOp(int rows, int cols)
        +~MatrixOp()
        +double get(int i, int j) const
        +void set(int i, int j, double val)
        +void apply(const MatrixOp* A, const MatrixOp* B, MatrixOp* result, double (*op)(double, double))
        +void forEachDiagonal(void (MatrixOp::*fn)(int, int)) const
        +void printAt(int i, int j) const
        +MatrixOp operator+(const MatrixOp& other) const
        +MatrixOp operator-(const MatrixOp& other) const
        +double determinant() const
        +const double* data() const
        +int size() const
    }

    MatrixOpBase <|-- MatrixOp

    %% Relaciones de uso
    MatrixOp --> "double (*)(double,double)" : usa puntero a función
    MatrixOp --> "void (MatrixOp::*)(int,int)" : usa puntero a miembro

```
