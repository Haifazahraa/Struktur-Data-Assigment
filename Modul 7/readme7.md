# <h1 align="center">Laporan Praktikum Modul 7 Queue </h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori
Queue/antrian adalah ordered list dengan penyisipan di satu ujung, sedang penghapusan di ujung lain. Ujung penyisipan biasa disebutrear/tail, sedang ujung penghapusa disebut front/head. Fenomena yang muncul adalah elemen yang lebih dulu disisipkan akan juga lebih dulu diambil. Queue berdisiplin FIFO (First In, First Out).

Karakteristik penting antrian sebagai berikut :

1.Elemen antrian yaitu item-item data yang
terdapat di elemen antrian

2.Head/front (elemen terdepan dari antrian )

3.Tail/rear (elemen terakhir dari antrian )

4.Jumlah elemen pada antrian (count)

5.Status/kondisi antrian.

Kondisi antrian yang menjadi perhatian adalah :

• Penuh
Bila elemen di antrian mencapai kapasitas
maksimum antrian. Pada kondisi ini, tidak
mungkin dilakukan penambahan ke antrian.
Penambahan elemen menyebabkan kondisi
kesalahan Overflow.

• Kosong
Bila tidak ada elemen di antrian. Pada kondisi ini,
tidak mungkin dilakukan pengambilan elemen dari
antrian. Pengambilan elemen menyebabkan kondisi
kesalahan Underflow.

Operasi-Operasi Pokok di Queue

• Operasi-operasi pokok antrian sebagai
berikut :

1.createQueue (Q), atau constructor menciptakan
antrian kosong Q.

2.addQueue (Q, X) memasukkan elemen X sebagai
elemen akhir di Q.

3.removeQueue (Q, X)atau mengambil elemen
depan di antrian Q ke elemenX[1]

## Guided 

### 1. [GUIDED 1]

```C++

#include <iostream>
using namespace std;
const int maksimalQueue = 5; // Maksimal antrian
int front = 0;               // Penanda antrian
int back = 0;                // Penanda
string queueTeller[5];       // Fungsi pengecekan
bool isFull()
{ // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue)
    {
        return true; // =1
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{ // Antriannya kosong atau tidak
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueueAntrian(string data)
{ // Fungsi menambahkan antrian
    if (isFull())
    {
        cout << "Antrian penuh" << endl;
    }
    else
    {
        if (isEmpty())
        { // Kondisi ketika queue kosong queueTeller[0] = data;
            front++;
            back++;
        }
        else
        { // Antrianya ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}
void dequeueAntrian()
{ // Fungsi mengurangi antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}
int countQueue()
{ // Fungsi menghitung banyak antrian
    return back;
}
void clearQueue()
{ // Fungsi menghapus semua antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}
void viewQueue()
{ // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}
int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Program ini mengimplementasikan antrian (queue) menggunakan array di C++. Program ini memiliki beberapa fungsi utama untuk mengelola antrian, seperti menambahkan elemen (enqueue), menghapus elemen (dequeue), memeriksa apakah antrian penuh atau kosong, menghitung jumlah elemen, menghapus semua elemen, dan menampilkan isi antrian.
## Unguided 

### 1. [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]

```C++
//Haifa Zahra Azzimmi
//2311102163
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    int count() {
        int cnt = 0;
        Node* current = front;
        while (current != nullptr) {
            cnt++;
            current = current->next;
        }
        return cnt;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        cout << "Queue contents:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". " << current->data << endl;
            current = current->next;
            index++;
        }
        if (index == 1) {
            cout << "(empty)" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue("John");
    q.enqueue("Jane");
    q.view();
    cout << "Queue size = " << q.count() << endl;

    q.dequeue();
    q.view();
    cout << "Queue size = " << q.count() << endl;

    q.clear();
    q.view();
    cout << "Queue size = " << q.count() << endl;

    return 0;
}

```
#### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/71c44760-4c0b-41f2-9029-5120cb0ba6c5)

Program ini adalah implementasi dari struktur data antrian (queue) menggunakan linked list dalam bahasa C++. Program ini terdiri dari beberapa bagian, termasuk definisi struktur `Node`, kelas `Queue` dengan beberapa metode untuk operasi antrian, dan fungsi `main` untuk menguji kelas `Queue`.

Pertama, struktur `Node` didefinisikan dengan dua atribut: `data` yang menyimpan nilai data dalam bentuk string dan pointer `next` yang menunjuk ke node berikutnya dalam antrian. Kelas `Queue` memiliki dua pointer, yaitu `front` dan `rear`, yang masing-masing menunjuk ke elemen pertama dan terakhir dalam antrian.

Dalam konstruktor `Queue`, kedua pointer diinisialisasi dengan nilai `nullptr`, menunjukkan bahwa antrian kosong saat pertama kali dibuat. Metode `isFull()` selalu mengembalikan `false` karena antrian yang diimplementasikan dengan linked list tidak memiliki batasan ukuran. Metode `isEmpty()` memeriksa apakah antrian kosong dengan mengecek apakah pointer `front` adalah `nullptr`.

Metode `enqueue(string data)` menambahkan elemen baru ke antrian. Sebuah node baru dibuat dengan data yang diberikan, dan jika antrian kosong, node baru ini menjadi elemen pertama dan terakhir. Jika tidak, node baru ditambahkan ke akhir antrian dan pointer `rear` diperbarui untuk menunjuk ke node baru tersebut.

Metode `dequeue()` menghapus elemen dari depan antrian. Jika antrian kosong, pesan "Queue is empty" ditampilkan. Jika tidak, elemen pertama dihapus, dan pointer `front` diperbarui untuk menunjuk ke elemen berikutnya. Jika setelah penghapusan antrian menjadi kosong, pointer `rear` juga diset ke `nullptr`.

Metode `count()` menghitung jumlah elemen dalam antrian dengan melintasi seluruh node dari depan ke belakang dan mengembalikan jumlah node yang ditemukan.

Metode `clear()` mengosongkan antrian dengan memanggil metode `dequeue()` berulang kali hingga antrian kosong.

Metode `view()` menampilkan isi antrian. Jika antrian kosong, pesan "(empty)" ditampilkan. Jika tidak, semua elemen dalam antrian ditampilkan dengan nomor urutannya.

Dalam fungsi `main()`, objek `Queue` dibuat dan beberapa elemen ditambahkan ke antrian dengan memanggil `enqueue()`. Isi antrian dan ukurannya ditampilkan setelah setiap operasi utama (penambahan, penghapusan, dan pengosongan) untuk memverifikasi bahwa antrian berfungsi dengan benar.

### 2. [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]

```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    string studentID;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isFull() {
        return false;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(string name, string studentID) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->studentID = studentID;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    int count() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void view() {
        cout << "Queue Student Data:" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index << ". Name: " << current->name << ", NIM: " << current->studentID << endl;
            current = current->next;
            index++;
        }
        if (index == 1) {
            cout << "(empty)" << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue("John", "2023001");
    q.enqueue("Doe", "2023002");
    q.view();
    cout << "Queue Size = " << q.count() << endl;

    q.dequeue();
    q.view();
    cout << "Queue Size = " << q.count() << endl;

    q.clear();
    q.view();
    cout << "Queue Size = " << q.count() << endl;

    return 0;
}

```
### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/7357c6aa-12f1-4f4b-944e-80bc0369ecae)

Program ini adalah implementasi dari struktur data antrian (queue) menggunakan linked list di C++. Program ini memanfaatkan struktur `Node` yang menyimpan data mahasiswa (nama dan NIM) dan memiliki pointer `next` untuk menghubungkan node-node tersebut dalam antrian.

Kelas `Queue` memiliki fungsi-fungsi dasar seperti `enqueue` untuk menambahkan data ke antrian, `dequeue` untuk menghapus data dari antrian, `count` untuk menghitung jumlah elemen dalam antrian, `clear` untuk mengosongkan antrian, dan `view` untuk menampilkan isi antrian.

Dalam fungsi `main()`, program menguji operasi-operasi dasar antrian seperti menambahkan data, menghapus data, menghitung jumlah data, mengosongkan antrian, dan menampilkan isi antrian setelah setiap operasi.
## Kesimpulan
Kesimpulannya, Queue (antrian) adalah salah satu jenis list linier dalam struktur data yang bekerja dengan prinsip First In First Out (FIFO), di mana elemen pertama yang masuk adalah elemen pertama yang keluar. Data dalam antrian bisa bertipe integer, real, atau record dalam bentuk sederhana atau terstruktur. Penyisipan data dalam queue dilakukan di satu ujung, sementara penghapusan dilakukan di ujung lainnya. Ujung untuk penyisipan disebut rear atau tail, dan ujung untuk penghapusan disebut front atau head. 

Sebuah queue dalam program setidaknya harus memiliki tiga variabel: head untuk menandai bagian depan antrian, tail untuk menandai bagian belakang antrian, dan array data untuk menyimpan elemen-elemen yang dimasukkan ke dalam queue tersebut. 

Ada beberapa operasi dasar pada queue, yaitu: prosedur create untuk membuat queue baru yang kosong, fungsi isEmpty untuk memeriksa apakah queue kosong, fungsi isFull untuk memeriksa apakah queue penuh, prosedur enqueue untuk menambahkan data ke dalam queue, prosedur dequeue untuk menghapus elemen dari posisi head pada queue, fungsi clear untuk menghapus semua elemen dalam queue, dan prosedur tampil untuk menampilkan elemen-elemen yang ada dalam queue.

### Referensi
[1] https://osf.io/preprints/osf/cs53p
