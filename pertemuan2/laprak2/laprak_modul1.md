# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>

<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori

Array merupakan sebuah struktur data yang digunakan untuk menyimpan kumpulan nilai yang bertipe data sama. Array memungkinkan untuk menyimpan beberapa nilai dalam satu variabel, dimana setiap nilai memiliki indeks atau kunci yang unik. Indeks ini digunakan untuk mengakses nilai-nilai tersebut.

1. Array Satu Dimensi
   Array satu dimensi merupakan jenis array yang memiliki satu indeks atau subscript. Elemen dalam array satu dimensi dapat diakses menggunakan hanya satu indeks, yang dimulai dari 0.

   Array satu dimensi sering digunakan dalam banyak situasi, seperti untuk menyimpan data yang bertipe data yang sama, seperti angka, huruf, atau boolean. Karena hanya memiliki satu indeks, array satu dimensi lebih mudah dibangun daripada array multidimensi.

2. Array Dua Dimensi
   Array dua dimensi, sering disebut sebagai matriks, merupakan perluasan dari array satu dimensi. Jika array satu dimensi hanya terdiri dari satu baris yang berisi elemen dari beberapa kolom, array dua dimensi terdiri dari beberapa baris elemen dengan tipe yang sama dan beberapa kolom. Mendeklarasikan array dua dimensi sama dengan mendeklarasikan array satu dimensi, hanya saja array dua dimensi memiliki dua jumlah elemen array yang diapit tanda kurung siku dan keduanya tidak boleh sama.
3. Array Multidimensi
   Array multidimensi, struktur data yang dapat menyimpan elemen-elemen dalam bentuk tabel dua dimensi atau lebih, di mana setiap elemen dapat diakses menggunakan satu atau lebih indeks. Dalam array multidimensi, elemen-elemen disusun dalam baris dan kolom, atau dalam dimensi yang lebih tinggi, seperti dalam bentuk matriks.

## Guided

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z
                     << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Kode diatas meminta user untuk menginputkan nilai untuk setiap elemen dari array tiga dimensi dengan menggunakan tiga loop. Setelah semua nilai dimasukkan, program mencetak nilai dari setiap elemen array menggunakan loop yang serupa. Terakhir, program mencetak kembali array secara berurutan, dengan setiap angka dipisahkan oleh spasi, menggunakan loop yang ketiga. Dengan demikian, program ini memungkinkan user untuk menginputkan dan melihat data dalam array tiga dimensi.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Kode diatas digunakan untuk mencari nilai maksimum dalam sebuah array dan menampilkan nilai maksimum beserta indeksnya. Pertama-tama, user diminta untuk menginputkan panjang array yang diinginkan. Kemudian, program meminta user untuk menginputkan angka-angka yang akan disimpan dalam array tersebut. Setelah semua angka dimasukkan, program melakukan iterasi melalui array untuk mencari nilai maksimum. Selama iterasi, jika nilai saat ini lebih besar dari nilai maksimum yang disimpan sebelumnya, maka nilai maksimum diupdate dan lokasi di mana nilai maksimum tersebut berada disimpan. Setelah iterasi selesai, program mencetak nilai maksimum beserta lokasinya dalam array.

## Unguided

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

```C++
// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
using namespace std;

int main() {
    int n_2146;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n_2146;

    int arr[n_2146];

    // menginputkan elemen array
    cout << "Masukkan data array:";
    for (int i = 0; i < n_2146; ++i) {
        std::cin >> arr[i];
    }
    // Fungsi untuk mencari bilangan yang genap
    cout << "Bilangan genap: ";
    for (int i = 0; i < n_2146; ++i) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    // Fungsi untuk mencari bilangan yang ganjil
    cout << "Bilangan ganjil: ";
    for (int i = 0; i < n_2146; ++i) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
```

#### Output:

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan1/laprak1/output_unguided1.png)

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan1/laprak1/output_unguidedd1.png)

Kode diatas meminta user untuk menginput jumlah elemen dalam array, kemudian meminta user untuk menginputkan nilai-nilai elemen tersebut. Setelah semua elemen dimasukkan, program memisahkan elemen-elemen array menjadi dua bagian, yaitu bilangan genap dan bilangan ganjil. Ini dilakukan dengan menggunakan dua loop yang berbeda: pertama, program mencari bilangan genap dengan mengiterasi melalui array dan memeriksa apakah nilai elemen tersebut habis dibagi dua atau tidak. Kedua, program mencari bilangan ganjil dengan memeriksa apakah nilai elemen tersebut tidak habis dibagi dua. Setelah itu, program mencetak kedua bagian bilangan tersebut secara terpisah.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
using namespace std;

int main() {
    int dimensi1, dimensi2, dimensi3;

    // Meminta pengguna untuk menginputkan ukuran array tiga dimensi
    cout << "Masukkan ukuran array tiga dimensi:\n";
    cout << "Dimensi 1: ";
    cin >> dimensi1;
    cout << "Dimensi 2: ";
    cin >> dimensi2;
    cout << "Dimensi 3: ";
    cin >> dimensi3;

    // Deklarasi array
    int arr[dimensi1][dimensi2][dimensi3];

    // Input elemen
    for (int x = 0; x < dimensi1; x++) {
        for (int y = 0; y < dimensi2; y++) {
            for (int z = 0; z < dimensi3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int x = 0; x < dimensi1; x++) {
        for (int y = 0; y < dimensi2; y++) {
            for (int z = 0; z < dimensi3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z
                     << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < dimensi1; x++) {
        for (int y = 0; y < dimensi2; y++) {
            for (int z = 0; z < dimensi3; z++) {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```

#### Output:

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan1/laprak1/output_unguided2.png)

Kode diatas meminta user untuk menginputkan ukuran array tiga dimensi, yaitu dimensi pertama, kedua, dan ketiga. Setelah itu, program mendeklarasikan sebuah array tiga dimensi dengan ukuran sesuai yang diinputkan user. Kemudian, program meminta user untuk menginputkan nilai-nilai elemen-elemen array tersebut melalui tiga loop, dimana setiap loop merepresentasikan satu dimensi dari array. Setelah semua nilai diinputkan, program mencetak nilai dari setiap elemen array menggunakan loop yang serupa. Terakhir, program mencetak kembali array secara berurutan, dengan setiap angka dipisahkan oleh spasi, menggunakan loop yang ketiga.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
#include <climits> // Untuk menggunakan INT_MIN dan INT_MAX
#include <iomanip> // Untuk mengatur presisi output

using namespace std;

int main()
{
    int n_2146;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n_2146;

    int arr[n_2146];

    // Input elemen array
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n_2146; ++i)
    {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Menu untuk mencari nilai maksimum, minimum, dan rata-rata
    int pilihan;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Cari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        // Case 1: Mencari nilai maksimum dari elemen-elemen array
        case 1:
        {
            int maksimum = INT_MIN; // Inisialisasi nilai maksimum dengan nilai minimum yang mungkin
            // Iterasi melalui array untuk mencari nilai maksimum
            for (int i = 0; i < n_2146; ++i)
            {
                if (arr[i] > maksimum)
                {
                    maksimum = arr[i]; // Jika nilai saat ini lebih besar dari maksimum, update nilai maksimum
                }
            }
            cout << "Nilai maksimum: " << maksimum << endl; // Tampilkan nilai maksimum
            break;
        }

        // Case 2: Mencari nilai minimum dari elemen-elemen array
        case 2:
        {
            int minimum = INT_MAX; // Inisialisasi nilai minimum dengan nilai maksimum yang mungkin
            // Iterasi melalui array untuk mencari nilai minimum
            for (int i = 0; i < n_2146; ++i)
            {
                if (arr[i] < minimum)
                {
                    minimum = arr[i]; // Jika nilai saat ini lebih kecil dari minimum, update nilai minimum
                }
            }
            cout << "Nilai minimum: " << minimum << endl; // Tampilkan nilai minimum
            break;
        }

        // Case 3: Menghitung nilai rata-rata dari elemen-elemen array
        case 3:
        {
            int total = 0; // Inisialisasi variabel untuk total elemen array
            // Iterasi melalui array untuk menjumlahkan semua elemen
            for (int i = 0; i < n_2146; ++i)
            {
                total += arr[i]; // Menambahkan nilai elemen saat ini ke total
            }
            double rata_rata = static_cast<double>(total) / n_2146; // Hitung rata-rata
            cout << "Nilai rata-rata: " << fixed << setprecision(2) << rata_rata << endl; // Tampilkan rata-rata
            break;
        }

        // Case 4: Keluar dari program
        case 4:
            cout << "Terima kasih telah menggunakan program ini.\n"; // Tampilkan pesan keluar
            break;

        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}
```

#### Output:

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan1/laprak1/output_unguided3.png)

Kode diatas meminta user untuk menginputkan jumlah elemen dalam sebuah array. user kemudian diminta untuk menginputkan nilai-nilai elemen tersebut. Setelah semua nilai dimasukkan, program menampilkan sebuah menu yang memungkinkan user untuk memilih operasi yang ingin dilakukan terhadap array tersebut, yaitu mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen array, atau keluar dari program. Program menggunakan loop do-while untuk terus menampilkan menu hingga user memilih untuk keluar. Setiap pilihan menu diimplementasikan menggunakan switch-case, dimana setiap case menjalankan operasi yang sesuai sesuai dengan pilihan user. Untuk mencari nilai maksimum dan minimum, program melakukan iterasi melalui array untuk mencari nilai terbesar dan terkecil, sedangkan untuk mencari nilai rata-rata, program menjumlahkan semua elemen dan kemudian membaginya dengan jumlah elemen array. Nilai rata-rata ditampilkan dengan dua desimal menggunakan fungsi setprecision().

## Referensi

[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.
[2] Arraffi, A. (2019). Tipe data larik (array).
