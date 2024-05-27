#include <iostream>  // Mengimpor pustaka input-output
#include <iomanip>   // Mengimpor pustaka manipulasi I/O
using namespace std; // Menggunakan namespace standar

// Struktur pohon
struct Pohon {
    char char_146; 
    Pohon *left, *right, *parent; // Pointer untuk anak kiri, anak kanan, dan parent
};

Pohon *root, *baru; // Deklarasi pointer root dan baru

// Fungsi untuk menginisialisasi pohon
void init() {
    root = NULL; // Set root menjadi NULL
}

// Fungsi untuk mengecek apakah pohon kosong
bool isEmpty() {
    return root == NULL; // Mengembalikan true jika root NULL
}

// Fungsi untuk membuat node baru
void buatNode(char char_146) {
    if (isEmpty()) { // Jika pohon kosong
        root = new Pohon(); // Buat node baru
        root->char_146 = char_146; // Set data node
        root->left = NULL; // Set anak kiri menjadi NULL
        root->right = NULL; // Set anak kanan menjadi NULL
        root->parent = NULL; // Set parent menjadi NULL
        cout << "\n Node " << char_146 << " berhasil dibuat sebagai root." << endl; // Cetak pesan sukses
    } else { // Jika pohon tidak kosong
        cout << "\n Tree sudah ada!" << endl; // Pesan jika tree sudah ada
    }
}

// Fungsi untuk menambah node kiri
Pohon* insertLeft(char char_146, Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
        return NULL;
    } else {
        if (node->left != NULL) { // Jika node kiri sudah ada
            cout << "\n Node " << node->char_146 << " sudah ada child kiri !" << endl; // Pesan jika anak kiri sudah ada
            return NULL;
        } else {
            Pohon *baru = new Pohon(); // Buat node baru
            baru->char_146 = char_146; // Set data node
            baru->left = NULL; // Set anak kiri menjadi NULL
            baru->right = NULL; // Set anak kanan menjadi NULL
            baru->parent = node; // Set parent node
            node->left = baru; // Set anak kiri dari node parent
            cout << "\n Node " << char_146 << " berhasil ditambahkan ke child kiri " << baru->parent->char_146 << endl; // Pesan sukses
            return baru; // Kembalikan node baru
        }
    }
}

// Fungsi untuk menambah node kanan
Pohon* insertRight(char char_146, Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
        return NULL;
    } else {
        if (node->right != NULL) { // Jika node kanan sudah ada
            cout << "\n Node " << node->char_146 << " sudah ada child kanan !" << endl; // Pesan jika anak kanan sudah ada
            return NULL;
        } else {
            Pohon *baru = new Pohon(); // Buat node baru
            baru->char_146 = char_146; // Set data node
            baru->left = NULL; // Set anak kiri menjadi NULL
            baru->right = NULL; // Set anak kanan menjadi NULL
            baru->parent = node; // Set parent node
            node->right = baru; // Set anak kanan dari node parent
            cout << "\n Node " << char_146 << " berhasil ditambahkan ke child kanan " << baru->parent->char_146 << endl; // Pesan sukses
            return baru; // Kembalikan node baru
        }
    }
}

// Fungsi untuk mengubah data node
void update(char char_146, Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (!node) { // Jika node tidak ada
            cout << "\n Node yang ingin diganti tidak ada!!" << endl; // Pesan jika node tidak ada
        } else {
            char temp = node->char_146; // Simpan data lama
            node->char_146 = char_146; // Set data baru
            cout << "\n Node " << temp << " berhasil diubah menjadi " << char_146 << endl; // Pesan sukses
        }
    }
}

// Fungsi untuk menampilkan data node
void retrieve(Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (!node) { // Jika node tidak ada
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Pesan jika node tidak ada
        } else {
            cout << "\n Data node : " << node->char_146 << endl; // Tampilkan data node
        }
    }
}

// Fungsi untuk mencari dan menampilkan informasi node
void find(Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (!node) { // Jika node tidak ada
            cout << "\n Node yang ditunjuk tidak ada!" << endl; // Pesan jika node tidak ada
        } else {
            cout << "\n Data Node : " << node->char_146 << endl; // Tampilkan data node
            cout << " Root : " << root->char_146 << endl; // Tampilkan data root
            if (!node->parent) // Jika tidak punya parent
                cout << " Parent : (tidak punya parent)" << endl; // Tampilkan pesan
            else
                cout << " Parent : " << node->parent->char_146 << endl; // Tampilkan parent
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node) // Jika sibling kiri
                cout << " Sibling : " << node->parent->left->char_146 << endl; // Tampilkan sibling kiri
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node) // Jika sibling kanan
                cout << " Sibling : " << node->parent->right->char_146 << endl; // Tampilkan sibling kanan
            else
                cout << " Sibling : (tidak punya sibling)" << endl; // Tampilkan pesan jika tidak punya sibling
            if (!node->left) // Jika tidak punya anak kiri
                cout << " Child Kiri : (tidak punya Child kiri)" << endl; // Tampilkan pesan
            else
                cout << " Child Kiri : " << node->left->char_146 << endl; // Tampilkan anak kiri
            if (!node->right) // Jika tidak punya anak kanan
                cout << " Child Kanan : (tidak punya Child kanan)" << endl; // Tampilkan pesan
            else
                cout << " Child Kanan : " << node->right->char_146 << endl; // Tampilkan anak kanan
        }
    }
}

// Fungsi untuk traversal preorder
void preOrder(Pohon *node = root) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (node != NULL) { // Jika node tidak NULL
            cout << " " << node->char_146 << ", "; // Tampilkan data node
            preOrder(node->left); // Rekursif ke anak kiri
            preOrder(node->right); // Rekursif ke anak kanan
        }
    }
}

// Fungsi untuk traversal inorder
void inOrder(Pohon *node = root) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (node != NULL) { // Jika node tidak NULL
            inOrder(node->left); // Rekursif ke anak kiri
            cout << " " << node->char_146 << ", "; // Tampilkan data node
            inOrder(node->right); // Rekursif ke anak kanan
        }
    }
}

// Fungsi untuk traversal postorder
void postOrder(Pohon *node = root) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (node != NULL) { // Jika node tidak NULL
            postOrder(node->left); // Rekursif ke anak kiri
            postOrder(node->right); // Rekursif ke anak kanan
            cout << " " << node->char_146 << ", "; // Tampilkan data node
        }
    }
}

// Fungsi untuk menghapus pohon
void deleteTree(Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (node != NULL) { // Jika node tidak NULL
            if (node != root) { // Jika node bukan root
                node->parent->left = NULL; // Set anak kiri parent ke NULL
                node->parent->right = NULL; // Set anak kanan parent ke NULL
            }
            deleteTree(node->left); // Rekursif hapus anak kiri
            deleteTree(node->right); // Rekursif hapus anak kanan
            if (node == root) { // Jika node adalah root
                delete root; // Hapus root
                root = NULL; // Set root ke NULL
            } else {
                delete node; // Hapus node
            }
        }
    }
}

// Fungsi untuk menghapus subtree
void deleteSub(Pohon *node) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        deleteTree(node->left); // Hapus anak kiri
        deleteTree(node->right); // Hapus anak kanan
        cout << "\n Node subtree " << node->char_146 << " berhasil dihapus." << endl; // Pesan sukses
    }
}

// Fungsi untuk menghapus semua node di tree
void clear() {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!!" << endl; // Pesan jika tree belum ada
    } else {
        deleteTree(root); // Hapus pohon
        cout << "\n Pohon berhasil dihapus." << endl; // Pesan sukses
    }
}

// Fungsi untuk menghitung ukuran pohon
int size(Pohon *node = root) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!!" << endl; // Pesan jika tree belum ada
        return 0;
    } else {
        if (!node) { // Jika node NULL
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right); // Rekursif hitung ukuran
        }
    }
}

// Fungsi untuk menghitung tinggi pohon
int height(Pohon *node = root) {
    if (isEmpty()) { // Jika pohon kosong
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
        return 0;
    } else {
        if (!node) { // Jika node NULL
            return 0;
        } else {
            int heightKiri = height(node->left); // Rekursif hitung tinggi kiri
            int heightKanan = height(node->right); // Rekursif hitung tinggi kanan
            if (heightKiri >= heightKanan) { // Bandingkan tinggi kiri dan kanan
                return heightKiri + 1; // Kembalikan tinggi kiri + 1
            } else {
                return heightKanan + 1; // Kembalikan tinggi kanan + 1
            }
        }
    }
}

// Fungsi untuk menampilkan karakteristik pohon
void characteristic() {
    cout << "\n Size Tree : " << size() << endl; // Tampilkan ukuran pohon
    cout << " Height Tree : " << height() << endl; // Tampilkan tinggi pohon
    cout << " Average Node of Tree : " << size() / height() << endl; // Tampilkan rata-rata node
}

// Fungsi untuk menampilkan anak-anak dari sebuah node
void displayChildren(Pohon *node) {
    if (node) { // Jika node tidak NULL
        cout << "\nChildren of Node " << node->char_146 << ": "; // Tampilkan data node
        if (node->left) // Jika anak kiri ada
            cout << "Left: " << node->left->char_146 << " "; // Tampilkan anak kiri
        else
            cout << "Left: NULL "; // Tampilkan pesan anak kiri NULL
        if (node->right) // Jika anak kanan ada
            cout << "Right: " << node->right->char_146 << " "; // Tampilkan anak kanan
        else
            cout << "Right: NULL "; // Tampilkan pesan anak kanan NULL
        cout << endl; // Pindah baris
    } else { // Jika node NULL
        cout << "\nNode tidak ditemukan!" << endl; // Pesan node tidak ditemukan
    }
}

// Fungsi untuk menampilkan keturunan dari sebuah node
void displayDescendants(Pohon *node) {
    if (node) { // Jika node tidak NULL
        cout << "\nDescendants of Node " << node->char_146 << ": "; // Tampilkan data node
        preOrder(node->left); // Preorder anak kiri
        preOrder(node->right); // Preorder anak kanan
        cout << endl; // Pindah baris
    } else { // Jika node NULL
        cout << "\nNode tidak ditemukan!" << endl; // Pesan node tidak ditemukan
    }
}

// Fungsi untuk menemukan node berdasarkan data
Pohon* findNode(char char_146, Pohon *node = root) {
    if (!node) // Jika node NULL
        return NULL;
    if (node->char_146 == char_146) // Jika data sama
        return node; // Kembalikan node
    Pohon *left = findNode(char_146, node->left); // Rekursif cari di anak kiri
    if (left) // Jika ditemukan di kiri
        return left;
    return findNode(char_146, node->right); // Rekursif cari di anak kanan
}

// Fungsi untuk menampilkan menu
void menu() {
    int choice; // Variabel pilihan
    char char_146, parentData; // Variabel data node
    Pohon *parentNode = NULL; // Pointer parent node

    do {
        cout << "\nMenu:\n"; // Tampilkan menu
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Display Children\n";
        cout << "8. Display Descendants\n";
        cout << "9. Traversal PreOrder\n";
        cout << "10. Traversal InOrder\n";
        cout << "11. Traversal PostOrder\n";
        cout << "12. Hapus Tree\n";
        cout << "13. Karakteristik Tree\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice; // Input pilihan

        switch (choice) {
            case 1: // Pilihan buat root
                cout << "Masukkan data untuk root: ";
                cin >> char_146; // Input data root
                buatNode(char_146); // Buat node root
                break;
            case 2: // Pilihan tambah node kiri
                cout << "Masukkan data untuk node kiri: ";
                cin >> char_146; // Input data node kiri
                cout << "Masukkan data parent: ";
                cin >> parentData; // Input data parent
                parentNode = findNode(parentData); // Cari parent node
                insertLeft(char_146, parentNode); // Tambah node kiri
                break;
            case 3: // Pilihan tambah node kanan
                cout << "Masukkan data untuk node kanan: ";
                cin >> char_146; // Input data node kanan
                cout << "Masukkan data parent: ";
                cin >> parentData; // Input data parent
                parentNode = findNode(parentData); // Cari parent node
                insertRight(char_146, parentNode); // Tambah node kanan
                break;
            case 4: // Pilihan update node
                cout << "Masukkan data baru: ";
                cin >> char_146; // Input data baru
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> parentData; // Input data node yang ingin diupdate
                parentNode = findNode(parentData); // Cari node yang ingin diupdate
                update(char_146, parentNode); // Update node
                break;
            case 5: // Pilihan retrieve node
                cout << "Masukkan data node yang ingin di-retrieve: ";
                cin >> char_146; // Input data node
                parentNode = findNode(char_146); // Cari node
                retrieve(parentNode); // Retrieve node
                break;
            case 6: // Pilihan find node
                cout << "Masukkan data node yang ingin di-find: ";
                cin >> char_146; // Input data node
                parentNode = findNode(char_146); // Cari node
                find(parentNode); // Find node
                break;
            case 7: // Pilihan display children
                cout << "Masukkan data node untuk menampilkan children: ";
                cin >> char_146; // Input data node
                parentNode = findNode(char_146); // Cari node
                displayChildren(parentNode); // Display children
                break;
            case 8: // Pilihan display descendants
                cout << "Masukkan data node untuk menampilkan descendants: ";
                cin >> char_146; // Input data node
                parentNode = findNode(char_146); // Cari node
                displayDescendants(parentNode); // Display descendants
                break;
            case 9: // Pilihan traversal preorder
                cout << "\nPreOrder :\n ";
                preOrder(root); // Traversal preorder
                cout << endl; // Pindah baris
                break;
            case 10: // Pilihan traversal inorder
                cout << "\nInOrder :\n ";
                inOrder(root); // Traversal inorder
                cout << endl; // Pindah baris
                break;
            case 11: // Pilihan traversal postorder
                cout << "\nPostOrder :\n ";
                postOrder(root); // Traversal postorder
                cout << endl; // Pindah baris
                break;
            case 12: // Pilihan hapus tree
                clear(); // Hapus tree
                break;
            case 13: // Pilihan karakteristik tree
                characteristic(); // Tampilkan karakteristik tree
                break;
            case 0: // Pilihan keluar
                cout << "Terima kasih!\n";
                break;
            default: // Pilihan tidak valid
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 0); // Loop sampai pilihan 0
}

// Fungsi utama
int main() {
    init(); // Inisialisasi pohon
    menu(); // Menampilkan menu
    return 0; // Mengembalikan 0 sebagai tanda program berjalan dengan baik
}
