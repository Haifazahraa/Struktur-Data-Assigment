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