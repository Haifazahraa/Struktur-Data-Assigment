# <h1 align="center">Laporan Praktikum Modul 4 Linked List Circular Dan Non Circular</h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori
A. Single Linked List
1. Linked List Non Circular
Setiap node pada linked list mempunyai field yang berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan node baru, mulanya pointer next dan prev akan menunjuk ke nilai NULL. Selanjutnya pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node selanjutnya pada list.[1]

2. Linked list Circular
Single Linked List yang pointer nextnya menunjuk pada dirinya sendiri. Jika Single Linked List tersebut terdiri dari beberapa node, maka pointer next pada node terakhir akan menunjuk ke node terdepannya.[1]

B. Double Linked List
1. Double Linked List Circular
Setiap node pada linked list mempunyai field yang berisi data dan pointer ke node berikutnya & ke node sebelumnya. Untuk pembentukan node baru, mulanya pointer next dan prevakan menunjuk ke dirinya sendiri. Jika sudah lebih dari satu node, maka pointer prev akan menunjuk ke node sebelumnya, dan pointer next akan menunjuk ke node sesudahnya.[2]

2. Double Linked List Non-Circular
adalah linked list dengan menggunakan pointer, dimana setiap node memiliki 3 field, yaitu 1 field pointer yang menunjuk pointer berikutnya (next), 1 field menunjuk pointer sebelumnya (prev), serta sebuah field yang berisi data untuk node tersebut.[2]

## Guided 

### 1. [Linked List Non Circular]

```C++
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
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
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
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
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;

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
    if (isEmpty() == 0)
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
Program ini merupakan program single linked list non-circular, terdapat struktur node yaitu data: menyimpan data integer dan next: pointer yang menunjuk ke node berikutnya. Ada juga deklarasi variabel global pada program ini yaitu head dan tail. Alur program ini pertama memulai dengan list kosong selanjutnya menambahkan node baru didepan dan belakang list kemudian menghitung jumlah node dalam list kemudian menghapus node pertama da terakhir dari list selanjutnya menambahkan node baru di tengah list kemudian menghapus node di tengah list selanjutnya mengubah data node pertama, tengah dan terakhir kemudian menampilkan data semua node dalam list dan menghapus semua node dari list. Program ini menggunakan pointer untuk menghubungkan node-node dalam list. List non-circular memiliki node terakhir dengan pointer NULL.

### 2. [Linked List Circular]

```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>

using namespace std;
/// PROGRAM SINGLE LINKED LIST CIRCULAR
// Deklarasi Struct Node
struct Node
{
    /// @brief 
    string data;
    Node *next;
};
Node *head, *tail, *baru, *bantu, *hapus;
void init()
{
    head = NULL;
    tail = head;
}
// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}
// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}
// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}
// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}
// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}
// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
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
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            delete hapus;
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Pada program ini terdapat Struktur Node yang mendefinisikan dua elemen yaitu data: menyimpan data string dan next: pointer yang menunjuk ke node berikutnya. Pada program ini menggunakan variabel global antara lain head, tail, baru, bantu dan hapus.
Alur program ini pertama memulai dengan list kosong kemudian menambahkan node baru ke depan dan belakang list kemudian menghitung jumlah node dalam list kemudian menghapus node pertama dan terakhir dari list selanjutnya menambahkan node baru ditengah list kemudian menghapus node tengah list selanjutnya menampilkan data semua node dalam list dan menghapus semua node dari list terakhir. Program ini menggunakan pointer untuk menghubungkan node-node dalam list, List circular tidak memiliki node terakhir dengan pointer NULL. Node terakhir menunjuk ke node pertama.

## Unguided 

### 1. [Buatlah program menu Linked List Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:]

![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/14774c3e-b949-4c84-bd8f-830fdb104eaf)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/09223224-f3bc-4a7b-ba55-ca8f5bf1b3db)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/2f33b674-0cf3-4844-986e-0a6057b08aa8)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/f7defadb-a562-45ce-a7ec-dbe4c070a944)

```C++
/Haifa Zahra Azzimmi
//2311102163

#include <iostream>
using namespace std;

// Struktur Node untuk Linked List Circular
struct Node {
    string name;
    string nim;
    Node* next;
};

// Kelas Circular Linked List
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambah node di depan
    void addFront(string name, string nim) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Data telah ditambahkan\n";
    }

    // Fungsi untuk menambah node di belakang
    void addBack(string name, string nim) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Data telah ditambahkan\n";
    }

    // Fungsi untuk menambah node di tengah
    void addMiddle(string name, string nim, int position) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        cout << "Data telah ditambahkan\n";
    }

    // Fungsi untuk menghapus node di depan
    void deleteFront() {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete temp;
        cout << "Data di depan berhasil dihapus\n";
    }

    // Fungsi untuk menghapus node di belakang
    void deleteBack() {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr) {
            head = nullptr;
        } else {
            prev->next = head;
        }
        delete temp;
        cout << "Data di belakang berhasil dihapus\n";
    }

    // Fungsi untuk menghapus node di tengah
    void deleteMiddle(int position) {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        for (int i = 0; i < position - 1; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Data di posisi " << position << " berhasil dihapus\n";
    }

    // Fungsi untuk menghapus semua node dalam Linked List Circular
    void deleteList() {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Node* temp = head;
        Node* nextNode = nullptr;
        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
        head = nullptr;
        cout << "Seluruh data berhasil dihapus\n";
    }

    // Fungsi untuk mengubah data di depan
    void updateFront(string name, string nim) {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        head->name = name;
        head->nim = nim;
        cout << "Data di depan berhasil diubah\n";
    }

    // Fungsi untuk mengubah data di belakang
    void updateBack(string name, string nim) {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->name = name;
        temp->nim = nim;
        cout << "Data di belakang berhasil diubah\n";
    }

    // Fungsi untuk mengubah data di tengah
    void updateMiddle(string name, string nim, int position) {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        temp->name = name;
        temp->nim = nim;
        cout << "Data di posisi " << position << " berhasil diubah\n";
    }

    // Fungsi untuk menampilkan semua node dalam Linked List Circular
    void display() {
        if (head == nullptr) {
            cout << "List kosong\n";
            return;
        }

        Node* temp = head;
        cout << "DATA MAHASISWA\n";
        cout << "NAMA\tNIM\n";
        do {
            cout << temp->name << "\t" << temp->nim << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    CircularLinkedList list;
    int choice;
    string name, nim;
    int position;

    do {
        cout << "PROGRAM SINGLE LINKED LIST CIRCULAR\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Hapus Depan\n";
        cout << "5. Hapus Belakang\n";
        cout << "6. Hapus Tengah\n";
        cout << "7. Hapus Seluruh Data\n";
        cout << "8. Ubah Data Depan\n";
        cout << "9. Ubah Data Tengah\n";
        cout << "10. Ubah Data Belakang\n";
        cout << "11. Tampilkan\n";
        cout << "0. Keluar\n";
        cout << "Pilih Operasi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "-Tambah Depan-\n";
                cout << "Masukkan Nama: ";
                cin >> name;
                cout << "Masukkan NIM: ";
                cin >> nim;
                list.addFront(name, nim);
                break;
            case 2:
                cout << "-Tambah Belakang-\n";
                cout << "Masukkan Nama: ";
                cin >> name;
                cout << "Masukkan NIM: ";
                cin >> nim;
                list.addBack(name, nim);
                break;
            case 3:
                cout << "-Tambah Tengah-\n";
                cout << "Masukkan Nama: ";
                cin >> name;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> position;
                list.addMiddle(name, nim, position);
                break;
            case 4:
                cout << "-Hapus Depan-\n";
                list.deleteFront();
                break;
            case 5:
                cout << "-Hapus Belakang-\n";
                list.deleteBack();
                break;
            case 6:
                cout << "-Hapus Tengah-\n";
                cout << "Masukkan Posisi: ";
                cin >> position;
                list.deleteMiddle(position);
                break;
            case 7:
                cout << "-Hapus Seluruh Data-\n";
                list.deleteList();
                break;
            case 8:
                cout << "-Ubah Data Depan-\n";
                cout << "Masukkan Nama Baru: ";
                cin >> name;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                list.updateFront(name, nim);
                break;
            case 9:
                cout << "-Ubah Data Tengah-\n";
                cout << "Masukkan Nama Baru: ";
                cin >> name;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                cout << "Masukkan Posisi: ";
                cin >> position;
                list.updateMiddle(name, nim, position);
                break;
            case 10:
                cout << "-Ubah Data Belakang-\n";
                cout << "Masukkan Nama Baru: ";
                cin >> name;
                cout << "Masukkan NIM Baru: ";
                cin >> nim;
                list.updateBack(name, nim);
                break;
            case 11:
                cout << "DATA MAHASISWA\n";
                cout << "NAMA NIM\n";
                list.display();
                break;
            case 0:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (choice != 0);

    return 0;
}

```
#### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/3e0e3416-0a39-40f0-9786-0998556790d8)

Program ini adalah sebuah implementasi dari Circular Linked List dalam bahasa pemrograman C++. Program ini memungkinkan pengguna untuk melakukan berbagai operasi pada data mahasiswa, seperti menambah data di depan, belakang, atau tengah, menghapus data, mengubah data, serta menampilkan seluruh data mahasiswa yang disimpan dalam Circular Linked List. Program juga dilengkapi dengan menu pilihan yang memudahkan pengguna dalam melakukan operasi-operasi tersebut.


### 2. [Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)]
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/4f5af637-7f6c-4edd-8b4e-bacdd64c6ca6)

#### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/abeca58a-89b7-40a8-b768-b9dc5a421811)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/e349f6d9-5816-4b30-9b72-d34ecce34863)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/bbac12d2-7c49-4cb7-87c0-aef9c0fbc0a1)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/abe15d6d-ef77-4e15-a45c-d21f6e9d761a)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/cb16954a-c523-45c8-89e6-0dae2acdf9e2)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/1fb321c5-b66c-4192-9b49-736e3ba78b2b)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/da4ebe55-6014-4457-b41e-c52f4220754e)


### 3. [Lakukan perintah berikut:]
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/a21d5954-fc05-4771-a195-d47f9fa06195)

#### Output
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/9268f170-0982-4663-9f92-c83f453129b3)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/b2039f15-2bcb-4db0-a1c4-076a5cebf005)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/ea090d57-e967-4abb-8b12-bb92529889ba)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/6a26d28e-6173-4f50-90d5-b1b101cfd212)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/99855de0-3b8b-4707-9ab1-f771162ec473)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/c94c58b6-d04d-42b7-8804-e2b8e7503677)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/4caa76c2-875c-458a-bb4d-877a9deb1c07)

## Kesimpulan
perbedaan antara Single Linked List Non-Circular, Single Linked List Circular, Double Linked List Circular, dan Double Linked List Non-Circular. Single Linked List Non-Circular memiliki pointer next yang menunjuk ke node berikutnya dan tidak kembali ke node pertama, sedangkan Single Linked List Circular memiliki pointer next yang kembali menunjuk ke node pertama. Double Linked List Circular memiliki pointer next dan prev yang menunjuk ke node berikutnya dan sebelumnya, sedangkan Double Linked List Non-Circular memiliki pointer next dan prev yang tidak kembali menunjuk ke dirinya sendiri.

## Referensi
[1] https://osf.io/preprints/osf/sczvp
[2] https://osf.io/preprints/osf/tjnfa
