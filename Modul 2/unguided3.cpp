#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << (i + 1) << ": ";
        cin >> arr[i];
    }

    int choice;
    cout << "Pilih operasi:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Hitung nilai rata-rata\n";
    cin >> choice;

    switch (choice) {
        case 1:
            {
                int max_val = *max_element(arr.begin(), arr.end());
                cout << "Nilai maksimum: " << max_val << endl;
            }
            break;
        case 2:
            {
                int min_val = *min_element(arr.begin(), arr.end());
                cout << "Nilai minimum: " << min_val << endl;
            }
            break;
        case 3:
            {
                int sum = 0;
                for (int num : arr) {
                    sum += num;
                }
                double avg = static_cast<double>(sum) / n;
                cout << "Nilai rata-rata: " << avg << endl;
            }
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            break;
    }

    return 0;
}
