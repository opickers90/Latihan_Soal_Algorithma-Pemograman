#include <stdio.h>
#include <string.h>

#define MAX_TRANSAKSI 100

// Struktur data untuk menyimpan transaksi
struct Transaksi {
    char jenis[20];   // "pemasukan" atau "pengeluaran"
    char kategori[50];
    double jumlah;
};

// Array untuk menyimpan transaksi
struct Transaksi transaksi[MAX_TRANSAKSI];
int jumlah_transaksi = 0;

// Fungsi untuk mencatat transaksi (soal a)
void catat_transaksi() {
    if (jumlah_transaksi < MAX_TRANSAKSI) {
        printf("Masukkan jenis transaksi (pemasukan/pengeluaran): ");
        scanf("%s", transaksi[jumlah_transaksi].jenis);
        printf("Masukkan kategori transaksi: ");
        scanf("%s", transaksi[jumlah_transaksi].kategori);
        printf("Masukkan jumlah transaksi: ");
        scanf("%lf", &transaksi[jumlah_transaksi].jumlah);
        jumlah_transaksi++;
        printf("Transaksi berhasil dicatat.\n");
    } else {
        printf("Kapasitas transaksi penuh.\n");
    }
}

// Fungsi untuk menampilkan seluruh transaksi (soal b)
void tampil_transaksi() {
    printf("\nDaftar seluruh transaksi:\n");
    for (int i = 0; i < jumlah_transaksi; i++) {
        printf("Jenis: %s, Kategori: %s, Jumlah: %.2f\n", transaksi[i].jenis, transaksi[i].kategori, transaksi[i].jumlah);
    }
}

// Fungsi untuk menghitung saldo akhir (soal c)
void saldo_akhir() {
    double total_pemasukan = 0;
    double total_pengeluaran = 0;

    for (int i = 0; i < jumlah_transaksi; i++) {
        if (strcmp(transaksi[i].jenis, "pemasukan") == 0) {
            total_pemasukan += transaksi[i].jumlah;
        } else if (strcmp(transaksi[i].jenis, "pengeluaran") == 0) {
            total_pengeluaran += transaksi[i].jumlah;
        }
    }

    double saldo = total_pemasukan - total_pengeluaran;
    printf("\nSaldo akhir: %.2f\n", saldo);
}

// Fungsi untuk mencari pengeluaran terbesar (soal d)
void pengeluaran_terbesar() {
    double terbesar = 0;
    char kategori_terbesar[50];

    for (int i = 0; i < jumlah_transaksi; i++) {
        if (strcmp(transaksi[i].jenis, "pengeluaran") == 0 && transaksi[i].jumlah > terbesar) {
            terbesar = transaksi[i].jumlah;
            strcpy(kategori_terbesar, transaksi[i].kategori);
        }
    }

    if (terbesar > 0) {
        printf("\nPengeluaran terbesar adalah kategori: %s dengan jumlah: %.2f\n", kategori_terbesar, terbesar);
    } else {
        printf("\nTidak ada pengeluaran yang dicatat.\n");
    }
}

// Fungsi untuk menghitung rata-rata pengeluaran (soal e)
void rata_rata_pengeluaran() {
    double total_pengeluaran = 0;
    int jumlah_pengeluaran = 0;

    for (int i = 0; i < jumlah_transaksi; i++) {
        if (strcmp(transaksi[i].jenis, "pengeluaran") == 0) {
            total_pengeluaran += transaksi[i].jumlah;
            jumlah_pengeluaran++;
        }
    }

    if (jumlah_pengeluaran > 0) {
        double rata_rata = total_pengeluaran / jumlah_pengeluaran;
        printf("\nRata-rata pengeluaran per kategori: %.2f\n", rata_rata);
    } else {
        printf("\nTidak ada pengeluaran yang dicatat untuk menghitung rata-rata.\n");
    }
}

// Main program
int main() {
    int jumlah;

    printf("Berapa banyak transaksi yang ingin dicatat? ");
    scanf("%d", &jumlah);

    printf("\n-------Soal a-------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("Transaksi ke-%d:\n", i + 1);
        catat_transaksi();
    }

    printf("\n-------Soal b-------\n");
    tampil_transaksi();

    printf("\n-------Soal c-------\n");
    saldo_akhir();

    printf("\n-------Soal d-------\n");
    pengeluaran_terbesar();

    printf("\n-------Soal e-------\n");
    rata_rata_pengeluaran();

    return 0;
}
