#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk menyimpan produk
struct Produk {
    string nama;
    double harga;
    int stok;
};

// Vector untuk menyimpan produk
vector<Produk> list_produk;

// Fungsi untuk menambahkan produk (soal a)
void tambah_produk() {
    string nama;
    double harga;
    int stok;

    cout << "Masukkan nama barang: ";
    cin >> nama;
    cout << "Masukkan harga barang: ";
    cin >> harga;
    cout << "Masukkan stok barang: ";
    cin >> stok;

    list_produk.push_back({nama, harga, stok});
    cout << "Produk berhasil ditambahkan." << endl;
}

// Fungsi untuk menampilkan seluruh produk (soal b)
void tampil_produk() {
    cout << "\nDaftar produk:\n";
    for (const auto& p : list_produk) {
        cout << "Nama: " << p.nama << ", Harga: " << p.harga << ", Stok: " << p.stok << endl;
    }
}

// Fungsi untuk mencari dan menampilkan produk termahal (soal c)
void produk_termahal() {
    if (list_produk.empty()) {
        cout << "Tidak ada produk.\n";
        return;
    }

    Produk termahal = list_produk[0];
    for (const auto& p : list_produk) {
        if (p.harga > termahal.harga) {
            termahal = p;
        }
    }

    cout << "\nProduk termahal adalah " << termahal.nama 
         << " dengan harga " << termahal.harga 
         << " dan stok " << termahal.stok << ".\n";
}

// Fungsi untuk menghitung rata-rata harga produk (soal d)
void rata_rata_harga() {
    if (list_produk.empty()) {
        cout << "Tidak ada produk.\n";
        return;
    }

    double total_harga = 0;
    for (const auto& p : list_produk) {
        total_harga += p.harga;
    }

    double rata2 = total_harga / list_produk.size();
    cout << "\nRata-rata harga produk adalah: " << rata2 << endl;
}

// Fungsi untuk memperbarui stok produk berdasarkan nama produk (soal e)
void update_stok(const string& nama, int stok_baru) {
    bool found = false;
    for (auto& p : list_produk) {
        if (p.nama == nama) {
            p.stok = stok_baru;
            cout << "Stok produk " << nama << " diperbarui menjadi " << stok_baru << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Produk dengan nama " << nama << " tidak ditemukan.\n";
    }
}

// Main program
int main() {
    int jumlah_produk;

    cout << "Berapa banyak produk yang ingin ditambahkan? ";
    cin >> jumlah_produk;

    cout << "\n-------Soal a-------\n";
    for (int i = 0; i < jumlah_produk; i++) {
        cout << "Produk ke-" << i + 1 << ":\n";
        tambah_produk();
    }

    cout << "\n-------Soal b-------\n";
    tampil_produk();

    cout << "\n-------Soal c-------\n";
    produk_termahal();

    cout << "\n-------Soal d-------\n";
    rata_rata_harga();

    cout << "\n-------Soal e-------\n";
    string nama_update;
    int stok_update;
    cout << "Masukkan nama produk yang ingin diupdate stoknya: ";
    cin >> nama_update;
    cout << "Masukkan stok baru: ";
    cin >> stok_update;
    update_stok(nama_update, stok_update);

    cout << "\nProduk setelah update stok:\n";
    tampil_produk();

    return 0;
}
