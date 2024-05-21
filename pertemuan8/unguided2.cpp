// 2311102146 - DANENDRA ARDEN SHADUQ
#include <iostream>
#include <string>
#include <cctype> // Untuk fungsi tolower

using namespace std;

// Fungsi untuk memeriksa apakah karakter adalah huruf vokal
bool isVowel(char ch) {
    // Mengonversi karakter ke huruf kecil
    ch = tolower(ch);
    // Memeriksa apakah karakter termasuk dalam huruf vokal
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// Fungsi untuk menghitung banyaknya huruf vokal dalam kalimat
int countVowels(const string& sentence_146) {
    int count = 0;
    // Melakukan pencarian berurutan (Sequential Search)
    for (int i = 0; i < sentence_146.length(); ++i) {
        if (isVowel(sentence_146[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    string sentence_146;

    // Meminta pengguna untuk memasukkan sebuah kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, sentence_146);

    // Menghitung banyaknya huruf vokal dalam kalimat
    int vowelCount = countVowels(sentence_146);

    // Menampilkan hasil
    cout << "Banyaknya huruf vokal dalam kalimat: " << vowelCount << endl;

    return 0;
}
