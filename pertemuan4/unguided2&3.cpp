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
