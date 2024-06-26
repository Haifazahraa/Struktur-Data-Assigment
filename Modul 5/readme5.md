# <h1 align="center">Laporan Praktikum Modul 5 Hast Table</h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori
Hash Table adalah struktur data yang efisien dalam operasi penambahan (insertion) dan pencarian (searching), diimplementasikan menggunakan array. Penambahan dan pencarian data dalam Hash Table bergantung pada fungsi hash yang digunakan, yang memetakan elemen-elemen ke indeks-ideks dalam Hash Table. Fungsi hash yang baik memiliki beberapa karakteristik penting, seperti mudah dihitung, mampu mendistribusikan key secara merata, dan meminimalkan jumlah collision (tabrakan) yang terjadi.

Terdapat beberapa teknik yang dapat digunakan dalam fungsi hash, di antaranya adalah:
- Truncation, yang mengambil beberapa digit dari key sebagai indeks.
- Folding, yang menjumlahkan beberapa digit dari key dan menggunakan hasil penjumlahan sebagai indeks.
- Modular, yang menggunakan sisa hasil bagi dari key dengan ukuran hash table sebagai indeks.

Collision terjadi ketika dua atau lebih key dipetakan ke sel yang sama dalam array hash. Untuk menangani collision, terdapat dua pendekatan utama dalam kategorisasi hash table:
- Closed Hashing (Open Addressing), di mana collision ditangani dengan cara menempatkan key tambahan pada sel yang berbeda dalam array yang sama.
- Open Hashing (Separate Chaining), di mana collision ditangani dengan membuat linked list di setiap sel array yang mengalami collision, sehingga key tambahan dapat disimpan pada posisi yang sesuai dalam linked list tersebut.

Dengan demikian, Hash Table menjadi sebuah struktur data yang sangat efisien dalam mengorganisir dan mengakses data, terutama ketika ukuran data sangat besar dan efisiensi operasi insertion dan searching menjadi kritis.

## Guided 

### 1. [GUIDED 1]

```C++
#include<iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) 
{
    return key % MAX_SIZE;
}

//Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value),
next(nullptr) {}
};

//Class hash Table
class HashTable 
{
    private:
        Node** table;
    public:
        HashTable() 
        {
            table = new Node*[MAX_SIZE]();
        }
        ~HashTable() 
        {
            for (int i = 0; i < MAX_SIZE; i++) 
            {
                Node* current = table[i];
                while (current != nullptr) 
                {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] table;
        }

        //Insertion
        void insert(int key, int value) 
        {
            int index = hash_func(key);
            Node* current = table[index];
            while (current != nullptr) 
            {
                if (current->key == key) 
                {
                    current->value = value;
                    return;
                }
                current = current->next;
            }
            Node* node = new Node(key, value);
            node->next = table[index];
            table[index] = node;
        }

        //Searching
        int get(int key) 
        {
            int index = hash_func(key);
            Node* current = table[index];
            while (current != nullptr) 
            {
                if (current->key == key) 
                {
                    return current->value;
                }
                current = current->next;
            }
                return -1;
        }

        //Deletion
        void remove(int key) 
        {
            int index = hash_func(key);
            Node* current = table[index];
            Node* prev = nullptr;
            while (current != nullptr) 
            {
                if (current->key == key) 
                {
                    if (prev == nullptr) 
                    {
                        table[index] = current->next;
                    } else 
                    {
                        prev->next = current->next;
                    }
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }

        //Traversal
        void traverse() 
        {
            for (int i = 0; i < MAX_SIZE; i++) 
            {
                Node* current = table[i];
                while (current != nullptr) 
                {
                    cout << current->key << ": " << current->value << endl;
                    current = current->next;
                }
            }
        }
};

int main()
{
    HashTable ht;

    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    
    // Deletion
    ht.remove(4);
    
    // Traversal
    ht.traverse();
    return 0;
}

```
Program ini adalah implementasi dari tabel hash menggunakan linked list untuk menangani operasi-operasi seperti penambahan data, pencarian data, penghapusan data, dan penelusuran seluruh data. Hal ini dicapai melalui penggunaan fungsi hash sederhana untuk menentukan indeks penyimpanan, struktur data Node untuk menyimpan data dengan kunci dan nilai, serta kelas HashTable yang mengelola operasi-operasi tersebut seperti insert untuk menambah data, get untuk mencari data, remove untuk menghapus data, dan traverse untuk menampilkan semua data dalam tabel hash.

### 2. [GUIDED 2]

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode 
{
    public:
        string name;
        string phone_number;
        HashNode(string name, string phone_number) 
        {
            this->name = name;
            this->phone_number = phone_number;
        }
};

class HashMap 
{
    private :
        vector<HashNode*> table[TABLE_SIZE];
    
    public :
        int hashFunc(string key) 
        {
            int hash_val = 0;
            for (char c : key) 
            {
                hash_val += c;
            }
            return hash_val % TABLE_SIZE;
        }
        
        void insert(string name, string phone_number) 
        {
            int hash_val = hashFunc(name);
            for (auto node : table[hash_val]) 
            {
                if (node->name == name) 
                {
                    node->phone_number = phone_number;
                    return;
                }
            }    
            table[hash_val].push_back(new HashNode(name, phone_number));
        }

        void remove(string name) 
        {
            int hash_val = hashFunc(name);
            for (auto it = table[hash_val].begin(); it !=
            table[hash_val].end(); it++) 
            {
                if ((*it)->name == name) 
                {
                    table[hash_val].erase(it);
                    return;
                 }
            }
        }
        
        string searchByName(string name) 
        {
            int hash_val = hashFunc(name);
            for (auto node : table[hash_val]) 
            {
                if (node->name == name) 
                {
                    return node->phone_number;
                }
            }
            return "";
        }

        void print() 
        {
            for (int i = 0; i < TABLE_SIZE; i++) 
            {
                cout << i << ": ";
                for (auto pair : table[i]) 
                {
                    if(pair != nullptr)
                    {
                        cout << "[" << pair->name << ", " << pair->phone_number << "]";
                    }
                }
                cout << endl;
            }
        }
};

int main() 
{
    HashMap employee_map;
    
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    
    employee_map.remove("Mistah");
    
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    
    cout << "Hash Table : " << endl;
    
    employee_map.print();
    
    return 0;
}
```
Program ini merupakan implementasi dari tabel hash menggunakan vektor untuk menangani operasi-operasi seperti penambahan data, pencarian data berdasarkan nama, penghapusan data berdasarkan nama, dan pencetakan seluruh data dalam tabel hash. Setiap entri dalam tabel hash direpresentasikan oleh objek HashNode yang menyimpan nama dan nomor telepon. Fungsi hashFunc digunakan untuk menentukan indeks penyimpanan berdasarkan nama, dan kelas HashMap mengelola operasi-operasi tersebut seperti insert untuk menambah data, searchByName untuk mencari data, remove untuk menghapus data, dan print untuk menampilkan seluruh data dalam tabel hash.

## Unguided 

### 1. [Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :]

![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/883701be-f7cf-475d-aa3a-082e58c45aa9)

```C++
//Haifa Zahra Azzimmi
//2311102163

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int TABLE_SIZE = 10;

// Struktur data untuk setiap mahasiswa
struct Student {
    string nim;
    int grade;
    Student(string nim, int grade) : nim(nim), grade(grade) {}
};

// Node untuk menyimpan data mahasiswa
struct HashNode {
    vector<Student> students;
};

// Kelas Hash Table
class HashTable {
private:
    vector<HashNode> table;

public:
    HashTable() : table(TABLE_SIZE) {}

    // Fungsi hash untuk menentukan indeks penyimpanan berdasarkan NIM
    int hashFunc(string nim) {
        int hash_val = 0;
        for (char c : nim) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Fungsi untuk menambah data mahasiswa
    void insert(string nim, int grade) {
        int index = hashFunc(nim);
        table[index].students.push_back(Student(nim, grade));
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void remove(string nim) {
        int index = hashFunc(nim);
        vector<Student>& students = table[index].students;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->nim == nim) {
                students.erase(it);
                break;
            }
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void searchByNIM(string nim) {
        int index = hashFunc(nim);
        vector<Student>& students = table[index].students;
        for (const auto& student : students) {
            if (student.nim == nim) {
                cout << "Mahasiswa dengan NIM " << nim << " ditemukan dengan nilai " << student.grade << endl;
                return;
            }
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan" << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
    void searchByGradeRange() {
        cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
        for (const auto& node : table) {
            for (const auto& student : node.students) {
                if (student.grade >= 80 && student.grade <= 90) {
                    cout << "NIM: " << student.nim << ", Nilai: " << student.grade << endl;
                }
            }
        }
    }
};

int main() {
    HashTable studentTable;
    int choice;
    string nim;
    int grade;

    do {
        cout << "\nMenu:\n1. Tambah Data Mahasiswa\n2. Hapus Data Mahasiswa\n3. Cari Data Mahasiswa berdasarkan NIM\n4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80 - 90)\n5. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan NIM mahasiswa: ";
            cin >> nim;
            cout << "Masukkan nilai mahasiswa: ";
            cin >> grade;
            studentTable.insert(nim, grade);
            break;
        case 2:
            cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
            cin >> nim;
            studentTable.remove(nim);
            break;
        case 3:
            cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
            cin >> nim;
            studentTable.searchByNIM(nim);
            break;
        case 4:
            studentTable.searchByGradeRange();
            break;
        case 5:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Ulangi." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
```
#### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/62d6e8aa-eeae-4ebc-9042-1abebdfb6c2a)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/a32e3205-789b-4f79-9bac-94d7f0b21c46)
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/1c75ca32-68af-40ce-89e5-4966f78f7a4d)

Program di atas adalah implementasi dari Hash Table dalam C++. Program ini memungkinkan pengguna untuk menyimpan data mahasiswa berupa NIM dan nilai dalam sebuah hash table dengan ukuran tetap. 

## Kesimpulan
Hash Table adalah struktur data efisien yang menggunakan fungsi hash untuk menetapkan elemen ke indeks array. Fungsi hash yang baik memungkinkan distribusi key yang merata dan mengurangi collision. Ada teknik hashing seperti Truncation, Folding, dan Modular. Collision diatasi melalui Closed Hashing (Open Addressing) atau Open Hashing (Separate Chaining). Hash Table memungkinkan operasi penambahan dan pencarian yang cepat, ideal untuk data besar dan efisiensi operasi yang penting.


## Referensi
[1] http://repository.uin-malang.ac.id/15252/7/15252.pdf
