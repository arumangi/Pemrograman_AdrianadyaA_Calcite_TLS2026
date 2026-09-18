#include <iostream>

using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot: ";
    cin >> N;

    cout << "Masukkan angka untuk mengeliminasi: ";
    cin >> K;

    int astronot[100];
    int Urutan_Eliminasi[100];

    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int jumlah_astronot = N;
    int jumlah_eliminasi = 0;
    int posisi_awal = 0;

    while (jumlah_astronot > 1) {

        int idx = (posisi_awal + K - 1) % jumlah_astronot;

        int nomor_tereliminasi = astronot[idx];

        Urutan_Eliminasi[jumlah_eliminasi] = nomor_tereliminasi;
        jumlah_eliminasi++;

        for (int i = idx; i < jumlah_astronot - 1; i++) {
            astronot[i] = astronot[i + 1];
        }

        jumlah_astronot--;

        if (nomor_tereliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;

            if (K < 2) {
                K = 2;
            }
        }

        if (jumlah_astronot > 0) {
            posisi_awal = idx % jumlah_astronot;
        }
    }

    cout << "\nAstronot terakhir (PEMENANG): "
         << astronot[0] << endl;

    cout << "Urutan Eliminasi: ";

    for (int i = 0; i < jumlah_eliminasi; i++) {
        cout << Urutan_Eliminasi[i];

        if (i < jumlah_eliminasi - 1) {
            cout << endl;
        }
    }

    return 0;
} 