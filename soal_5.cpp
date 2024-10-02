#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data untuk menyimpan nilai mahasiswa
struct Mahasiswa {
    string nama;
    double nilai;
};

// Vector untuk menyimpan nilai mahasiswa
vector<Mahasiswa> nilai_mahasiswa;

// Fungsi untuk menambahkan nilai mahasiswa baru (soal a)
void tambah_nilai() {
    string nama_mahasiswa;
    double nilai;

    cout << "Masukkan nama mahasiswa: ";
    cin >> nama_mahasiswa;
    cout << "Masukkan nilai mahasiswa: ";
    cin >> nilai;

    nilai_mahasiswa.push_back({nama_mahasiswa, nilai});
    cout << "Nilai berhasil ditambahkan." << endl;
}

// Fungsi untuk menampilkan seluruh nilai mahasiswa (soal b)
void tampil_nilai() {
    cout << "\nDaftar seluruh nilai mahasiswa:\n";
    for (const auto& m : nilai_mahasiswa) {
        cout << "Nama: " << m.nama << ", Nilai: " << m.nilai << endl;
    }
}

// Fungsi untuk mencari dan menampilkan mahasiswa dengan nilai tertinggi (soal c)
void nilai_tertinggi() {
    if (nilai_mahasiswa.empty()) {
        cout << "Tidak ada nilai yang dicatat.\n";
        return;
    }

    Mahasiswa tertinggi = nilai_mahasiswa[0];
    for (const auto& m : nilai_mahasiswa) {
        if (m.nilai > tertinggi.nilai) {
            tertinggi = m;
        }
    }

    cout << "\nMahasiswa dengan nilai tertinggi adalah " << tertinggi.nama 
         << " dengan nilai " << tertinggi.nilai << ".\n";
}

// Fungsi untuk menghitung dan menampilkan rata-rata nilai mahasiswa (soal d)
void rata_rata_nilai() {
    if (nilai_mahasiswa.empty()) {
        cout << "Tidak ada nilai yang dicatat.\n";
        return;
    }

    double total_nilai = 0;
    for (const auto& m : nilai_mahasiswa) {
        total_nilai += m.nilai;
    }

    double rata_rata = total_nilai / nilai_mahasiswa.size();
    cout << "\nRata-rata nilai mahasiswa adalah: " << rata_rata << endl;
}

// Fungsi untuk memperbarui nilai mahasiswa berdasarkan nama (soal e)
void update_nilai(const string& nama_mahasiswa, double nilai_baru) {
    bool found = false;
    for (auto& m : nilai_mahasiswa) {
        if (m.nama == nama_mahasiswa) {
            m.nilai = nilai_baru;
            cout << "Nilai mahasiswa " << nama_mahasiswa << " telah diperbarui menjadi " << nilai_baru << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Mahasiswa dengan nama " << nama_mahasiswa << " tidak ditemukan.\n";
    }
}

// Main program
int main() {
    int jumlah_mahasiswa;

    cout << "Berapa banyak mahasiswa yang ingin ditambahkan nilainya? ";
    cin >> jumlah_mahasiswa;

    cout << "\n-------Soal a-------\n";
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        cout << "Mahasiswa ke-" << i + 1 << ":\n";
        tambah_nilai();
    }

    cout << "\n-------Soal b-------\n";
    tampil_nilai();

    cout << "\n-------Soal c-------\n";
    nilai_tertinggi();

    cout << "\n-------Soal d-------\n";
    rata_rata_nilai();

    cout << "\n-------Soal e-------\n";
    string nama_mahasiswa_update;
    double nilai_baru;
    cout << "Masukkan nama mahasiswa yang ingin diupdate nilainya: ";
    cin >> nama_mahasiswa_update;
    cout << "Masukkan nilai baru: ";
    cin >> nilai_baru;
    update_nilai(nama_mahasiswa_update, nilai_baru);

    cout << "\nNilai mahasiswa setelah update:\n";
    tampil_nilai();

    return 0;
}
