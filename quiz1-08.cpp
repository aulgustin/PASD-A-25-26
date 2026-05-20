#include <iostream>
using namespace std;

int sequentialSearch(string A[], int n, string target);
void tampilkanData(string A[], int n);

int main() {
    const int MAX = 10;
    string nomorKendaraan[MAX];
    int jumlahKendaraan = 0;
    int pilihan;

    cout << "********************************" << endl;
    cout << "**   SISTEM PARKIR MALL       **" << endl;
    cout << "********************************" << endl;

    do {
        cout << "========= MENU UTAMA =========" << endl;
        cout << "1. Input Data Kendaraan" << endl;
        cout << "2. Cari Kendaraan" << endl;
        cout << "3. Keluar" << endl;
        cout << "==============================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "--- INPUT DATA KENDARAAN ---" << endl;
                int tambah;
                cout << "Berapa kendaraan yang ingin ditambahkan? ";
                cin >> tambah;

                for (int i = 0; i < tambah; i++) {
                    if (jumlahKendaraan >= MAX) {
                        cout << "Parkiran penuh!" << endl;
                        break;
                    }
                    cout << "Nomor kendaraan [" << jumlahKendaraan << "]: ";
                    cin >> nomorKendaraan[jumlahKendaraan];
                    jumlahKendaraan++;
                }

                cout << "Data berhasil ditambahkan!" << endl;
                tampilkanData(nomorKendaraan, jumlahKendaraan);
                break;
            }

            case 2: {
                cout << "--- CARI KENDARAAN ---" << endl;
                if (jumlahKendaraan == 0) {
                    cout << "Belum ada data kendaraan!" << endl;
                    break;
                }

                tampilkanData(nomorKendaraan, jumlahKendaraan);
                string cari;
                cout << "Masukkan nomor kendaraan yang dicari: ";
                cin >> cari;

                int hasil = sequentialSearch(nomorKendaraan, jumlahKendaraan, cari);

                if (hasil != -1)
                    cout << "Kendaraan " << cari << " DITEMUKAN pada index: [" << hasil << "]" << endl;
                else
                    cout << "Data kendaraan " << cari << " TIDAK ADA dalam parkiran." << endl;
                break;
            }

            case 3: {
                cout << "Terima kasih! Program selesai." << endl;
                break;
            }

            default: {
                cout << "Pilihan tidak valid! Silakan pilih 1-3." << endl;
                break;
            }
        }

    } while (pilihan != 3);

    return 0;
}

int sequentialSearch(string A[], int n, string target) {
    for (int i = 0; i < n; i++) {
        if (A[i] == target)
            return i;
    }
    return -1;
}

void tampilkanData(string A[], int n) {
    cout << "\n--- Data Parkiran Saat Ini ---" << endl;
    if (n == 0) {
        cout << "Tidak ada data." << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "Index [" << i << "] --> " << A[i] << endl;
    }
    cout << "Total kendaraan: " << n << endl;
}