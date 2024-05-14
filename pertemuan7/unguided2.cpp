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
