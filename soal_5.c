#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 100

// Struktur data untuk menyimpan nilai mahasiswa
struct Mahasiswa {
    char nama[50];
    double nilai;
};

// Array untuk menyimpan nilai mahasiswa
struct Mahasiswa nilai_mahasiswa[MAX_MAHASISWA];
int jumlah_mahasiswa = 0;

// Fungsi untuk menambahkan nilai mahasiswa baru (soal a)
void tambah_nilai() {
    if (jumlah_mahasiswa < MAX_MAHASISWA) {
        printf("Masukkan nama mahasiswa: ");
        scanf("%s", nilai_mahasiswa[jumlah_mahasiswa].nama);
        printf("Masukkan nilai mahasiswa: ");
        scanf("%lf", &nilai_mahasiswa[jumlah_mahasiswa].nilai);
        jumlah_mahasiswa++;
        printf("Nilai berhasil ditambahkan.\n");
    } else {
        printf("Kapasitas penuh, tidak bisa menambahkan lebih banyak mahasiswa.\n");
    }
}

// Fungsi untuk menampilkan seluruh nilai mahasiswa (soal b)
void tampil_nilai() {
    printf("\nDaftar seluruh nilai mahasiswa:\n");
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("Nama: %s, Nilai: %.2f\n", nilai_mahasiswa[i].nama, nilai_mahasiswa[i].nilai);
    }
}

// Fungsi untuk mencari dan menampilkan mahasiswa dengan nilai tertinggi (soal c)
void nilai_tertinggi() {
    if (jumlah_mahasiswa == 0) {
        printf("Tidak ada nilai yang dicatat.\n");
        return;
    }

    struct Mahasiswa tertinggi = nilai_mahasiswa[0];
    for (int i = 1; i < jumlah_mahasiswa; i++) {
        if (nilai_mahasiswa[i].nilai > tertinggi.nilai) {
            tertinggi = nilai_mahasiswa[i];
        }
    }

    printf("\nMahasiswa dengan nilai tertinggi adalah %s dengan nilai %.2f\n", tertinggi.nama, tertinggi.nilai);
}

// Fungsi untuk menghitung dan menampilkan rata-rata nilai mahasiswa (soal d)
void rata_rata_nilai() {
    if (jumlah_mahasiswa == 0) {
        printf("Tidak ada nilai yang dicatat.\n");
        return;
    }

    double total_nilai = 0;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        total_nilai += nilai_mahasiswa[i].nilai;
    }

    double rata_rata = total_nilai / jumlah_mahasiswa;
    printf("\nRata-rata nilai mahasiswa adalah: %.2f\n", rata_rata);
}

// Fungsi untuk memperbarui nilai mahasiswa berdasarkan nama (soal e)
void update_nilai(char nama[], double nilai_baru) {
    int found = 0;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        if (strcmp(nilai_mahasiswa[i].nama, nama) == 0) {
            nilai_mahasiswa[i].nilai = nilai_baru;
            printf("Nilai mahasiswa %s telah diperbarui menjadi %.2f\n", nama, nilai_baru);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Mahasiswa dengan nama %s tidak ditemukan.\n", nama);
    }
}

// Main program
int main() {
    int jumlah;

    printf("Berapa banyak mahasiswa yang ingin ditambahkan nilainya? ");
    scanf("%d", &jumlah);

    printf("\n-------Soal a-------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("Mahasiswa ke-%d:\n", i + 1);
        tambah_nilai();
    }

    printf("\n-------Soal b-------\n");
    tampil_nilai();

    printf("\n-------Soal c-------\n");
    nilai_tertinggi();

    printf("\n-------Soal d-------\n");
    rata_rata_nilai();

    printf("\n-------Soal e-------\n");
    char nama_mahasiswa[50];
    double nilai_baru;
    printf("Masukkan nama mahasiswa yang ingin diupdate nilainya: ");
    scanf("%s", nama_mahasiswa);
    printf("Masukkan nilai baru: ");
    scanf("%lf", &nilai_baru);
    update_nilai(nama_mahasiswa, nilai_baru);

    printf("\nNilai mahasiswa setelah update:\n");
    tampil_nilai();

    return 0;
}
