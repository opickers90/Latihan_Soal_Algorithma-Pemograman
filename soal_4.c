#include <stdio.h>
#include <string.h>

#define MAX_BARANG 100

// Struktur data untuk menyimpan barang di inventaris
struct Barang {
    char nama[50];
    int stok;
    double harga_satuan;
};

// Array untuk menyimpan barang-barang di inventaris
struct Barang inventaris[MAX_BARANG];
int jumlah_barang = 0;

// Fungsi untuk menambahkan barang baru (soal a)
void tambah_barang() {
    if (jumlah_barang < MAX_BARANG) {
        printf("Masukkan nama barang: ");
        scanf("%s", inventaris[jumlah_barang].nama);
        printf("Masukkan stok barang: ");
        scanf("%d", &inventaris[jumlah_barang].stok);
        printf("Masukkan harga satuan barang: ");
        scanf("%lf", &inventaris[jumlah_barang].harga_satuan);
        jumlah_barang++;
        printf("Barang berhasil ditambahkan.\n");
    } else {
        printf("Kapasitas inventaris penuh.\n");
    }
}

// Fungsi untuk menampilkan seluruh barang di dalam inventaris (soal b)
void tampil_inventaris() {
    printf("\nDaftar seluruh barang di dalam inventaris:\n");
    for (int i = 0; i < jumlah_barang; i++) {
        printf("Nama barang: %s, Stok: %d, Harga satuan: %.2f\n",
               inventaris[i].nama, inventaris[i].stok, inventaris[i].harga_satuan);
    }
}

// Fungsi untuk mencari dan menampilkan barang dengan stok terendah (soal c)
void barang_stok_terendah() {
    if (jumlah_barang == 0) {
        printf("Tidak ada barang dalam inventaris.\n");
        return;
    }

    struct Barang stok_terendah = inventaris[0];
    for (int i = 1; i < jumlah_barang; i++) {
        if (inventaris[i].stok < stok_terendah.stok) {
            stok_terendah = inventaris[i];
        }
    }

    printf("\nBarang dengan stok terendah adalah %s dengan stok %d.\n", stok_terendah.nama, stok_terendah.stok);
}

// Fungsi untuk menghitung dan menampilkan total nilai inventaris (soal d)
void total_nilai_inventaris() {
    double total_nilai = 0;
    for (int i = 0; i < jumlah_barang; i++) {
        total_nilai += inventaris[i].stok * inventaris[i].harga_satuan;
    }
    printf("\nTotal nilai inventaris: %.2f\n", total_nilai);
}

// Fungsi untuk memperbarui stok barang berdasarkan nama barang (soal e)
void update_stok(char nama_barang[], int stok_baru) {
    int found = 0;
    for (int i = 0; i < jumlah_barang; i++) {
        if (strcmp(inventaris[i].nama, nama_barang) == 0) {
            inventaris[i].stok = stok_baru;
            printf("Stok barang %s telah diperbarui menjadi %d.\n", nama_barang, stok_baru);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Barang dengan nama %s tidak ditemukan.\n", nama_barang);
    }
}

// Main program
int main() {
    int jumlah;

    printf("Berapa banyak barang yang ingin ditambahkan? ");
    scanf("%d", &jumlah);

    printf("\n-------Soal a-------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("Barang ke-%d:\n", i + 1);
        tambah_barang();
    }

    printf("\n-------Soal b-------\n");
    tampil_inventaris();

    printf("\n-------Soal c-------\n");
    barang_stok_terendah();

    printf("\n-------Soal d-------\n");
    total_nilai_inventaris();

    printf("\n-------Soal e-------\n");
    char nama_barang_update[50];
    int stok_baru;
    printf("Masukkan nama barang yang ingin diupdate stoknya: ");
    scanf("%s", nama_barang_update);
    printf("Masukkan stok baru: ");
    scanf("%d", &stok_baru);
    update_stok(nama_barang_update, stok_baru);

    printf("\nBarang setelah update stok:\n");
    tampil_inventaris();

    return 0;
}
