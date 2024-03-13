# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori
## Tipe Data

## A. Pengertian
Tipe data memfasilitasi program dalam mengenali beragam jenis informasi, yang secara efektif memastikan sistem operasi berjalan dengan baik dan mengurangi kemungkinan kesalahan (error).
Secara mendasar, komputer hanya dapat memproses informasi dalam bahasa biner, yaitu menggunakan representasi 1 dan 0. Untuk menjalankan operasi yang lebih kompleks, tipe data yang dapat dimengerti oleh bahasa pemrograman diperlukan.

## B. Macam - Macam Tipe Data
 1. Tipe Data Primitif
   Tipe data primitif, sebagaimana namanya, merupakan jenis tipe data yang sederhana. Jenis data ini mampu menyimpan satu nilai tunggal, seperti digit, byte, atau karakter.
   Namun, tipe data primitif tidak mampu menangani data yang kompleks dengan tingkat kerumitan yang tinggi. Ada beberapa macam tipedata primitif antara lain:
   
    a. Integer atau bilangan bulat adalah tipe data primitif yang digunakan untuk angka tanpa pecahan. Artinya tipe data ini tidak memiliki pecahan desimal. Bilangan bulat bisa berupa negatif atau positif
   
    b. Floating point adalah tipe data numerik yang menyatakan angka dengan nominal pecahan

    c. Character adalah tipe data yang digunakan untuk menyatakan satu angka huruf atau special character

    d. String adalah tipe data yang menyatakan rangkaian character angka atau simbol–dan selalu diperlakukan sebagai teks. karena itu meski dalam keadaan berbentuk numerik sekalipun tipe data string tidak bisa dipakai untuk operasi perhitungan matematis
   
2. Tipe Data Abstrak (ADT) adalah konsep pemrograman yang mendefinisikan tampilan struktur data tingkat tinggi, tanpa menentukan detail implementasi. Dengan kata lain, ini adalah cetak biru untuk membuat struktur data yang mendefinisikan perilaku dan antarmuka struktur, tanpa menentukan bagaimana implementasinya.
ADT dalam struktur data dapat dianggap sebagai sekumpulan operasi yang dapat dilakukan pada sekumpulan nilai. Rangkaian operasi ini sebenarnya mendefinisikan perilaku struktur data, dan digunakan untuk memanipulasi data dengan cara yang sesuai dengan kebutuhan program.
ADT sering digunakan untuk menghilangkan kompleksitas struktur data dan menyediakan antarmuka yang sederhana dan intuitif untuk mengakses dan memanipulasi data. Hal ini memudahkan pemrogram untuk memikirkan struktur data, dan menggunakannya dengan benar dalam program mereka.

3. Tipe Data Koleksi adalah tipe data yang berupa rangkaian atau kumpulan data yang berindeks. Terdapat tiga tipe dasar koleksi di Java yaitu:

    a. Array : koleksi statis dengan ukuran tetap dan hanya bisa mengelompokkan tipe data yang sama.

    b. List : koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda.
  
    c. Map : koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda dengan menggunakan pasangan <key, value>.

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char op;
    float num1, num2;

    
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
   
    cout << "Enter two operands: ";
    cin>>num1>>num2;

    switch (op) {
// If user enters +
    case '+':
        cout << "Result: " << num1 + num2;
        break;
// If user enters -
    case '-':
        cout << "Result: " << num1 - num2;
        break;
// If user enters *
    case '*':
        cout << "Result: " << num1 * num2;
        break;
// If user enters /
    case '/':
    if (num2 != 0) {
        cout << "Result: " << fixed << setprecision(2) <<num1 / num2;
    } else {
        cout << "Error! Division by zero is not allowed.";
    }
    break;

default:
    cout << "Error! Operator is not correct";
} 
return 0;
}

```
Program di atas adalah sebuah kalkulator sederhana yang meminta pengguna memasukkan operator dan dua operan, kemudian melakukan operasi aritmatika sesuai dengan operator yang dimasukkan. Pengguna diminta untuk memasukkan operator dan dua angka, kemudian program akan menampilkan hasil operasi tersebut. Program ini menyediakan fungsi dasar seperti penjumlahan, pengurangan, perkalian, dan pembagian.
### 2. [Tipe Data Abstrak]

```C++
#include <stdio.h>
#include <string.h>

//Struct
struct Mahasiswa
{
    char name[50];
    char address[100];
    int age;
};
int main()
{

// menggunakan struct
struct Mahasiswa mhs1, mhs2;
// mengisi nilai ke struct
strcpy(mhs1.name, "Dian");
strcpy(mhs1.address, "Mataram");
mhs1.age = 22;
strcpy(mhs2.name, "Bambang");
strcpy(mhs2.address, "Surabaya");
mhs2.age = 23;

// mencetak isi struct
printf("## Mahasiswa 1 ##\n");
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf ("\n");
printf("## Mahasiswa 2 ##\n");
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}

```

Program di atas merupakan sebuah program dalam bahasa C yang menggunakan struktur (struct) untuk mengelola informasi tentang dua mahasiswa. Struktur `Mahasiswa` didefinisikan dengan tiga anggota: `name` (nama), `address` (alamat), dan `age` (umur). Program kemudian menggunakan struktur tersebut untuk membuat dua variabel `mhs1` dan `mhs2`, yang mewakili data dua mahasiswa yang berbeda. Informasi mahasiswa, seperti nama, alamat, dan umur, diisi ke dalam variabel-variabel tersebut. Selanjutnya, program mencetak informasi ini ke layar menggunakan fungsi `printf()`. Terakhir, program mengembalikan nilai 0 untuk menandakan bahwa eksekusi program berhasil. Dengan menggunakan struktur, program dapat mengatur dan menyimpan data secara terstruktur, meningkatkan keterbacaan dan pemahaman program.

### 3. [Tipe Data Koleksi]

```C++
#include <iostream>
#include <array>
using namespace std;

int main() {
// Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    
    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;

    return 0;
}

```
Program di atas merupakan program dalam bahasa C++ yang menggunakan array untuk menampung dan menampilkan sejumlah nilai.Pertama, program mendeklarasikan array `nilai` dengan ukuran 5 dan tipe data integer. Kemudian, nilai-nilai dalam array tersebut diinisialisasi menggunakan indeks dari 0 hingga 4.
Selanjutnya, program mencetak nilai dari setiap elemen array menggunakan pernyataan `cout`, dengan menampilkan nilai dari setiap elemen secara berurutan.Penggunaan array memungkinkan program untuk efisien menyimpan sejumlah nilai dalam satu variabel dan mengaksesnya menggunakan indeks. Hal ini memungkinkan program untuk mengelola kumpulan data yang besar dengan cara yang terstruktur dan efisien.


## Unguided 

### 1.Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
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

```

#### Output:
![Capture1](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/c86d5a02-a190-4bb4-9a85-30c6eb66bc6c)

Program di atas adalah sebuah program dalam bahasa C++ yang menghitung faktorial dari suatu bilangan dan memeriksa apakah suatu bilangan adalah bilangan prima atau bukan.Fungsi `hitung_faktorial()` digunakan untuk menghitung faktorial dari suatu bilangan yang dimasukkan pengguna, sedangkan fungsi `cek_prima()` digunakan untuk memeriksa apakah bilangan yang dimasukkan adalah bilangan prima atau tidak.
Program utama meminta pengguna memasukkan dua bilangan, yaitu bilangan untuk dihitung faktorialnya dan bilangan untuk diperiksa apakah prima atau bukan. Setelah itu, program mencetak hasil faktorial dari bilangan pertama dan apakah bilangan kedua merupakan bilangan prima atau bukan.Program ini membantu pengguna dalam melakukan perhitungan matematika dasar dan mengecek sifat suatu bilangan.

#### code Screenshot:
![Capture2](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/af253361-086e-4e79-a62d-8b33860a0a1c)

## 2.Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
Class adalah sebuah konstruksi dalam pemrograman yang memungkinkan pengguna untuk mendefinisikan sebuah tipe data baru yang menyatukan data (variabel) dan fungsi (metode) ke dalam satu entitas yang disebut objek. Ini membantu dalam pembuatan kode yang lebih terstruktur, modular, dan mudah diorganisir.

Struct (structure) adalah tipe data yang memungkinkan pengguna untuk menggabungkan beberapa jenis data yang berbeda ke dalam satu unit. Struct serupa dengan class dalam hal membuat tipe data baru dengan gabungan data yang berbeda, tetapi perbedaannya terletak pada aksesibilitas default: anggota dari struct secara defaultnya bersifat public, sementara pada class secara defaultnya bersifat private.

## 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.


```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> umur;

    nilai["Haifa"] = 100;
    nilai["Zahra"] = 90;
    nilai["Azzimmi"] = 75;

    cout << "Nilai Haifa: " << umur["Haifa"] << endl;
    cout << "Nilai Zahra: " << umur["Zahra"] << endl;
    cout << "Nilai Azzimmi: " << umur["Azzimmi"] << endl;

    return 0;
}

```
Program menggunakan pustaka `map` untuk memetakan nama (dalam bentuk string) ke nilai (dalam bentuk integer). Kemudian, nilai-nilai tersebut dimasukkan ke dalam peta untuk setiap nama. Setelahnya, program mencetak nilai yang terhubung dengan setiap nama yang telah dimasukkan ke dalam peta. Dengan menggunakan map, program memungkinkan pengelolaan dan akses data yang efisien.

Array dan map memiliki perbedaan dalam struktur data, indeks, ukuran, tipe kunci, dan penggunaan. Array adalah struktur data berurutan dengan indeks numerik, sementara map adalah struktur data berpasangan kunci-nilai yang memungkinkan akses berdasarkan kunci unik. Array cocok untuk kumpulan data sederhana, sedangkan map berguna untuk menyimpan dan mengakses data berpasangan tanpa urutan tertentu.

## Kesimpulan
Tipe data adalah kunci dalam memfasilitasi program untuk mengenali dan mengelola informasi. Komputer hanya dapat memproses informasi dalam bentuk biner (1 dan 0), dan tipe data memungkinkan bahasa pemrograman untuk memahami dan bekerja dengan informasi tersebut. Ada tiga jenis utama tipe data:

1. **Primitif**: Tipe data sederhana seperti integer, floating point, karakter, dan string yang cocok untuk operasi dasar matematika dan pengolahan teks.

2. **Abstrak (ADT)**: Konsep ini mendefinisikan struktur data tingkat tinggi tanpa detail implementasi, memungkinkan manipulasi data tanpa memahami detail teknisnya. Contohnya adalah stack, queue, dan tree.

3. **Koleksi**: Tipe data yang mengelompokkan data, termasuk array (statis), list, dan map (dinamis). Mereka memungkinkan pengelompokan data berindeks, dengan map menyimpan data dalam pasangan kunci-nilai.


## Referensi
https://revou.co/kosakata/tipe-data

https://www.prepbytes.com/blog/data-structure/abstract-data-type-adt-in-data-structure/

https://perkembanganinformatika.wordpress.com/2014/04/05/praktikum-struktur-data-tipe-data-primitif-abstrak-dan-koleksi/
