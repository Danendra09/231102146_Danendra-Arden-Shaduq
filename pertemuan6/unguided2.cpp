#include <iostream>
#include <stack>
#include <string>
#include <sstream> // Untuk stringstream

using namespace std;

// Fungsi untuk membalikkan setiap kata
string reverseWord(const string& word) {
    string reversedWord;
    for (int i = word.length() - 1; i >= 0; --i) {
        reversedWord += word[i];
    }
    return reversedWord;
}

// Fungsi untuk membalikkan kata menggunakan stack
string reverseSentence(const string& kata_146) {
    stack<string> wordStack;

    // Menggunakan stringstream untuk memisahkan setiap kata 
    stringstream ss(kata_146);
    string word;
    while (ss >> word) {
        // Memasukkan setiap kata yang sudah dibalikkan ke dalam stack
        wordStack.push(reverseWord(word));
    }

    // Memasukkan kata-kata yang sudah dibalikkan dari stack ke dalam kalimat baru
    string reversedSentence;
    while (!wordStack.empty()) {
        reversedSentence += wordStack.top() + " ";
        wordStack.pop();
    }
    // Menghapus spasi di akhir kalimat
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }
    return reversedSentence;
}

int main() {
    string kata_146;
    cout << "Masukkan kalimat: ";
    getline(cin, kata_146);

    // Memanggil fungsi untuk membalikkan kata
    string reversed = reverseSentence(kata_146);
    cout << "Setelah melakukan pembalikan: " << reversed << endl;

    return 0;
}
