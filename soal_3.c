#include <stdio.h>
#include <string.h>

#define MAX_RESERVASI 100

// Struktur data untuk menyimpan reservasi hotel
struct Reservasi {
    char nomor_kamar[10];
    char nama_tamu[50];
    double harga_per_malam;
    int jumlah_malam;
};

// Array untuk menyimpan reservasi
struct Reservasi reservasi[MAX_RESERVASI];
int jumlah_reservasi = 0;

// Fungsi untuk mencatat pemesanan kamar (soal a)
void catat_reservasi() {
    if (jumlah_reservasi < MAX_RESERVASI) {
        printf("Masukkan nomor kamar: ");
        scanf("%s", reservasi[jumlah_reservasi].nomor_kamar);
        printf("Masukkan nama tamu: ");
        scanf("%s", reservasi[jumlah_reservasi].nama_tamu);
        printf("Masukkan harga per malam: ");
        scanf("%lf", &reservasi[jumlah_reservasi].harga_per_malam);
        printf("Masukkan jumlah malam: ");
        scanf("%d", &reservasi[jumlah_reservasi].jumlah_malam);
        jumlah_reservasi++;
        printf("Reservasi berhasil dicatat.\n");
    } else {
        printf("Kapasitas reservasi penuh.\n");
    }
}

// Fungsi untuk menampilkan seluruh reservasi (soal b)
void tampil_reservasi() {
    printf("\nDaftar seluruh reservasi:\n");
    for (int i = 0; i < jumlah_reservasi; i++) {
        printf("Nomor kamar: %s, Nama tamu: %s, Harga per malam: %.2f, Jumlah malam: %d\n",
               reservasi[i].nomor_kamar, reservasi[i].nama_tamu,
               reservasi[i].harga_per_malam, reservasi[i].jumlah_malam);
    }
}

// Fungsi untuk mencari kamar yang paling sering dipesan (soal c)
void kamar_tersering() {
    if (jumlah_reservasi == 0) {
        printf("Tidak ada reservasi.\n");
        return;
    }

    char kamar_terbanyak[10];
    int frekuensi[MAX_RESERVASI] = {0};

    for (int i = 0; i < jumlah_reservasi; i++) {
        for (int j = 0; j < jumlah_reservasi; j++) {
            if (strcmp(reservasi[i].nomor_kamar, reservasi[j].nomor_kamar) == 0) {
                frekuensi[i]++;
            }
        }
    }

    int max_freq = 0;
    for (int i = 0; i < jumlah_reservasi; i++) {
        if (frekuensi[i] > max_freq) {
            max_freq = frekuensi[i];
            strcpy(kamar_terbanyak, reservasi[i].nomor_kamar);
        }
    }

    printf("\nKamar yang paling sering dipesan adalah kamar nomor %s dengan %d kali pemesanan.\n",
           kamar_terbanyak, max_freq);
}

// Fungsi untuk menghitung total pendapatan hotel (soal d)
void total_pendapatan() {
    double total = 0;
    for (int i = 0; i < jumlah_reservasi; i++) {
        total += reservasi[i].harga_per_malam * reservasi[i].jumlah_malam;
    }
    printf("\nTotal pendapatan hotel adalah: %.2f\n", total);
}

// Fungsi untuk memperbarui status ketersediaan kamar (soal e)
void update_ketersediaan_kamar(char nomor_kamar[]) {
    int found = 0;
    for (int i = 0; i < jumlah_reservasi; i++) {
        if (strcmp(reservasi[i].nomor_kamar, nomor_kamar) == 0) {
            printf("Ketersediaan kamar nomor %s telah diperbarui.\n", nomor_kamar);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Kamar nomor %s tidak ditemukan.\n", nomor_kamar);
    }
}

// Main program
int main() {
    int jumlah;

    printf("Berapa banyak reservasi yang ingin dicatat? ");
    scanf("%d", &jumlah);

    printf("\n-------Soal a-------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("Reservasi ke-%d:\n", i + 1);
        catat_reservasi();
    }

    printf("\n-------Soal b-------\n");
    tampil_reservasi();

    printf("\n-------Soal c-------\n");
    kamar_tersering();

    printf("\n-------Soal d-------\n");
    total_pendapatan();

    printf("\n-------Soal e-------\n");
    char nomor_kamar_update[10];
    printf("Masukkan nomor kamar yang ingin diupdate ketersediaannya: ");
    scanf("%s", nomor_kamar_update);
    update_ketersediaan_kamar(nomor_kamar_update);

    return 0;
}
