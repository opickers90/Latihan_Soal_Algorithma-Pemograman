#include <stdio.h>
#include <string.h>

#define MAX_PRODUK 100

// Struktur data untuk menyimpan produk
struct Produk {
    char nama[50];
    double harga;
    int stok;
};

// Array untuk menyimpan produk
struct Produk list_produk[MAX_PRODUK];
int jumlah_produk = 0;

// Fungsi untuk menambahkan produk baru (soal a)
void tambah_produk() {
    if (jumlah_produk < MAX_PRODUK) {
        printf("Masukkan nama barang: ");
        scanf("%s", list_produk[jumlah_produk].nama);
        printf("Masukkan harga barang: ");
        scanf("%lf", &list_produk[jumlah_produk].harga);
        printf("Masukkan stok barang: ");
        scanf("%d", &list_produk[jumlah_produk].stok);
        jumlah_produk++;
        printf("Produk berhasil ditambahkan.\n");
    } else {
        printf("Kapasitas produk penuh.\n");
    }
}

// Fungsi untuk menampilkan seluruh produk (soal b)
void tampil_produk() {
    printf("\nDaftar produk:\n");
    for (int i = 0; i < jumlah_produk; i++) {
        printf("Nama: %s, Harga: %.2f, Stok: %d\n", list_produk[i].nama, list_produk[i].harga, list_produk[i].stok);
    }
}

// Fungsi untuk mencari dan menampilkan produk termahal (soal c)
void produk_termahal() {
    if (jumlah_produk == 0) {
        printf("Tidak ada produk yang dicatat.\n");
        return;
    }

    struct Produk termahal = list_produk[0];
    for (int i = 1; i < jumlah_produk; i++) {
        if (list_produk[i].harga > termahal.harga) {
            termahal = list_produk[i];
        }
    }

    printf("\nProduk termahal adalah %s dengan harga %.2f dan stok %d\n", termahal.nama, termahal.harga, termahal.stok);
}

// Fungsi untuk menghitung dan menampilkan rata-rata harga produk (soal d)
void rata_rata_harga() {
    if (jumlah_produk == 0) {
        printf("Tidak ada produk yang dicatat.\n");
        return;
    }

    double total_harga = 0;
    for (int i = 0; i < jumlah_produk; i++) {
        total_harga += list_produk[i].harga;
    }

    double rata_rata = total_harga / jumlah_produk;
    printf("\nRata-rata harga produk adalah: %.2f\n", rata_rata);
}

// Fungsi untuk memperbarui stok produk berdasarkan nama produk (soal e)
void update_stok(char nama[], int stok_baru) {
    int found = 0;
    for (int i = 0; i < jumlah_produk; i++) {
        if (strcmp(list_produk[i].nama, nama) == 0) {
            list_produk[i].stok = stok_baru;
            printf("Stok produk %s telah diperbarui menjadi %d\n", nama, stok_baru);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Produk dengan nama %s tidak ditemukan.\n", nama);
    }
}

// Main program
int main() {
    int jumlah;
    printf("Berapa banyak produk yang ingin ditambahkan? ");
    scanf("%d", &jumlah);

    printf("\n-------Soal a-------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("Produk ke-%d:\n", i + 1);
        tambah_produk();
    }

    printf("\n-------Soal b-------\n");
    tampil_produk();

    printf("\n-------Soal c-------\n");
    produk_termahal();

    printf("\n-------Soal d-------\n");
    rata_rata_harga();

    printf("\n-------Soal e-------\n");
    char nama_update[50];
    int stok_baru;
    printf("Masukkan nama produk yang ingin diupdate stoknya: ");
    scanf("%s", nama_update);
    printf("Masukkan stok baru: ");
    scanf("%d", &stok_baru);
    update_stok(nama_update, stok_baru);

    printf("\nProduk setelah update stok:\n");
    tampil_produk();

    return 0;
}
