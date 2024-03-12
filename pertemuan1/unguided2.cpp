#include <iostream>

using namespace std;
//struct mhs_2146 yang berisi data string(nama, jurusan), int(angkatan)
struct mhs_2146 {
    string nama;
    string jurusan;
    int angkatan;
};
//class buku_2146 yang berisi data string(judul, penulis), int(tahun terbit) yang bersifat public
class buku_2146 {
public:
    string judul;
    string penulis;
    int tahun_terbit;
    //fungsi info yang menampilkan data judul, penulis, dan tahun terbit
    void info() {
        cout << "Judul: " << judul << endl;
        cout << "Penulis: " << penulis << endl;
        cout << "Tahun Terbit: " << tahun_terbit<< endl;
    }
};

int main() {
    // Menggunakan struct
    mhs_2146 mhs;
    mhs.nama = "Danendra";
    mhs.jurusan = "S1 Teknik Informatika";
    mhs.angkatan = 23;

    cout << "Data Mahasiswa:" << endl;
    cout << "Nama: " << mhs.nama << endl;
    cout << "Jurusan: " << mhs.jurusan << endl;
    cout << "Angkatan: " << mhs.angkatan << endl;

    cout << endl;

    // Menggunakan class
    buku_2146 buku;
    buku.judul = "Hyouka";
    buku.penulis = "Honobu Yonezawa";
    buku.tahun_terbit = 2001;

    cout << "Data buku pinjaman:" << endl;
    buku.info();

    return 0;
}