# List untuk menyimpan transaksi keuangan
transaksi = []

# Fungsi untuk mencatat pemasukan dan pengeluaran (soal a)
def catat_transaksi():
    jenis = input("Masukkan jenis transaksi (Pemasukan/Pengeluaran): ").lower()
    kategori = input("Masukkan kategori transaksi: ")
    jumlah = float(input("Masukkan jumlah transaksi: "))
    
    transaksi.append({"jenis": jenis, "kategori": kategori, "jumlah": jumlah})
    print("Transaksi berhasil dicatat.")

# Fungsi untuk menampilkan seluruh transaksi (soal b)
def tampil_transaksi():
    print("\nDaftar seluruh transaksi:")
    for t in transaksi:
        print(f"Jenis: {t['jenis']}, Kategori: {t['kategori']}, Jumlah: {t['jumlah']}")

# Fungsi untuk menghitung saldo akhir (soal c)
def saldo_akhir():
    total_pemasukan = sum(t['jumlah'] for t in transaksi if t['jenis'] == 'pemasukan')
    total_pengeluaran = sum(t['jumlah'] for t in transaksi if t['jenis'] == 'pengeluaran')
    
    saldo = total_pemasukan - total_pengeluaran
    print(f"\nSaldo akhir: {saldo}")

# Fungsi untuk mencari pengeluaran terbesar berdasarkan kategori (soal d)
def pengeluaran_terbesar():
    pengeluaran = [t for t in transaksi if t['jenis'] == 'pengeluaran']
    if pengeluaran:
        terbesar = max(pengeluaran, key=lambda x: x['jumlah'])
        print(f"\nPengeluaran terbesar adalah: Kategori {terbesar['kategori']} dengan jumlah {terbesar['jumlah']}")
    else:
        print("\nTidak ada pengeluaran yang dicatat.")

# Fungsi untuk menghitung rata-rata pengeluaran per kategori (soal e)
def rata_rata_pengeluaran():
    pengeluaran = [t['jumlah'] for t in transaksi if t['jenis'] == 'pengeluaran']
    if pengeluaran:
        rata_rata = sum(pengeluaran) / len(pengeluaran)
        print(f"\nRata-rata pengeluaran per kategori: {rata_rata}")
    else:
        print("\nTidak ada pengeluaran untuk dihitung rata-rata.")

# Main program
if __name__ == "__main__":
    jumlah_transaksi = int(input("Berapa banyak transaksi yang ingin dicatat? "))

    print("\n-------Soal a-------")
    for i in range(jumlah_transaksi):
        print(f"\nTransaksi ke-{i + 1}:")
        catat_transaksi()

    print("\n-------Soal b-------")
    tampil_transaksi()

    print("\n-------Soal c-------")
    saldo_akhir()

    print("\n-------Soal d-------")
    pengeluaran_terbesar()

    print("\n-------Soal e-------")
    rata_rata_pengeluaran()
