#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <matrix.hpp>

int main(){
    Matrix m1(5,6); // tworzenie dwoch macierzy 5x6
    Matrix m2(5,6);
    Matrix m3(3); // tworzenie macierzy kwadratowej 3x3
    m3.print();
    cout << endl;
    m1.set(1,1,5); // zmiana wartości pierwszej komórki macierzy m1 na 5
    cout << m1.get(1,1) << endl; // wyświetlanie pierwszej komórki macierzy m1
    m2.set(1,1,6); // zmiana wartości pierwszej komórki macierzy m2 na 6
    m1.multiply(m2).print(); // mnożenie macierzy m1 oraz m2
    cout << endl;
    m1.add(m2).print(); // dodawanie macierzy m1 oraz m2
    cout << endl;
    m1.subtract(m2).print(); // odejmowanie macierzy m2 od m1
    cout << endl;
    cout << m1.cols() << endl; // wyświetlanie liczby kolumn macierzy m1
    cout << m1.rows() << endl; // wyświetlanie liczby wierszy macierzy m1
    m1.store("macierz.txt","../"); // zapisywanie liczby macierzy m1 do pliku
    m1.print(); // wyświetlanie macierzy m1
}
