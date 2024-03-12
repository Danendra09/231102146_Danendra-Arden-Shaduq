# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>
<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori

Tipe data merupakan sebuah jenis nilai atau berupa nilai apa yang akan  ditampung  oleh  sebuah  variabel.  Tipe  data  ini  wajib  ada  ketika  akan membuat  sebuah  variabel  agar  variabel  tersebut  memiliki  nilai  yang  spesifik dan  jelas  ketika  digunakan  nantinya.

1. Tipe Data Primitif
Tipe data primitif adalah tipe data bawaan bahasa pemrograman dan bisa langsung digunakan programmer untuk mendeklarasikan variabel. Contohnya sebagai berikut : 
- Integer(int)
Tipe data integer biasanya membutuhkan 4 bytes memory dan memiliki nilai antara -2147483648 sampai 2147483647.
- Character(char)
Tipe data yang hanya bisa menyimpan satu karakter saja
- Boolean(bool)
Tipe data yang menyimpan nilai true atau false.
- Floating(float)
Tipe data angka pecahan digunakan untuk menyimpan nilai angka pecahan.

2. Tipe Data Abstrak
Tipe data abstrak (Abstract Data Types, atau disingkat ADT) dalam C++ adalah tipe data yang didefinisikan oleh pengguna dengan menggunakan klasifikasi dan operasi yang diinginkan. Tipe data abstrak ini tidak didefinisikan secara langsung dalam C++, tetapi dapat didefinisikan oleh pengguna dengan menggunakan klasifikasi dan operasi yang diinginkan.

3. Tipe Data Koleksi
Tipe data koleksi adalah tipe data yang digunakan untuk mengelompokkan dan mengorganisasi beberapa elemen data dalam satu unit. Berikut beberapa contohnya :
- Array, sebuah kumpulan elemen dengan tipe data yang sama. Ukuran array biasanya tetap setelah dideklarasikan.
- Vector, mirip dengan array, tetapi ukuran vektor dapat berubah secara dinamis saat program berjalan.
- Map, mirip dengan array namun dengan index yang memungkinkan untuk berupa tipe data selain integer. 

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
    // It allows user to enter the operands
    cout << "Enter two operands: ";
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enters +
    case '+':
        cout << "Result: " << num1 + num2;
        break;
    // If user enters -
    case '-':
        cout << "Result: " << num1 - num2;
        break;
    // If user enters *
    case '*':
        cout << "Result: " << num1 * num2;
        break;
    // If user enters /
    case '/':
        if (num2 != 0)
        {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2;
        }
        else
        {
            cout << "Error! Division by zero is not allowed.";
        }
        break;
    // If the operator is other than +, -, * or /,
    // error message will display
    default:
        cout << "Error! Operator is not correct";
    } // switch statement ends
    return 0;
}
```
Kode di atas digunakan untuk melakukan operasi perhitungan penjumlahan(+), pengurangan (-),perkalian(*), dan pembagian(/). Terdapat dua tipe data primitif yang digunakan pada kode diatas, char dan float, char digunakan pada switch, float digunakan untuk menginputkan angka pada operasi yang dipilih.

### 2. [Tipe Data Abstrak]
```C++
#include <stdio.h>
#include <string.h>

//struct
struct Mahasiswa
{
    char name[50];
    char address[100];
    int age;
};
int main(){
    struct Mahasiswa mhs1, mhs2;
    //mengisi nilai ke struct
    strcpy(mhs1.name, "Dian");
    strcpy(mhs1.address, "Mataram");
    mhs1.age = 22;
    strcpy(mhs2.name, "Bambang");
    strcpy(mhs2.address, "Surabaya");
    mhs1.age = 23;
    //mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
Kode diatas termasuk tipe data abstrak, dengan menggunakan struct. Struct diatas menggunakan struct Mahasiswa yang berisikan, char name yang memuat maksimal 50 karakter, char address yang memuat maksimal 100 karakter, dan int age. Kemudian bagian int main berisikan data mhs1 yang bernama Dian dan mhs2 yang bernama Bambang.
### 3. [Tipe Data Koleksi]
```C++
#include <iostream>
#include <array>
using namespace std;
int main()
{
    // Deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;
    // Mencetak array dengan tab
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua : " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```
Kode diatas merupakan tipe data koleksi yang menggunakan array. Array "nilai" dapat menampung 5 nilai yang sudah dideklarasikan, yaitu 23,50,34,78,dan 90.
## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
#include <cmath>//Library yang menyediakan berbagai fungsi matematika yang sering digunakan.
using namespace std;

//Fungsi untuk menghitung perpangkatan
double perpangkatan(double basis,int pangkat)//double -> bilangan desimal, int -> bilangan bulat
{
    return pow(basis, pangkat);//pow() -> fungsi untuk memangkatkan
}

//Fungsi untuk menghitung akar
double akarKuadrat(double angka)
{
    return sqrt(angka);//sqrt() -> "square root" digunakan untuk menghitung akar kuadrat dari sebuah bilangan
}
// Fungsi untuk memeriksa apakah suatu angka adalah bilangan prima
bool prima(int angka)//bool -> tipe data yang hanya memiliki dua nilai yaitu true dan false.
{
    if (angka <= 1) return false;//Memeriksa apakah angka kurang dari atau sama dengan 1
    if (angka <= 3) return true;//Memeriksa apakah angka kurang dari atau sama dengan 3
    if (angka % 2 == 0 || angka % 3 == 0) return false;//Memeriksa apakah angka merupakan kelipatan dari 2 atau 3
    for (int i = 5; i * i <= angka; i += 6)//Memeriksa untuk faktor-faktor lain yang bukan kelipatan dari 2 atau 3
    {
        if (angka % i == 0 || angka % (i + 2) == 0) return false;
    }
    //Jika tidak ada faktor selain 1 dan angka itu sendiri, maka angka adalah bilangan prima
    return true;
}

int main() {
    char pilihan;
    int pangkat, angka;

    do {
        cout << "Pilih operasi yang ingin Anda lakukan:";
        cout << "\na. Perpangkatan";
        cout << "\nb. Akar";
        cout << "\nc. Identifikasi bilangan prima";
        cout << "\nd. Keluar";
        cout << "\nPilihan Anda: ";
        cin >> pilihan;

        switch (toupper(pilihan))//toupper() -> fungsi untuk mengubah karakter ke kapital
        {
            case 'A':
                double basis;
                cout << "Masukkan angka yang dipangkatkan: ";
                cin >> basis;
                cout << "Masukkan pangkat: ";
                cin >> pangkat;
                cout << "Hasil perpangkatan: " << perpangkatan(basis, pangkat) << endl;
                break;
            case 'B':
                cout << "Masukkan angka: ";
                cin >> angka;
                cout << "Akar kuadrat dari " << angka << " adalah: " << akarKuadrat(angka) << endl;
                break;
            case 'C':
                cout << "Masukkan angka: ";
                cin >> angka;
                if (prima(angka))
                    cout << angka << " adalah bilangan prima." << endl;
                else
                    cout << angka << " bukan bilangan prima." << endl;
                break;
            case 'D':
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (toupper(pilihan) != 'D');// jika tidak menginput 'D' atau 'd' maka terus berulang

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan1/laprak1/output_unguided1.png)

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan1/laprak1/output_unguidedd1.png)

Kode diatas merupakan contoh program yang menggunakan tipe data primitif. Disini saya menggunakan tipe data double,int, bool, dan char. Program ini memiliki empat pilihan, yang pertama(a/A) ada perpangkatan, user akan diminta memasukkan angka yang akan dipangkatkan, kemudian memasukkan angka pangkat, lalu akan muncul outputnya. Pilihan kedua(b/B) yaitu menghitung akar kuadrat dari suatu bilangan, user akan diminta memasukkan angka yang akan dicari akar kuadratnya, kemudian akan muncul outputnya. Pilihan ketiga(c/C) menentukan apakah bilangan yang diinputkan user termasuk bilangan prima atau bukan. Pilihan keempat yaitu keluar dari program, jika user menginputkan selain a,b,c,d atau A,B,C,D, maka program akan kembali ke menu utama.

## Kesimpulan
Kesimpulan yang saya dapat dari mempelajari tipe data primitif ini, setiap tipe data memiliki perannya masing masing menyesuaikan kebutuhan yang akan digunakan, dan memilih tipe data yang sesuai sangat penting, karena ini akan berdampak ada keefisiensi dari program yang dibuat[1].

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
```C++
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
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan1/laprak1/output_unguided2.png)

Kode diatas menggunakan struct dan class. Struct mhs_2146 berisi string(nama, jurusan), int (angkatan). Untuk class buku_2146 bersifat public yang berisikan string(judul, penulis), int (tahun_terbit) dan void info yang akan menampilkan isi atau data judul, penulis dan tahun terbit. Pada bagian int main akan mendeklarasikan isi dari struct mhs_2146 dan class buku_2146.

A. Fungsi dari Class
Class mendefinisikan data yang akan disimpan dan operasi yang dapat dilakukan pada data tersebut. Ini memungkinkan untuk membuat objek yang menggabungkan data dan fungsionalitas dalam satu kesatuan.
B. Fungsi dari Struct
Struct, kumpulan data yang berbagai jenis (variabel) yang dikelompokkan bersama di dalam satu unit. Secara konseptual, struct mirip dengan class, namun dengan perbedaan-perbedaan tertentu dalam cara default aksesibilitas dan pewarisan bekerja.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.
```C++
#include <iostream>
#include <map>//library supaya bisa menggunakan fungsi map

using namespace std;
int main() {
    //Membuat map dengan key bertipe string dan value bertipe int
    map<string, int> nilai_2146;

    // Menambahkan data ke dalam map
    nilai_2146["Zoe"] = 85;
    nilai_2146["Samuel"] = 90;
    nilai_2146["Eli"] = 75;
    nilai_2146["Peter"] = 88;

    //Menampilkan nilai_2146 dari setiap elemen dalam map
    cout << "nilai Zoe: " << nilai_2146["Zoe"] << endl;
    cout << "nilai Samuel: " << nilai_2146["Samuel"] << endl;
    cout << "nilai Eli: " << nilai_2146["Eli"] << endl;
    cout << "nilai Peter: " << nilai_2146["Peter"] << endl;

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan1/laprak1/output_unguided3.png)

Kode di atas menggunakan library map untuk membuat dan mengelola sebuah map yang menggunakan string sebagai key dan integer sebagai value. Pertama, program membuat objek map dengan nama nilai_2146. Kemudian, program menambahkan beberapa pasangan key-value ke dalam map tersebut, yang mewakili nilai dari beberapa siswa. Setelah itu, program menampilkan nilai dari setiap siswa dengan menggunakan key-nya. Output dari program ini akan menampilkan nilai-nilai dari siswa yang telah ditambahkan sebelumnya. Dengan menggunakan map.

- Array memiliki ukuran yang sudah dideklarasikan, sedangkan map bisa berubah secara dinamis
- Array hanya bisa menggunakan satu tipe data yang sama, sedangkan map bisa menggunakan tipe data yang berbeda
- Array menyimpan data secara berurutan sedangkan map tidak berurutan, dengan key dan kita ingin mengakses atau memanipulasi data dengan cepat menggunakan key tersebut.

## Referensi
[1] Wimawan, R. B. (2019, April 11). Tipe Data Sederhana.