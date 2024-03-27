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