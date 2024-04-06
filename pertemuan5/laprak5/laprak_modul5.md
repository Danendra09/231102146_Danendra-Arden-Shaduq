# <h1 align="center">Laporan Praktikum Modul 5 - Hash Table</h1>

<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori

Hash table adalah struktur data yang digunakan dalam pemrograman komputer untuk menyimpan dan mengakses data dengan efisien. Hash table berfungsi dengan menggunakan fungsi hash untuk memetakan kunci (key) data ke lokasi penyimpanan yang tepat dalam tabel. Fungsi hash mengambil input berupa kunci data dan menghasilkan nilai hash, yang kemudian digunakan sebagai indeks untuk menentukan lokasi penyimpanan dalam tabel. Tujuan utama dari penggunaan hash table adalah untuk mempercepat pencarian, penyisipan, dan penghapusan data dengan cara meminimalkan waktu akses ke data tersebut. Ini adalah salah satu struktur data yang paling umum digunakan dalam pengembangan perangkat lunak karena kemampuannya untuk menyediakan waktu akses yang konstan (O(1)) untuk operasi dasar seperti pencarian, penyisipan, dan penghapusan data.

Fungsi hash table adalah algoritma matematis yang digunakan untuk memetakan kunci data ke lokasi penyimpanan dalam tabel hash. Tujuannya adalah untuk menghasilkan nilai hash yang unik untuk setiap kunci data, memungkinkan akses cepat ke data dalam hash table. Fungsi hash harus dirancang sedemikian rupa sehingga meminimalkan tabrakan hash, sehingga data tersimpan secara efisien dan pencarian dilakukan dengan waktu yang optimal.

Struktur hash table terdiri dari sejumlah bucket atau slot penyimpanan, di mana setiap bucket memiliki indeks yang berbeda. Saat data dimasukkan ke dalam hash table, fungsi hash digunakan untuk menghitung indeks penyimpanan, dan data kemudian ditempatkan di bucket yang sesuai. Namun, dalam prakteknya, terkadang dua atau lebih kunci data dapat dihasilkan oleh fungsi hash yang sama, yang disebut sebagai tabrakan hash. Untuk mengatasi tabrakan hash, teknik penanganan tabrakan seperti chaining atau open addressing digunakan. Dalam chaining, setiap bucket berisi daftar atau rantai dari semua nilai yang dihash ke lokasi tersebut, sementara dalam open addressing, pencarian dilakukan untuk menemukan slot yang kosong dalam tabel.

## Guided

### 1. Guided 1

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}
// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};
// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }
    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }
    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value
                     << endl;
                current = current->next;
            }
        }
    }
};
int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
    // Deletion
    ht.remove(4);
    // Traversal
    ht.traverse();
    return 0;
}
```
Kode diatas mendefinisikan sebuah struct Node yang mewakili setiap elemen dalam hash table. Setiap node berisi sebuah kunci, sebuah nilai, dan sebuah pointer ke node berikutnya dalam rantai.

class HashTable berisi sebuah array dari pointer ke node, yang mewakili hash table itu sendiri. class ini memiliki beberapa metode:

insert(key, value): Memasukkan pasangan kunci-nilai baru ke dalam hash table. Jika kunci sudah ada, nilai akan diperbarui.
get(key): Mengembalikan nilai yang terkait dengan kunci yang diberikan. Jika kunci tidak ada, fungsi ini mengembalikan -1.
remove(key): Menghapus pasangan kunci-nilai yang terkait dengan kunci yang diberikan dari hash table.
traverse(): Mencetak semua pasangan kunci-nilai dalam hash table.
Fungsi main menunjukkan bagaimana menggunakan class HashTable. Ini membuat hash table baru, memasukkan beberapa pasangan kunci-nilai, mencari kunci, menghapus sebuah kunci, dan menelusuri hash table untuk mencetak semua pasangan kunci-nilai.

### 2. Guided 2

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string name;
string phone_number;
class HashNode
{
public:
    string name;
    string phone_number;
    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name,
                                               phone_number));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it !=
                                                table[hash_val].end();
             it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};
int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : "
    << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
    << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
    << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```
Program ini mengimplementasikan hash map sederhana dalam bahasa C++. Ini mencakup pustaka yang diperlukan dan mendefinisikan konstanta integer `TABLE_SIZE` untuk menentukan ukuran hash table. 

Ada dua class utama: `HashNode` dan `HashMap`. `HashNode` mewakili setiap elemen dalam hash table dan berisi atribut `name` dan `phone_number`. `HashMap` adalah implementasi hash table sebenarnya, menggunakan array dari vektor untuk menangani tabrakan. 

class `HashMap` termasuk metode untuk memasukkan, menghapus, dan mencari elemen berdasarkan nama karyawan. Metode-metode ini menggunakan fungsi hash sederhana yang menjumlahkan nilai ASCII setiap karakter dalam nama dan menghitung modulus dengan `TABLE_SIZE` untuk menentukan indeks. 

Di dalam fungsi `main`, objek `HashMap` dibuat, dan beberapa entri karyawan dimasukkan ke dalam hash table. Operasi seperti mencari nomor telepon berdasarkan nama, menghapus entri karyawan, dan mencetak isi hash table ditunjukkan.

## Unguided

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :

a. Setiap mahasiswa memiliki NIM dan nilai.

b. Program memiliki tampilan pilihan menu berisi poin C.

c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).


```C++
// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
#include <list>
#include <string>

using namespace std;

// Struktur data untuk menyimpan informasi mahasiswa
struct Mahasiswa {
    string nama_2146;   // Variabel nama mahasiswa
    int nim_2146;       // Variabel NIM mahasiswa
    int nilai_2146;     // Variabel nilai mahasiswa
};

// Ukuran tabel hash
const int hash_table_size = 10;

// Kelas untuk hash table
class HashTable {
private:
    list<Mahasiswa> table[hash_table_size];  // Array dari linked list untuk menyimpan data

    // Fungsi hash sederhana untuk menghasilkan indeks
    int hashFunction(int nim_2146) {  // Fungsi hash sederhana dengan parameter NIM
        return nim_2146 % hash_table_size;  // Mengembalikan nilai modulo untuk mendapatkan indeks
    }

public:
    // Fungsi untuk menambahkan data mahasiswa ke hash table
    void tambahData(Mahasiswa data) {  // Fungsi untuk menambahkan data mahasiswa
        int index = hashFunction(data.nim_2146);  // Mendapatkan indeks menggunakan fungsi hash
        table[index].push_back(data);  // Menambahkan data ke linked list pada indeks yang sesuai
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void hapusData(int nim_2146) {  // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
        int index = hashFunction(nim_2146);  // Mendapatkan indeks menggunakan fungsi hash
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {  // Iterasi melalui linked list pada indeks
            if (it->nim_2146 == nim_2146) {  // Jika NIM cocok
                cout << "NIM " << it->nim_2146 << " dengan nama " << it->nama_2146 << " berhasil dihapus" << endl;  // Pesan sukses
                table[index].erase(it);  // Hapus data dari linked list
                return;  // Keluar dari fungsi
            }
        }
        cout << "Data tidak ditemukan" << endl;  // Jika NIM tidak ditemukan
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void cariByNIM(int nim_2146) {  // Fungsi untuk mencari data mahasiswa berdasarkan NIM
        int index = hashFunction(nim_2146);  // Mendapatkan indeks menggunakan fungsi hash
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {  // Iterasi melalui linked list pada indeks
            if (it->nim_2146 == nim_2146) {  // Jika NIM cocok
                cout << "Nama: " << it->nama_2146 << " NIM: " << it->nim_2146 << " Nilai: " << it->nilai_2146 << endl;  // Cetak informasi mahasiswa
                return;  // Keluar dari fungsi
            }
        }
        cout << "Data tidak ditemukan" << endl;  // Jika NIM tidak ditemukan
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80-90)
    void cariByNilai() {  // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80-90)
        for (int i = 0; i < hash_table_size; ++i) {  // Iterasi melalui semua indeks tabel hash
            for (auto it = table[i].begin(); it != table[i].end(); ++it) {  // Iterasi melalui linked list pada setiap indeks
                if (it->nilai_2146 >= 80 && it->nilai_2146 <= 90) {  // Jika nilai berada dalam rentang
                    cout << "Nama: " << it->nama_2146 << " NIM: " << it->nim_2146 << " Nilai: " << it->nilai_2146 << endl;  // Cetak informasi mahasiswa
                }
            }
        }
    }
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Tambah Data Mahasiswa" << endl;
    cout << "2. Hapus Data Mahasiswa" << endl;
    cout << "3. Cari Data Mahasiswa by NIM" << endl;
    cout << "4. Cari Data Mahasiswa by Nilai (80-90)" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih: ";
}

int main() {
    HashTable hashTable;  // Deklarasi objek hash table
    int choice;  // Variabel untuk menyimpan pilihan menu

    do {  // Loop untuk memperbarui menu
        tampilkanMenu();
        cin >> choice;

        switch (choice) {  // Switch case untuk memilih operasi
            case 1: {  // Tambah data mahasiswa
                Mahasiswa mhs;  // Deklarasi objek mahasiswa
                cout << "Masukkan Nama: ";
                cin.ignore();  // Menghapus karakter newline dari buffer
                getline(cin, mhs.nama_2146);  // Input nama
                cout << "Masukkan NIM: ";
                cin >> mhs.nim_2146;
                cout << "Masukkan Nilai: ";
                cin >> mhs.nilai_2146;
                hashTable.tambahData(mhs);  // Tambahkan data ke hash table
                break;  // Keluar dari switch case
            }
            case 2: {  // Hapus data mahasiswa
                int nim_2146;  // Variabel untuk menyimpan NIM yang akan dihapus
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim_2146;  // Masukkan NIM yang akan dihapus
                hashTable.hapusData(nim_2146);  // Hapus data dari hash table
                break;  // Keluar dari switch case
            }
            case 3: {  // Cari data mahasiswa berdasarkan NIM
                int nim_2146;  // Variabel untuk menyimpan NIM yang akan dicari
                cout << "Masukkan NIM yang akan dicari: ";
                cin >> nim_2146;  // Masukkan NIM yang akan dicari
                hashTable.cariByNIM(nim_2146);  // Cari data berdasarkan NIM
                break;  // Keluar dari switch case
            }
            case 4: {  // Cari data mahasiswa berdasarkan rentang nilai
                cout << "Mahasiswa dengan nilai antara 80-90:" << endl;
                hashTable.cariByNilai();  // Cari data berdasarkan rentang nilai
                break;  // Keluar dari switch case
            }
            case 5:  // Keluar dari program
                cout << "Keluar..." << endl;
                break;  // Keluar dari switch case
            default:  // Pilihan tidak valid
                cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 5);  // Ulangi selama pilihan tidak sama dengan 5

    return 0;  // Selesai
}
```

#### Output:
Tambah Data
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan5/laprak5/ug1a.png)

Hapus Data
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan5/laprak5/ug1b.png)

Cari Data by NIM
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan5/laprak5/ug1c.png)

Cari Data by Nilai (80-90)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan5/laprak5/ug1d.png)

Coding program tersebut adalah implementasi dari hash table untuk menyimpan data mahasiswa. Setiap mahasiswa direpresentasikan sebagai sebuah struktur `Mahasiswa` yang memiliki tiga atribut: `nama_2146`, `nim_2146`, dan `nilai_2146`. Ukuran tabel hash ditentukan oleh konstanta `hash_table_size`. Kelas `HashTable` memiliki metode untuk menambahkan data mahasiswa ke tabel hash, menghapus data berdasarkan NIM, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai antara 80-90. Pada fungsi `main`, pengguna diberikan pilihan menu yang memungkinkan untuk melakukan operasi seperti menambah data, menghapus data, mencari data berdasarkan NIM, mencari data berdasarkan rentang nilai, atau keluar dari program. Pengguna dapat memasukkan data mahasiswa dengan menentukan nama, NIM, dan nilai. Hasil operasi akan ditampilkan sesuai dengan pilihan yang dibuat pengguna.

## Referensi

[1] D. Liu, Z. Cui, S. Xu and H. Liu, "An empirical study on the performance of hash table," 2014 IEEE/ACIS 13th International Conference on Computer and Information Science (ICIS), Taiyuan, China, 2014.

[2] GeeksforGeeks, Hash Table Data Structure https://www.geeksforgeeks.org/hash-table-data-structure/
