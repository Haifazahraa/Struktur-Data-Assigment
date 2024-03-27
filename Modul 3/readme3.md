# <h1 align="center">Laporan Praktikum Modul 3 Single and Double Linked list</h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori
Single Linked List
Linked List adalah salah satu bentuk struktur data, berisi kumpulan data (node) yang tersusun secara sekuensial, saling sambungmenyambung, dinamis dan terbatas.
- Linked List sering disebut juga Senarai Berantai
- Linked List saling terhubung dengan bantuan variabel pointer
- Masing-masing data dalam Linked List disebut dengan node (simpul) yang menempati alokasi memori secara dinamis dan biasanya berupa struct yang terdiri dari beberapa field.
Single Linked List adalah sebuah LINKED LIST yang menggunakan sebuah variabel pointer saja untuk menyimpan banyak data dengan metode LINKED LIST, suatu daftar isi yang saling berhubungan.
Single Linked List adalah sekumpulan dari node yang saling terhubung dengan node lain melalui sebuah pointer.
Single Linked List hanya memiliki satu arah dan tidak memiliki dua arah atau bolak balik, dua arah tersebut disebut dengan double linked list.
Pada Implementasinya, Single Linked List terdapat dua variasi yaitu circular dan noncircular. [1]

Double Linked List Circular adalah linked list dengan menggunakan pointer, dimana setiap node memiliki 3 field, yaitu 1 field pointer yang menunjuk pointer berikutnya (next), 1 field menunjuk pointer sebelumnya (prev), serta sebuah field yang berisi data untuk node tersebut. 
Double Linked List Circular pointer next dan prev-nya menunjuk ke dirinya sendiri secara circular. [2]



## Guided 

### 1. [Single Linked List]

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Dalam program di atas ini, terdapat sejumlah fungsi yang digunakan antara lain ada:
Deklarasi Struct Node mendefinisikan struktur data untuk setiap node dalam Single Linked List, yang terdiri dari data dan pointer ke node berikutnya.
Inisialisasi Node mengatur variabel head dan tail menjadi NULL pada awal program.
Pengecekan Kosong memeriksa apakah Single Linked List kosong atau tidak.
Insert Depan menambahkan node baru di awal Single Linked List.
Insert Belakang menambahkan node baru di akhir Single Linked List.
Hitung Jumlah List menghitung jumlah node dalam Single Linked List.
Insert Tengah menambahkan node baru di posisi tengah Single Linked List.
Hapus Depan menghapus node pertama dari Single Linked List.
Hapus Belakang menghapus node terakhir dari Single Linked List.
Hapus Tengah menghapus node di posisi tengah Single Linked List.
Ubah Depan mengubah nilai data pada node pertama Single Linked List.
Ubah Belakang mengubah nilai data pada node terakhir Single Linked List.
Ubah Tengah mengubah nilai data pada node di posisi tengah Single Linked List.
Hapus List menghapus semua node dalam Single Linked List.
Tampilkan List menampilkan isi Single Linked List.

### 2. [Double Linked List]

```C++
#include <iostream>
using namespace std;


class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program ini menggunakan dua kelas utama, yaitu Node dan DoubleLinkedList. Kelas Node digunakan untuk mendefinisikan struktur node dalam Double Linked List dengan atribut data (integer) serta pointer prev dan next. Kelas DoubleLinkedList mengelola operasi-operasi pada Double Linked List seperti menambahkan data menghapus data update mengubah data menghapus semua data, dan menampilkan data. Program memiliki menu pilihan yang mencakup operasi-operasi tersebut dan menggunakan loop while(true) dalam fungsi main untuk menampilkan menu pilihan kepada pengguna.

## Unguided 

### 1. [Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:]
![Capture17](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/82b8b76b-915d-40c9-b726-29599808cb36)

```C++
#include <iostream>
using namespace std;

struct Node {
    string nama;
    int usia;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertFront(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(string nama, int usia, string key) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data " << key << " tidak ditemukan." << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(string key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->nama == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->nama != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data " << key << " tidak ditemukan." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void modifyData(string oldNama, string newNama, int newUsia) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != oldNama) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Data " << oldNama << " tidak ditemukan." << endl;
            return;
        }

        temp->nama = newNama;
        temp->usia = newUsia;
    }

    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    // a. Insert data
    list.insertFront("Haifa", 19);
    list.insertEnd("Zahra", 20);
    list.insertEnd("Azzimmi", 18);
    list.insertEnd("Zalfa", 12);
    list.insertEnd("Damar", 20);
    list.insertEnd("Wulan", 11);
    list.insertEnd("Lintang", 15);

    // b. Delete data
    list.deleteNode("Haifa");

    // c. Insert data after a key
    list.insertAfter("Zahra", 20, "Damar");

    // d. Insert data at the beginning
    list.insertFront("Zalfa", 12);

    // e. Modify data
    list.modifyData("Haifa", "Lintang", 15);

    // f. Display all data
    list.displayList();

    return 0;
}
```
#### Output:
![Capture22](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/f1b013d0-a61a-4797-bfd4-f3d92a1ff53b)

Dalam program ini, setiap node dalam linked list memiliki dua atribut yaitu `nama` yang merupakan nama seseorang, dan `usia` yang merupakan usia orang tersebut. Struktur `Node` digunakan untuk mendefinisikan node, sedangkan kelas `LinkedList` digunakan untuk mengelola linked list tersebut dengan berbagai operasi seperti insert (masukkan), delete (hapus), modify (ubah), dan display (tampilkan).

Dalam contoh program ini, data nama dan usia dimasukkan ke dalam linked list, kemudian dilakukan beberapa operasi seperti penghapusan data, penambahan data setelah node tertentu, penambahan data di awal, perubahan data, dan akhirnya menampilkan seluruh data yang ada dalam linked list.

### 2. [Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / diurutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.]
![Capture18](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/e6b929ba-efa8-4826-8a6a-d46e015c2bde)
![Capture19](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/1c63c744-2a2a-481b-abbc-12b434dcc1a9)
![Capture20](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/a8b755c2-a224-4424-8a1a-b3d12282c63c)
![Capture21](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/6aa67cfd-0790-4681-91a6-81f2ea0d4742)


```C++
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string nama_produk;
    int harga;
    Node* next;
    Node* prev;

    Node(string nama_produk, int harga) {
        this->nama_produk = nama_produk;
        this->harga = harga;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void tambah_data(string nama_produk, int harga) {
        Node* new_node = new Node(nama_produk, harga);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
            new_node->prev = current;
        }
    }

    void hapus_data(string nama_produk) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_produk == nama_produk) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                if (current == head) {
                    head = current->next;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    void update_data(string nama_produk, int harga) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nama_produk == nama_produk) {
                current->harga = harga;
                return;
            }
            current = current->next;
        }
    }

    void tambah_data_urutan_tertentu(string nama_produk, int harga, int urutan) {
        Node* new_node = new Node(nama_produk, harga);
        if (urutan == 1 || head == nullptr) {
            new_node->next = head;
            if (head != nullptr) {
                head->prev = new_node;
            }
            head = new_node;
        } else {
            Node* current = head;
            int count = 1;
            while (current != nullptr && count < urutan - 1) {
                current = current->next;
                count++;
            }
            if (current == nullptr) {
                cout << "Urutan melebihi jumlah produk yang ada" << endl;
                return;
            }
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next != nullptr) {
                current->next->prev = new_node;
            }
            current->next = new_node;
        }
    }

    void hapus_data_urutan_tertentu(int urutan) {
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        if (urutan == 1) {
            head = current->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete current;
            return;
        }
        int count = 1;
        while (current != nullptr && count < urutan) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            return;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        delete current;
    }

    void hapus_seluruh_data() {
        Node* current = head;
        while (current != nullptr) {
            Node* next_node = current->next;
            delete current;
            current = next_node;
        }
        head = nullptr;
    }

    void tampilkan_data() {
        Node* current = head;
        cout << "Nama Produk Harga" << endl;
        while (current != nullptr) {
            cout << current->nama_produk << " " << current->harga << endl;
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    // Menambahkan data awal
    dll.tambah_data("Originote", 60000);
    dll.tambah_data("Somethinc", 150000);
    dll.tambah_data("Skintific", 100000);
    dll.tambah_data("Wardah", 50000);
    dll.tambah_data("Hanasui", 30000);

    // Modifikasi sesuai dengan case yang diberikan
    dll.tambah_data_urutan_tertentu("Azarine", 65000, 3);
    dll.hapus_data("Wardah");
    dll.update_data("Hanasui", 55000);

    // Tampilkan menu
    cout << "Toko Skincare Purwokerto" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tambah Data Urutan Tertentu" << endl;
    cout << "5. Hapus Data Urutan Tertentu" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Exit" << endl;

    // Tampilkan data setelah modifikasi
    dll.tampilkan_data();

    return 0;
}
}
```
#### Output:
![Capture23](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/12092982-6507-4f7a-aa14-cbb8cc09d13e)

Program ini mengizinkan pengguna untuk mengelola data produk skincare dalam toko dengan berbagai operasi yang disediakan, termasuk menambah, menghapus, mengubah, dan menampilkan data dalam Doubly Linked List. Dua kelas utama yang digunakan adalah Node untuk struktur node dan DoublyLinkedList untuk mengelola operasi-operasi tersebut.


## Kesimpulan

1. Linked List adalah struktur data yang mengorganisir data secara sekuensial dan dinamis dengan menggunakan variabel pointer untuk menyambungkan node-node secara berurutan.

2. Single Linked List merupakan bentuk Linked List yang menggunakan satu variabel pointer per node untuk menyimpan dan menghubungkan data-data, hanya memiliki satu arah, dan tidak memiliki kemampuan bolak-balik seperti Double Linked List.

3. Double Linked List Circular adalah variasi dari Double Linked List yang memiliki pointer next dan prev yang menunjuk ke node berikutnya dan sebelumnya secara circular, membentuk suatu lingkaran.

Dengan demikian, Linked List menyediakan fleksibilitas dalam pengelolaan data dengan variasi seperti Single Linked List dan Double Linked List Circular

## Referensi
[1] https://osf.io/preprints/osf/u6qf7
[2] https://osf.io/preprints/osf/he29v
