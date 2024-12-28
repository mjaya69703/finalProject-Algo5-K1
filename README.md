# Final Project: Sistem Manajemen Bisnis Ayam Potong

## Deskripsi Proyek
Sistem ini adalah sebuah **Sistem Manajemen Bisnis Ayam Potong** yang dirancang untuk membantu pengelolaan stok, penjualan, dan analisis bisnis pada skala UMKM. Proyek ini dikembangkan berdasarkan pengamatan dan penelitian kelompok terhadap Bisnis UMKM Ayam Potong Sejahtera.

## Fitur Utama
1. **Manajemen Stok**:
   - Tambah, tampilkan, dan edit data stok ayam.
   - Memastikan ketersediaan stok secara real-time.

2. **Proses Penjualan**:
   - Pencatatan transaksi penjualan dengan informasi detail seperti berat dan harga.
   - Pengurangan stok otomatis setelah penjualan.

3. **Laporan Penjualan Harian**:
   - Menampilkan semua transaksi penjualan yang terjadi dalam satu hari.
   - Menyediakan ringkasan berupa total berat terjual dan total penghasilan harian.

4. **Akses Terpisah**:
   - **Pemilik**:
     - Mengelola stok, melihat laporan penjualan, dan mengakses fitur penuh.
   - **Kasir**:
     - Fokus hanya pada proses penjualan.

## Teknologi yang Digunakan
- **Bahasa Pemrograman**: C++
- **Lingkungan Pengembangan**: Kompiler C++ seperti GCC dan Visual Studio beserta Kompiler c++ ``OnlineGDB.com`` .

## Struktur Program
1. **Kelas Utama**:
   - `StokAyam`: Menyimpan data ayam seperti jenis, berat, harga, dan jumlah stok.
   - `Penjualan`: Menyimpan data transaksi penjualan.
   - `ManajemenAyam`: Mengelola stok, penjualan, dan laporan.

2. **Fungsi Utama**:
   - `tambahStok`: Menambah stok ayam baru.
   - `tampilkanStok`: Menampilkan daftar stok ayam.
   - `editStok`: Mengedit data stok ayam yang sudah ada.
   - `prosesPenjualan`: Mencatat transaksi penjualan dan mengurangi stok.
   - `tampilkanPenjualan`: Menampilkan laporan harian beserta ringkasan.

3. **Menu**:
   - **Pemilik**: Mengakses fitur penuh (stok, penjualan, laporan).
   - **Kasir**: Mengakses fitur proses penjualan saja.

## Cara Menjalankan Program Pada Compiler Online
1. Buka browser favorit anda dan kunjungi situs OnlineGDB
   ```
   https://www.onlinegdb.com/online_c++_compiler
   ```
2. Buka file main.cpp > Copy semua script pada main.cpp ke bagian script yang disediakan

3. Jalankan program dengan mengklik tombol Run di pojok kiri atas

4. Pilih login sebagai **Pemilik** atau **Kasir** sesuai kebutuhan.

5. Gunakan menu yang tersedia untuk mengelola stok dan penjualan.

## Cara Menjalankan Program Pada Device Pribadi
1. Kompilasi file sumber menggunakan perintah:
   ```
   g++ -o main main.cpp
   ```

2. Jalankan program:
   ```
   ./main
   ```

3. Pilih login sebagai **Pemilik** atau **Kasir** sesuai kebutuhan.

4. Gunakan menu yang tersedia untuk mengelola stok dan penjualan.

## Struktur File
```
.
├── main.cpp             # File utama program
└── README.md            # Dokumentasi proyek
```

## Kontributor
- Kelompok 1
  - Muhamad Jaya Kusuma
  - David Abadi Anugrah
  - Daffa Rizki Ariyanto
  - Rizky Febrian


---

> Proyek ini dikembangkan sebagai bagian dari tugas akhir mata kuliah **Algoritma dan Pemrograman Dasar** Semester 1 di Universitas Cakrawala. Sistem ini diharapkan dapat memberikan solusi praktis bagi UMKM dalam mengelola bisnis ayam potong mereka.
