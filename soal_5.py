# List untuk menyimpan data nilai mahasiswa
nilai_mahasiswa = []

# Fungsi untuk menambahkan nilai mahasiswa baru (soal a)
def tambah_nilai():
    nama = input("Masukkan nama mahasiswa: ")
    nilai = float(input("Masukkan nilai mahasiswa: "))
    
    nilai_mahasiswa.append({"nama": nama, "nilai": nilai})
    print("Nilai berhasil ditambahkan.")

# Fungsi untuk menampilkan seluruh nilai mahasiswa (soal b)
def tampil_nilai():
    print("\nDaftar seluruh nilai mahasiswa:")
    for m in nilai_mahasiswa:
        print(f"Nama: {m['nama']}, Nilai: {m['nilai']}")

# Fungsi untuk mencari dan menampilkan mahasiswa dengan nilai tertinggi (soal c)
def nilai_tertinggi():
    if not nilai_mahasiswa:
        print("Tidak ada nilai yang dicatat.")
        return
    
    tertinggi = max(nilai_mahasiswa, key=lambda x: x['nilai'])
    print(f"\nMahasiswa dengan nilai tertinggi adalah {tertinggi['nama']} dengan nilai {tertinggi['nilai']}.")

# Fungsi untuk menghitung dan menampilkan rata-rata nilai mahasiswa (soal d)
def rata_rata_nilai():
    if not nilai_mahasiswa:
        print("Tidak ada nilai yang dicatat.")
        return

    total_nilai = sum(m['nilai'] for m in nilai_mahasiswa)
    rata_rata = total_nilai / len(nilai_mahasiswa)
    print(f"\nRata-rata nilai mahasiswa adalah: {rata_rata}")

# Fungsi untuk memperbarui nilai mahasiswa berdasarkan nama (soal e)
def update_nilai(nama, nilai_baru):
    found = False
    for m in nilai_mahasiswa:
        if m['nama'] == nama:
            m['nilai'] = nilai_baru
            print(f"Nilai {nama} telah diperbarui menjadi {nilai_baru}.")
            found = True
            break
    if not found:
        print(f"Mahasiswa dengan nama {nama} tidak ditemukan.")

# Main program
if __name__ == "__main__":
    jumlah_mahasiswa = int(input("Berapa banyak mahasiswa yang ingin ditambahkan nilainya? "))

    print("\n-------Soal a-------")
    for i in range(jumlah_mahasiswa):
        print(f"\nMahasiswa ke-{i + 1}:")
        tambah_nilai()

    print("\n-------Soal b-------")
    tampil_nilai()

    print("\n-------Soal c-------")
    nilai_tertinggi()

    print("\n-------Soal d-------")
    rata_rata_nilai()

    print("\n-------Soal e-------")
    nama_update = input("Masukkan nama mahasiswa yang ingin diupdate nilainya: ")
    nilai_baru = float(input("Masukkan nilai baru: "))
    update_nilai(nama_update, nilai_baru)

    print("\nNilai mahasiswa setelah update:")
    tampil_nilai()
