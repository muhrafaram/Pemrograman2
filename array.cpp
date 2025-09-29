#include <iostream>
using namespace std;

int reverseNumber(int x) {
    if (x == 0) return 0;

    bool negatif = (x < 0);
    if (negatif) x = -x;

    int hasil = 0;
    while (x > 0) {
        int digit = x % 10;      
        hasil = hasil * 10 + digit;
        x = x / 10;
    }

    if (negatif) hasil = -hasil;
    return hasil;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[100]; 
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = 0;
    cout << "Array setelah transformasi:\n";
    for (int i = 0; i < n; i++) {
        int nilai = arr[i];
        if (i % 2 == 0) { 
            nilai = reverseNumber(nilai);
        }
        cout << nilai << " ";
        total += nilai;
    }
    cout << "\nJumlah total = " << total << endl;

    return 0;
}
