#include <iostream>
#include <string>
using namespace std;

// Fungsi buang huruf vokal
string removeVowels(string s) {
    string res = "";
    for (char c : s) {
        char lower = tolower(c);
        if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
            res += c;
        }
    }
    return res;
}

// Fungsi membalik string manual (tanpa reverse bawaan)
string manualReverse(string s) {
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}

// Fungsi Encode
string encode(string kata) {
    string konsonan = removeVowels(kata);
    string dibalik = manualReverse(konsonan);

    int asciiVal = (int)kata[0]; // ASCII huruf pertama
    string asciiStr = to_string(asciiVal);

    // sisipkan ascii di tengah
    int mid = dibalik.size() / 2;
    return dibalik.substr(0, mid) + asciiStr + dibalik.substr(mid);
}

// Fungsi Decode
string decode(string sandi) {
    string angka = "";
    string kiri = "", kanan = "";

    // cari bagian angka (ASCII)
    for (char c : sandi) {
        if (isdigit(c)) angka += c;
        else if (angka.empty()) kiri += c;
        else kanan += c;
    }

    int asciiVal = stoi(angka);
    char hurufPertama = (char)asciiVal;

    // gabung kembali dan balik
    string sisa = kiri + kanan;
    string kembali = manualReverse(sisa);

    return kembali; // skeleton konsonan asli
}

int main() {
    cout << "=== Lost and Found Machine ===\n";
    cout << "Pilih mode: 1=Encode kata -> sandi, 2=Decode sandi -> pola\n";
    int mode; cin >> mode;

    if (mode == 1) {
        string kata;
        cout << "Masukkan kata asli (tanpa spasi): ";
        cin >> kata;
        cout << "Encoded password: " << encode(kata) << endl;
    } else if (mode == 2) {
        string sandi;
        cout << "Masukkan sandi: ";
        cin >> sandi;
        cout << "Reconstructed skeleton: " << decode(sandi) << endl;
    } else {
        cout << "Pilihan tidak valid!\n";
    }

    return 0;
}
