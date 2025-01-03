#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ManajemenAyam {
private:
    struct StokAyam {
        string jenis;
        float berat;
        float harga;
        int stok;
        StokAyam *next;
    };

    struct Penjualan {
        string jenisAyam;
        float berat;
        float totalHarga;
        Penjualan *next;
    };

    StokAyam *headStok;
    Penjualan *headPenjualan;

public:
    ManajemenAyam() : headStok(nullptr), headPenjualan(nullptr) {}

    ~ManajemenAyam() {
        while (headStok) {
            StokAyam *temp = headStok;
            headStok = headStok->next;
            delete temp;
        }

        while (headPenjualan) {
            Penjualan *temp = headPenjualan;
            headPenjualan = headPenjualan->next;
            delete temp;
        }
    }

    void tambahStok(const string &jenisAyam, float beratAyam, float hargaAyam, int jumlahStokAyam) {
        StokAyam *baru = new StokAyam{jenisAyam, beratAyam, hargaAyam, jumlahStokAyam, headStok};
        headStok = baru;
        cout << "Stok berhasil ditambahkan.\n";
    }

    void tampilkanStok() {
        cout << "\nDaftar Stok Ayam:\n";
        cout << left << setw(15) << "Jenis" << setw(10) << "Berat" << setw(10) << "Harga" << "Stok" << endl;
        StokAyam *current = headStok;
        while (current) {
            cout << left << setw(15) << current->jenis << setw(10) << current->berat << setw(10) << current->harga << current->stok << endl;
            current = current->next;
        }
    }

    void editStok() {
        if (!headStok) {
            cout << "Tidak ada stok ayam tersedia untuk diedit.\n";
            return;
        }

        tampilkanStok();

        string jenisAyam;
        cout << "Masukkan jenis ayam yang ingin diedit: ";
        cin.ignore();
        getline(cin, jenisAyam);

        StokAyam *current = headStok;
        while (current && current->jenis != jenisAyam) {
            current = current->next;
        }

        if (!current) {
            cout << "Jenis ayam tidak ditemukan.\n";
            return;
        }

        float berat, harga;
        int stok;
        cout << "Masukkan berat baru (kg): ";
        cin >> berat;
        cout << "Masukkan harga baru: ";
        cin >> harga;
        cout << "Masukkan jumlah stok baru: ";
        cin >> stok;

        current->berat = berat;
        current->harga = harga;
        current->stok = stok;

        cout << "Stok berhasil diperbarui.\n";
    }

    void prosesPenjualan() {
        if (!headStok) {
            cout << "Tidak ada stok ayam tersedia.\n";
            return;
        }

        tampilkanStok();

        string jenisAyam;
        float berat;
        cout << "Masukkan jenis ayam yang dijual: ";
        cin.ignore();
        getline(cin, jenisAyam);
        cout << "Masukkan berat yang dijual (kg): ";
        cin >> berat;

        StokAyam *current = headStok;
        while (current && current->jenis != jenisAyam) {
            current = current->next;
        }

        if (!current) {
            cout << "Jenis ayam tidak ditemukan.\n";
            return;
        }

        if (berat > current->stok) {
            cout << "Stok tidak mencukupi.\n";
            return;
        }

        float totalHarga = berat * current->harga;
        Penjualan *baru = new Penjualan{jenisAyam, berat, totalHarga, headPenjualan};
        headPenjualan = baru;

        current->stok -= berat;

        cout << "Total harga: Rp " << totalHarga << endl;
        cout << "Penjualan berhasil diproses.\n";
    }

    void tampilkanPenjualan() {
        float totalBerat = 0;
        float totalPenghasilan = 0;

        cout << "\nLaporan Penjualan Harian:\n";
        cout << left << setw(15) << "Jenis Ayam" << setw(10) << "Berat" << "Total Harga" << endl;

        Penjualan *current = headPenjualan;
        while (current) {
            cout << left << setw(15) << current->jenisAyam << setw(10) << current->berat << current->totalHarga << endl;
            totalBerat += current->berat;
            totalPenghasilan += current->totalHarga;
            current = current->next;
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
