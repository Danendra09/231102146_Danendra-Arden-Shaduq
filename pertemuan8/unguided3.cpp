// 2311102146 - DANENDRA ARDEN SHADUQ
#include <iostream> 
#include <vector>   // Mengimpor pustaka untuk menggunakan kontainer vector

using namespace std; // Menggunakan namespace standar

// Fungsi untuk menghitung berapa kali angka target muncul dalam data menggunakan Sequential Search
int countNumber(const vector<int>& data_146, int target) {
    int count = 0; // Inisialisasi variabel penghitung

    // Melakukan pencarian berurutan (Sequential Search) melalui seluruh elemen data
    for (int i = 0; i < data_146.size(); ++i) { // Looping melalui seluruh elemen dalam vector
        if (data_146[i] == target) { // Jika elemen saat ini sama dengan target
            count++; // Tambahkan 1 ke variabel penghitung
        }
    }

    return count; // Mengembalikan jumlah elemen yang sama dengan target
}

int main() {
    // data yang diberikan
    vector<int> data_146 = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Inisialisasi vector dengan nilai yang diberikan
    int target = 4; // Angka yang ingin dihitung kemunculannya

    // Menghitung berapa kali angka target muncul dalam data
    int count = countNumber(data_146, target); // Memanggil fungsi countNumber dan menyimpan hasilnya

    // Menampilkan hasil
    cout << "Data = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4} ";
    cout << "\nBanyaknya angka " << target << " dalam data : " << count << endl; // Mencetak hasil ke layar

    return 0; // Mengembalikan 0 untuk menunjukkan program berakhir dengan sukses
}
