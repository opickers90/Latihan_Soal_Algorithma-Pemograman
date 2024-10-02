#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Struktur data untuk reservasi
struct Reservasi {
    string nomor_kamar;
    string nama_tamu;
    double harga_per_malam;
    int jumlah_malam;
};

// Vector untuk menyimpan reservasi
vector<Reservasi> reservasi;

// Fungsi untuk mencatat pemesanan kamar baru (soal a)
void catat_reservasi() {
    string nomor_kamar, nama_tamu;
    double harga_per_malam;
    int jumlah_malam;

    cout << "Masukkan nomor kamar: ";
    cin >> nomor_kamar;
    cout << "Masukkan nama tamu: ";
    cin >> nama_tamu;
    cout << "Masukkan harga per malam: ";
    cin >> harga_per_malam;
    cout << "Masukkan jumlah malam: ";
    cin >> jumlah_malam;

    reservasi.push_back({nomor_kamar, nama_tamu, harga_per_malam, jumlah_malam});
    cout << "Reservasi berhasil dicatat." << endl;
}

// Fungsi untuk menampilkan seluruh reservasi (soal b)
void tampil_reservasi() {
    cout << "\nDaftar seluruh reservasi:\n";
    for (const auto& r : reservasi) {
        cout << "Nomor kamar: " << r.nomor_kamar << ", Nama tamu: " << r.nama_tamu 
             << ", Harga per malam: " << r.harga_per_malam << ", Jumlah malam: " << r.jumlah_malam << endl;
    }
}

// Fungsi untuk mencari kamar yang paling sering dipesan (soal c)
void kamar_tersering() {
    if (reservasi.empty()) {
        cout << "Tidak ada reservasi.\n";
        return;
    }

    unordered_map<string, int> freq;
    for (const auto& r : reservasi) {
        freq[r.nomor_kamar]++;
    }

    string kamar_terbanyak;
    int max_freq = 0;
    for (const auto& pair : freq) {
        if (pair.second > max_freq) {
            kamar_terbanyak = pair.first;
            max_freq = pair.second;
        }
    }

    cout << "\nKamar yang paling sering dipesan adalah kamar nomor " << kamar_terbanyak 
         << " dengan " << max_freq << " kali pemesanan.\n";
}

// Fungsi untuk menghitung total pendapatan hotel (soal d)
void total_pendapatan() {
    double total = 0;
    for (const auto& r : reservasi) {
        total += r.harga_per_malam * r.jumlah_malam;
    }
    cout << "\nTotal pendapatan hotel adalah: " << total << endl;
}

// Fungsi untuk memperbarui status ketersediaan kamar (soal e)
void update_ketersediaan_kamar(const string& nomor_kamar) {
    bool found = false;
    for (const auto& r : reservasi) {
        if (r.nomor_kamar == nomor_kamar) {
            cout << "Ketersediaan kamar nomor " << nomor_kamar << " telah diperbarui." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Kamar nomor " << nomor_kamar << " tidak ditemukan." << endl;
    }
}

// Main program
int main() {
    int jumlah_reservasi;

    cout << "Berapa banyak reservasi yang ingin dicatat? ";
    cin >> jumlah_reservasi;

    cout << "\n-------Soal a-------\n";
    for (int i = 0; i < jumlah_reservasi; i++) {
        cout << "Reservasi ke-" << i + 1 << ":\n";
        catat_reservasi();
    }

    cout << "\n-------Soal b-------\n";
    tampil_reservasi();

    cout << "\n-------Soal c-------\n";
    kamar_tersering();

    cout << "\n-------Soal d-------\n";
    total_pendapatan();

    cout << "\n-------Soal e-------\n";
    string nomor_kamar_update;
    cout << "Masukkan nomor kamar yang ingin diupdate ketersediaannya: ";
    cin >> nomor_kamar_update;
    update_ketersediaan_kamar(nomor_kamar_update);

    return 0;
}
