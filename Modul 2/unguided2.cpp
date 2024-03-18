#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    cout << "Masukkan jumlah blok array: ";
    cin >> x;
    cout << "Masukkan jumlah baris array: ";
    cin >> y;
    cout << "Masukkan jumlah elemen array: ";
    cin >> z;

    int ***arr = new int**[x];
    for (int i = 0; i < x; i++) {
        arr[i] = new int*[y];
        for (int j = 0; j < y; j++) {
            arr[i][j] = new int[z];
        }
    }

    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Array[" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "Elemen-elemen array yang dimasukkan:\n";
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                cout << "Array[" << i << "][" << j << "][" << k << "]: " << arr[i][j][k] << endl;
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
