#include <iostream>
using namespace std;

int arr[]={1,2,3,4,5,6,7,8,9,10,15,14};
int cari = 15;
bool ketemu = false;
int panjangArray = sizeof(arr)/sizeof(arr[0]);
int i;

int main()
{
    for (i = 0; i < panjangArray; i++){
        if(arr[i] == cari) {
            ketemu = true;
            break;
        } else {
            i++;
        }
    }

    cout << "Panjang Array : " << panjangArray <<endl;
    cout << cari << " Terdapat pada index ke- " << i;
}