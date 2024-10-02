# List untuk menyimpan data reservasi
reservasi = []

# Fungsi untuk mencatat pemesanan kamar baru (soal a)
def catat_reservasi():
    nomor_kamar = input("Masukkan nomor kamar: ")
    nama_tamu = input("Masukkan nama tamu: ")
    harga_per_malam = float(input("Masukkan harga per malam: "))
    jumlah_malam = int(input("Masukkan jumlah malam: "))
    
    reservasi.append({
        "nomor_kamar": nomor_kamar,
        "nama_tamu": nama_tamu,
        "harga_per_malam": harga_per_malam,
        "jumlah_malam": jumlah_malam,
    })
    print("Reservasi berhasil dicatat.")

# Fungsi untuk menampilkan seluruh reservasi (soal b)
def tampil_reservasi():
    print("\nDaftar seluruh reservasi:")
    for r in reservasi:
        print(f"Nomor kamar: {r['nomor_kamar']}, Nama tamu: {r['nama_tamu']}, Harga per malam: {r['harga_per_malam']}, Jumlah malam: {r['jumlah_malam']}")

# Fungsi untuk mencari dan menampilkan kamar yang paling sering dipesan (soal c)
def kamar_tersering():
    if not reservasi:
        print("Tidak ada reservasi.")
        return

    freq = {}
    for r in reservasi:
        if r['nomor_kamar'] in freq:
            freq[r['nomor_kamar']] += 1
        else:
            freq[r['nomor_kamar']] = 1

    kamar_terbanyak = max(freq, key=freq.get)
    print(f"Kamar yang paling sering dipesan adalah kamar nomor {kamar_terbanyak} dengan {freq[kamar_terbanyak]} kali pemesanan.")

# Fungsi untuk menghitung total pendapatan hotel (soal d)
def total_pendapatan():
    total = sum(r['harga_per_malam'] * r['jumlah_malam'] for r in reservasi)
    print(f"\nTotal pendapatan hotel adalah: {total}")

# Fungsi untuk memperbarui status ketersediaan kamar (soal e)
def update_ketersediaan_kamar(nomor_kamar):
    found = False
    for r in reservasi:
        if r['nomor_kamar'] == nomor_kamar:
            print(f"Ketersediaan kamar nomor {nomor_kamar} telah diperbarui.")
            found = True
            break
    if not found:
        print(f"Kamar nomor {nomor_kamar} tidak ditemukan.")

# Main program
if __name__ == "__main__":
    jumlah_reservasi = int(input("Berapa banyak reservasi yang ingin dicatat? "))

    print("\n-------Soal a-------")
    for i in range(jumlah_reservasi):
        print(f"\nReservasi ke-{i + 1}:")
        catat_reservasi()

    print("\n-------Soal b-------")
    tampil_reservasi()

    print("\n-------Soal c-------")
    kamar_tersering()

    print("\n-------Soal d-------")
    total_pendapatan()

    print("\n-------Soal e-------")
    nomor_kamar_update = input("Masukkan nomor kamar yang ingin diupdate ketersediaannya: ")
    update_ketersediaan_kamar(nomor_kamar_update)
