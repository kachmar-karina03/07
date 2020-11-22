// Lab_7_2.cpp
// < Качмар Каріни >
// Лабораторна робота No 7.2
 // Варіант 21
//Написати програму, яка міняє місцями елементи парних рядків матриці (nxn) так, щоб
//максимальні елементи по парних рядках розмістилися на головній діагоналi


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int UnitTest(int* a, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        S += a[i];
    return S;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    srand((int)time(0));

    int n, jmax;
    cout << "Квадратна матриця з елементами nxn, введіть n:"; cin >> n;

    double** a = new double* [n];
    for (int i = 0; i < n; i++)
        a[i] = new double[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 9 + 1;
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    for (int i = 1; i < n; i += 2)
    {
        jmax = 0;
        for (int j = 1; j < n; j++)
            if (a[i][j] > a[i][jmax]) jmax = j;
        swap(a[i][i], a[i][jmax]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        delete[]a[i];
        delete[]a;
    }

    system("pause");
    return 0;
}