#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk menyimpan barang inventaris
struct Barang {
    string nama;
    int stok;
    double harga_satuan;
};

// Vector untuk menyimpan barang-barang di gudang
vector<Barang> inventaris;

// Fungsi untuk menambahkan barang baru (soal a)
void tambah_barang() {
    string nama_barang;
    int stok;
    double harga_satuan;

    cout << "Masukkan nama barang: ";
    cin >> nama_barang;
    cout << "Masukkan jumlah stok: ";
    cin >> stok;
    cout << "Masukkan harga satuan: ";
    cin >> harga_satuan;

    inventaris.push_back({nama_barang, stok, harga_satuan});
    cout << "Barang berhasil ditambahkan." << endl;
}

// Fungsi untuk menampilkan seluruh barang di dalam inventaris (soal b)
void tampil_inventaris() {
    cout << "\nDaftar seluruh barang di dalam inventaris:\n";
    for (const auto& b : inventaris) {
        cout << "Nama barang: " << b.nama << ", Stok: " << b.stok 
             << ", Harga satuan: " << b.harga_satuan << endl;
    }
}

// Fungsi untuk mencari dan menampilkan barang dengan stok terendah (soal c)
void barang_stok_terendah() {
    if (inventaris.empty()) {
        cout << "Tidak ada barang dalam inventaris." << endl;
        return;
    }

    Barang stok_terendah = inventaris[0];
    for (const auto& b : inventaris) {
        if (b.stok < stok_terendah.stok) {
            stok_terendah = b;
        }
    }

    cout << "\nBarang dengan stok terendah adalah " << stok_terendah.nama 
         << " dengan stok " << stok_terendah.stok << "." << endl;
}

// Fungsi untuk menghitung dan menampilkan total nilai inventaris (soal d)
void total_nilai_inventaris() {
    double total_nilai = 0;
    for (const auto& b : inventaris) {
        total_nilai += b.stok * b.harga_satuan;
    }

    cout << "\nTotal nilai inventaris adalah: " << total_nilai << endl;
}

// Fungsi untuk memperbarui stok barang berdasarkan nama barang (soal e)
void update_stok(const string& nama_barang, int stok_baru) {
    bool found = false;
    for (auto& b : inventaris) {
        if (b.nama == nama_barang) {
            b.stok = stok_baru;
            cout << "Stok barang " << nama_barang << " telah diperbarui menjadi " << stok_baru << "." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Barang dengan nama " << nama_barang << " tidak ditemukan." << endl;
    }
}

// Main program
int main() {
    int jumlah_barang;

    cout << "Berapa banyak barang yang ingin ditambahkan? ";
    cin >> jumlah_barang;

    cout << "\n-------Soal a-------\n";
    for (int i = 0; i < jumlah_barang; i++) {
        cout << "Barang ke-" << i + 1 << ":\n";
        tambah_barang();
    }

    cout << "\n-------Soal b-------\n";
    tampil_inventaris();

    cout << "\n-------Soal c-------\n";
    barang_stok_terendah();

    cout << "\n-------Soal d-------\n";
    total_nilai_inventaris();

    cout << "\n-------Soal e-------\n";
    string nama_barang_update;
    int stok_update;
    cout << "Masukkan nama barang yang ingin diupdate stoknya: ";
    cin >> nama_barang_update;
    cout << "Masukkan stok baru: ";
    cin >> stok_update;
    update_stok(nama_barang_update, stok_update);

    cout << "\nBarang setelah update stok:\n";
    tampil_inventaris();

    return 0;
}
