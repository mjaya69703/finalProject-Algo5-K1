#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

class StokAyam {
public:
    string jenis;
    float berat;
    float harga;
    int stok;

    StokAyam(string j, float b, float h, int s) : jenis(j), berat(b), harga(h), stok(s) {}
};

class Penjualan {
public:
    string jenisAyam;
    float berat;
    float totalHarga;

    Penjualan(string j, float b, float t) : jenisAyam(j), berat(b), totalHarga(t) {}
};

class ManajemenAyam {
private:
    vector<StokAyam> inventaris;
    vector<Penjualan> penjualanHarian;

public:
    void tambahStok(string jenis, float berat, float harga, int stok) {
        inventaris.emplace_back(jenis, berat, harga, stok);
        cout << "Stok berhasil ditambahkan.\n";
    }

    void tampilkanStok() {
        cout << "\nDaftar Stok Ayam:\n";
        cout << left << setw(15) << "Jenis" << setw(10) << "Berat" << setw(10) << "Harga" << "Stok" << endl;
        for (const auto &ayam : inventaris) {
            cout << left << setw(15) << ayam.jenis << setw(10) << ayam.berat << setw(10) << ayam.harga << ayam.stok << endl;
        }
    }

    void editStok() {
        if (inventaris.empty()) {
            cout << "Tidak ada stok ayam tersedia untuk diedit.\n";
            return;
        }

        cout << "\nDaftar Stok Ayam:\n";
        for (size_t i = 0; i < inventaris.size(); ++i) {
            cout << i + 1 << ". " << inventaris[i].jenis << " " << inventaris[i].berat << "kg (Stok: " << inventaris[i].stok << ")\n";
        }

        int pilihan;
        cout << "Pilih nomor stok ayam yang ingin diedit: ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > inventaris.size()) {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        StokAyam &ayamDipilih = inventaris[pilihan - 1];
        cout << "Edit data untuk " << ayamDipilih.jenis << ":\n";

        float berat, harga;
        int stok;
        cout << "Masukkan berat baru (kg): ";
        cin >> berat;
        cout << "Masukkan harga baru: ";
        cin >> harga;
        cout << "Masukkan jumlah stok baru: ";
        cin >> stok;

        ayamDipilih.berat = berat;
        ayamDipilih.harga = harga;
        ayamDipilih.stok = stok;

        cout << "Stok berhasil diperbarui.\n";
    }

    void prosesPenjualan() {
        if (inventaris.empty()) {
            cout << "Tidak ada stok ayam tersedia.\n";
            return;
        }

        cout << "\nStok Tersedia:\n";
        for (size_t i = 0; i < inventaris.size(); ++i) {
            cout << i + 1 << ". " << inventaris[i].jenis << " " << inventaris[i].berat << "kg (Stok: " << inventaris[i].stok << ")\n";
        }

        int pilihan;
        cout << "Pilih jenis ayam (masukkan nomor): ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > inventaris.size()) {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        StokAyam &ayamDipilih = inventaris[pilihan - 1];
        float berat;
        cout << "Masukkan berat yang dijual (kg): ";
        cin >> berat;

        if (berat > ayamDipilih.stok) {
            cout << "Stok tidak mencukupi.\n";
            return;
        }

        float totalHarga = berat * ayamDipilih.harga;
        penjualanHarian.emplace_back(ayamDipilih.jenis, berat, totalHarga);
        ayamDipilih.stok -= berat;

        cout << "Total harga: Rp " << totalHarga << endl;
        cout << "Penjualan berhasil diproses.\n";
    }

    void tampilkanPenjualan() {
        float totalBerat = 0;
        float totalPenghasilan = 0;

        cout << "\nLaporan Penjualan Harian:\n";
        cout << left << setw(15) << "Jenis Ayam" << setw(10) << "Berat" << "Total Harga" << endl;
        for (const auto &transaksi : penjualanHarian) {
            cout << left << setw(15) << transaksi.jenisAyam << setw(10) << transaksi.berat << transaksi.totalHarga << endl;
            totalBerat += transaksi.berat;
            totalPenghasilan += transaksi.totalHarga;
        }

        cout << "\nRingkasan Penjualan:\n";
        cout << "Total Berat Terjual: " << totalBerat << " kg\n";
        cout << "Total Penghasilan: Rp " << totalPenghasilan << endl;
    }
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    cout << "Tekan enter untuk melanjutkan...";
    cin.ignore();
    cin.get();
}

void menuPemilik(ManajemenAyam &manajemen) {
    int pilihan;
    while (true) {
        clearScreen();
        cout << "1. Tambah Stok\n";
        cout << "2. Tampilkan Stok\n";
        cout << "3. Edit Stok\n";
        cout << "4. Tampilkan Penjualan\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                clearScreen();
                string jenis;
                float berat, harga;
                int stok;
                cout << "Masukkan jenis ayam: ";
                cin.ignore();
                getline(cin, jenis);
                cout << "Masukkan berat ayam (kg): ";
                cin >> berat;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan jumlah stok: ";
                cin >> stok;
                manajemen.tambahStok(jenis, berat, harga, stok);
                pause();
                break;
            }
            case 2:
                clearScreen();
                manajemen.tampilkanStok();
                pause();
                break;
            case 3:
                clearScreen();
                manajemen.editStok();
                pause();
                break;
            case 4:
                clearScreen();
                manajemen.tampilkanPenjualan();
                pause();
                break;
            case 5:
                return;
            default:
                cout << "Pilihan tidak valid.\n";
                pause();
        }
    }
}

void menuKasir(ManajemenAyam &manajemen) {
    int pilihan;
    while (true) {
        clearScreen();
        cout << "1. Proses Penjualan\n";
        cout << "2. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                clearScreen();
                manajemen.prosesPenjualan();
                pause();
                break;
            }
            case 2:
                return;
            default:
                cout << "Pilihan tidak valid.\n";
                pause();
        }
    }
}

int main() {
    ManajemenAyam manajemen;
    int pilihan;

    while (true) {
        clearScreen();
        cout << "1. Login sebagai Pemilik\n";
        cout << "2. Login sebagai Kasir\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                menuPemilik(manajemen);
                break;
            case 2:
                menuKasir(manajemen);
                break;
            case 3:
                cout << "Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid.\n";
                pause();
        }
    }
}
