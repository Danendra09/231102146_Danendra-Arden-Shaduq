# <h1 align="center">Laporan Praktikum Modul 4 - Circular dan Non Circular</h1>

<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori

Circular linked lists dan non-circular linked lists adalah dua jenis data structure yang digunakan untuk menyimpan dan mengakses koleksi item.

1. Circular Linked List
Circular linked list adalah jenis linked list yang memiliki pointer yang menunjuk ke node yang sama sebagai node awal. Dalam sebuah circular linked list, pointer terakhir akan menunjuk ke node pertama, membuat linked list berputar. Ini memungkinkan untuk mengakses data dalam linked list tanpa perlu mengetahui posisi awal atau akhir dari list. Circular linked list ideal untuk aplikasi yang membutuhkan data yang dapat ditambah dan dihapus secara kontinu, seperti aplikasi real-time atau simulasi.
Struktur Circular Linked List
Circular linked list memiliki beberapa kelebihan terhadap linked list non-circular:
- Data dapat ditambah dan dihapus dari list kapanpun, seperti dalam aplikasi real-time.
- Data dapat diakses dalam loop yang berlangsung secara keseluruhan.
- Circular linked list lebih efisien dalam penggunaan memori, karena hanya memerlukan satu pointer tertentu (head pointer) untuk dijadikan referensi.
- Circular linked list lebih mudah untuk mengimplementasikan, karena tidak memerlukan data structures tambahan seperti stack atau queue untuk mengatur list.

2. Non-Circular Linked List
Non-circular linked list adalah jenis linked list yang memiliki pointer yang tidak menunjuk ke node yang sama sebagai node awal. Dalam sebuah non-circular linked list, pointer terakhir akan menunjuk ke NULL, membuat linked list tidak berputar. Ini memungkinkan untuk mengakses data dalam linked list dengan mengetahui posisi awal dari list. Non-circular linked list ideal untuk aplikasi yang membutuhkan data yang dapat ditambah dan dihapus secara berurutan, seperti aplikasi data yang berurutan atau aplikasi yang membutuhkan data yang dapat diakses secara berurutan.

## Guided

### 1. Linked List Non Circular

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

// tambah depan
void insertDepan(int nilai)
{
    // Buat node baru
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

// tambah belakang
void insertBelakang(int nilai)
{
    // Buat node baru
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

// Hitung jumlah list
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

// Tambah tengah
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
    Node *bantu, *hapus, *sebelum;
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
                sebelum = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == 0)
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
    if (isEmpty() == 0)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
        }
        else
        {
            cout << "Posisi bukan posisi tengah" << endl;
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
    if (isEmpty() == 0)
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
Kode diatas melakukan inisialisasi linked list dengan mengatur pointer head dan tail menjadi NULL. Selanjutnya, program menambahkan beberapa node ke dalam linked list menggunakan fungsi insertDepan dan insertBelakang, serta menampilkan isi linked list setiap kali sebuah operasi penambahan atau penghapusan dilakukan. Kemudian, program menghapus node dari depan dan belakang linked list menggunakan fungsi hapusDepan dan hapusBelakang, serta melakukan operasi penambahan dan penghapusan di posisi tengah menggunakan fungsi insertTengah dan hapusTengah. Terakhir, program melakukan operasi pengubahan nilai pada node depan, belakang, dan tengah menggunakan fungsi ubahDepan, ubahBelakang, dan ubahTengah, serta menampilkan isi linked list setelah operasi pengubahan dilakukan. Hasil akhir dari program adalah menampilkan isi linked list setelah semua operasi telah selesai dieksekusi.

### 2. Linked List Circular

```C++
#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
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
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
kode diatas melakukan inisialisasi linked list dengan mengatur pointer head dan tail menjadi NULL. Kemudian, program menambahkan beberapa node ke dalam linked list menggunakan fungsi insertDepan dan insertBelakang, serta menampilkan isi linked list setiap kali sebuah operasi penambahan atau penghapusan dilakukan. Setelah itu, program melakukan penghapusan node dari depan dan belakang linked list menggunakan fungsi hapusDepan dan hapusBelakang, serta melakukan operasi penambahan dan penghapusan di posisi tengah menggunakan fungsi insertTengah dan hapusTengah. Hasil akhir dari program adalah menampilkan isi linked list setelah semua operasi telah selesai dieksekusi. Program menggunakan konsep circular, di mana pointer tail menunjuk kembali ke head, sehingga linked list membentuk siklus tertutup.

## Unguided

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa
```C++
// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream> // Library untuk input-output stream
#include <string> // Library untuk tipe data string
using namespace std; // Menggunakan namespace std untuk memudahkan penggunaan fungsi dari standard library

// Struktur Node
struct Node
{
    string nama_2146; // Variabel untuk menyimpan nama mahasiswa
    string nim_2146; // Variabel untuk menyimpan NIM mahasiswa
    Node *next; // Pointer ke node selanjutnya
};

// Kelas LinkedList
class LinkedList
{
private:
    Node *head; // Pointer ke kepala linked list

public:
    // Konstruktor
    LinkedList()
    {
        head = nullptr; // Inisialisasi head ke nullptr ketika linked list dibuat
    }

    // Fungsi untuk menambahkan node di depan
    void tambahDepan(string nama_2146, string nim_2146)
    {
        Node *newNode = new Node; // Buat node baru
        newNode->nama_2146 = nama_2146; // Isi data nama
        newNode->nim_2146 = nim_2146; // Isi data NIM
        newNode->next = head; // Sambungkan node baru dengan head
        head = newNode; // Perbarui head menjadi node baru
    }

    // Fungsi untuk menambahkan node di belakang
    void tambahBelakang(string nama_2146, string nim_2146)
    {
        Node *newNode = new Node; // Buat node baru
        newNode->nama_2146 = nama_2146; // Isi data nama
        newNode->nim_2146 = nim_2146; // Isi data NIM
        newNode->next = nullptr; // Tetapkan pointer next ke nullptr karena node baru akan menjadi node terakhir

        if (head == nullptr)
        {
            head = newNode; // Jika linked list kosong, buat node baru sebagai head
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // Cari node terakhir
            }
            temp->next = newNode; // Sambungkan node baru di belakang node terakhir
        }
    }

    // Fungsi untuk menambahkan node di tengah
    void tambahTengah(int pos, string nama_2146, string nim_2146)
    {
        if (pos <= 0)
        {
            cout << "Posisi harus lebih dari 0" << endl; // Jika posisi tidak valid, tampilkan pesan kesalahan
            return;
        }

        if (pos == 1)
        {
            tambahDepan(nama_2146, nim_2146); // Jika posisi pertama, tambahkan di depan
            return;
        }

        Node *newNode = new Node; // Buat node baru
        newNode->nama_2146 = nama_2146; // Isi data nama
        newNode->nim_2146 = nim_2146; // Isi data NIM

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; ++i)
        {
            temp = temp->next; // Temukan node sebelum posisi yang diinginkan
        }

        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl; // Jika posisi tidak valid, tampilkan pesan kesalahan
            return;
        }

        newNode->next = temp->next; // Sambungkan node baru
        temp->next = newNode;
    }

    // Fungsi untuk mengubah data node di depan
    void ubahDepan(string nama_2146, string nim_2146)
    {
        if (head != nullptr)
        {
            cout << "Data " << head->nama_2146 << " telah diganti dengan data " << nama_2146 << endl; // Tampilkan pesan
            head->nama_2146 = nama_2146; // Ubah data nama
            head->nim_2146 = nim_2146; // Ubah data NIM
        }
        else
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
        }
    }

    // Fungsi untuk mengubah data node di belakang
    void ubahBelakang(string nama_2146, string nim_2146)
    {
        if (head != nullptr)
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // Cari node terakhir
            }
            cout << "Data " << temp->nama_2146 << " telah diganti dengan data " << nama_2146 << endl; // Tampilkan pesan
            temp->nama_2146 = nama_2146; // Ubah data nama
            temp->nim_2146 = nim_2146; // Ubah data NIM
        }
        else
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
        }
    }

    // Fungsi untuk mengubah data node di tengah
    void ubahTengah(int pos, string nama_2146, string nim_2146)
    {
        Node *temp = head;
        for (int i = 1; i < pos && temp != nullptr; ++i)
        {
            temp = temp->next; // Temukan node pada posisi yang diinginkan
        }

        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl; // Tampilkan pesan jika posisi tidak valid
        }
        else
        {
            string namaLama = temp->nama_2146; // Simpan nama lama sebelum diubah
            temp->nama_2146 = nama_2146; // Ubah data nama
            temp->nim_2146 = nim_2146; // Ubah data NIM
            cout << "Data " << namaLama << " telah diganti dengan data " << nama_2146 << endl; // Tampilkan pesan
        }
    }

    // Fungsi untuk menghapus node di depan
    void hapusDepan()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            cout << "Data " << temp->nama_2146 << " berhasil dihapus" << endl; // Tampilkan pesan
            delete temp; // Hapus node
        }
        else
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
        }
    }

    // Fungsi untuk menghapus node di belakang
    void hapusBelakang()
    {
        if (head != nullptr)
        {
            if (head->next == nullptr)
            {
                cout << "Data " << head->nama_2146 << " berhasil dihapus" << endl; // Tampilkan pesan
                delete head; // Hapus head jika hanya satu node
                head = nullptr;
            }
            else
            {
                Node *temp = head;
                Node *prev = nullptr;
                while (temp->next != nullptr)
                {
                    prev = temp;
                    temp = temp->next; // Cari node terakhir
                }
                cout << "Data " << temp->nama_2146 << " berhasil dihapus" << endl; // Tampilkan pesan
                delete temp; // Hapus node terakhir
                prev->next = nullptr;
            }
        }
        else
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
        }
    }

    // Fungsi untuk menghapus node di tengah
    void hapusTengah(int pos)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
            return;
        }

        if (pos <= 0)
        {
            cout << "Posisi harus lebih dari 0" << endl; // Tampilkan pesan jika posisi tidak valid
            return;
        }

        if (pos == 1)
        {
            hapusDepan(); // Hapus node di depan jika posisi pertama
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;
        for (int i = 1; i < pos && temp != nullptr; ++i)
        {
            prev = temp;
            temp = temp->next; // Temukan node pada posisi yang diinginkan
        }

        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl; // Tampilkan pesan jika posisi tidak valid
            return;
        }

        prev->next = temp->next;
        cout << "Data " << temp->nama_2146 << " berhasil dihapus" << endl; // Tampilkan pesan
        delete temp; // Hapus node
    }

    // Fungsi untuk membersihkan seluruh linked list
    void hapusList()
    {
        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr; // Atur head menjadi nullptr setelah menghapus semua node
    }

    // Fungsi untuk menampilkan semua data
    void tampilkanSemua()
    {
        Node *temp = head;
        cout << "Nama\t\tNIM" << endl;
        while (temp != nullptr)
        {
            cout << temp->nama_2146 << "\t\t" << temp->nim_2146 << endl; // Tampilkan nama dan NIM
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList list; // Deklarasi objek LinkedList
    int pilihan; // Variabel untuk menyimpan pilihan pengguna
    string nama_2146, nim_2146; // Variabel untuk menyimpan data nama dan NIM
    int pos; // Variabel untuk menyimpan posisi

    // Perulangan menu
    do
    {
        // Tampilkan menu
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. Tampilkan Semua Data\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        // Pilihan pengguna
        switch (pilihan)
        {
        case 1:
            cout << "\n-Tambah Depan-\n";
            cout << "Masukkan nama: ";
            cin >> nama_2146;
            cout << "Masukkan NIM: ";
            cin >> nim_2146;
            list.tambahDepan(nama_2146, nim_2146); // Tambahkan data di depan linked list
            cout << "Data telah ditambahkan\n";
            break;
        case 2:
            cout << "\n-Tambah Belakang-\n";
            cout << "Masukkan nama: ";
            cin >> nama_2146;
            cout << "Masukkan NIM: ";
            cin >> nim_2146;
            list.tambahBelakang(nama_2146, nim_2146); // Tambahkan data di belakang linked list
            cout << "Data telah ditambahkan\n";
            break;
        case 3:
            cout << "\n-Tambah Tengah-\n";
            cout << "Masukkan nama: ";
            cin >> nama_2146;
            cout << "Masukkan NIM: ";
            cin >> nim_2146;
            cout << "Masukkan posisi: ";
            cin >> pos;
            list.tambahTengah(pos, nama_2146, nim_2146); // Tambahkan data di tengah linked list
            cout << "Data telah ditambahkan\n";
            break;
        case 4:
            cout << "\n-Ubah Depan-\n";
            cout << "Masukkan nama baru untuk depan: ";
            cin >> nama_2146;
            cout << "Masukkan NIM baru untuk depan: ";
            cin >> nim_2146;
            list.ubahDepan(nama_2146, nim_2146); // Ubah data di depan linked list
            break;
        case 5:
            cout << "\n-Ubah Belakang-\n";
            cout << "Masukkan nama baru untuk belakang: ";
            cin >> nama_2146;
            cout << "Masukkan NIM baru untuk belakang: ";
            cin >> nim_2146;
            list.ubahBelakang(nama_2146, nim_2146); // Ubah data di belakang linked list
            break;
        case 6:
            cout << "\n-Ubah Tengah-\n";
            cout << "Masukkan nama baru untuk tengah: ";
            cin >> nama_2146;
            cout << "Masukkan NIM baru untuk tengah: ";
            cin >> nim_2146;
            cout << "Masukkan posisi: ";
            cin >> pos;
            list.ubahTengah(pos, nama_2146, nim_2146); // Ubah data di tengah linked list
            break;
        case 7:
            cout << "\n-Hapus Depan-\n";
            list.hapusDepan(); // Hapus data di depan linked list
            break;
        case 8:
            cout << "\n-Hapus Belakang-\n";
            list.hapusBelakang(); // Hapus data di belakang linked list
            break;
        case 9:
            cout << "\n-Hapus Tengah-\n";
            cout << "Masukkan posisi yang akan dihapus: ";
            cin >> pos;
            list.hapusTengah(pos); // Hapus data di tengah linked list
            break;
        case 10:
            list.hapusList(); // Hapus seluruh data linked list
            cout << "Linked list telah dihapus" << endl;
            break;
        case 11:
            list.tampilkanSemua(); // Tampilkan semua data dalam linked list
            break;
        case 0:
            cout << "Terima kasih!\n"; // Keluar dari program
            break;
        default:
            cout << "Pilihan tidak valid!\n"; // Tampilkan pesan jika pilihan tidak valid
        }
    } while (pilihan != 0); // Ulangi menu sampai pengguna memilih untuk keluar

    return 0; // Akhiri program
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug1a.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug1b.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug1c.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug1d.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug1e.png)

Program ini memungkinkan user untuk melakukan berbagai operasi seperti menambah, mengubah, dan menghapus data pada linked list. Setiap data yang dimasukkan terdiri dari nama dan NIM mahasiswa. Program ini menyediakan menu interaktif di mana user dapat memilih operasi yang ingin dilakukan. Setiap operasi diimplementasikan melalui metode yang sesuai dalam kelas LinkedList, seperti tambahDepan, tambahBelakang, tambahTengah, ubahDepan, ubahBelakang, ubahTengah, hapusDepan, hapusBelakang, hapusTengah, dan hapusList. Program akan terus berjalan hingga user memilih opsi untuk keluar. Jika user memilih opsi untuk menampilkan semua data, program akan mencetak semua nama dan NIM mahasiswa yang tersimpan dalam linked list.

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
```C++
// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream> // Library untuk input-output stream
#include <string> // Library untuk tipe data string
using namespace std; // Menggunakan namespace std untuk memudahkan penggunaan fungsi dari standard library

// Struktur Node
struct Node
{
    string nama_2146; // Variabel untuk menyimpan nama mahasiswa
    string nim_2146; // Variabel untuk menyimpan NIM mahasiswa
    Node *next; // Pointer ke node selanjutnya
};

// Kelas LinkedList
class LinkedList
{
private:
    Node *head; // Pointer ke kepala linked list

public:
    // Konstruktor
    LinkedList()
    {
        head = nullptr; // Inisialisasi head ke nullptr ketika linked list dibuat
    }

    // Fungsi untuk menambahkan node di depan
    void tambahDepan(string nama_2146, string nim_2146)
    {
        Node *newNode = new Node; // Buat node baru
        newNode->nama_2146 = nama_2146; // Isi data nama
        newNode->nim_2146 = nim_2146; // Isi data NIM
        newNode->next = head; // Sambungkan node baru dengan head
        head = newNode; // Perbarui head menjadi node baru
    }

    // Fungsi untuk menambahkan node di belakang
    void tambahBelakang(string nama_2146, string nim_2146)
    {
        Node *newNode = new Node; // Buat node baru
        newNode->nama_2146 = nama_2146; // Isi data nama
        newNode->nim_2146 = nim_2146; // Isi data NIM
        newNode->next = nullptr; // Tetapkan pointer next ke nullptr karena node baru akan menjadi node terakhir

        if (head == nullptr)
        {
            head = newNode; // Jika linked list kosong, buat node baru sebagai head
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // Cari node terakhir
            }
            temp->next = newNode; // Sambungkan node baru di belakang node terakhir
        }
    }

    // Fungsi untuk menambahkan node di tengah
    void tambahTengah(int pos, string nama_2146, string nim_2146)
    {
        if (pos <= 0)
        {
            cout << "Posisi harus lebih dari 0" << endl; // Jika posisi tidak valid, tampilkan pesan kesalahan
            return;
        }

        if (pos == 1)
        {
            tambahDepan(nama_2146, nim_2146); // Jika posisi pertama, tambahkan di depan
            return;
        }

        Node *newNode = new Node; // Buat node baru
        newNode->nama_2146 = nama_2146; // Isi data nama
        newNode->nim_2146 = nim_2146; // Isi data NIM

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; ++i)
        {
            temp = temp->next; // Temukan node sebelum posisi yang diinginkan
        }

        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl; // Jika posisi tidak valid, tampilkan pesan kesalahan
            return;
        }

        newNode->next = temp->next; // Sambungkan node baru
        temp->next = newNode;
    }

    // Fungsi untuk mengubah data node di depan
    void ubahDepan(string nama_2146, string nim_2146)
    {
        if (head != nullptr)
        {
            cout << "Data " << head->nama_2146 << " telah diganti dengan data " << nama_2146 << endl; // Tampilkan pesan
            head->nama_2146 = nama_2146; // Ubah data nama
            head->nim_2146 = nim_2146; // Ubah data NIM
        }
        else
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
        }
    }

    // Fungsi untuk mengubah data node di belakang
    void ubahBelakang(string nama_2146, string nim_2146)
    {
        if (head != nullptr)
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next; // Cari node terakhir
            }
            cout << "Data " << temp->nama_2146 << " telah diganti dengan data " << nama_2146 << endl; // Tampilkan pesan
            temp->nama_2146 = nama_2146; // Ubah data nama
            temp->nim_2146 = nim_2146; // Ubah data NIM
        }
        else
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
        }
    }

    // Fungsi untuk mengubah data node di tengah
    void ubahTengah(int pos, string nama_2146, string nim_2146)
    {
        Node *temp = head;
        for (int i = 1; i < pos && temp != nullptr; ++i)
        {
            temp = temp->next; // Temukan node pada posisi yang diinginkan
        }

        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl; // Tampilkan pesan jika posisi tidak valid
        }
        else
        {
            string namaLama = temp->nama_2146; // Simpan nama lama sebelum diubah
            temp->nama_2146 = nama_2146; // Ubah data nama
            temp->nim_2146 = nim_2146; // Ubah data NIM
            cout << "Data " << namaLama << " telah diganti dengan data " << nama_2146 << endl; // Tampilkan pesan
        }
    }

    // Fungsi untuk menghapus node di depan
    void hapusDepan()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            cout << "Data " << temp->nama_2146 << " berhasil dihapus" << endl; // Tampilkan pesan
            delete temp; // Hapus node
        }
        else
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
        }
    }

    // Fungsi untuk menghapus node di belakang
    void hapusBelakang()
    {
        if (head != nullptr)
        {
            if (head->next == nullptr)
            {
                cout << "Data " << head->nama_2146 << " berhasil dihapus" << endl; // Tampilkan pesan
                delete head; // Hapus head jika hanya satu node
                head = nullptr;
            }
            else
            {
                Node *temp = head;
                Node *prev = nullptr;
                while (temp->next != nullptr)
                {
                    prev = temp;
                    temp = temp->next; // Cari node terakhir
                }
                cout << "Data " << temp->nama_2146 << " berhasil dihapus" << endl; // Tampilkan pesan
                delete temp; // Hapus node terakhir
                prev->next = nullptr;
            }
        }
        else
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
        }
    }

    // Fungsi untuk menghapus node di tengah
    void hapusTengah(int pos)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl; // Tampilkan pesan jika linked list kosong
            return;
        }

        if (pos <= 0)
        {
            cout << "Posisi harus lebih dari 0" << endl; // Tampilkan pesan jika posisi tidak valid
            return;
        }

        if (pos == 1)
        {
            hapusDepan(); // Hapus node di depan jika posisi pertama
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;
        for (int i = 1; i < pos && temp != nullptr; ++i)
        {
            prev = temp;
            temp = temp->next; // Temukan node pada posisi yang diinginkan
        }

        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl; // Tampilkan pesan jika posisi tidak valid
            return;
        }

        prev->next = temp->next;
        cout << "Data " << temp->nama_2146 << " berhasil dihapus" << endl; // Tampilkan pesan
        delete temp; // Hapus node
    }

    // Fungsi untuk membersihkan seluruh linked list
    void hapusList()
    {
        Node *current = head;
        Node *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr; // Atur head menjadi nullptr setelah menghapus semua node
    }

    // Fungsi untuk menampilkan semua data
    void tampilkanSemua()
    {
        Node *temp = head;
        cout << "Nama\t\tNIM" << endl;
        while (temp != nullptr)
        {
            cout << temp->nama_2146 << "\t\t" << temp->nim_2146 << endl; // Tampilkan nama dan NIM
            temp = temp->next;
        }
    }
};

// Fungsi untuk meminta pengguna menginputkan data mahasiswa
void inputData(LinkedList &list)
{
    int jumlah;
    string nama_2146, nim_2146;

    cout << "Masukkan jumlah data mahasiswa: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; ++i)
    {
        cout << "Data ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> nama_2146;
        cout << "NIM: ";
        cin >> nim_2146;
        list.tambahBelakang(nama_2146, nim_2146); // Tambahkan data ke belakang linked list
    }
}

int main()
{
    LinkedList list; // Deklarasi objek LinkedList
    int pilihan; // Variabel untuk menyimpan pilihan pengguna
    string nama_2146, nim_2146; // Variabel untuk menyimpan data nama dan NIM
    int pos; // Variabel untuk menyimpan posisi

    // Meminta pengguna untuk menginputkan data mahasiswa
    inputData(list);

    // Perulangan menu
    do
    {
        // Tampilkan menu
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Tambah Tengah\n";
        cout << "4. Ubah Depan\n";
        cout << "5. Ubah Belakang\n";
        cout << "6. Ubah Tengah\n";
        cout << "7. Hapus Depan\n";
        cout << "8. Hapus Belakang\n";
        cout << "9. Hapus Tengah\n";
        cout << "10. Hapus List\n";
        cout << "11. Tampilkan Semua Data\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        // Pilihan pengguna
        switch (pilihan)
        {
        case 1:
            cout << "\n-Tambah Depan-\n";
            cout << "Masukkan nama: ";
            cin >> nama_2146;
            cout << "Masukkan NIM: ";
            cin >> nim_2146;
            list.tambahDepan(nama_2146, nim_2146); // Tambahkan data di depan linked list
            cout << "Data telah ditambahkan\n";
            break;
        case 2:
            cout << "\n-Tambah Belakang-\n";
            cout << "Masukkan nama: ";
            cin >> nama_2146;
            cout << "Masukkan NIM: ";
            cin >> nim_2146;
            list.tambahBelakang(nama_2146, nim_2146); // Tambahkan data di belakang linked list
            cout << "Data telah ditambahkan\n";
            break;
        case 3:
            cout << "\n-Tambah Tengah-\n";
            cout << "Masukkan nama: ";
            cin >> nama_2146;
            cout << "Masukkan NIM: ";
            cin >> nim_2146;
            cout << "Masukkan posisi: ";
            cin >> pos;
            list.tambahTengah(pos, nama_2146, nim_2146); // Tambahkan data di tengah linked list
            cout << "Data telah ditambahkan\n";
            break;
        case 4:
            cout << "\n-Ubah Depan-\n";
            cout << "Masukkan nama baru untuk depan: ";
            cin >> nama_2146;
            cout << "Masukkan NIM baru untuk depan: ";
            cin >> nim_2146;
            list.ubahDepan(nama_2146, nim_2146); // Ubah data di depan linked list
            break;
        case 5:
            cout << "\n-Ubah Belakang-\n";
            cout << "Masukkan nama baru untuk belakang: ";
            cin >> nama_2146;
            cout << "Masukkan NIM baru untuk belakang: ";
            cin >> nim_2146;
            list.ubahBelakang(nama_2146, nim_2146); // Ubah data di belakang linked list
            break;
        case 6:
            cout << "\n-Ubah Tengah-\n";
            cout << "Masukkan nama baru untuk tengah: ";
            cin >> nama_2146;
            cout << "Masukkan NIM baru untuk tengah: ";
            cin >> nim_2146;
            cout << "Masukkan posisi: ";
            cin >> pos;
            list.ubahTengah(pos, nama_2146, nim_2146); // Ubah data di tengah linked list
            break;
        case 7:
            cout << "\n-Hapus Depan-\n";
            list.hapusDepan(); // Hapus data di depan linked list
            break;
        case 8:
            cout << "\n-Hapus Belakang-\n";
            list.hapusBelakang(); // Hapus data di belakang linked list
            break;
        case 9:
            cout << "\n-Hapus Tengah-\n";
            cout << "Masukkan posisi yang akan dihapus: ";
            cin >> pos;
            list.hapusTengah(pos); // Hapus data di tengah linked list
            break;
        case 10:
            list.hapusList(); // Hapus seluruh data linked list
            cout << "Linked list telah dihapus" << endl;
            break;
        case 11:
            list.tampilkanSemua(); // Tampilkan semua data dalam linked list
            break;
        case 0:
            cout << "Terima kasih!\n"; // Keluar dari program
            break;
        default:
            cout << "Pilihan tidak valid!\n"; // Tampilkan pesan jika pilihan tidak valid
        }
    } while (pilihan != 0); // Ulangi menu sampai pengguna memilih untuk keluar

    return 0; // Akhiri program
}
```

#### Output:

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug2a.png)
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug2b.png)

Kode diatas hampir sama seperti sebelumnya, perbedaannya sebelum memilih menu, user diminta untuk menginputkan nama dan nim sesuai yang diinginkan user, begitu juga dengan jumlahnya.

### 3. Lakukan perintah berikut:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/soal.png)

Untuk codingannya sama seperti nomor 2, hanya melanjutkan saja.

#### Output:
a.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3a.png)

b.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3b.png)

c.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3c.png)

d.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3d.png)

e.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3e.png)

f.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3f.png)

g.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3g.png)

h.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3h.png)

i.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3i.png)

j.
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan4/Laprak4/ug3j.png)

## Referensi

[1] Siregar, A. A. N. (2019, April 25). Pengertian Linked Object.

[2] Nugraha, A. S. (2019, March 29). Artikel Double Linked List Circulate. 
