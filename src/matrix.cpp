#include <iostream>
#include <stdio.h>
#include <fstream>
#include "matrix.hpp"

using namespace std;

Matrix::Matrix(int n, int m){
    if(n==0 || m==0) 
        cout << "Nie mozna utworzyc macierzy" << endl;
    else {
        wiersze = n;
        kolumny = m;
        matrix = new double* [n];
        for(int i=0; i<n; i++)
           matrix[i] = new double[m];
        for (int i=0; i<n; i++) {
           for (int j=0; j<m; j++) {
               matrix[i][j] = 0;
           }
        }
    }
}

Matrix::Matrix(int n){
    if(n==0) {
        cout << "Nie mozna utworzyc macierzy" << endl;
    }
    else {
        wiersze = n;
        kolumny = n;
        matrix = new double* [n];
        for (int i = 0; i < n; i++)
            matrix[i] = new double[n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                matrix[i][j] = 0;
            }
        }
    }
}

void Matrix::store(std::string filename, std::string path) {
    std::fstream plik;
    plik.open(path + filename, std::ios::out);
    if (plik.good() == true) {
        plik << kolumny << " " << wiersze << "\n";
        for (int i = 0; i < kolumny; i++) {
            for (int j = 0; j < wiersze; j++) {
                plik << matrix[i][j] << " ";
            }
            plik << "\n";
        }
        plik.close();
    }
    else {
        cout << "Nie można otworzyć pliku";
    }   
}

void Matrix::set(int n, int m, double val) {
    if ((n > wiersze) || (m > kolumny)){
        cout << "Błędne dane" << endl;
    }
    else{
        matrix[n - 1][m - 1] = val;
    }
}

double Matrix::get(int n, int m){
    if ((n > wiersze) || (m > kolumny)){
        cout << "Błędne dane" << endl;
    }
    else{
        return matrix[n - 1][m - 1];     
    }
}

Matrix Matrix::add(Matrix& m2){
    if ((wiersze == m2.wiersze) && (kolumny == m2.kolumny)){
        Matrix suma(wiersze, kolumny);
        for (int i = 0; i < wiersze; i++){
            for (int j = 0; j < kolumny; j++){
                suma.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
            }
        }
        return suma;
    }
    else{
        cout << "Macierze nie są takich samych rozmiarów" << endl;
    }
}

Matrix Matrix::subtract(Matrix& m2){
    if ((wiersze == m2.wiersze) && (kolumny == m2.kolumny)){
        Matrix wynik(wiersze, kolumny);
        for (int i = 0; i < wiersze; i++){
            for (int j = 0; j < kolumny; j++){
                wynik.matrix[i][j] = matrix[i][j] - m2.matrix[i][j];
            }
        }
        return wynik;
    }
    else{
        cout << "Macierze nie mają takich samych rozmiarów" << endl;
    }
}

Matrix Matrix::multiply(Matrix& m2){
    if ((wiersze == m2.wiersze) && (kolumny == m2.kolumny)) {
        Matrix wynik(wiersze,kolumny);
        for (int i = 0; i < wiersze; i++) {
            for (int j = 0; j < kolumny; j++) {
                wynik.matrix[i][j] = matrix[i][j] * m2.matrix[i][j];
            }
        }
        return wynik;
    }
    else {
        cout << "Macierze nie mają takich samych rozmiarów" << endl;
    }
}

int Matrix::cols(){
    return kolumny;
}

int Matrix::rows(){
    return wiersze;
}

void Matrix::print(){
    for (int i = 0; i < wiersze; i++){
        for (int j = 0; j < kolumny; j++){
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
};