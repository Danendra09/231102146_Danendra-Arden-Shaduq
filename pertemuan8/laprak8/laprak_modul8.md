# <h1 align="center">Laporan Praktikum Modul 8 - ALGORITMA SEARCHING</h1>

<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori
Algoritma Pencarian (Searching Algorithms)
Algoritma pencarian adalah teknik yang digunakan untuk menemukan nilai tertentu (atau kumpulan nilai) dalam kumpulan data seperti array, daftar, atau struktur data lainnya. Tujuan dari algoritma pencarian adalah untuk menentukan apakah elemen yang dicari ada di dalam kumpulan data, dan jika ada, di mana letaknya.

Tergantung pada sifat kumpulan data dan sumber daya yang tersedia, berbagai jenis algoritma pencarian digunakan. Beberapa algoritma pencarian yang umum digunakan meliputi:

### 1. Sequential Search (Pencarian Berurutan)
Sequential search, juga dikenal sebagai linear search, adalah metode pencarian sederhana yang digunakan untuk mencari elemen tertentu dalam array atau daftar. Algoritma ini bekerja dengan memeriksa setiap elemen satu per satu dari awal hingga akhir array sampai elemen yang dicari ditemukan atau sampai akhir array tercapai.

Pseuducode : 
1. Inisialisasi indeks pencarian (index) dengan 0.
2. Lakukan iterasi melalui setiap elemen array.
3. Pada setiap iterasi, periksa apakah elemen saat ini sama dengan elemen yang dicari.
4. Jika ditemukan, kembalikan indeks saat ini.
5. Jika tidak, lanjutkan ke elemen berikutnya.
6. Jika iterasi selesai dan elemen tidak ditemukan, kembalikan nilai yang menandakan bahwa elemen tidak ada.

### 2. Binary Search (Pencarian Biner)
Binary search adalah algoritma pencarian yang efisien yang bekerja dengan cara membagi array menjadi dua bagian dan memeriksa elemen tengah. Jika elemen tengah sama dengan elemen yang dicari, pencarian selesai. Jika tidak, pencarian dilanjutkan di salah satu setengah array tergantung pada apakah elemen yang dicari lebih kecil atau lebih besar dari elemen tengah.

Pseuducode : 
1. Inisialisasi indeks awal (left) dengan 0 dan indeks akhir (right) dengan panjang array - 1.
2. Selama left <= right:
    a. Hitung indeks tengah (mid) sebagai (left + right) / 2.
    b. Jika elemen di indeks tengah sama dengan elemen yang dicari, kembalikan indeks tengah.
    c. Jika elemen di indeks tengah lebih kecil dari elemen yang dicari, perbarui left = mid + 1.
    d. Jika elemen di indeks tengah lebih besar dari elemen yang dicari, perbarui right = mid - 1.
3. Jika pencarian selesai dan elemen tidak ditemukan, kembalikan nilai yang menandakan bahwa elemen tidak ada.

## Guided

### 1. Guided 1

```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data[n] = {9,4,1,7,5,12,4,13,4,10};
    int cari = 10;
    bool ketemu = false;
    int i;

    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout<<"Program Sequential Search"<<endl;
    cout<<"data : {9,4,1,7,5,12,4,13,4,10} "<<endl;

    if (ketemu) {
        cout<<"\nAngka "<<cari<<" ditemukan pada indeks ke-"<<i<<endl;
    } else {
        cout<<"data tidak ditemukan"<<endl;
    }

    return 0;
}
```
Kode di atas merupakan salah satu contoh implementasi dari Sequential Search untuk mencari nilai tertentu dalam array. Pertama, program mendeklarasikan sebuah array `data` berisi 10 elemen dengan nilai yang telah ditentukan. Nilai yang akan dicari, `cari`, diinisialisasi dengan 10. Variabel `ketemu` diinisialisasi sebagai `false` untuk menunjukkan apakah nilai tersebut ditemukan. Program kemudian menggunakan loop `for` untuk memeriksa setiap elemen dalam array. Jika elemen yang dicari ditemukan, `ketemu` diatur menjadi `true` dan loop dihentikan menggunakan `break`, mencatat indeks dimana elemen tersebut ditemukan dalam variabel `i`. Setelah loop selesai, program menampilkan pesan "Program Sequential Search" dan isi dari array. Kemudian, berdasarkan nilai `ketemu`, program mencetak apakah nilai yang dicari ditemukan dan menunjukkan indeksnya, atau mencetak pesan bahwa nilai tidak ditemukan. Program berakhir dengan mengembalikan 0, menandakan eksekusi yang sukses.

### 2. Guided 2

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort()
{
    int temp, min, i, j;
    for (i = 0; i < 7; i++)
    {
        min = i;
        for (j = i + 1; j < 7; j++)
        {
            if (dataArray[j] < dataArray[min])
            {
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}
void binarysearch()
{
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6; // Corrected to 6 to match array bounds
    while (!b_flag && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (dataArray[tengah] == cari)
        {
            b_flag = true;
        }
        else if (dataArray[tengah] < cari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (b_flag)
    {
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    }
    else
    {
        cout << "\nData tidak ditemukan\n";
    }
}
int main()
{
    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData: ";
    // Tampilkan data awal
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    cout << "\nData diurutkan: ";
    // Urutkan data dengan selection sort
    selection_sort();
    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++)
    {
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    binarysearch();
    _getche();
    return 0;
}
```
Kode di atas adalah salah satu penerapan Binary Search untuk mencari nilai tertentu dalam sebuah array setelah array tersebut diurutkan menggunakan algoritma Selection Sort. Program dimulai dengan mendeklarasikan array `dataArray` berisi 7 elemen dan sebuah variabel `cari` untuk menyimpan nilai yang akan dicari. Fungsi `selection_sort` mengurutkan elemen-elemen dalam `dataArray` dengan cara menemukan elemen terkecil dan menukarnya dengan elemen saat ini, berulang untuk setiap elemen. Fungsi `binarysearch` melakukan pencarian biner pada array yang telah diurutkan. Variabel `awal`, `akhir`, dan `tengah` digunakan untuk melacak batas pencarian dan posisi tengah. Selama nilai yang dicari belum ditemukan (`b_flag` false) dan masih ada elemen yang belum diperiksa (`awal <= akhir`), algoritma akan membandingkan nilai tengah dengan nilai yang dicari. Jika cocok, pencarian selesai; jika nilai tengah lebih kecil, pencarian dilanjutkan di bagian kanan; jika lebih besar, pencarian dilanjutkan di bagian kiri. Fungsi `main` menampilkan data awal, meminta input user untuk nilai yang dicari, menampilkan data setelah diurutkan, dan memanggil `binarysearch` untuk mencari nilai tersebut. Hasil pencarian, apakah data ditemukan atau tidak, kemudian ditampilkan. Program menunggu input dari user sebelum selesai menggunakan `_getche()` untuk memastikan output terlihat sebelum program berakhir.

## Unguided

### 1.  Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
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
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan8/laprak8/ug1.png)

kode dia atas digunakan untuk mencari semua kemunculan huruf tertentu dalam sebuah kalimat menggunakan algoritma Binary Search. Pertama, program mengambil input kalimat dan huruf yang dicari dari user. Selanjutnya, program mengubah seluruh kalimat dan huruf target menjadi huruf kecil untuk memastikan pencarian tidak case-sensitive. Setelah itu, program menghapus semua spasi dari kalimat dan mengurutkan kalimat tersebut dalam urutan abjad. Setelah kalimat diurutkan, program melakukan Binary Search untuk menemukan semua kemunculan huruf target dalam kalimat yang telah diurutkan. Jika huruf target ditemukan, program mencatat semua indeks di mana huruf tersebut muncul dalam sebuah vector. Program kemudian menampilkan semua indeks ini kepada user. Jika huruf target tidak ditemukan, program menampilkan pesan yang sesuai. Proses ini memastikan pencarian yang efisien dan tepat dengan memanfaatkan karakteristik Binary Search pada data yang telah diurutkan.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
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
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan8/laprak8/ug2.png)

Kode di atas bertujuan untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh user. Dimulai dengan mendeklarasikan beberapa pustaka standar, program kemudian mendefinisikan fungsi `isVowel` yang memeriksa apakah sebuah karakter merupakan huruf vokal (a, e, i, o, u). Fungsi ini mengubah karakter menjadi huruf kecil menggunakan `tolower` sebelum melakukan pengecekan. Selanjutnya, fungsi `countVowels` menghitung jumlah huruf vokal dalam kalimat yang diberikan dengan melakukan pencarian berurutan melalui setiap karakter dalam kalimat dan menggunakan `isVowel` untuk memeriksa apakah karakter tersebut vokal. Dalam fungsi `main`, program meminta user untuk memasukkan sebuah kalimat, yang dibaca menggunakan `getline`. Setelah itu, `countVowels` dipanggil untuk menghitung jumlah vokal dalam kalimat tersebut. Hasil perhitungan kemudian ditampilkan ke layar. Program berakhir dengan mengembalikan 0, menandakan bahwa eksekusinya berhasil.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
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

```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan8/laprak8/ug3.png)

Kode di atas bertujuan untuk menghitung berapa kali angka tertentu muncul dalam sebuah daftar angka menggunakan pencarian berurutan (Sequential Search). Program dimulai dengan mengimpor pustaka standar `iostream` dan `vector`, serta mendeklarasikan penggunaan namespace standar `std`. Fungsi `countNumber` didefinisikan untuk menghitung kemunculan angka target dalam sebuah vector `data_146`. Fungsi ini memulai dengan inisialisasi variabel penghitung `count` menjadi 0, kemudian menggunakan loop untuk memeriksa setiap elemen dalam vector. Jika elemen saat ini sama dengan target, penghitung ditambah satu. Setelah loop selesai, fungsi mengembalikan nilai penghitung. Dalam fungsi `main`, vector `data_146` diinisialisasi dengan nilai-nilai yang telah ditentukan, dan target pencarian ditetapkan ke 4. Program kemudian memanggil `countNumber` dengan `data_146` dan `target`, menyimpan hasilnya dalam variabel `count`. Hasil perhitungan kemudian ditampilkan ke layar, menunjukkan berapa kali angka target muncul dalam data. Program berakhir dengan mengembalikan nilai 0, menandakan bahwa eksekusi berhasil.

## Referensi

[1] Markuci, D., & Prianto, C. (2022). Analisis perbandingan penggunaan algoritma Sequential Search dan Binary Search pada aplikasi surat perjalanan dinas. JATI (Jurnal Mahasiswa Teknik Informatika), 6(1), 110-119.

[2] Binary Search Algorithm – Iterative and Recursive Implementation
https://www.geeksforgeeks.org/binary-search/


