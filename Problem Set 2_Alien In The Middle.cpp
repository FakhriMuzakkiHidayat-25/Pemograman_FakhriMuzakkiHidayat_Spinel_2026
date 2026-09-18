#include <iostream>
using namespace std;

int hurufKePosisi(char c) {
    return (c - 'A') + 1;
}

char posisiKeHuruf(int pos) {
    return (char)('A' + (pos - 1));
}

int main() {
    char pesan[100];
    int panjang = 0;

    cout << "Masukkan pesan (huruf kapital, tanpa spasi): ";
    cin >> pesan;

    while (pesan[panjang] != '\0') {
        panjang++;
    }

    char hasil[100];

    hasil[0] = pesan[0];

    for (int i = 1; i < panjang; i++) {
        int posisiSekarang   = hurufKePosisi(pesan[i]);
        int posisiSebelumnya = hurufKePosisi(pesan[i - 1]);

        int posisiBaru = posisiSekarang + posisiSebelumnya;

        // jika hasil melewati Z (26), putar kembali mulai dari A
        while (posisiBaru > 26) {
            posisiBaru -= 26;
        }

        hasil[i] = posisiKeHuruf(posisiBaru);
    }
    hasil[panjang] = '\0';

    cout << "\nPesan asli  : " << pesan << endl;
    cout << "Pesan sandi : " << hasil << endl;

    return 0;
}
