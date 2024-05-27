// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>  
#include <iomanip>   

using namespace std; 

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
    if (isEmpty()) {
        root = new Pohon(); // Buat node baru
        root->char_146 = char_146; // Set data node
        root->left = NULL; // Set anak kiri menjadi NULL
        root->right = NULL; // Set anak kanan menjadi NULL
        root->parent = NULL; // Set parent menjadi NULL
        cout << "\n Node " << char_146 << " berhasil dibuat sebagai root." << endl;
    } else {
        cout << "\n Tree sudah ada!" << endl; // Pesan jika tree sudah ada
    }
}

// Fungsi untuk menambah node kiri
Pohon* insertLeft(char char_146, Pohon *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\n Node " << node->char_146 << " sudah ada child kiri !" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon(); // Buat node baru
            baru->char_146 = char_146; // Set data node
            baru->left = NULL; // Set anak kiri menjadi NULL
            baru->right = NULL; // Set anak kanan menjadi NULL
            baru->parent = node; // Set parent node
            node->left = baru; // Set anak kiri dari node parent
            cout << "\n Node " << char_146 << " berhasil ditambahkan ke child kiri " << baru->parent->char_146 << endl;
            return baru;
        }
    }
}

// Fungsi untuk menambah node kanan
Pohon* insertRight(char char_146, Pohon *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\n Node " << node->char_146 << " sudah ada child kanan !" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon(); // Buat node baru
            baru->char_146 = char_146; // Set data node
            baru->left = NULL; // Set anak kiri menjadi NULL
            baru->right = NULL; // Set anak kanan menjadi NULL
            baru->parent = node; // Set parent node
            node->right = baru; // Set anak kanan dari node parent
            cout << "\n Node " << char_146 << " berhasil ditambahkan ke child kanan " << baru->parent->char_146 << endl;
            return baru;
        }
    }
}

// Fungsi untuk mengubah data node
void update(char char_146, Pohon *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (!node) {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->char_146; // Simpan data lama
            node->char_146 = char_146; // Set data baru
            cout << "\n Node " << temp << " berhasil diubah menjadi " << char_146 << endl;
        }
    }
}

// Fungsi untuk menampilkan data node
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (!node) {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data node : " << node->char_146 << endl;
        }
    }
}

// Fungsi untuk mencari dan menampilkan informasi node
void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (!node) {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data Node : " << node->char_146 << endl;
            cout << " Root : " << root->char_146 << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->char_146 << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->char_146 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->char_146 << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->char_146 << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->char_146 << endl;
        }
    }
}

// Fungsi untuk traversal preorder
void preOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (node != NULL) {
            cout << " " << node->char_146 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// Fungsi untuk traversal inorder
void inOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->char_146 << ", ";
            inOrder(node->right);
        }
    }
}

// Fungsi untuk traversal postorder
void postOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->char_146 << ", ";
        }
    }
}

// Fungsi untuk menghapus pohon
void deleteTree(Pohon *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Fungsi untuk menghapus subtree
void deleteSub(Pohon *node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->char_146 << " berhasil dihapus." << endl;
    }
}

// Fungsi untuk menghapus semua node di tree
void clear() {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!!" << endl; // Pesan jika tree belum ada
    } else {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}

// Fungsi untuk menghitung ukuran pohon
int size(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!!" << endl; // Pesan jika tree belum ada
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Fungsi untuk menghitung tinggi pohon
int height(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl; // Pesan jika tree belum ada
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Fungsi untuk menampilkan karakteristik pohon
void characteristic() {
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

// Fungsi untuk menampilkan anak-anak dari sebuah node
void displayChildren(Pohon *node) {
    if (node) {
        cout << "\nChildren of Node " << node->char_146 << ": ";
        if (node->left)
            cout << "Left: " << node->left->char_146 << " ";
        else
            cout << "Left: NULL ";
        if (node->right)
            cout << "Right: " << node->right->char_146 << " ";
        else
            cout << "Right: NULL ";
        cout << endl;
    } else {
        cout << "\nNode tidak ditemukan!" << endl;
    }
}

// Fungsi untuk menampilkan keturunan dari sebuah node
void displayDescendants(Pohon *node) {
    if (node) {
        cout << "\nDescendants of Node " << node->char_146 << ": ";
        preOrder(node->left);
        preOrder(node->right);
        cout << endl;
    } else {
        cout << "\nNode tidak ditemukan!" << endl;
    }
}

// Fungsi untuk menemukan node berdasarkan data
Pohon* findNode(char char_146, Pohon *node = root) {
    if (!node)
        return NULL;
    if (node->char_146 == char_146)
        return node;
    Pohon *left = findNode(char_146, node->left);
    if (left)
        return left;
    return findNode(char_146, node->right);
}

// Fungsi untuk menampilkan menu
void menu() {
    int choice;
    char char_146, parentData;
    Pohon *parentNode = NULL;

    do {
        cout << "\nMenu:\n";
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
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data untuk root: ";
                cin >> char_146;
                buatNode(char_146);
                break;
            case 2:
                cout << "Masukkan data untuk node kiri: ";
                cin >> char_146;
                cout << "Masukkan data parent: ";
                cin >> parentData;
                parentNode = findNode(parentData);
                insertLeft(char_146, parentNode);
                break;
            case 3:
                cout << "Masukkan data untuk node kanan: ";
                cin >> char_146;
                cout << "Masukkan data parent: ";
                cin >> parentData;
                parentNode = findNode(parentData);
                insertRight(char_146, parentNode);
                break;
            case 4:
                cout << "Masukkan data baru: ";
                cin >> char_146;
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> parentData;
                parentNode = findNode(parentData);
                update(char_146, parentNode);
                break;
            case 5:
                cout << "Masukkan data node yang ingin di-retrieve: ";
                cin >> char_146;
                parentNode = findNode(char_146);
                retrieve(parentNode);
                break;
            case 6:
                cout << "Masukkan data node yang ingin di-find: ";
                cin >> char_146;
                parentNode = findNode(char_146);
                find(parentNode);
                break;
            case 7:
                cout << "Masukkan data node untuk menampilkan children: ";
                cin >> char_146;
                parentNode = findNode(char_146);
                displayChildren(parentNode);
                break;
            case 8:
                cout << "Masukkan data node untuk menampilkan descendants: ";
                cin >> char_146;
                parentNode = findNode(char_146);
                displayDescendants(parentNode);
                break;
            case 9:
                cout << "\nPreOrder :\n ";
                preOrder(root);
                cout << endl;
                break;
            case 10:
                cout << "\nInOrder :\n ";
                inOrder(root);
                cout << endl;
                break;
            case 11:
                cout << "\nPostOrder :\n ";
                postOrder(root);
                cout << endl;
                break;
            case 12:
                clear();
                break;
            case 13:
                characteristic();
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 0);
}

// Fungsi utama
int main() {
    init(); // Inisialisasi pohon
    menu(); // Menampilkan menu
    return 0; // Mengembalikan 0 sebagai tanda program berjalan dengan baik
}
