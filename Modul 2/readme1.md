# <h1 align="center">Laporan Praktikum Modul 2 Array</h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori
# Pengertian
Array adalah kumpulan-kumpulan variabel yang menyimpan data dengan tipe yang sama atau data-data yang tersusun secara linear dimana di dalamnya terdapat elemen dengan tipe yang sama. Indeks dalam array menyatakan elemen yang disimpan dan panjang atau length menyatakan total elemen yang tersimpan.
# jenis-jenis Array Adalah
1. Array satu dimensi adalah jenis array dasar yang terdiri dari beberapa kolom elemen. Dalam satu baris tersusun dari beberapa elemen-elemen yang sama. Keunggulan dari array satu dimensi adalah mudah digunakan dan mudah dibaca sehingga paling umum digunakan.

2. Array dua dimensi merupakan perluasan dari array satu dimensi sehingga array dua dimensi terdiri dari kolom dan baris atau berbentuk matrix. Maka harus perhatikan nomor baris dan kolom.Kelebihan dari array dua dimensi yaitu dapat menyimpan data yang lebih kompleks.

3. Array multidimensi digunakan untuk ke array yang lebih dari dua dimensi atau lebih. Bentuknya memiliki banyak dimensi sehingga untuk menentukan posisi elemen data tidak menggunakan indeks namun menggunakan key atau string. String merupakan array dari karakter.

## Guided 

### 1. [Program Input Array Tiga Dimensi]

```C++
#include <iostream>
using namespace std;
//PROGRAM INPUR ARRAY 3 DIMENSI 
int main()
{
    //Deklarasi Array
    int arr[2] [3] [3];
    //Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "] [" << y << "] [" << z << "] =";
                cin >> arr[x] [y] [z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array [" << x << "] [" << y << "] [" << z << "] = " << arr[x] [y] [z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilkan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x] [y] [z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Program di atas adalah contoh implementasi array tiga dimensi dalam bahasa pemrograman C++. Array arr dideklarasikan dengan ukuran 2 x 3 x 3, yang berarti terdiri dari dua blok, masing-masing blok memiliki tiga baris, dan setiap baris memiliki tiga elemen.
Pertama-tama, program meminta pengguna untuk menginput nilai elemen-elemen array tersebut menggunakan nested loop dengan variabel x, y, dan z. Selanjutnya, program mencetak nilai elemen-elemen array yang telah dimasukkan. Program juga mencetak kembali seluruh elemen array dalam format yang lebih terstruktur, dengan setiap elemen dipisahkan dalam satu baris.Dengan demikian, program ini memberikan contoh penggunaan array tiga dimensi secara praktis dalam bahasa pemrograman C++.

### 2. [Program Mencari Nilai Maksimal pada Array]

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nailai maksimun adalah" << maks << "berada di Arrray ke " << lokasi << endl;
}

```
Program C++ di atas meminta pengguna untuk memasukkan panjang array dan elemen-elemen array. Setelah pengguna selesai memasukkan nilai-nilai tersebut, program akan mencari nilai maksimum dari array bersama dengan lokasinya. Program ini menggunakan loop for untuk memproses input pengguna dan melakukan perbandingan nilai array dengan nilai maksimum yang telah ditentukan sebelumnya. Hasilnya, program akan mencetak nilai maksimum beserta lokasinya dalam array. Program ini memberikan contoh yang jelas tentang bagaimana menggunakan array dan melakukan operasi sederhana seperti mencari nilai maksimum dalam array dalam bahasa pemrograman C++.

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];

    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "Elemen array ganjil:\n";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    cout << "Elemen array genap:\n";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

```
#### Output:
![Capture7](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/9dcbd0a8-7632-413f-a631-f45ca87b4ba9)

Berikut adalah contoh program C++ yang meminta pengguna untuk menginput jumlah elemen array (n) dan nilai-nilai elemen array sebanyak n kali. Setelah itu, program akan mencetak elemen array ganjil dan genap secara terpisah. Elemen-elemen ganjil akan dicetak terlebih dahulu, diikuti oleh elemen-elemen genap. Program ini memberikan contoh penggunaan array untuk memisahkan elemen ganjil dan genap dari input pengguna.

#### Full code Screenshot:
![Capture8](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/05294688-370b-4045-980b-b9800e5236a2)


### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

```C++
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

```
#### Output:
![Capture14](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/9967ed98-f3c7-40be-8e83-8b1d700cf7a7)

Program ini menggunakan array dinamis untuk mengalokasikan memori secara dinamis sesuai dengan ukuran array yang dimasukkan oleh pengguna. Hal ini memungkinkan program untuk menggunakan array tiga dimensi dengan jumlah elemen yang diinputkan oleh pengguna. Setelah selesai digunakan, program juga menghapus memori yang telah dialokasikan untuk array dinamis.

#### Full code Screenshot:
![Capture15](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/c2044018-9d8c-4bdd-bc7b-50abfc60e152)

![Capture16](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/f383039d-58ef-4af9-a9a0-ddb881a04988)


### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << (i + 1) << ": ";
        cin >> arr[i];
    }

    int choice;
    cout << "Pilih operasi:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Hitung nilai rata-rata\n";
    cin >> choice;

    switch (choice) {
        case 1:
            {
                int max_val = *max_element(arr.begin(), arr.end());
                cout << "Nilai maksimum: " << max_val << endl;
            }
            break;
        case 2:
            {
                int min_val = *min_element(arr.begin(), arr.end());
                cout << "Nilai minimum: " << min_val << endl;
            }
            break;
        case 3:
            {
                int sum = 0;
                for (int num : arr) {
                    sum += num;
                }
                double avg = static_cast<double>(sum) / n;
                cout << "Nilai rata-rata: " << avg << endl;
            }
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }

    return 0;
}

```
#### Output:
![Capture9](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/7cde1085-80b6-4918-9842-125534102689)
![Capture10](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/d931ba7b-046d-45c5-9e2c-388381916e5b)
![Capture11](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/14542f05-821e-495d-ba5b-671647af347c)

Program ini menggunakan library <algorithm> dan <vector> untuk menyederhanakan proses mencari nilai maksimum dan minimum dengan fungsi max_element dan min_element dari STL (Standard Template Library). Program juga menggunakan vektor vector<int> untuk menyimpan elemen-elemen array dengan jumlah yang fleksibel sesuai input pengguna.

#### Full code Screenshot:
![Capture12](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/1095fa50-48fa-46fa-9ccd-2ce9ba6f5968)
![Capture13](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/a1e319ce-9313-4f94-b71d-55dfc3046302)


## Kesimpulan
Kesimpulannya, array adalah struktur data yang penting dalam pemrograman karena memungkinkan penyimpanan data dalam format yang terstruktur dan mudah diakses. Array dapat digunakan dalam berbagai konteks, baik itu untuk menyimpan data sederhana maupun data yang lebih kompleks.

## Referensi
https://itbox.id/blog/array-adalah/
