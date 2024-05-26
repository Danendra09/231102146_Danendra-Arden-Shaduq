// 2311102146 - DANENDRA ARDEN SHADUQ
#include <iostream> // Menyertakan pustaka input-output
#include <vector>   // Menyertakan pustaka vektor
#include <string>   // Menyertakan pustaka string
#include <iomanip>  // Menyertakan pustaka untuk pengaturan output

using namespace std; // Menggunakan namespace std

int main() {
    int n_146; // Deklarasi variabel untuk menyimpan jumlah simpul
    cout << "Silakan masukan jumlah simpul: "; // Menampilkan pesan untuk memasukkan jumlah simpul
    cin >> n_146; // Membaca jumlah simpul dari pengguna
    
    vector<string> cities(n_146); // Membuat vektor untuk menyimpan nama-nama simpul (kota)
    vector<vector<int>> graph(n_146, vector<int>(n_146)); // Membuat matriks ketetanggaan untuk menyimpan bobot antar simpul
    
    cout << "Silakan masukan nama simpul" << endl; // Menampilkan pesan untuk memasukkan nama-nama simpul
    for (int i = 0; i < n_146; ++i) { // Loop untuk membaca nama-nama simpul
        cout << "Simpul " << i + 1 << ": "; // Menampilkan pesan untuk memasukkan nama simpul ke-i
        cin >> cities[i]; // Membaca nama simpul dari pengguna
    }
    
    cout << "Silakan masukan bobot antar simpul" << endl; // Menampilkan pesan untuk memasukkan bobot antar simpul
    for (int i = 0; i < n_146; ++i) { // Loop untuk setiap simpul asal
        for (int j = 0; j < n_146; ++j) { // Loop untuk setiap simpul tujuan
            cout << cities[i] << "--> " << cities[j] << " = "; // Menampilkan pesan untuk memasukkan bobot antara simpul asal dan tujuan
            cin >> graph[i][j]; // Membaca bobot dari pengguna
        }
    }
    
    cout << "\n"; // Menampilkan baris kosong untuk pemisahan
    cout << setw(10) << ""; // Mengatur lebar kolom untuk penampilan nama simpul
    for (int i = 0; i < n_146; ++i) { // Loop untuk menampilkan nama-nama simpul di baris pertama tabel
        cout << setw(10) << cities[i]; // Menampilkan nama simpul dengan lebar kolom 10
    }
    cout << "\n"; // Menampilkan baris baru
    
    for (int i = 0; i < n_146; ++i) { // Loop untuk setiap baris pada tabel
        cout << setw(10) << cities[i]; // Menampilkan nama simpul di awal baris
        for (int j = 0; j < n_146; ++j) { // Loop untuk setiap kolom pada tabel
            cout << setw(10) << graph[i][j]; // Menampilkan bobot dengan lebar kolom 10
        }
        cout << "\n"; // Menampilkan baris baru setelah setiap baris tabel selesai
    }
    
    return 0; // Mengembalikan nilai 0 menandakan program selesai dengan sukses
}
