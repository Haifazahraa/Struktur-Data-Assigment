# <h1 align="center">Laporan Praktikum Modul 8 Algoritma Serching </h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori


## Guided 

### 1. [GUIDED 1]

```C++


}
```
### 2. [GUIDED 2]

```C++


}
```

## Unguided 

### 1. [Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!]

```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk melakukan pencarian linear pada string
int linearSearch(const string& kalimat, char hurufDicari) {
    for (int i = 0; i < kalimat.length(); ++i) {
        if (kalimat[i] == hurufDicari) {
            return i; // Mengembalikan indeks jika huruf ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika huruf tidak ditemukan
}

int main() {
    string kalimat;
    char hurufDicari;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> hurufDicari;

    // Melakukan pencarian linear pada kalimat
    int hasilPencarian = linearSearch(kalimat, hurufDicari);

    if (hasilPencarian != -1) {
        cout << "Huruf '" << hurufDicari << "' ditemukan pada indeks " << hasilPencarian << " dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << hurufDicari << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}

```
#### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/4e8f18f9-9852-4a42-b559-9ad9bb68b824)

Program ini memiliki fungsi linearSearch yang menerima sebuah string dan karakter yang dicari, kemudian melakukan pencarian linear pada string tersebut. Jika karakter ditemukan, fungsi akan mengembalikan indeksnya, jika tidak, fungsi akan mengembalikan -1. Di dalam fungsi main, program meminta pengguna memasukkan sebuah kalimat dan huruf yang ingin dicari. Setelah itu, program memanggil fungsi linearSearch untuk mencari huruf tersebut dalam kalimat. Hasil pencarian ditampilkan dengan menampilkan indeks huruf jika ditemukan, atau pesan bahwa huruf tidak ditemukan jika tidak ada.

### 2. [Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!]

```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int hitungVokal(const string& teks) {
    int jumlahVokal = 0;
    for (char karakter : teks) {
        // Mengubah huruf menjadi huruf kecil untuk memudahkan perbandingan
        char huruf = tolower(karakter);
        // Memeriksa apakah karakter tersebut adalah huruf vokal
        if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u') {
            jumlahVokal++;
        }
    }
    return jumlahVokal;
}

int main() {
    string teks;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, teks);

    // Menghitung jumlah huruf vokal dalam teks
    int totalVokal = hitungVokal(teks);

    cout << "Jumlah huruf vokal dalam kalimat adalah: " << totalVokal << endl;

    return 0;
}

```
### Output
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/9752c4cb-1e3c-4d8f-b2e9-7c7027fec072)

Program ini memiliki fungsi jumlahVokal yang menerima string dan menghitung jumlah huruf vokal di dalamnya dengan mengubah setiap karakter menjadi huruf kecil dan memeriksa apakah karakter tersebut adalah vokal. Di dalam fungsi main, program meminta pengguna memasukkan kalimat, kemudian memanggil fungsi jumlahVokal untuk menghitung jumlah vokal dalam kalimat tersebut, dan akhirnya menampilkan hasilnya.

### 3. [Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!]
```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>
using namespace std;

// Fungsi untuk mencari jumlah kemunculan elemen target dalam array
int hitungKemunculan(int arr[], int panjang, int elemen) {
    int counter = 0;
    for (int i = 0; i < panjang; ++i) {
        if (arr[i] == elemen) {
            counter++;
        }
    }
    return counter;
}

int main() {
    int arr[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int panjang = sizeof(arr) / sizeof(arr[0]);
    int elemen = 4;

    // Memanggil fungsi untuk menghitung kemunculan elemen target
    int jumlah = hitungKemunculan(arr, panjang, elemen);

    cout << "Jumlah angka " << elemen << " dalam array adalah: " << jumlah << endl;

    return 0;
}

```
### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/90835d17-0baf-4f90-96c6-f2697a5ffaab)

Program ini memiliki fungsi hitungKemunculan yang menerima array, panjang array, dan elemen target, kemudian menghitung dan mengembalikan jumlah kemunculan elemen target dalam array. Di dalam fungsi main, program menginisialisasi array, menghitung panjang array, menentukan elemen target, lalu memanggil fungsi hitungKemunculan untuk menghitung kemunculan elemen target. Hasilnya ditampilkan di layar, menunjukkan berapa kali angka 4 muncul dalam array.

### Kesimpulan 

### Referensi
[1] 
