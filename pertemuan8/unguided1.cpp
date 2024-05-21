// 2311102146 - DANENDRA ARDEN SHADUQ
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// Fungsi untuk mencari semua indeks dari huruf target dalam string yang diurutkan
vector<int> binarySearchAllIndices(const string& sortedStr, char target) {
    vector<int> indeks_146;  // Vector untuk menyimpan indeks yang ditemukan
    int left = 0;            // Indeks awal dari pencarian
    int right = sortedStr.length() - 1; // Indeks akhir dari pencarian

    while (left <= right) {  // Lakukan pencarian selama batas kiri <= batas kanan
        int middle = left + (right - left) / 2; // Hitung indeks tengah

        if (sortedStr[middle] == target) { // Jika elemen tengah adalah target
            indeks_146.push_back(middle); // Tambahkan indeks tengah ke vector

            // Cari ke kiri dari middle untuk menemukan semua kemunculan
            int temp = middle - 1;
            while (temp >= left && sortedStr[temp] == target) {
                indeks_146.push_back(temp); // Tambahkan indeks ke vector
                temp--; // Bergerak ke kiri
            }

            // Cari ke kanan dari middle untuk menemukan semua kemunculan
            temp = middle + 1;
            while (temp <= right && sortedStr[temp] == target) {
                indeks_146.push_back(temp); // Tambahkan indeks ke vector
                temp++; // Bergerak ke kanan
            }
            break; // Keluar dari loop setelah semua kemunculan ditemukan
        }

        if (sortedStr[middle] < target) { // Jika elemen tengah kurang dari target
            left = middle + 1; // Ubah batas kiri ke indeks setelah middle
        } else { // Jika elemen tengah lebih dari target
            right = middle - 1; // Ubah batas kanan ke indeks sebelum middle
        }
    }

    return indeks_146; // Kembalikan vector berisi semua indeks yang ditemukan
}

int main() {
    string inputStr; // Variabel untuk menyimpan kalimat input
    char targetChar; // Variabel untuk menyimpan huruf yang dicari

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, inputStr); // Ambil input kalimat dari pengguna

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> targetChar; // Ambil input huruf yang dicari dari pengguna

    // Mengubah kalimat dan targetChar menjadi huruf kecil
    transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);
    targetChar = tolower(targetChar);

    // Menghapus spasi dari kalimat untuk keperluan binary search
    inputStr.erase(remove(inputStr.begin(), inputStr.end(), ' '), inputStr.end());

    // Mengurutkan kalimat
    sort(inputStr.begin(), inputStr.end());

    // Menampilkan kalimat yang sudah diurutkan
    cout << "Kalimat yang diurutkan: " << inputStr << endl;

    // Mencari huruf menggunakan Binary Search
    vector<int> result = binarySearchAllIndices(inputStr, targetChar);

    // Memeriksa apakah hasil pencarian tidak kosong
    if (!result.empty()) {
        cout << "Huruf '" << targetChar << "' ditemukan pada indeks: ";
        for (int index : result) {
            cout << index << " "; // Tampilkan setiap indeks yang ditemukan
        }
        cout << endl;
    } else {
        cout << "Huruf '" << targetChar << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0; // Mengakhiri program
}
