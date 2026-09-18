#include <iostream>
using namespace std;

int main() {
    int n, k;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> n;
    cout << "Masukkan nilai awal K: ";
    cin >> k;

    const int MAX_N = 1000; // batas maksimum jumlah astronot
    int astronot[MAX_N];

    // isi array dengan nomor astronot 1..N
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int sisa = n;   // jumlah astronot yang masih ada di lingkaran
    int posisi = 0; // index array untuk astronot nomor 1 (posisi awal hitungan)

    cout << "\nUrutan astronot yang dieliminasi:\n";

    while (sisa > 1) {
        // hitung index astronot yang mendapat hitungan ke-K
        posisi = (posisi + k - 1) % sisa;

        int tereliminasi = astronot[posisi];
        cout << tereliminasi << " ";

        // hapus astronot yang tereliminasi dengan menggeser array ke kiri
        for (int i = posisi; i < sisa - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        sisa--; // jumlah astronot berkurang 1

        // update nilai K sesuai aturan khusus
        if (tereliminasi % 2 == 0) {
            k += 2; // nomor genap -> K bertambah 2
        } else {
            k -= 1; // nomor ganjil -> K berkurang 1
        }
        if (k < 2) {
            k = 2; // K tidak boleh kurang dari 2
        }

        // posisi awal hitungan berikutnya = astronot tepat setelah yang tereliminasi
        if (sisa > 0) {
            posisi = posisi % sisa;
        }
    }

    cout << "\n\nAstronot terakhir yang bertahan: " << astronot[0] << endl;

    return 0;
}
