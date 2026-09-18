#include <iostream>

using namespace std;

bool cek_huruf(char huruf) {
    if ((huruf >= 'A' && huruf <= 'Z') ||
        (huruf >= 'a' && huruf <= 'z')) {
        return true;
    }

    return false;
}

char ubah_besar(char huruf) {
    if (huruf >= 'a' && huruf <= 'z') {
        return huruf - 'a' + 'A';
    }

    return huruf;
}

int nilai_alphabet(char huruf) {
    char h = ubah_besar(huruf);

    if (h >= 'A' && h <= 'Z') {
        return h - 'A' + 1;
    }

    return 0;
}

char karakter_alphabet(int nilai) {
    if (nilai >= 1 && nilai <= 26) {
        return nilai + 'A' - 1;
    }

    return ' ';
}

int main() {
    char pesan_asli[100];
    char kode_akhir[100];

    int nilai_baru = 0;
    int nilai_sekarang = 0;
    int first_char = 0;
    int i = 0;

    cout << "Masukkan pesan Anda: ";
    cin.getline(pesan_asli, 100);

    for (int j = 0; pesan_asli[j] != '\0'; j++) {

        char huruf = pesan_asli[j];

        if (!cek_huruf(huruf)) {
            kode_akhir[i] = huruf;
            i++;
            continue;
        }

        nilai_sekarang = nilai_alphabet(huruf);
        nilai_baru = first_char + nilai_sekarang;

        if (nilai_baru > 26) {
            nilai_baru = nilai_baru - 26;
        }

        kode_akhir[i] = karakter_alphabet(nilai_baru);
        i++;

        first_char = nilai_sekarang;
    }

    kode_akhir[i] = '\0';

    cout << "Hasil kode akhir: " << kode_akhir << endl;
    cout << "Proses selesai" << endl;

    return 0;
}