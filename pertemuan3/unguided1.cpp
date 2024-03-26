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
        cout << "Pilih opsi: " << endl;
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
