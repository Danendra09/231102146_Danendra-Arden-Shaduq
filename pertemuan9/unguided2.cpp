// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream> // Menyertakan pustaka input-output
#include <iomanip>  // Menyertakan pustaka untuk pengaturan output
#include <queue>    // Menyertakan pustaka queue
using namespace std; // Menggunakan namespace std

// Struktur untuk node pohon
struct Pohon {
    char data_146; // Data yang disimpan di node
    Pohon *left, *right, *parent; // Pointer ke anak kiri, anak kanan, dan parent
};

Pohon *root; // Deklarasi pointer root

// Inisialisasi root
void init() {
    root = NULL; // Set root ke NULL
}

// Mengecek apakah pohon kosong
bool isEmpty() {
    return root == NULL; // Mengembalikan true jika root NULL
}

// Membuat node baru sebagai root
void buatNode(char data_146) {
    if (isEmpty()) { // Jika pohon kosong
        root = new Pohon(); // Buat node baru
        root->data_146 = data_146; // Set data pada root
        root->left = NULL; // Set anak kiri root ke NULL
        root->right = NULL; // Set anak kanan root ke NULL
        root->parent = NULL; // Set parent root ke NULL
        cout << "\n Node " << data_146 << " berhasil dibuat sebagai root." << endl; // Pesan sukses
    } else {
        cout << "\n Tree sudah ada!" << endl; // Pesan jika pohon sudah ada
    }
}

// Menambahkan node di kiri
Pohon *insertLeft(char data_146, Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan untuk membuat pohon dulu
        return NULL; // Kembalikan NULL
    } else {
        if (node->left != NULL) { // Jika node sudah punya anak kiri
            cout << "\n Node " << node->data_146 << " sudah memiliki child kiri !" << endl; // Pesan error
            return NULL; // Kembalikan NULL
        } else {
            Pohon *baru = new Pohon(); // Buat node baru
            baru->data_146 = data_146; // Set data pada node baru
            baru->left = NULL; // Set anak kiri node baru ke NULL
            baru->right = NULL; // Set anak kanan node baru ke NULL
            baru->parent = node; // Set parent node baru ke node
            node->left = baru; // Set anak kiri node ke node baru
            cout << "\n Node " << data_146 << " berhasil ditambahkan ke child kiri " << baru->parent->data_146 << endl; // Pesan sukses
            return baru; // Kembalikan node baru
        }
    }
}

// Menambahkan node di kanan
Pohon *insertRight(char data_146, Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan untuk membuat pohon dulu
        return NULL; // Kembalikan NULL
    } else {
        if (node->right != NULL) { // Jika node sudah punya anak kanan
            cout << "\n Node " << node->data_146 << " sudah memiliki child kanan !" << endl; // Pesan error
            return NULL; // Kembalikan NULL
        } else {
            Pohon *baru = new Pohon(); // Buat node baru
            baru->data_146 = data_146; // Set data pada node baru
            baru->left = NULL; // Set anak kiri node baru ke NULL
            baru->right = NULL; // Set anak kanan node baru ke NULL
            baru->parent = node; // Set parent node baru ke node
            node->right = baru; // Set anak kanan node ke node baru
            cout << "\n Node " << data_146 << " berhasil ditambahkan ke child kanan " << baru->parent->data_146 << endl; // Pesan sukses
            return baru; // Kembalikan node baru
        }
    }
}

// Mengupdate data pada node
void update(char data_146, Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan untuk membuat pohon dulu
    } else {
        if (!node) { // Jika node tidak ada
            cout << "\n Node yang ingin diganti tidak ada!!" << endl; // Pesan error
        } else {
            char temp = node->data_146; // Simpan data lama
            node->data_146 = data_146; // Update data
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data_146 << endl; // Pesan sukses
        }
    }
}

// Mengambil data pada node
void retrieve(Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan untuk membuat pohon dulu
    } else {
        if (!node) { // Jika node tidak ada
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Pesan error
        } else {
            cout << "\n Data node : " << node->data_146 << endl; // Tampilkan data node
        }
    }
}

// Mencari node dan menampilkan informasi tentang node tersebut
void find(Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan untuk membuat pohon dulu
    } else {
        if (!node) { // Jika node tidak ada
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Pesan error
        } else {
            cout << "\n Data Node : " << node->data_146 << endl; // Tampilkan data node
            cout << " Root : " << root->data_146 << endl; // Tampilkan data root
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl; // Jika node tidak punya parent
            else
                cout << " Parent : " << node->parent->data_146 << endl; // Tampilkan data parent

            // Tampilkan sibling node
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data_146 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data_146 << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;

            // Tampilkan anak kiri dan kanan
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data_146 << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data_146 << endl;

            // Menampilkan descendant dari node
            cout << " Descendant dari node " << node->data_146 << " : ";
            queue<Pohon *> q; // Membuat queue untuk traversal level-order
            q.push(node); // Push node ke queue
            while (!q.empty()) { // Selama queue tidak kosong
                Pohon *current = q.front(); // Ambil node dari depan queue
                q.pop(); // Hapus node dari queue
                if (current->left) { // Jika ada anak kiri
                    cout << current->left->data_146 << " "; // Tampilkan anak kiri
                    q.push(current->left); // Push anak kiri ke queue
                }
                if (current->right) { // Jika ada anak kanan
                    cout << current->right->data_146 << " "; // Tampilkan anak kanan
                    q.push(current->right); // Push anak kanan ke queue
                }
            }
            cout << endl; // Baris baru
        }
    }
}

// Fungsi traversal preOrder
void preOrder(Pohon *node) {
    if (node) { // Jika node tidak NULL
        cout << node->data_146 << " "; // Tampilkan data node
        preOrder(node->left); // Traversal preOrder anak kiri
        preOrder(node->right); // Traversal preOrder anak kanan
    }
}

// Fungsi traversal inOrder
void inOrder(Pohon *node) {
    if (node) { // Jika node tidak NULL
        inOrder(node->left); // Traversal inOrder anak kiri
        cout << node->data_146 << " "; // Tampilkan data node
        inOrder(node->right); // Traversal inOrder anak kanan
    }
}

// Fungsi traversal postOrder
void postOrder(Pohon *node) {
    if (node) { // Jika node tidak NULL
        postOrder(node->left); // Traversal postOrder anak kiri
        postOrder(node->right); // Traversal postOrder anak kanan
        cout << node->data_146 << " "; // Tampilkan data node
    }
}

// Fungsi menghapus seluruh node dalam pohon
void deleteTree(Pohon *node) {
    if (node) { // Jika node tidak NULL
        deleteTree(node->left); // Hapus anak kiri
        deleteTree(node->right); // Hapus anak kanan
        delete node; // Hapus node
    }
}

// Fungsi mengosongkan pohon
void clear() {
    deleteTree(root); // Hapus seluruh node mulai dari root
    root = NULL; // Set root ke NULL
    cout << "Tree telah dikosongkan." << endl; // Pesan sukses
}

// Fungsi karakteristik (belum diimplementasikan)
void characteristic() {
    cout << "Fungsi characteristic belum diimplementasikan." << endl; // Pesan placeholder
}

// Fungsi utama
int main() {
    init(); // Inisialisasi pohon
    char choice; // Variabel untuk pilihan menu
    char data_146; // Variabel untuk data
    Pohon *node; // Variabel untuk pointer node

    do {
        // Menampilkan menu
        cout << "\nMENU:\n";
        cout << "1. Buat Node\n";
        cout << "2. Insert Left\n";
        cout << "3. Insert Right\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Characteristic Tree\n";
        cout << "8. PreOrder Traversal\n";
        cout << "9. InOrder Traversal\n";
        cout << "10. PostOrder Traversal\n";
        cout << "11. Clear Tree\n";
        cout << "12. Exit\n";
        cout << "Pilihan Anda: ";
        cin >> choice; // Membaca pilihan dari user

        switch (choice) { // Switch case berdasarkan pilihan user
        case '1':
            cout << "Masukkan data untuk node baru: ";
            cin >> data_146; // Membaca data untuk node baru
            buatNode(data_146); // Membuat node baru
            break;
        case '2':
            cout << "Masukkan data untuk node baru: ";
            cin >> data_146; // Membaca data untuk node baru
            cout << "Masukkan data parent: ";
            cin >> data_146; // Membaca data parent
            node = insertLeft(data_146, root); // Menambahkan node di kiri
            break;
        case '3':
            cout << "Masukkan data untuk node baru: ";
            cin >> data_146; // Membaca data untuk node baru
            cout << "Masukkan data parent: ";
            cin >> data_146; // Membaca data parent
            node = insertRight(data_146, root); // Menambahkan node di kanan
            break;
        case '4':
            cout << "Masukkan data baru: ";
            cin >> data_146; // Membaca data baru
            cout << "Masukkan data node yang ingin diupdate: ";
            cin >> data_146; // Membaca data node yang ingin diupdate
            update(data_146, node); // Mengupdate data node
            break;
        case '5':
            cout << "Masukkan data node yang ingin diretrieve: ";
            cin >> data_146; // Membaca data node yang ingin diretrieve
            retrieve(node); // Mengambil data node
            break;
        case '6':
            cout << "Masukkan data node yang ingin ditemukan: ";
            cin >> data_146; // Membaca data node yang ingin ditemukan
            find(node); // Mencari node dan menampilkan informasinya
            break;
        case '7':
            characteristic(); // Memanggil fungsi karakteristik
            break;
        case '8':
            cout << "\nPreOrder :\n ";
            preOrder(root); // Traversal preOrder
            cout << endl;
            break;
        case '9':
            cout << "\nInOrder :\n ";
            inOrder(root); // Traversal inOrder
            cout << endl;
            break;
        case '10':
            cout << "\nPostOrder :\n ";
            postOrder(root); // Traversal postOrder
            cout << endl;
            break;
        case '11':
            clear(); // Mengosongkan pohon
            break;
        case '12':
            cout << "Terima kasih!\n"; // Pesan keluar
            break;
        default:
            cout << "Pilihan tidak valid!" << endl; // Pesan jika pilihan tidak valid
        }
    } while (choice != '12'); // Loop sampai user memilih untuk keluar

    return 0; // Mengembalikan nilai 0 menandakan program selesai dengan sukses
}
