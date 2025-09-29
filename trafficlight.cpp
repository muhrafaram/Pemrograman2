#include <iostream>
using namespace std;

string trafficLight(long long t) {
    long long cycle = 103; // 20 hijau + 3 kuning + 80 merah

    if (t < 45) {
        if (t >= 1 && t <= 25) return "Merah";
        else if (t >= 26 && t <= 40) return "Hijau";
        else if (t >= 41 && t <= 44) return "Merah";
        else return "Belum ada lampu (t=0)";
    } 
    else {
        long long rel = (t - 45) % cycle;
        if (rel < 3) return "Kuning";        
        else if (rel < 83) return "Merah";   
        else return "Hijau";                 
    }
}

int main() {
    long long t;
    cout << "Masukkan detik t: ";
    cin >> t;
    cout << "Warna lampu: " << trafficLight(t) << endl;

    return 0;
}
