#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

// 🎨 Warna ANSI untuk tampilan terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

struct Mahasiswa {
    string nama;
    string nim;
    string kelas;
    string nilai;
};

// Fungsi untuk menampilkan semua data mahasiswa
void tampilData(Mahasiswa mhs[], int n) {
    cout << CYAN << "\n=== DATA MAHASISWA ===\n" << RESET;
    for (int i = 0; i < n; i++) {
        cout << YELLOW << i + 1 << ". " << RESET
             << BOLD << mhs[i].nama << RESET << endl;
        cout << "   " << BLUE << "NIM   : " << RESET << mhs[i].nim << endl;
        cout << "   " << MAGENTA << "Kelas : " << RESET << mhs[i].kelas << endl;
        cout << "   " << GREEN << "Nilai : " << RESET << mhs[i].nilai << endl;
        cout << WHITE << "---------------------------\n" << RESET;
    }
    cout << "\n" << YELLOW << "Tekan ENTER untuk kembali ke menu..." << RESET;
    cin.ignore();
    cin.get();
}

// Fungsi untuk mengurutkan data berdasarkan Nama
void urutNama(Mahasiswa mhs[], int n) {
    sort(mhs, mhs + n, [](Mahasiswa a, Mahasiswa b) {
        return a.nama < b.nama;
    });
    cout << GREEN << "\nData berhasil diurutkan berdasarkan Nama (A-Z)!\n" << RESET;
    tampilData(mhs, n);
}

// Fungsi untuk mengurutkan data berdasarkan NIM
void urutNIM(Mahasiswa mhs[], int n) {
    sort(mhs, mhs + n, [](Mahasiswa a, Mahasiswa b) {
        return a.nim < b.nim;
    });
    cout << GREEN << "\nData berhasil diurutkan berdasarkan NIM (kecil ke besar)!\n" << RESET;
    tampilData(mhs, n);
}

// Fungsi untuk mengurutkan data berdasarkan Nilai
void urutNilai(Mahasiswa mhs[], int n) {
    sort(mhs, mhs + n, [](Mahasiswa a, Mahasiswa b) {
        return stoi(a.nilai) > stoi(b.nilai); // besar ke kecil
    });
    cout << GREEN << "\nData berhasil diurutkan berdasarkan Nilai (tertinggi ke terendah)!\n" << RESET;
    tampilData(mhs, n);
}

// Fungsi untuk mencari data berdasarkan NIM
void cariNIM(Mahasiswa mhs[], int n) {
    string cari;
    cout << YELLOW << "Masukkan NIM yang ingin dicari: " << RESET;
    cin >> cari;
    bool ditemukan = false;
    for (int i = 0; i < n; i++) {
        if (mhs[i].nim == cari) {
            cout << GREEN << "\nData ditemukan!\n" << RESET;
            cout << BOLD << "Nama  : " << RESET << mhs[i].nama << endl;
            cout << BOLD << "NIM   : " << RESET << mhs[i].nim << endl;
            cout << BOLD << "Kelas : " << RESET << mhs[i].kelas << endl;
            cout << BOLD << "Nilai : " << RESET << mhs[i].nilai << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
        cout << RED << "Data dengan NIM " << cari << " tidak ditemukan.\n" << RESET;

    cout << "\n" << YELLOW << "Tekan ENTER untuk kembali ke menu..." << RESET;
    cin.ignore();
    cin.get();
}

// Fungsi untuk mencari data berdasarkan kelas
void cariKelas(Mahasiswa mhs[], int n) {
    string cari;
    cout << YELLOW << "Masukkan Kelas yang ingin dicari: " << RESET;
    cin >> cari;
    bool ditemukan = false;
    cout << CYAN << "\n=== HASIL PENCARIAN KELAS " << cari << " ===\n" << RESET;
    for (int i = 0; i < n; i++) {
        if (mhs[i].kelas == cari) {
            cout << BOLD << "Nama  : " << RESET << mhs[i].nama << endl;
            cout << "NIM   : " << mhs[i].nim << endl;
            cout << "Nilai : " << mhs[i].nilai << endl;
            cout << WHITE << "---------------------------\n" << RESET;
            ditemukan = true;
        }
    }
    if (!ditemukan)
        cout << RED << "Tidak ada mahasiswa di kelas " << cari << ".\n" << RESET;

    cout << "\n" << YELLOW << "Tekan ENTER untuk kembali ke menu..." << RESET;
    cin.ignore();
    cin.get();
}

int main() {
    Mahasiswa data[] = {
        {"MAULIA FITRI", "2513025002", "B", "90"},
        {"RAISYA PUTRI RAHAYU", "2513025004", "B", "85"},
        {"RADIET FEBRIAN S", "2513025006", "B", "88"},
        {"ARIEL SETIAWAN", "2513025008", "B", "92"},
        {"ANTIKA MAHARANI", "2513025010", "B", "87"},
        {"AURA RAHADATUL AIZY", "2513025012", "B", "90"},
        {"YOSINTA ARIYANI", "2513025014", "B", "85"},
        {"DORIS OLGA ULIMAZ ALZENA", "2513025016", "B", "88"},
        {"YURNI EFENDI", "2513025018", "B", "92"},
        {"EKA DYTA SARI", "2513025020", "B", "87"},
        {"RATU NABILA ULFA", "2513025022", "B", "88"},
        {"FAUZAN RADITIYA", "2513025024", "B", "90"},
        {"HAURA AZRA AFFIFAH", "2513025026", "B", "85"},
        {"LARASATI", "2513025028", "B", "88"},
        {"SYARAFINA NASHFATI GHAISANI ARIF", "2513025030", "B", "92"},
        {"MUHAMMAD KAHFI ASAFA", "2513025032", "B", "87"},
        {"NOFA ARIKO ALDIYANSYAH", "2513025034", "B", "90"},
        {"NOVITA RAHAYU", "2513025036", "B", "85"},
        {"AZ ZAHRA PUTRI AULIA", "2513025038", "B", "88"},
        {"JENI ANGGRAINI", "2513025040", "B", "92"},
        {"TYAS SYAFA PRATIWI", "2513025042", "B", "87"},
        {"NADIA VALENTINA", "2513025044", "B", "88"},
        {"ASIFA DWI LESTARI", "2513025046", "B", "90"},
        {"ERIK MEDIYANTO", "2513025048", "B", "85"},
        {"MUHAMMAD ADITYA RAHMAN", "2513025050", "B", "88"},
        {"REZA PRAWIRA ADIJAYA", "2513025052", "B", "92"},
        {"SULISTIAH", "2513025054", "B", "87"},
        {"SHYPA RAHMAWATI", "2513025056", "B", "90"},
        {"AHMAD AVICENA KOMAROV", "2513025058", "B", "85"},
        {"AZHIMI ALMI SWAY UMPU", "2513025060", "B", "88"},
        {"BERLIANTINA JULIA PUTRI", "2513025062", "B", "92"},
        {"M. JEFRI AKBAR", "2513025064", "B", "87"},
        {"TEGAR PUJIONO", "2513025066", "B", "88"},
        {"AL RIFQII SULTHAAN PRADHANA", "2513025068", "B", "90"},
        {"NISWA REGINA PUTRI", "2513025070", "B", "85"},
        {"MAWADDATUL FADILAH", "2513025072", "B", "88"},
        {"G. PUSPO VALENRICO PANGESTU", "2513025074", "B", "92"},
        {"RIFAL SANI PIRMANSYAH", "2553025001", "B", "90"}
    };

    int n = sizeof(data) / sizeof(data[0]);
    int pilihan;

    do {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        cout << BOLD << CYAN << "===== MENU DATA MAHASISWA =====\n" << RESET;
        cout << YELLOW << "1. " << RESET << "Tampilkan semua data\n";
        cout << YELLOW << "2. " << RESET << "Urutkan berdasarkan Nama\n";
        cout << YELLOW << "3. " << RESET << "Urutkan berdasarkan NIM\n";
        cout << YELLOW << "4. " << RESET << "Urutkan berdasarkan Nilai\n";
        cout << YELLOW << "5. " << RESET << "Cari berdasarkan NIM\n";
        cout << YELLOW << "6. " << RESET << "Cari berdasarkan Kelas\n";
        cout << YELLOW << "7. " << RESET << RED << "Keluar\n" << RESET;
        cout << BLUE << "Pilih menu (1-7): " << RESET;

        cin >> pilihan;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1: tampilData(data, n); break;
            case 2: urutNama(data, n); break;
            case 3: urutNIM(data, n); break;
            case 4: urutNilai(data, n); break;
            case 5: cariNIM(data, n); break;
            case 6: cariKelas(data, n); break;
            case 7:
                cout << GREEN << "Terima kasih telah menggunakan program ini!\n" << RESET;
                break;
            default:
                cout << RED << "Pilihan tidak valid!\n" << RESET;
                cout << YELLOW << "Tekan ENTER untuk kembali ke menu..." << RESET;
                cin.get();
        }
    } while (pilihan != 7);

    return 0;
}
