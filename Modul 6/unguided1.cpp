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
