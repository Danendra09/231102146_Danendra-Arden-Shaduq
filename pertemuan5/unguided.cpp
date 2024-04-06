#include <iostream>
#include <list>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string nama_2146;   // Variabel nama mahasiswa
    int nim_2146;       // Variabel NIM mahasiswa
    int nilai_2146;     // Variabel nilai mahasiswa
};

// Ukuran tabel hash
const int hash_table_size = 10;

// Kelas untuk hash table
class HashTable {
private:
    list<Mahasiswa> table[hash_table_size];  // Array dari linked list untuk menyimpan data

    // Fungsi hash sederhana untuk menghasilkan indeks
    int hashFunction(int nim_2146) {  // Fungsi hash sederhana dengan parameter NIM
        return nim_2146 % hash_table_size;  // Mengembalikan nilai modulo untuk mendapatkan indeks
    }

public:
    // Fungsi untuk menambahkan data mahasiswa ke hash table
    void tambahData(Mahasiswa data) {  // Fungsi untuk menambahkan data mahasiswa
        int index = hashFunction(data.nim_2146);  // Mendapatkan indeks menggunakan fungsi hash
        table[index].push_back(data);  // Menambahkan data ke linked list pada indeks yang sesuai
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusData(int nim_2146) {  // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
        int index = hashFunction(nim_2146);  // Mendapatkan indeks menggunakan fungsi hash
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {  // Iterasi melalui linked list pada indeks
            if (it->nim_2146 == nim_2146) {  // Jika NIM cocok
                cout << "NIM " << it->nim_2146 << " dengan nama " << it->nama_2146 << " berhasil dihapus" << endl;  // Pesan sukses
                table[index].erase(it);  // Hapus data dari linked list
                return;  // Keluar dari fungsi
            }
        }
        cout << "Data tidak ditemukan" << endl;  // Jika NIM tidak ditemukan
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariByNIM(int nim_2146) {  // Fungsi untuk mencari data mahasiswa berdasarkan NIM
        int index = hashFunction(nim_2146);  // Mendapatkan indeks menggunakan fungsi hash
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {  // Iterasi melalui linked list pada indeks
            if (it->nim_2146 == nim_2146) {  // Jika NIM cocok
                cout << "Nama: " << it->nama_2146 << " NIM: " << it->nim_2146 << " Nilai: " << it->nilai_2146 << endl;  // Cetak informasi mahasiswa
                return;  // Keluar dari fungsi
            }
        }
        cout << "Data tidak ditemukan" << endl;  // Jika NIM tidak ditemukan
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80-90)
    void cariByNilai() {  // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80-90)
        for (int i = 0; i < hash_table_size; ++i) {  // Iterasi melalui semua indeks tabel hash
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {  // Iterasi melalui linked list pada setiap indeks
                if (it->nilai_2146 >= 80 && it->nilai_2146 <= 90) {  // Jika nilai berada dalam rentang
                    cout << "Nama: " << it->nama_2146 << " NIM: " << it->nim_2146 << " Nilai: " << it->nilai_2146 << endl;  // Cetak informasi mahasiswa
                }
            }
        }
    }
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Tambah Data Mahasiswa" << endl;
    cout << "2. Hapus Data Mahasiswa" << endl;
    cout << "3. Cari Data Mahasiswa by NIM" << endl;
    cout << "4. Cari Data Mahasiswa by Nilai (80-90)" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih: ";
}

int main() {
    HashTable hashTable;  // Deklarasi objek hash table
    int choice;  // Variabel untuk menyimpan pilihan menu

    do {  // Loop untuk memperbarui menu
        tampilkanMenu();
        cin >> choice;

        switch (choice) {  // Switch case untuk memilih operasi
            case 1: {  // Tambah data mahasiswa
                Mahasiswa mhs;  // Deklarasi objek mahasiswa
                cout << "Masukkan Nama: ";
                cin.ignore();  // Menghapus karakter newline dari buffer
                getline(cin, mhs.nama_2146);  // Input nama
                cout << "Masukkan NIM: ";
                cin >> mhs.nim_2146;
                cout << "Masukkan Nilai: ";
                cin >> mhs.nilai_2146;
                hashTable.tambahData(mhs);  // Tambahkan data ke hash table
                break;  // Keluar dari switch case
            }
            case 2: {  // Hapus data mahasiswa
                int nim_2146;  // Variabel untuk menyimpan NIM yang akan dihapus
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim_2146;  // Masukkan NIM yang akan dihapus
                hashTable.hapusData(nim_2146);  // Hapus data dari hash table
                break;  // Keluar dari switch case
            }
            case 3: {  // Cari data mahasiswa berdasarkan NIM
                int nim_2146;  // Variabel untuk menyimpan NIM yang akan dicari
                cout << "Masukkan NIM yang akan dicari: ";
                cin >> nim_2146;  // Masukkan NIM yang akan dicari
                hashTable.cariByNIM(nim_2146);  // Cari data berdasarkan NIM
                break;  // Keluar dari switch case
            }
            case 4: {  // Cari data mahasiswa berdasarkan rentang nilai
                cout << "Mahasiswa dengan nilai antara 80-90:" << endl;
                hashTable.cariByNilai();  // Cari data berdasarkan rentang nilai
                break;  // Keluar dari switch case
            }
            case 5:  // Keluar dari program
                cout << "Keluar..." << endl;
                break;  // Keluar dari switch case
            default:  // Pilihan tidak valid
                cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 5);  // Ulangi selama pilihan tidak sama dengan 5

    return 0;  // Selesai
}
