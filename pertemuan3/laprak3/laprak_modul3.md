# <h1 align="center">Laporan Praktikum Modul 1 - Tipe Data</h1>

<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori

Linked list adalah struktur data linear di mana setiap elemen disimpan dalam sebuah node. Setiap node memiliki dua komponen utama: data dan pointer yang menunjuk ke node berikutnya dalam urutan. Dengan kata lain, setiap elemen dalam linked list terhubung ke elemen berikutnya melalui pointer, membentuk serangkaian node yang terhubung.

Pentingnya linked list terletak pada fleksibilitasnya. Ketika array memerlukan alokasi memori yang berdekatan untuk menyimpan elemen, linked list memungkinkan penyimpanan data dalam lokasi yang tidak berurutan dalam memori, karena setiap node memiliki pointer yang menunjuk ke lokasi memori node berikutnya.

Linked list memiliki beberapa varian, diantaranya single linked list, double linked list, dan circular linked list, masing-masing memiliki karakteristik yang unik tergantung pada jumlah pointer yang dimiliki setiap node (misalnya, double linked list memiliki pointer ke node sebelumnya dan node berikutnya). Linked list sering digunakan dalam implementasi struktur data lain, seperti stack, queue, dan hashtable.

1. Single Linked List
Single linked list adalah struktur data linear di mana setiap elemen, disebut node, terdiri dari dua bagian: data itu sendiri dan sebuah pointer yang menunjukkan ke node berikutnya dalam urutan. Setiap node terhubung secara berurutan melalui pointer, membentuk serangkaian elemen yang terhubung. Node pertama dalam linked list disebut sebagai head, sedangkan node terakhir biasanya memiliki pointer yang menunjuk ke nilai null, menandakan akhir dari list. Kelebihan dari single linked list yaitu kemampuannya untuk memungkinkan penambahan dan penghapusan elemen secara efisien di bagian tengah list, namun akses elemen secara acak kurang efisien karena memerlukan iterasi melalui list dari awal hingga elemen yang diinginkan. Linked list sering digunakan dalam implementasi struktur data lain dan cocok untuk situasi di mana ukuran dan jumlah elemen sering berubah.

2. Double Linked List
Double linked list adalah struktur data linear di mana setiap elemen, disebut node, memiliki tiga bagian: data itu sendiri, pointer yang menunjuk ke node sebelumnya, dan pointer yang menunjuk ke node berikutnya dalam urutan. Dibandingkan dengan single linked list, double linked list memungkinkan navigasi maju dan mundur dalam list dengan mudah karena setiap node memiliki referensi ke node sebelumnya dan berikutnya. Hal ini membuat operasi seperti penghapusan dan penambahan elemen di tengah list lebih efisien, karena tidak perlu mencari elemen sebelumnya untuk mengakses elemen yang ingin dihapus atau dimasukkan. Namun, double linked list memerlukan alokasi memori tambahan untuk setiap node karena penyimpanan pointer tambahan, sehingga dapat menggunakan lebih banyak memori dibandingkan dengan single linked list. Meskipun demikian, kelebihan navigasi dan fleksibilitas membuat double linked list berguna dalam berbagai implementasi struktur data dan algoritma.

## Guided

### 1. Latihan Single Linked List

```C++
#include <iostream>

using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Kode diatas melakukan berbagai operasi dasar pada linked list seperti penambahan, penghapusan, dan pengubahan elemen, serta menampilkan isi dari linked list. Pertama, program menginisialisasi linked list dengan fungsi init(). Kemudian, program dapat menambahkan elemen pada bagian depan, belakang, atau ditengah linked list dengan fungsi-fungsi seperti insertDepan(), insertBelakang(), dan insertTengah(). Setelah itu, program melakukan penghapusan elemen dari depan, belakang, atau ditengah menggunakan fungsi-fungsi hapusDepan(), hapusBelakang(), dan hapusTengah(). Program juga dapat melakukan pengubahan nilai elemen menggunakan fungsi-fungsi seperti ubahDepan(), ubahBelakang(), dan ubahTengah(). Terakhir, program dapat menampilkan isi linked list menggunakan fungsi tampil().

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        head = newNode;
    }
    void pop()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == oldData)
            {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main()
{
    DoublyLinkedList list;
    while (true)
    {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2:
        {
            list.pop();
            break;
        }
        case 3:
        {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData,newData);
            if (!updated)
            {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4:
        {
            list.deleteAll();
            break;
        }
        case 5:
        {
            list.display();
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```
Ketika program dijalankan, pengguna diberikan opsi untuk memilih operasi yang ingin dilakukan. Opsi yang tersedia termasuk menambah data baru, menghapus data, memperbarui data, menghapus semua data, menampilkan data, dan keluar dari program. Setiap opsi memiliki implementasi yang sesuai dalam class DoublyLinkedList.

Pilihan 1 (Add data) meminta pengguna untuk memasukkan data baru dan menambahkannya ke linked list menggunakan fungsi push().
Pilihan 2 (Delete data) menghapus data dari depan linked list menggunakan fungsi pop().
Pilihan 3 (Update data) meminta pengguna untuk memasukkan data lama dan data baru, kemudian memperbarui data lama menjadi data baru menggunakan fungsi update().
Pilihan 4 (Clear data) menghapus semua data dari linked list menggunakan fungsi deleteAll().
Pilihan 5 (Display data) menampilkan semua data yang ada dalam linked list menggunakan fungsi display().
Pilihan 6 (Exit) mengakhiri program.

## Unguided

### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk
menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan
dari user. Lakukan operasi berikut:
a. Masukkan data sesuai urutan berikut. (Gunakan insert depan,
belakang atau tengah). Data pertama yang dimasukkan adalah
nama dan usia anda.

Nama_anda Usia_anda
John 19
Jane 20
Michael 18
Yusuke 19
Akechi 20
Hoshino 18
Karin 18

b. Hapus data Akechi
c. Tambahkan data berikut diantara John dan Jane : Futaba 18
d. Tambahkan data berikut diawal : Igor 20
e. Ubah data Michael menjadi : Reyn 18
f. Tampilkan seluruh data

```C++
// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
using namespace std;

// Node struct untuk merepresentasikan node dalam linked list
struct Node
{
    string nama_2146;
    int usia_2146;
    Node *next;
};

// class untuk mengelola linked list
class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
    }

    // Destructor
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di depan
    void insertDepan(string nama_2146, int usia_2146)
    {
        Node *newNode = new Node;
        newNode->nama_2146 = nama_2146;
        newNode->usia_2146 = usia_2146;
        newNode->next = head;
        head = newNode;
    }

    // Fungsi untuk menambahkan node di belakang
    void insertBelakang(string nama_2146, int usia_2146)
    {
        Node *newNode = new Node;
        newNode->nama_2146 = nama_2146;
        newNode->usia_2146 = usia_2146;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    // Fungsi untuk menambahkan node di tengah
    void insertTengah(string nama_2146, int usia_2146, int posisi)
    {
        if (posisi <= 0)
        {
            cout << "Posisi harus lebih besar dari 0" << endl;
            return;
        }
        if (posisi == 1)
        {
            insertDepan(nama_2146, usia_2146);
            return;
        }
        Node *newNode = new Node;
        newNode->nama_2146 = nama_2146;
        newNode->usia_2146 = usia_2146;
        Node *current = head;
        for (int i = 1; i < posisi - 1 && current != nullptr; ++i)
        {
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Posisi terlalu besar" << endl;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Fungsi untuk mencari node berdasarkan nama
    Node *search(string nama_2146)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->nama_2146 == nama_2146)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void hapus(string nama_2146)
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->nama_2146 == nama_2146)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->nama_2146 == nama_2146)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    // Fungsi untuk mengupdate data berdasarkan nama
    void update(string nama_2146, string newNama_2146, int newUsia_2146)
    {
        Node *current = search(nama_2146);
        if (current != nullptr)
        {
            current->nama_2146 = newNama_2146;
            current->usia_2146 = newUsia_2146;
        }
        else
        {
            cout << "Data tidak ditemukan" << endl;
        }
    }

    // Fungsi untuk menampilkan seluruh data
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->nama_2146 << " " << current->usia_2146 << endl;
            current = current->next;
        }
    }
};

int main()
{
    LinkedList list;

    // Input data pengguna
    string namaSaya;
    int usiaSaya;

    // Input data pengguna sendiri
    cout << "Masukkan nama Anda: ";
    getline(cin, namaSaya);
    cout << "Masukkan usia Anda: ";
    cin >> usiaSaya;
    cin.ignore();

    // Masukkan data pengguna ke dalam linked list
    list.insertDepan(namaSaya, usiaSaya);

    // Input data nama dan usia mahasiswa lain dari pengguna
    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa lain: ";
    cin >> jumlahMahasiswa;
    cin.ignore();

    for (int i = 0; i < jumlahMahasiswa; ++i)
    {
        string namaMahasiswa;
        int usiaMahasiswa;

        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, namaMahasiswa);
        cout << "Masukkan usia mahasiswa ke-" << i + 1 << ": ";
        cin >> usiaMahasiswa;
        cin.ignore();

        list.insertBelakang(namaMahasiswa, usiaMahasiswa);
    }

    // Tampilkan seluruh data
    cout << "Data mahasiswa:" << endl;
    list.display();
    cout << endl;

    // Menu operasi
    while (true)
    {
        char opsi;
        cout << "Menu Operasi:" << endl;
        cout << "1. Hapus data" << endl;
        cout << "2. Tambahkan data di depan" << endl;
        cout << "3. Tambahkan data di tengah" << endl;
        cout << "4. Tambahkan data di belakang" << endl;
        cout << "5. Update data" << endl;
        cout << "6. Tampilkan data" << endl;
        cout << "7. Keluar" << endl;
        cin >> opsi;
        cin.ignore();

        // Proses operasi sesuai dengan opsi yang dipilih
        switch (opsi)
        {
        case '1':
        {
            string namaHapus;
            cout << "Masukkan nama yang ingin dihapus: ";
            getline(cin, namaHapus);
            list.hapus(namaHapus);
            break;
        }
        case '2':
        {
            string namaTambahDepan;
            int usiaTambahDepan;
            cout << "Masukkan nama yang ingin ditambahkan di depan: ";
            getline(cin, namaTambahDepan);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di depan: ";
            cin >> usiaTambahDepan;
            cin.ignore();
            list.insertDepan(namaTambahDepan, usiaTambahDepan);
            break;
        }
        case '3':
        {
            string namaTambahTengah;
            int usiaTambahTengah;
            int posisiTambahTengah;
            cout << "Masukkan nama yang ingin ditambahkan di tengah: ";
            getline(cin, namaTambahTengah);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di tengah: ";
            cin >> usiaTambahTengah;
            cout << "Masukkan posisi untuk menambahkan data di tengah: ";
            cin >> posisiTambahTengah;
            cin.ignore();
            list.insertTengah(namaTambahTengah, usiaTambahTengah, posisiTambahTengah);
            break;
        }
        case '4':
        {
            string namaTambahBelakang;
            int usiaTambahBelakang;
            cout << "Masukkan nama yang ingin ditambahkan di belakang: ";
            getline(cin, namaTambahBelakang);
            cout << "Masukkan usia mahasiswa yang ingin ditambahkan di belakang: ";
            cin >> usiaTambahBelakang;
            cin.ignore();
            list.insertBelakang(namaTambahBelakang, usiaTambahBelakang);
            break;
        }
        case '5':
        {
            string namaUpdate;
            cout << "Masukkan nama yang ingin diupdate: ";
            getline(cin, namaUpdate);
            string newNama;
            int newUsia;
            cout << "Masukkan nama baru: ";
            getline(cin, newNama);
            cout << "Masukkan usia baru: ";
            cin >> newUsia;
            cin.ignore();
            list.update(namaUpdate, newNama, newUsia);
            break;
        }
        case '6':
        {
            cout << "Data mahasiswa:" << endl;
            list.display();
            break;
        }
        case '7':
        {
            cout << "Keluar dari program" << endl;
            exit(0);
        }
        default:
            cout << "pilihan tidak ada" << endl;
        }
    }

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan3/laprak3/ug1a.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan3/laprak3/ug1b.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan3/laprak3/ug1c.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan3/laprak3/ug1d.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan3/laprak3/ug1e.png)

Saat program pertama kali dijalankan, pengguna diminta untuk memasukkan nama dan usia mereka sendiri, yang kemudian dimasukkan ke dalam linked list sebagai node pertama. Selanjutnya, pengguna diminta untuk memasukkan jumlah mahasiswa lainnya serta data mereka, yang akan ditambahkan ke linked list sebagai node-node berikutnya. Setelah semua data dimasukkan, program menampilkan seluruh data mahasiswa yang tersimpan dalam linked list. Kemudian, program menampilkan menu operasi yang memungkinkan pengguna untuk melakukan berbagai tindakan, seperti menambah, menghapus, memperbarui, dan menampilkan data mahasiswa. Setiap operasi diproses sesuai dengan pilihan pengguna, dan program terus berjalan hingga pengguna memilih opsi untuk keluar.

### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini

Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit

```C++
// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
#include <iomanip>
using namespace std;

// Node class untuk merepresentasikan node dalam linked list
class Node
{
public:
    string product_name;
    int price;
    Node *prev; // Pointer ke node sebelumnya
    Node *next; // Pointer ke node berikutnya

    // Constructor untuk membuat node baru
    Node(string name, int p)
    {
        product_name = name;
        price = p;
        prev = nullptr;
        next = nullptr;
    }
};

// DoubleLinkedList class untuk mengelola linked list
class DoubleLinkedList
{
private:
    Node *head;

public:
    // Constructor untuk inisialisasi linked list
    DoubleLinkedList()
    {
        head = nullptr;
    }

    // Fungsi untuk menambahkan node baru ke akhir linked list
    void addNode(string name, int price)
    {
        Node *newNode = new Node(name, price);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    // Fungsi untuk menghapus node terakhir dari linked list
    void deleteLastNode()
    {
        if (head == nullptr)
        {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->prev->next = nullptr;
            delete current;
        }
    }

    // Fungsi untuk mengupdate data pada node tertentu berdasarkan indeks
    void updateNode(int index, string name, int price)
    {
        Node *current = head;
        int count = 0;
        while (current != nullptr && count != index)
        {
            current = current->next;
            count++;
        }
        if (current != nullptr)
        {
            current->product_name = name;
            current->price = price;
        }
        else
        {
            cout << "Indeks tidak ditemukan." << endl;
        }
    }

    // Fungsi untuk menyisipkan node baru pada indeks tertentu
    void insertNodeAtIndex(int index, string name, int price)
    {
        if (index == 0)
        {
            Node *newNode = new Node(name, price);
            newNode->next = head;
            if (head != nullptr)
            {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }
        Node *current = head;
        int count = 0;
        while (current != nullptr && count != index)
        {
            current = current->next;
            count++;
        }
        if (current != nullptr)
        {
            Node *newNode = new Node(name, price);
            newNode->prev = current->prev;
            newNode->next = current;
            if (current->prev != nullptr)
            {
                current->prev->next = newNode;
            }
            current->prev = newNode;
        }
        else
        {
            cout << "Index out of range." << endl;
        }
    }

    // Fungsi untuk menghapus node pada indeks tertentu
    void deleteNodeAtIndex(int index)
    {
        if (head == nullptr)
        {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node *current = head;
        int count = 0;
        while (current != nullptr && count != index)
        {
            current = current->next;
            count++;
        }
        if (current != nullptr)
        {
            current->prev->next = current->next;
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            delete current;
        }
        else
        {
            cout << "Index out of range." << endl;
        }
    }

    // Fungsi untuk menghapus seluruh node dalam linked list
    void deleteAllNodes()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Fungsi untuk menampilkan seluruh data dalam linked list
    void displayList()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << "+--------------+---------------+" << endl;
        cout << "| Nama Produk  |     Harga     |" << endl;
        cout << "+--------------+---------------+" << endl;
        Node *current = head;
        while (current != nullptr)
        {
            cout << "| " << setw(12) << left << current->product_name << " | ";
            cout << setw(13) << left << current->price << " |" << endl;
            current = current->next;
        }
        cout << "+--------------+---------------+" << endl;
    }

    // Destructor untuk menghapus semua node saat objek dihapus
    ~DoubleLinkedList()
    {
        deleteAllNodes();
    }
};

int main()
{
    DoubleLinkedList list;
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data Terakhir\n";
        cout << "3. Update Data\n";
        cout << "4. Tambah Data di Urutan Tertentu\n";
        cout << "5. Hapus Data di Urutan Tertentu\n";
        cout << "6. Hapus Seluruh Data\n";
        cout << "7. Tampilkan Data\n";
        cout << "8. Exit\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int numItems;
            cout << "Masukkan jumlah data yang ingin dimasukkan: ";
            cin >> numItems;

            for (int i = 0; i < numItems; ++i)
            {
                string name;
                int price;
                cout << "Masukkan Nama Produk ke-" << i + 1 << ": ";
                cin >> name;
                cout << "Masukkan Harga Produk ke-" << i + 1 << ": ";
                cin >> price;

                list.addNode(name, price);
            }
            cout << "Seluruh data telah ditambahkan." << endl;
            break;
        }
        case 2:
            list.deleteLastNode();
            break;
        case 3:
        {
            int index, price;
            string name;
            cout << "Masukkan Indeks Data yang Akan Diupdate: ";
            cin >> index;
            cout << "Masukkan Nama Produk Baru: ";
            cin >> name;
            cout << "Masukkan Harga Baru: ";
            cin >> price;
            list.updateNode(index, name, price);
            break;
        }
        case 4:
        {
            int index, price;
            string name;
            cout << "Masukkan Indeks Tempat Penyisipan Data Baru: ";
            cin >> index;
            cout << "Masukkan Nama Produk Baru: ";
            cin >> name;
            cout << "Masukkan Harga Baru: ";
            cin >> price;
            list.insertNodeAtIndex(index, name, price);
            break;
        }
        case 5:
        {
            int index;
            cout << "Masukkan Indeks Data yang Akan Dihapus: ";
            cin >> index;
            list.deleteNodeAtIndex(index);
            break;
        }
        case 6:
            list.deleteAllNodes();
            cout << "Seluruh data telah dihapus." << endl;
            break;
        case 7:
            list.displayList();
            break;
        case 8:
            cout << "Terima kasih. Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 8);

    return 0;
}
```

#### Output:

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan3/laprak3/ug2a.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan3/laprak3/ug2b.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan3/laprak3/ug2c.png)

Ketika program pertama kali dijalankan, user disajikan dengan menu yang memungkinkan mereka untuk menambah, menghapus, mengupdate, serta menampilkan data produk. Setiap opsi di menu tersebut memiliki fungsi yang sesuai di dalam kelas DoubleLinkedList. Misalnya, jika user memilih untuk menambah data, mereka diminta untuk memasukkan nama produk dan harganya, yang kemudian ditambahkan ke dalam linked list menggunakan metode addNode. Begitu juga dengan opsi lainnya seperti menghapus data terakhir, mengupdate data, menyisipkan data di urutan tertentu, menghapus data di urutan tertentu, dan menghapus seluruh data. Setiap operasi tersebut dieksekusi sesuai dengan pilihan user hingga mereka memilih untuk keluar dari program. Program memberikan respons yang sesuai setiap kali user memilih opsi dalam menu dan berinteraksi dengan linked list untuk memanipulasi data produk yang tersimpan.

## Referensi

[1] Siregar, A. A. N. (2019, April 25). Pengertian Linked Object.

[2] Nugraha, A. S. (2019, March 29). Artikel Double Linked List Circulate. 
