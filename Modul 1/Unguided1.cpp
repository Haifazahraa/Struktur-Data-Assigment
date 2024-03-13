#include <iostream>
using namespace std;

int hitung_faktorial(int n) {
    int faktorial = 1;
    for (int i = 1; i <= n; ++i) {
        faktorial *= i;
    }
    return faktorial;
}

cek_prima(int angka) {
    if (angka <= 1) {
        return false;
    }
    for (int i = 2; i < angka; ++i) {
        if (angka % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, angka;

    cout << "Masukkan bilangan untuk menghitung faktorial: ";
    cin >> n;

    int hasil_faktorial = hitung_faktorial(n);
    cout << "Faktorial dari " << n << " adalah: " << hasil_faktorial << endl;

    cout << "Masukkan sebuah bilangan untuk diperiksa apakah prima atau bukan: ";
    cin >> angka;

    if (cek_prima(angka)) {
        cout << angka << " adalah bilangan prima" << endl;
    } else {
        cout << angka << " bukan bilangan prima" << endl;
    }

    return 0;
}
