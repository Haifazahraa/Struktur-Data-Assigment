# <h1 align="center">Laporan Praktikum Modul 6 Stack </h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori
Stack adalah metode atau tehnik dalam menyimpan atau mengambil data ke dan dari memori.Stack dapat diibaratkan sebuah tumpukan barang dalam sebuah tempat yang hanya memiliki satu pintu di atasnya (memasukkan dan mengambil barang hanya dapat dilakukan melalui pintu itu). Sehingga barang yang akan dikeluarkan pertama kali adalah barang yang terakhir kali dimasukkan. Dengan demikian, kaidah stack adalah First In Last Out atau Last In First Out.[1]

Secara sederhana,   tumpukan(stack) dapat diartikan sebagai suatu kumpulan data yang seolah-olah ada data yang diletakkan di atas data yang lain. Satu hal yang perlu diingat adalah bahwa dapat ditambah (menyisipkan) data dan mengambil (menghapus) data lewat ujung yang sama, yang disebut sebagai ujung atas tumpukan (top of stack). 

Misalnya kita mempunyai dua buah kotak yang ditumpuk, sehingga kotak diletakkan di atas kotak yang lain. Jika kemudian tumpukan dua buah kotak itu ditambah dengan kotak ketiga, keempat dan seterusnya, maka akan diperoleh sebuah tumpukan kotak, yang terdiri dari N kotak. Dapat dilihat pula bahwa tumpukan merupakan kumpulan data yang sifatnya dinamis, artinya dapat ditambah dan diambil data darinya.[2]

## Guided 

### 1. [GUIDED 1]

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}
bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = ' ';
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang dapat di lihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void chargeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top - 1; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang di cetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {

    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();

    cout << "\n" << endl;
    cout << "apakah data stack penuh? " << isFull() << endl;
    cout << "apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);

    popArrayBuku();

    cout << "banyaknya data = " << countStack() << endl;

    chargeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n" << endl;

    destroyArrayBuku();
    cout << "Jumlah data setelah di hapus : " << top << endl;

    cetakArrayBuku();

    return 0;
}

```
Program ini adalah implementasi dari struktur data stack menggunakan array dalam C++. Program ini memiliki fungsi-fungsi dasar seperti pushArrayBuku untuk menambahkan data ke dalam stack, popArrayBuku untuk menghapus data dari stack, peekArrayBuku untuk melihat data pada posisi tertentu dalam stack, chargeArrayBuku untuk mengubah data pada posisi tertentu dalam stack, destroyArrayBuku untuk menghapus semua data dalam stack, cetakArrayBuku untuk mencetak semua data dalam stack, dan countStack untuk menghitung jumlah data dalam stack. Selain itu, program ini juga memiliki fungsi isFull dan isEmpty untuk memeriksa apakah stack penuh atau kosong.

## Unguided 

### 1. [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]

![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/883701be-f7cf-475d-aa3a-082e58c45aa9)

```C++
//Haifa Zahra Azzimmi
//2311102163



```
#### Output:


Program di atas adalah implementasi dari Hash Table dalam C++. Program ini memungkinkan pengguna untuk menyimpan data mahasiswa berupa NIM dan nilai dalam sebuah hash table dengan ukuran tetap. 

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

```C++
//Haifa Zahra Azzimmi
//2311102163


```

### Output:

## Kesimpulan


## Referensi
[1] https://www.jurnal.pelitabangsa.ac.id/index.php/sigma/article/view/1267/820
[2] https://repository.penerbiteureka.com/id/publications/558553/algoritma-pemrograman-dan-struktur-data
