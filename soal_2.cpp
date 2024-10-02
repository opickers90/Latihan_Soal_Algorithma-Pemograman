#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk transaksi
struct Transaksi {
    string jenis;  // "pemasukan" atau "pengeluaran"
    string kategori;
    double jumlah;
};

// Vector untuk menyimpan transaksi
vector<Transaksi> transaksi;

// Fungsi untuk mencatat transaksi (soal a)
void catat_transaksi() {
    string jenis, kategori;
    double jumlah;

    cout << "Masukkan jenis transaksi (pemasukan/pengeluaran): ";
    cin >> jenis;
    cout << "Masukkan kategori transaksi: ";
    cin >> kategori;
    cout << "Masukkan jumlah transaksi: ";
    cin >> jumlah;

    transaksi.push_back({jenis, kategori, jumlah});
    cout << "Transaksi berhasil dicatat." << endl;
}

// Fungsi untuk menampilkan seluruh transaksi (soal b)
void tampil_transaksi() {
    cout << "\nDaftar seluruh transaksi:\n";
    for (const auto& t : transaksi) {
        cout << "Jenis: " << t.jenis << ", Kategori: " << t.kategori << ", Jumlah: " << t.jumlah << endl;
    }
}

// Fungsi untuk menghitung saldo akhir (soal c)
void saldo_akhir() {
    double total_pemasukan = 0;
    double total_pengeluaran = 0;

    for (const auto& t : transaksi) {
        if (t.jenis == "pemasukan") {
            total_pemasukan += t.jumlah;
        } else if (t.jenis == "pengeluaran") {
            total_pengeluaran += t.jumlah;
        }
    }

    double saldo = total_pemasukan - total_pengeluaran;
    cout << "\nSaldo akhir: " << saldo << endl;
}

// Fungsi untuk mencari dan menampilkan pengeluaran terbesar (soal d)
void pengeluaran_terbesar() {
    double terbesar = 0;
    string kategori_terbesar;

    for (const auto& t : transaksi) {
        if (t.jenis == "pengeluaran" && t.jumlah > terbesar) {
            terbesar = t.jumlah;
            kategori_terbesar = t.kategori;
        }
    }

    if (terbesar > 0) {
        cout << "\nPengeluaran terbesar adalah kategori: " << kategori_terbesar << " dengan jumlah: " << terbesar << endl;
    } else {
        cout << "\nTidak ada pengeluaran yang dicatat." << endl;
    }
}

// Fungsi untuk menghitung rata-rata pengeluaran (soal e)
void rata_rata_pengeluaran() {
    double total_pengeluaran = 0;
    int jumlah_pengeluaran = 0;

    for (const auto& t : transaksi) {
        if (t.jenis == "pengeluaran") {
            total_pengeluaran += t.jumlah;
            jumlah_pengeluaran++;
        }
    }

    if (jumlah_pengeluaran > 0) {
        double rata_rata = total_pengeluaran / jumlah_pengeluaran;
        cout << "\nRata-rata pengeluaran per kategori: " << rata_rata << endl;
    } else {
        cout << "\nTidak ada pengeluaran untuk dihitung rata-rata." << endl;
    }
}

// Main program
int main() {
    int jumlah_transaksi;

    cout << "Berapa banyak transaksi yang ingin dicatat? ";
    cin >> jumlah_transaksi;

    cout << "\n-------Soal a-------\n";
    for (int i = 0; i < jumlah_transaksi; i++) {
        cout << "Transaksi ke-" << i + 1 << ":\n";
        catat_transaksi();
    }

    cout << "\n-------Soal b-------\n";
    tampil_transaksi();

    cout << "\n-------Soal c-------\n";
    saldo_akhir();

    cout << "\n-------Soal d-------\n";
    pengeluaran_terbesar();

    cout << "\n-------Soal e-------\n";
    rata_rata_pengeluaran();

    return 0;
}
