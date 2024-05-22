# <h1 align="center">Laporan Praktikum Modul 8 Algoritma Serching </h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori
Data Searching adalah proses yang ada dan dibutuhkan dalam pembangun-an sebuah aplikasi, ada banyak algoritma yang bisa diterapkan namun tidak semua algoritma memiliki efisiensi yang baik selama algoritma itu berjalan. Untuk data yang sedikit mungkin perbedaannya belum terlalu besar, namun saat ini perkembangan data juga semakin berkembang yang biasa disebut Big Data. Big Data adalah sekumpulan data yang sangat besar bisa terdiri dari data text, numerik ataupun multimedia yang disimpan dalam sebuah database tertentu.

Ada beberapa algoritma yang bisa digunakan untuk melakukan pencarian, salah satunya adalah SequentialSearch, yaitu  algoritma yang dasar dan simpel dari pencarian, dimana menggunakan metode pencarian data dari paling awal hingga paling akhir dari sebuah list sampai  data  ditemukan. Selain itu ada algoritma BinarySearch, yaitu sebauh listyang sudah terurut kemudian dibagi menjadi dua bagian. Awalnya adalah membandingkan inputan dengan nilai tengah, selanjutnya dibandingkan ke kanan atau ke kiri sesuai dengan urutan listnya.

A. SequentialSearch

SequentialSearch adalah cara untuk  pencarian  data  dalam  array  1 dimensi. Data yang akan dicari nanti akan ditelusuri dalam semua elemen-elemen array dari awal sampai akhir, dan data yang dicari tersebut tidak perlu diurutkan terlebih dahulu. Terdapat 2 kemungkinan yang akan terjadi dalam waktu pencarian data SequentialSearch, antara lain:

1. Best CaseBest case   

kemungkinan terbaik akan terjadi apabila data yang dicari terletak pada index array yang paling depan, sehingga waktu yang dibutuhkan untuk mencari data sedikit. 

2. Worse CaseWorse  case

kemungkinan terburuk akan terjadi apabila data yang dicari terletak pada index array yang paling akhir, sehingga waktu yang dibutuhkan untuk mencari data akan sangat lama.

B. Binary Search 

adalah cara untuk pencarian data pada array yang sudah terurut. karena salah satu syarat dalam BinarySearch adalah data sudah dalam keadaan terurut dengan kata lain apabila data belum   dalam keadaan terurut, pencarian Binary tidak dapat dilakukan BinarySearchini dilakukan untuk

1. Memperkecil jumlah operasi perbandingan yang harus dilakukan antara data yang dicari dengan data yang ada didalam tabel, khususnya untuk jumlah data yang sangat besar ukurannya.

2. Beban komputasi lebih kecil karena pencarian dilakukan dari depan, belakang dan tengah.

3. Prinsip dasarnya adalah melakukan proses pembagian ruang pencarian secara  berulang-ulang sampai data ditemukan atau sampai pencarian tidak  dapat dibagi Lagi (berarti terdapat kemungkinan data  tidak dtiemukan)[1]

## Guided 

### 1. [GUIDED 1]

```C++
#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "\tProgram Sequential Search Sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu) {
        cout << "\nangka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}

}
```
Program di atas mencari nilai 10 dalam sebuah array menggunakan algoritma pencarian berurutan (sequential search). Array berisi 10 elemen, dan nilai yang dicari adalah 10. Program melakukan iterasi melalui setiap elemen array dan membandingkannya dengan nilai yang dicari. Jika nilai ditemukan, variabel `ketemu` diatur menjadi true dan loop dihentikan. Program kemudian mencetak pesan apakah nilai tersebut ditemukan atau tidak beserta indeks di mana nilai tersebut berada jika ditemukan.

### 2. [GUIDED 2]

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (dataArray[j] < dataArray[min]) {
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void binarysearch() {
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6; // Corrected to 6 to match array bounds
    while (!b_flag && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari) {
            b_flag = true;
        } else if (dataArray[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if (b_flag) {
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    // Display initial data
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    cout << "\nData diurutkan: ";
    // Sort data with selection sort
    selection_sort();
    // Display data after sorting
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    binarysearch();
    _getche();
    return 0;
}

}
```
Program di atas melakukan pencarian biner pada array yang telah diurutkan. Pertama, data awal array ditampilkan, kemudian pengguna diminta memasukkan nilai yang ingin dicari. Program ini menggunakan algoritma selection sort untuk mengurutkan array secara ascending. Setelah array diurutkan, data yang telah diurutkan ditampilkan. Selanjutnya, algoritma binary search digunakan untuk mencari nilai yang dimasukkan oleh pengguna. Jika nilai ditemukan, program akan menampilkan indeks posisi data tersebut dalam array; jika tidak, program akan memberi tahu bahwa data tidak ditemukan.

### 3. [GUIDED 3]

```C++
#include <iostream>
using namespace std;

int arr[]={1,2,3,4,5,6,7,8,9,10,15,14};
int cari = 15;
bool ketemu = false;
int panjangArray = sizeof(arr)/sizeof(arr[0]);
int i;

int main()
{
    for (i = 0; i < panjangArray; i++){
        if(arr[i] == cari) {
            ketemu = true;
            break;
        } else {
            i++;
        }
    }

    cout << "Panjang Array : " << panjangArray <<endl;
    cout << cari << " Terdapat pada index ke- " << i;
}

}
```
Program di atas mencari nilai 15 dalam sebuah array menggunakan pencarian linear. Array berisi 12 elemen, dan variabel cari berisi nilai yang dicari, yaitu 15. Variabel ketemu digunakan sebagai indikator apakah nilai tersebut ditemukan atau tidak. Program menghitung panjang array menggunakan ukuran byte array dibagi ukuran byte elemen pertama. Dalam fungsi mai, program melakukan iterasi melalui elemen array dan membandingkan setiap elemen dengan nilai yang dicari. Jika nilai ditemukan, variabel `ketemu` diatur menjadi true dan loop dihentikan. Program kemudian mencetak panjang array dan indeks tempat nilai yang dicari ditemukan.

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
Algoritma Searching merupakan algoritma yang sangat penting dalam pengelolaan sistem manajemen database. Data yang besar (Big  Data) perlu diolah untuk memudahkan dalam pencarian data. Dari pembahasan diatas, kami membandingkan beberapa algoritma Searchingseperti SequentialSearch dan BinarySearch dengan mengimplementasi-kan dalam  berbagai segi  antara lain konsep,   algoritma, koding  dan kompleksitas  waktu. Dari percobaan dengan menggunakan bahasa phyton, dapat disimpulkan algoritma SequentialSearch memiliki komplek-sitas waktu lebih besar    dibanding dengan BinarySearch.

### Referensi
[1]https://www.jurnal.pelitabangsa.ac.id/index.php/pelitatekno/article/view/232/184
