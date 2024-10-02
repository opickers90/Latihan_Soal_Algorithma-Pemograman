'''
Soal Ujian 1: Aplikasi Pengelolaan Data Produk
Deskripsi Soal:
Buat aplikasi untuk mengelola data produk di toko. Aplikasi ini harus dapat menambahkan produk, menampilkan produk, mencari produk termahal, 
menghitung rata-rata harga, dan mengupdate stok produk.

Pertanyaan:
a. Buat program untuk menambahkan produk baru (nama, harga, stok) ke dalam array/list, dan tampilkan seluruh data setelah produk ditambahkan.
b. Buat program untuk menampilkan semua produk yang ada di toko.
c. Buat program untuk mencari dan menampilkan produk dengan harga tertinggi.
d. Buat program untuk menghitung dan menampilkan rata-rata harga produk.
e. Buat program untuk memperbarui stok produk yang ada di toko berdasarkan nama produk yang dimasukkan pengguna.
'''
# buat list kosong nama product
list_produk = []

# buat fungsi menambah product (soal a)
def tambah_produk():
    nama = input("Masukan nama barang: ")
    harga = int(input("Masukan harga barang: "))
    stok = int(input("Masukan stock barang: "))
    list_produk.append({"nama": nama, "harga": harga, "stok":stok})
    print("Produk Berhasil Ditambahkan")

# buat fungsi tampil product (soal b)
def tampil_produk():    
    for nama_produk in list_produk:
        print(f"Nama item: {nama_produk['nama']}")
        print(f"Harga item: {nama_produk['harga']}")
        print(f"Jumlah stock: {nama_produk['stok']}")

# buat program dengan harga tertinggi (soal c)
def produk_termahal():
    if not list_produk:
        print("Tidak ada produk pada list produk")
        return
    termahal = list_produk[0]
    for nama_produk in list_produk:
        if nama_produk['harga'] > termahal['harga']:
            termahal = nama_produk
    print(f"Produk termahal adalah: Nama: {termahal['nama']}, Harga: {termahal['harga']}, dan Stok {termahal['stok']}")

# buat program untuk menghitung rata-rata harga produk (soal d)
def rata_rata_harga():
    if not list_produk:
        print("Tidak ada produk pada list produk")
        return
    total_harga = 0
    for nama_produk in list_produk:
        total_harga += nama_produk['harga']
    rata2 = total_harga/len(list_produk)
    print(f"Rata-rata harga adalah: {rata2}") 

# buat program untuk update produk (soal e)
def update_stok(nama, stok_update):
    for nama_produk in list_produk:
        if nama_produk['nama'] == nama:
            nama_produk['stok'] = stok_update
            print(f"Nama Produk : {nama} telah diupdate dengan")
            print(f"Stock Baru: {stok_update}")
        else:
            print("Produk tidak ditemukan")

# main program
if __name__ == "__main__":
    jumlah_produk = int(input("Berapa Item yang ingin dimasukan: "))
    print("\n-------soal a-------\n")
    for i in range(jumlah_produk):
        print(f"Produk ke-{i+1} adalah:")
        tambah_produk()
    print("\n-------soal b-------\n")
    tampil_produk()
    print("\n-------soal c-------\n")
    produk_termahal()
    print("\n-------soal d-------\n")
    rata_rata_harga()
    print("\n-------soal e-------\n")
    update_stok("motor", 1)
    tampil_produk()