# <h1 align="center">Laporan Praktikum Modul 7 - Queue</h1>

<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori
Queue (antrian) adalah salah satu struktur data yang mengikuti prinsip FIFO (First In First Out). Dalam queue, elemen pertama yang dimasukkan adalah elemen pertama yang akan dikeluarkan. Konsep ini mirip dengan antrian pada kasir atau loket tiket, di mana pelanggan yang datang pertama dilayani terlebih dahulu.

Operasi Dasar Queue
Operasi dasar yang dapat dilakukan pada queue adalah sebagai berikut:

1. Enqueue: Menambahkan elemen ke akhir antrian.
2. Dequeue: Mengeluarkan elemen dari depan antrian.
3. IsFull: Mengecek apakah queue penuh atau tidak.
4. IsEmpty: Mengecek apakah antrian kosong.
5. Size: Mengetahui jumlah elemen dalam antrian.
6. Peek: Mengambil data dari queue tanpa menghapusnya.

## Guided

### 1. Guided 1

```C++
#include <iostream>

using namespace std;

const int maksimalAntrian_146 = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// menambah antrian
void tambahData(string nama)
{
    if (isFull())
    {
        queueTeller[0] = nama;
        front++;
        back++;
    }
    else
    {
        queueTeller[back] = nama;
        back++;
    }
}

// mengurangi antrian
void kurangAntrian()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

// menghitung banyak antrian
int count()
{
    return back;
}

// menghapus seluruh antrian
void clearQueue()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
            queueTeller[i] = "";
    }
    back = 0;
    front = 0;
}

// melihat antrian
void viewQueue()
{
    cout << "Data antrian: " << endl;
    for (int i = 0; i < maksimalAntrian_146; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". " << "antrian kosong" << endl;
        }
    }
}

int main()
{
    tambahData("Andi");
    tambahData("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    kurangAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    return 0;
}
```
Pada kodingan diatas, queue yang berkapasitas maksimal 5 elemen dan menggunakan variabel global front dan back untuk melacak elemen pertama dan terakhir. Fungsi tambahData menambahkan nama ke dalam queue, sementara kurangAntrian menghapus elemen terdepan dan menggeser elemen lainnya ke depan. Fungsi isFull dan isEmpty digunakan untuk memeriksa apakah queue penuh atau kosong. count mengembalikan jumlah elemen dalam queue, dan clearQueue menghapus semua elemen. Fungsi viewQueue menampilkan semua elemen dalam queue. Dalam main, dua nama ditambahkan ke queue, ditampilkan, dihitung jumlahnya, satu elemen dihapus, dan prosesnya diulang hingga queue dikosongkan dan ditampilkan lagi hasilnya. Namun, ada kesalahan pada logika isFull yang menyebabkan fungsi tersebut selalu mengembalikan true saat back adalah 0, yang seharusnya memeriksa kondisi penuh dengan membandingkan back dengan kapasitas maksimal queue.

## Unguided

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
// Danendra Arden Shaduq - 2311102146
#include <iostream>

using namespace std;

// Struktur untuk merepresentasikan elemen dalam antrian
struct Node {
    string data; // Data pada setiap elemen antrian
    Node* next; // Pointer ke elemen berikutnya dalam antrian
};

// Kelas untuk merepresentasikan sebuah antrian
class Queue {
private:
    Node* front; // Pointer ke elemen pertama dalam antrian
    Node* rear; // Pointer ke elemen terakhir dalam antrian
    int size; // Ukuran (jumlah elemen) dalam antrian

public:
    // Konstruktor untuk inisialisasi antrian kosong
    Queue() {
        front = nullptr; // Pointer ke elemen pertama diatur menjadi null
        rear = nullptr; // Pointer ke elemen terakhir diatur menjadi null
        size = 0; // Ukuran antrian diatur menjadi 0
    }

    // Metode untuk menambahkan data ke dalam antrian
    void tambahData(string nama) {
        Node* newNode = new Node; // Membuat node baru
        newNode->data = nama; // Mengisi data pada node baru dengan nama yang diberikan
        newNode->next = nullptr; // Mengatur pointer next node baru menjadi null
        
        // Jika antrian kosong, maka node baru menjadi elemen pertama dan terakhir
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else { // Jika tidak kosong, node baru ditambahkan di belakang elemen terakhir
            rear->next = newNode;
            rear = newNode;
        }
        size++; // Meningkatkan ukuran antrian
    }

    // Metode untuk mengurangi elemen dari antrian
    void kurangqueue() {
        // Jika antrian kosong, cetak pesan
        if (isEmpty()) {
            cout << "queue kosong" << endl;
        } else { // Jika tidak kosong, hapus elemen pertama dan ubah pointer front
            Node* temp = front; // Simpan pointer ke elemen pertama
            front = front->next; // Ubah pointer front ke elemen berikutnya
            delete temp; // Hapus elemen pertama
            size--; // Kurangi ukuran antrian
        }
    }

    // Metode untuk menghitung jumlah elemen dalam antrian
    int count() {
        return size; // Mengembalikan ukuran antrian
    }

    // Metode untuk menghapus seluruh elemen dalam antrian
    void clearQueue() {
        while (!isEmpty()) { // Selama antrian tidak kosong, hapus elemen pertama
            kurangqueue();
        }
    }

    // Metode untuk menampilkan seluruh elemen dalam antrian
    void viewQueue() {
        cout << "\nData antrian: " << endl;
        Node* current = front; // Pointer untuk traversal antrian, diawali dari elemen pertama
        for (int i = 1; i <= 5; i++) { // Loop untuk mencetak lima baris
            if (current != nullptr) { // Jika masih ada elemen dalam antrian
                cout << i << ". " << current->data << endl; // Cetak data elemen saat ini
                current = current->next; // Pindah ke elemen berikutnya dalam antrian
            } else { // Jika antrian kosong sebelum mencapai lima baris
                cout << i << ". antrian kosong" << endl; // Cetak "antrian kosong"
            }
        }
    }

    // Metode untuk memeriksa apakah antrian kosong
    bool isEmpty() {
        return size == 0; // Mengembalikan true jika ukuran antrian adalah 0
    }
};

// Fungsi utama program
int main() {
    Queue queue_146; // Membuat objek antrian

    // Menambahkan beberapa data ke dalam antrian
    queue_146.tambahData("Andi");
    queue_146.tambahData("Maya");

    // Menampilkan antrian
    queue_146.viewQueue();
    cout << "Jumlah antrian = " << queue_146.count() << endl;

    // Mengurangi satu elemen dari antrian dan menampilkan hasilnya
    queue_146.kurangqueue();
    queue_146.viewQueue();
    cout << "Jumlah antrian = " << queue_146.count() << endl;

    // Menghapus seluruh elemen dari antrian dan menampilkan hasilnya
    queue_146.clearQueue();
    queue_146.viewQueue();
    cout << "Jumlah antrian = " << queue_146.count() << endl;

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan7/laprak7/ug1.png)

Kode di atas mengimplementasikan struktur data queue menggunakan linked list. Kelas `Queue` memiliki metode untuk menambah (`tambahData`), menghapus (`kurangqueue`), menghitung jumlah elemen (`count`), menghapus semua elemen (`clearQueue`), menampilkan elemen (`viewQueue`), dan memeriksa apakah queue kosong (`isEmpty`). Pada fungsi `main`, objek `queue_146` dibuat, dan beberapa nama ditambahkan ke dalam antrian. Fungsi `viewQueue` digunakan untuk menampilkan antrian, diikuti dengan menampilkan jumlah elemen dengan `count`. Kemudian, satu elemen dihapus dari antrian dengan `kurangqueue`, dan antrian ditampilkan kembali. Terakhir, seluruh elemen dalam antrian dihapus menggunakan `clearQueue`, dan antrian ditampilkan sekali lagi untuk menunjukkan bahwa antrian kosong. Metode `tambahData` menambahkan elemen baru ke akhir antrian, sedangkan `kurangqueue` menghapus elemen dari depan antrian. Kode ini menggunakan dynamic memory allocation dengan `new` untuk menambahkan elemen baru dan `delete` untuk menghapus elemen, memastikan bahwa memori dikelola dengan baik.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
// Danendra Arden Shaduq - 2311102146
#include <iostream>

using namespace std;

// Struktur Mahasiswa untuk merepresentasikan data mahasiswa
struct Mahasiswa {
    string nama; // Variabel untuk menyimpan nama mahasiswa
    string nim; // Variabel untuk menyimpan NIM mahasiswa
};

// Struktur Node untuk merepresentasikan elemen dalam antrian
struct Node {
    Mahasiswa data; // Objek Mahasiswa yang menyimpan data pada setiap elemen antrian
    Node* next; // Pointer ke elemen berikutnya dalam antrian
};

// Kelas Queue untuk merepresentasikan sebuah antrian
class Queue {
private:
    Node* front; // Pointer ke elemen pertama dalam antrian
    Node* rear; // Pointer ke elemen terakhir dalam antrian
    int size; // Ukuran (jumlah elemen) dalam antrian

public:
    // Konstruktor untuk inisialisasi antrian kosong
    Queue() {
        front = nullptr; // Pointer ke elemen pertama diatur menjadi null
        rear = nullptr; // Pointer ke elemen terakhir diatur menjadi null
        size = 0; // Ukuran antrian diatur menjadi 0
    }

    // Metode untuk menambahkan data mahasiswa ke dalam antrian
    void tambahAntrian(string nama, string nim) {
        Node* newNode = new Node; // Membuat node baru
        newNode->data.nama = nama; // Mengisi nama mahasiswa pada node baru
        newNode->data.nim = nim; // Mengisi NIM mahasiswa pada node baru
        newNode->next = nullptr; // Mengatur pointer next node baru menjadi null
        
        // Jika antrian kosong, maka node baru menjadi elemen pertama dan terakhir
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else { // Jika tidak kosong, node baru ditambahkan di belakang elemen terakhir
            rear->next = newNode;
            rear = newNode;
        }
        size++; // Meningkatkan ukuran antrian
    }

    // Metode untuk mengurangi elemen pertama dari antrian
    void kurangAntrian() {
        // Jika antrian kosong, cetak pesan
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else { // Jika tidak kosong, hapus elemen pertama dan ubah pointer front
            Node* temp = front; // Simpan pointer ke elemen pertama
            front = front->next; // Ubah pointer front ke elemen berikutnya
            delete temp; // Hapus elemen pertama
            size--; // Kurangi ukuran antrian
        }
    }

    // Metode untuk menghitung jumlah elemen dalam antrian
    int count() {
        return size; // Mengembalikan ukuran antrian
    }

    // Metode untuk menghapus seluruh elemen dari antrian
    void clearQueue() {
        while (!isEmpty()) { // Selama antrian tidak kosong, hapus elemen pertama
            kurangAntrian();
        }
    }

    // Metode untuk menampilkan seluruh elemen dalam antrian beserta data mahasiswa
    void viewQueue() {
        cout << "\nData antrian: " << endl; // Cetak pesan untuk menandakan awal data antrian
        Node* current = front; // Pointer untuk traversal antrian, diawali dari elemen pertama
        for (int i = 1; i <= 5; i++) { // Loop untuk mencetak lima baris
            if (current != nullptr) { // Jika masih ada elemen dalam antrian
                cout << i << ". Nama: " << current->data.nama << ", NIM: " << current->data.nim << endl; // Cetak nama dan NIM mahasiswa pada elemen saat ini
                current = current->next; // Pindah ke elemen berikutnya dalam antrian
            } else { // Jika antrian kosong sebelum mencapai lima baris
                cout << i << ". antrian kosong" << endl; // Cetak "antrian kosong"
            }
        }
    }

    // Metode untuk memeriksa apakah antrian kosong
    bool isEmpty() {
        return size == 0; // Mengembalikan true jika ukuran antrian adalah 0
    }
};

// Fungsi utama program
int main() {
    Queue queue_146; // Membuat objek antrian

    // Menambahkan beberapa data mahasiswa ke dalam antrian
    queue_146.tambahAntrian("Andi", "12345");
    queue_146.tambahAntrian("Maya", "67890");
    queue_146.tambahAntrian("Danendra", "146");

    // Menampilkan antrian beserta data mahasiswa
    queue_146.viewQueue();
    cout << "Jumlah antrian = " << queue_146.count() << endl;

    // Mengurangi satu elemen dari antrian dan menampilkan hasilnya
    queue_146.kurangAntrian();
    queue_146.viewQueue();
    cout << "Jumlah antrian = " << queue_146.count() << endl;
    
    // Mengurangi satu elemen dari antrian dan menampilkan hasilnya
    queue_146.kurangAntrian();
    queue_146.viewQueue();
    cout << "Jumlah antrian = " << queue_146.count() << endl;

    // Menghapus seluruh elemen dari antrian dan menampilkan hasilnya
    queue_146.clearQueue();
    queue_146.viewQueue();
    cout << "Jumlah antrian = " << queue_146.count() << endl;

    return 0;
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan7/laprak7/ug2.png)

Kodingan di atas adalah implementasi dari antrian (queue) menggunakan struktur data linked list. Program ini mencakup dua struktur utama: `Mahasiswa`, yang menyimpan data mahasiswa berupa nama dan NIM, serta `Node`, yang menyimpan objek `Mahasiswa` dan pointer ke elemen berikutnya dalam antrian. Kelas `Queue` memiliki atribut untuk menunjukkan elemen pertama (front), elemen terakhir (rear), dan ukuran antrian (size). Fungsi-fungsi utama dalam kelas `Queue` meliputi: `tambahAntrian` untuk menambahkan mahasiswa ke antrian, `kurangAntrian` untuk menghapus elemen pertama dari antrian, `count` untuk menghitung jumlah elemen dalam antrian, `clearQueue` untuk mengosongkan seluruh elemen dari antrian, `viewQueue` untuk menampilkan elemen-elemen dalam antrian, dan `isEmpty` untuk memeriksa apakah antrian kosong. Dalam fungsi `main`, beberapa data mahasiswa ditambahkan ke antrian, kemudian antrian ditampilkan dan dimanipulasi dengan mengurangi elemen-elemen, serta mengosongkan antrian, sambil menampilkan kondisi antrian dan jumlah elemennya setelah setiap operasi.

## Referensi

[1] Carroll, S., & Goponenko, A. (2019). A C++ implementation of a threadsafe priority queue based on multi-dimensional linked lists and MRLock.

[2] L. Josipović, A. Guerrieri and P. Ienne, "From C/C++ Code to High-Performance Dataflow Circuits," in IEEE Transactions on Computer-Aided Design of Integrated Circuits and Systems, vol. 41, no. 7, pp. 2142-2155, July 2022, doi: 10.1109/TCAD.2021.3105574.


