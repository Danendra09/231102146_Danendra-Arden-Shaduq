// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream> 
#include <stack> // Library untuk menggunakan struktur data stack
#include <string> // Library untuk menggunakan tipe data string
#include <cctype> // Library untuk fungsi-fungsi karakter seperti isalnum() dan tolower()

using namespace std; 

// Fungsi untuk pra-pemrosesan string, menghapus karakter non-alphanumeric dan mengubah huruf menjadi lowercase
string preprocessString(const string& str) {
    string processedStr; // Variabel untuk menyimpan hasil string yang sudah diproses
    for (char c : str) { // Loop untuk setiap karakter dalam string input
        if (isalnum(c)) { // Jika karakter adalah alphanumeric (huruf atau angka)
            processedStr += tolower(c); // Tambahkan karakter ke string yang sudah diproses dalam lowercase
        }
    }
    return processedStr; // Kembalikan string yang sudah diproses
}

// Fungsi untuk mengecek apakah string merupakan palindrom atau bukan
bool isPalindrome(const string& str) {
    stack<char> charStack; // Deklarasi stack yang akan digunakan untuk membalikkan string
    int length = str.length(); // Panjang string input

    // Loop untuk memasukkan setiap karakter string input ke dalam stack
    for (int i = 0; i < length; ++i) {
        charStack.push(str[i]); // Masukkan karakter ke dalam stack
    }

    // Loop untuk membandingkan setiap karakter dari string input dengan karakter yang di-pop dari stack
    for (int i = 0; i < length; ++i) {
        if (charStack.top() != str[i]) { // Jika karakter dari stack tidak sama dengan karakter dari string input
            return false; // String tidak merupakan palindrom, kembalikan false
        }
        charStack.pop(); // Pop karakter dari stack
    }
    return true; // Jika semua karakter cocok, kembalikan true (string merupakan palindrom)
}

int main() {
    string input_146; // Variabel untuk menyimpan string input dari pengguna
    cout << "Masukkan kalimat: "; // Tampilkan pesan untuk meminta input dari pengguna
    getline(cin, input_146); // Dapatkan input kalimat dari pengguna menggunakan getline()

    string processedInput = preprocessString(input_146); // Pra-pemrosesan string input

    // Memeriksa apakah string input adalah palindrom atau bukan, dan menampilkan hasilnya
    if (isPalindrome(processedInput)) {
        cout << "Kalimat tersebut adalah palindrom" << endl; // Jika palindrom, tampilkan pesan ini
    } else {
        cout << "Kalimat tersebut adalah bukan palindrom" << endl; // Jika bukan palindrom, tampilkan pesan ini
    }

    return 0;
}
