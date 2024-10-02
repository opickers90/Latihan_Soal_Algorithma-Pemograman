# List untuk menyimpan data inventaris
inventaris = []

# Fungsi untuk menambahkan barang baru (soal a)
def tambah_barang():
    nama_barang = input("Masukkan nama barang: ")
    stok = int(input("Masukkan jumlah stok: "))
    harga_satuan = float(input("Masukkan harga satuan: "))
    
    inventaris.append({"nama": nama_barang, "stok": stok, "harga_satuan": harga_satuan})
    print("Barang berhasil ditambahkan.")

# Fungsi untuk menampilkan seluruh barang yang ada di dalam inventaris (soal b)
def tampil_inventaris():
    print("\nDaftar seluruh barang dalam inventaris:")
    for b in inventaris:
        print(f"Nama barang: {b['nama']}, Stok: {b['stok']}, Harga satuan: {b['harga_satuan']}")

# Fungsi untuk mencari dan menampilkan barang dengan stok terendah (soal c)
def barang_stok_terendah():
    if not inventaris:
        print("Tidak ada barang dalam inventaris.")
        return
    
    stok_terendah = min(inventaris, key=lambda x: x['stok'])
    print(f"\nBarang dengan stok terendah adalah {stok_terendah['nama']} dengan stok {stok_terendah['stok']}.")

# Fungsi untuk menghitung dan menampilkan total nilai inventaris (soal d)
def total_nilai_inventaris():
    total_nilai = sum(b['stok'] * b['harga_satuan'] for b in inventaris)
    print(f"\nTotal nilai inventaris: {total_nilai}")

# Fungsi untuk memperbarui jumlah stok barang (soal e)
def update_stok(nama_barang, stok_baru):
    found = False
    for b in inventaris:
        if b['nama'] == nama_barang:
            b['stok'] = stok_baru
            print(f"Stok {nama_barang} telah diperbarui menjadi {stok_baru}.")
            found = True
            break
    if not found:
        print(f"Barang dengan nama {nama_barang} tidak ditemukan.")

# Main program
if __name__ == "__main__":
    jumlah_barang = int(input("Berapa banyak barang yang ingin ditambahkan? "))

    print("\n-------Soal a-------")
    for i in range(jumlah_barang):
        print(f"\nBarang ke-{i + 1}:")
        tambah_barang()

    print("\n-------Soal b-------")
    tampil_inventaris()

    print("\n-------Soal c-------")
    barang_stok_terendah()

    print("\n-------Soal d-------")
    total_nilai_inventaris()

    print("\n-------Soal e-------")
    nama_barang_update = input("Masukkan nama barang yang ingin diupdate stoknya: ")
    stok_baru = int(input("Masukkan stok baru: "))
    update_stok(nama_barang_update, stok_baru)

    print("\nBarang setelah update stok:")
    tampil_inventaris()
