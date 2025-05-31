/**
 * @file MatrixOp.cpp
 * @brief Implementación de MatrixOp.
 * @date YYYY-MM-DD
 * @author Angeles
 */

#include "MatrixOp.h"

#include <iostream>
#include <stdexcept>
using namespace std;

MatrixOp::MatrixOp(int rows, int cols)
    : rows_(rows), cols_(cols), data_(nullptr) {
    if (rows_ <= 0 || cols_ <= 0) {
        throw invalid_argument("Rows and Columns must be positive integers");
    }

    data_ = new double[rows_ * cols_];
    for (int i = 0; i < rows_ * cols_; ++i) {
        data_[i] = 0.0;
    }
}

MatrixOp::~MatrixOp() {
    delete[] data_;
    data_ = nullptr;
}

void MatrixOp::set(int i, int j, double v) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw out_of_range("Index out of range.");
    }
    data_[i * cols_ + j] = v;
}

double MatrixOp::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw out_of_range("Index out of bounds.");
    }
    return data_[i * cols_ + j];
}

int MatrixOp::getRows() const { return rows_; }
int MatrixOp::getCols() const { return cols_; }

void MatrixOp::add(const MatrixOp* other, MatrixOp* result) const {
    // Validar dimensiones
    if (other->rows_ != rows_ || other->cols_ != cols_ ||
        result->rows_ != rows_ || result->cols_ != cols_) {
        throw std::invalid_argument("Las dimensiones de las matrices no coinciden.");
    }

    // Sumar elemento a elemento usando índice lineal
    for (int k = 0; k < rows_ * cols_; ++k) {
        result->data_[k] = this->data_[k] + other->data_[k];
    }
}

void MatrixOp::apply(const MatrixOp* A, const MatrixOp* B, MatrixOp* out, OpFunc op) const {
    if (!A || !B || !out) {
        throw std::invalid_argument("Puntero nulo en apply.");
    }

    if (A->rows_ != B->rows_ || A->cols_ != B->cols_ ||
        A->rows_ != out->rows_ || A->cols_ != out->cols_) {
        throw std::invalid_argument("Dimensiones incompatibles en apply.");
    }

    for (int k = 0; k < rows_ * cols_; ++k) {
        out->data_[k] = op(A->data_[k], B->data_[k]);
    }
}

 // Ejercicio A4
 #include <algorithm>  // Para std::min

void MatrixOp::printAt(int i, int j) const {
    std::cout << get(i, j) << " ";
}

void MatrixOp::forEachDiagonal(void (MatrixOp::*fn)(int, int) const) const {
    int n = std::min(rows_, cols_);
    for (int i = 0; i < n; ++i) {
        (this->*fn)(i, i);
    }
    std::cout << std::endl;
}

