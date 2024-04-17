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
  