//Haifa Zahra Azzimmi
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
