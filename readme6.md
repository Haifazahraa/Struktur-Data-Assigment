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


```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string kalimat) {
    stack<char> stackKarakter;
    int length = kalimat.length();

    // Memasukkan setengah karakter pertama ke dalam stack
    for (int i = 0; i < length / 2; i++) {
        stackKarakter.push(kalimat[i]);
    }

    // Membandingkan karakter dari setengah kedua kalimat dengan stack
    int i = (length + 1) / 2;
    while (i < length) {
        if (kalimat[i] != stackKarakter.top()) {
            return false;  // Tidak palindrom
        }
        stackKarakter.pop();
        i++;
    }

    return true;  // Palindrom
}

int main() {
    string kalimat;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    if (isPalindrome(kalimat)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}

```
#### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/f81cc7a9-3908-490a-9eae-1fa2ae7033c0)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/1137c374-bdb8-430c-9433-43c20b227435)


Program ini pertama-tama menggunakan stack (`stack<char> stackKarakter`) untuk menyimpan setengah karakter pertama dari kalimat. Kemudian, program menggunakan perulangan pertama (`for (int i = 0; i < length / 2; i++)`) untuk memasukkan setengah karakter pertama ke dalam stack. Selanjutnya, program menentukan indeks awal (`int i = (length + 1) / 2;`) untuk membandingkan setengah kedua kalimat dengan stack. Perulangan kedua (`while (i < length)`) digunakan untuk membandingkan karakter dari setengah kedua kalimat dengan karakter yang dikeluarkan dari stack. Jika ditemukan perbedaan, maka kalimat tidak merupakan palindrom dan fungsi mengembalikan `false`. Namun, jika kedua perulangan selesai dan tidak ditemukan perbedaan, maka kalimat tersebut dianggap sebagai palindrom dan fungsi mengembalikan `true`.

### 2. [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]

```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseLetters(string sentence) {
    stack<char> letters;
    string reversedSentence = "";

    // Memasukkan huruf-huruf dalam kalimat ke dalam stack
    for (char letter : sentence) {
        letters.push(letter);
    }

    // Mengambil huruf-huruf dari stack untuk membentuk kalimat yang terbalik
    while (!letters.empty()) {
        reversedSentence += letters.top();
        letters.pop();
    }

    return reversedSentence;
}

int main() {
    string sentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    string reversedSentence = reverseLetters(sentence);
    cout << "\nHasil: " << reversedSentence << endl;

    return 0;
}

```
### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/961b02e5-3661-434b-b708-e63e2eb21b66)

1. Penjelasan operasi atau fungsi yang dibuat
   
Fungsi `reverseLetters(string sentence)` berperan dalam membalikkan urutan huruf-huruf dalam sebuah kalimat. Program menggunakan struktur data stack (`stack<char> letters`) untuk menampung urutan huruf dalam kalimat. Dalam perulangan pertama (`for (char letter : sentence)`), tiap huruf dalam kalimat dimasukkan ke dalam stack. Setelah seluruh huruf dimasukkan ke dalam stack, program menggunakan perulangan kedua (`while (!letters.empty())`) untuk mengambil huruf-huruf dari stack dan menyusunnya kembali sehingga membentuk kalimat yang terbalik.

2. Penjelasan output program
   
Pertama nantinta program akan meminta pengguna untuk memasukan sebuah kalimat setelah kalimat dimasukan program akan membalikan huruf huruf dalam kalimat tersebut. Output program akan menampilkan kalimat yang telah dibalikan huruf hurufnya contoh di program ini saya memasukan kalimat 'haifa zahra azzimmi' output yang dikeluarkan menjadi 'immizza arhaz afiah' seperti itu.
   
## Kesimpulan
Kesimpulannya, stack adalah struktur data yang mengikuti prinsip First In Last Out (FILO) atau Last In First Out (LIFO), di mana data ditambahkan dan diambil dari ujung atas tumpukan, dan tumpukan memiliki sifat dinamis yang memungkinkan penambahan dan pengambilan data secara fleksibe

## Referensi
[1] https://www.jurnal.pelitabangsa.ac.id/index.php/sigma/article/view/1267/820
[2] https://repository.penerbiteureka.com/id/publications/558553/algoritma-pemrograman-dan-struktur-data
