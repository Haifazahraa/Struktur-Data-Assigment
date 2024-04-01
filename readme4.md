# <h1 align="center">Laporan Praktikum Modul 4 Linked List Circular Dan Non Circular</h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori



## Guided 

### 1. [Linked List Non Circular]

```C++


```


### 2. [Linked List Circular]

```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>
using namespace std;

//PROGRAM SINGLE LINKED LIST CIRCULAR

//Deklarasi Struct Node
struct *Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

//Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

//Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

//Hitung List
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

//Tambah Depan
void insertDepan(string data)
{
    //Buat Node Baru
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

//Tambah Belakang
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
    else{
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

//Tambah Tengah
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

//Hapus Depan
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

            delete hapus;
        }
        else
        {
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

//Hapus Belakang
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

            delete hapus;
        }
        else
        {
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

//Hapus Tengah
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

//Hapus List
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

//Tampilkan List
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

## Unguided 

### 1. [Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:]

![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/14774c3e-b949-4c84-bd8f-830fdb104eaf)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/09223224-f3bc-4a7b-ba55-ca8f5bf1b3db)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/2f33b674-0cf3-4844-986e-0a6057b08aa8)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/f7defadb-a562-45ce-a7ec-dbe4c070a944)

```C++
```
#### Output:
![Capture22](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/f1b013d0-a61a-4797-bfd4-f3d92a1ff53b)

Dalam program ini, setiap node dalam linked list memiliki dua atribut yaitu `nama` yang merupakan nama seseorang, dan `usia` yang merupakan usia orang tersebut. Struktur `Node` digunakan untuk mendefinisikan node, sedangkan kelas `LinkedList` digunakan untuk mengelola linked list tersebut dengan berbagai operasi seperti insert (masukkan), delete (hapus), modify (ubah), dan display (tampilkan).

Dalam contoh program ini, data nama dan usia dimasukkan ke dalam linked list, kemudian dilakukan beberapa operasi seperti penghapusan data, penambahan data setelah node tertentu, penambahan data di awal, perubahan data, dan akhirnya menampilkan seluruh data yang ada dalam linked list.

### 2. [Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)]
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/4f5af637-7f6c-4edd-8b4e-bacdd64c6ca6)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/a21d5954-fc05-4771-a195-d47f9fa06195)

```C++

```
#### Output:

Program ini mengizinkan pengguna untuk mengelola data produk skincare dalam toko dengan berbagai operasi yang disediakan, termasuk menambah, menghapus, mengubah, dan menampilkan data dalam Doubly Linked List. Dua kelas utama yang digunakan adalah Node untuk struktur node dan DoublyLinkedList untuk mengelola operasi-operasi tersebut.


## Kesimpulan



## Referensi
[1] 
[2] 
