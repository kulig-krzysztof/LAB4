  
#include <iostream>

using namespace std;

class Matrix{
private:
    double** matrix;
    int wiersze;
    int kolumny;
public:
    Matrix(int n, int m);
    Matrix(int n);
    void store(std::string filename, std::string path);
    ~Matrix() { };
    void set(int n, int m, double val);
    double get(int n, int m);
    Matrix add(Matrix& m2);
    Matrix subtract(Matrix& m2);
    Matrix multiply(Matrix& m2);  
    int cols();
    int rows();
    void print();
};