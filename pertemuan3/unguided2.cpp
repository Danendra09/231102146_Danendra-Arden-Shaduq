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
