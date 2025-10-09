#include <iostream>
#include <string>
#include <algorithm> // untuk sort
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string kelas;
    string nilai;
};


void tampilData(Mahasiswa mhs[], int n) {
    cout << "\n=== DATA MAHASISWA ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". Nama  : " << mhs[i].nama << endl;
        cout << "   NIM   : " << mhs[i].nim << endl;
        cout << "   Kelas : " << mhs[i].kelas << endl;
        cout << "   Nilai : " << mhs[i].nilai << endl << endl;
    }
}

// Fungsi untuk mengurutkan data berdasarkan nama
void urutNama(Mahasiswa mhs[], int n) {
    sort(mhs, mhs + n, [](Mahasiswa a, Mahasiswa b) {
        return a.nama < b.nama;
    });
    cout << "\nData berhasil diurutkan berdasarkan NAMA (A-Z)\n";
}

// Fungsi untuk mengurutkan data berdasarkan NIM
void urutNIM(Mahasiswa mhs[], int n) {
    sort(mhs, mhs + n, [](Mahasiswa a, Mahasiswa b) {
        return a.nim < b.nim;
    });
    cout << "\nData berhasil diurutkan berdasarkan NIM (kecil ke besar)\n";
}

// Fungsi pencarian berdasarkan NIM
void cariNIM(Mahasiswa mhs[], int n, string cari) {
    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (mhs[i].nim == cari) {
            cout << "\nData ditemukan:\n";
            cout << "Nama  : " << mhs[i].nama << endl;
            cout << "NIM   : " << mhs[i].nim << endl;
            cout << "Kelas : " << mhs[i].kelas << endl;
            cout << "Nilai : " << mhs[i].nilai << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
        cout << "\nData dengan NIM " << cari << " tidak ditemukan.\n";
}

// Fungsi pencarian berdasarkan kelas
void cariKelas(Mahasiswa mhs[], int n, string cari) {
    bool ditemukan = false;
    cout << "\nMahasiswa dengan kelas " << cari << ":\n";
    for (int i = 0; i < n; i++) {
        if (mhs[i].kelas == cari) {
            cout << "- " << mhs[i].nama << " (" << mhs[i].nim << ") | Nilai: " << mhs[i].nilai << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan)
        cout << "Tidak ada mahasiswa di kelas " << cari << ".\n";
}

int main() {
    int n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore(); // membersihkan buffer

    Mahasiswa mhs[n];

    // Input data mahasiswa
    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        getline(cin, mhs[i].nama);
        cout << "NIM   : ";
        getline(cin, mhs[i].nim);
        cout << "Kelas : ";
        getline(cin, mhs[i].kelas);
        cout << "Nilai : ";
        getline(cin, mhs[i].nilai);
    }

    int pilihan;
    string cari;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Urutkan Berdasarkan Nama\n";
        cout << "3. Urutkan Berdasarkan NIM\n";
        cout << "4. Cari Berdasarkan NIM\n";
        cout << "5. Cari Berdasarkan Kelas\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tampilData(mhs, n);
                break;
            case 2:
                urutNama(mhs, n);
                tampilData(mhs, n);
                break;
            case 3:
                urutNIM(mhs, n);
                tampilData(mhs, n);
                break;
            case 4:
                cout << "Masukkan NIM yang dicari: ";
                getline(cin, cari);
                cariNIM(mhs, n, cari);
                break;
            case 5:
                cout << "Masukkan Kelas yang dicari: ";
                getline(cin, cari);
                cariKelas(mhs, n, cari);
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
