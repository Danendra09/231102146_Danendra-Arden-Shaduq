# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>

<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori

Stack adalah struktur data linier yang mengikuti prinsip LIFO (Last In First Out), yang berarti elemen yang terakhir dimasukkan ke dalam stack akan menjadi yang pertama dikeluarkan. Stack sangat berguna dalam pemrograman karena memungkinkan penyimpanan dan pengambilan data dengan cara yang efisien.

Operasi yang digunakan pada stack :
1. Push: Menambahkan elemen ke atas tumpukan.
2. Pop: Menghapus dan mengembalikan elemen teratas dari tumpukan.
3. Top: Mengembalikan nilai dari elemen teratas tumpukan tanpa menghapusnya.
4. isEmpty: Memeriksa apakah tumpukan kosong atau tidak.
5. isFull (tidak selalu ada pada semua implementasi stack): Memeriksa apakah tumpukan penuh atau tidak, terutama pada implementasi tumpukan berukuran tetap.
6. Peek: Mengembalikan nilai dari elemen di posisi tertentu pada tumpukan tanpa menghapusnya.
7. Search: Mencari elemen terentu pada tumpukan.
8. Clear: Menghapus semua elemen pada tumpukan.
9. Size: Mengembalikan jumlah elemen yang ada dalam tumpukan.

## Guided

### 1. Guided 1

```C++
#include <iostream>
using namespace std;
string arrayBuku[5];
int maksimal = 5, top = 0;
bool isFull()
{
    return (top == maksimal);
}
bool isEmpty()
{
    return (top == 0);
}
void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}
void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}
void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}
int countStack()
{
    return top;
}
void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}
void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}
void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}
int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    
    cetakArrayBuku();
    return 0;
}
```
Pertama program mendefinisikan sebuah array "arrayBuku" yang memiliki ukuran maksimum 5 dan variabel top untuk menandai indeks teratas (atau jumlah elemen) dalam stack. Program kemudian mendefinisikan beberapa fungsi, seperti isFull() untuk memeriksa apakah stack penuh, isEmpty() untuk memeriksa apakah stack kosong, pushArrayBuku() untuk menambahkan data ke dalam stack, popArrayBuku() untuk menghapus data dari stack, peekArrayBuku() untuk melihat data pada posisi tertentu dalam stack, countStack() untuk menghitung jumlah data dalam stack, changeArrayBuku() untuk mengubah data pada posisi tertentu dalam stack, destroyArrayBuku() untuk menghapus semua data dalam stack, dan cetakArrayBuku() untuk mencetak seluruh data dalam stack.

Didalam fungsi main(), beberapa data buku ditambahkan ke dalam stack menggunakan fungsi pushArrayBuku(), lalu stack dicetak menggunakan cetakArrayBuku(). Kemudian, program memeriksa apakah stack penuh atau kosong menggunakan isFull() dan isEmpty(). Data pada posisi ke-2 dalam stack dilihat menggunakan peekArrayBuku(), lalu satu elemen dihapus dari stack menggunakan popArrayBuku(). Jumlah data dalam stack dihitung menggunakan countStack(), dan data pada posisi ke-2 diubah menggunakan changeArrayBuku(). Setelah itu, semua data dalam stack dihapus menggunakan destroyArrayBuku() dan jumlah data setelah dihapus dicetak.

## Unguided

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
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
```

#### Output:
Palindrom
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan6/laprak6/ug1a.png)

Bukan Palindrom
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan6/laprak6/ug1b.png)

Kode diatas meminta user untuk memasukkan sebuah kalimat, kemudian melakukan pra-pemrosesan terhadap kalimat tersebut dengan menghapus karakter non-alphanumeric dan mengubah semua huruf menjadi lowercase. Setelah itu, program memeriksa apakah kalimat yang sudah diproses tersebut merupakan palindrom atau tidak dengan menggunakan struktur data stack. Jika kalimat tersebut merupakan palindrom, program akan mencetak pesan "Kalimat tersebut adalah palindrom", dan jika bukan palindrom, program akan mencetak pesan "Kalimat tersebut adalah bukan palindrom". Proses pengecekan palindrom dilakukan dengan memasukkan setiap karakter kalimat ke dalam stack, kemudian membandingkan setiap karakter dengan karakter yang dikeluarkan dari stack. Jika semua karakter cocok, kalimat dianggap palindrom; jika tidak, kalimat dianggap bukan palindrom.

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
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
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan6/laprak6/ug2.png)

kode diatas meminta user untuk memasukkan sebuah kalimat atau kata, kemudian membalikkan urutan setiap kata dalam kalimat tersebut. Proses pembalikan kata dilakukan menggunakan struktur data stack. Pertama-tama, program menggunakan stringstream untuk memisahkan setiap kata dari kalimat input. Kemudian, setiap kata yang telah dipisahkan tersebut dibalikkan urutannya menggunakan fungsi reverseWord() yang mengiterasi setiap karakter dari belakang ke depan dan menyimpannya dalam variabel reversedWord. Kata yang telah dibalikkan kemudian dimasukkan ke dalam stack. Setelah semua kata dalam kalimat diproses, program mengambil setiap kata dari stack satu per satu dan menggabungkannya untuk membentuk kalimat baru yang telah dibalikkan urutannya. Spasi di akhir kalimat baru dihapus, dan hasil pembalikan kalimat ditampilkan ke layar.

## Referensi

[1] Wortman, K. (2022). Stacks: CS2/C++. POGIL Activity Clearinghouse, 3(4).

[2] Stack in C++ STL (2023), https://www.geeksforgeeks.org/stack-in-cpp-stl/
