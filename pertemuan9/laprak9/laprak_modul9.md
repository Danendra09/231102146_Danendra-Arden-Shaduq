# <h1 align="center">Laporan Praktikum Modul 9 - GRAPH DAN TREE</h1>

<p align="center">Danendra Arden Shaduq - 2311102146</p>

## Dasar Teori
### 1. GRAPH 
Graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk edge atau sisi. Graf terdiri dari kumpulan simpul (vertex) dan busur (edge) yang secara matematis dinyatakan sebagai G = (V, E), di mana V adalah kumpulan vertex dan E adalah kumpulan edge. Graph banyak digunakan dalam berbagai aplikasi seperti jaringan sosial, pemetaan jalan, dan pemodelan data.

Jenis-jenis Graph:
1. Directed Graph (Graf Berarah): Urutan simpul memiliki arti, misalnya busur AB berbeda dengan busur BA.

2. Undirected Graph (Graf Tak Berarah): Urutan simpul tidak diperhatikan, misalnya busur AB sama dengan busur BA.

3. Weighted Graph (Graf Berbobot): Setiap edge memiliki bobot atau nilai tertentu.


Representasi Graph:
1. Matriks Adjacency: Representasi graph dalam bentuk matriks dua dimensi di mana elemen matriks menunjukkan adanya edge antara simpul-simpul.

2. Linked List: Setiap vertex dihubungkan dengan daftar yang berisi vertex lain yang terhubung dengannya.


### 2. TREE 
Tree adalah struktur data hirarkis yang terdiri dari node-node yang terhubung, di mana setiap node memiliki nol atau lebih node anak, dan paling banyak satu node induk. Tree sering digunakan untuk merepresentasikan data yang memiliki sifat hierarkis seperti struktur organisasi, family tree, dan skema pertandingan.

Istilah dalam Tree:
1. Root: Node paling atas dari tree.

2. Parent: Node yang memiliki anak.

3. Child: Node yang merupakan keturunan dari node lain.

4. Leaf: Node yang tidak memiliki anak.

5. Binary Tree: Setiap node memiliki paling banyak dua anak.

6. Binary Search Tree: Binary tree di mana node kiri selalu memiliki nilai yang lebih kecil dan node kanan memiliki nilai yang lebih besar.


Operasi pada Tree:
1. Create: Membuat tree baru yang kosong.

2. Insert: Menambahkan node baru ke dalam tree.

3. Delete: Menghapus node dari tree.

4. Traverse: Mengunjungi semua node dalam tree menggunakan metode seperti pre-order, in-order, dan post-order traversal.

5. Search: Mencari node dalam tree.


## Guided

### 1. Guided 1

```C++
#include <iostream>
#include <iomanip>
using namespace std;
string simpul[7] = {"Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};
void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}
int main()
{
    tampilGraph();
    return 0;
}
```
Kode di atas merepresentasikan sebuah graph berbobot dengan simpul dan busur. Terdapat array `simpul` yang berisi nama-nama kota, serta matriks `busur` yang menyimpan bobot antar simpul yang terhubung. Fungsi `tampilGraph()` digunakan untuk menampilkan graph ini dalam bentuk teks. Dalam fungsi ini, dua loop digunakan untuk iterasi melalui baris dan kolom dari matriks `busur`. Untuk setiap simpul yang memiliki busur (nilai tidak nol dalam matriks), ditampilkan nama kota tujuan dan bobot busurnya. Fungsi `main()` memanggil `tampilGraph()` untuk menampilkan graph. Output akan menunjukkan setiap kota dengan daftar kota yang terhubung dan bobot yang terkait.

### 2. Guided 2

```C++
#include <iostream>
#include <iomanip>
using namespace std;
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "\n Tree sudah ada!" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kiri !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\n Node " << node->data << " sudah ada child kanan !" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    }
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    buatNode('A');
    Pohon *nodeB = insertLeft('B', root);
    Pohon *nodeC = insertRight('C', root);
    Pohon *nodeD = insertLeft('D', nodeB);
    Pohon *nodeE = insertRight('E', nodeB);
    Pohon *nodeF = insertLeft('F', nodeC);
    Pohon *nodeG = insertLeft('G', nodeE);
    Pohon *nodeH = insertRight('H', nodeE);
    Pohon *nodeI = insertLeft('I', nodeG);
    Pohon *nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);

    retrieve(nodeC);
    find(nodeC);

    characteristic();

    cout << "\nPreOrder :\n ";
    preOrder(root);
    cout << "\n\nInOrder :\n ";
    inOrder(root);
    cout << "\n\nPostOrder :\n ";
    postOrder(root);

    cout << endl;
    return 0;
}
```
Kode di atas merepresentasikan implementasi dari sebuah pohon biner. Pada awalnya, fungsi `init` menginisialisasi pohon kosong. Fungsi `buatNode` membuat simpul root, sementara `insertLeft` dan `insertRight` menambahkan simpul kiri dan kanan pada simpul tertentu. Fungsi `update` mengubah data pada simpul tertentu, dan `retrieve` serta `find` digunakan untuk menampilkan informasi simpul. Traversal pohon dilakukan dengan fungsi `preOrder`, `inOrder`, dan `postOrder`, yang masing-masing mencetak simpul dalam urutan pre-order, in-order, dan post-order. Fungsi `deleteTree` dan `deleteSub` menghapus seluruh pohon atau sub-pohon, sedangkan `clear` menghapus seluruh pohon. Fungsi `size` dan `height` mengembalikan ukuran dan tinggi pohon, dan `characteristic` menampilkan karakteristik pohon seperti ukuran, tinggi, dan rata-rata jumlah simpul. Pada fungsi `main`, berbagai operasi dilakukan termasuk penambahan simpul, pengubahan data, pencarian informasi simpul, dan traversal pohon, diakhiri dengan mencetak hasil traversal pre-order, in-order, dan post-order.

## Unguided

### 1.  Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
// 2311102146 - DANENDRA ARDEN SHADUQ
#include <iostream> // Menyertakan pustaka input-output
#include <vector>   // Menyertakan pustaka vektor
#include <string>   // Menyertakan pustaka string
#include <iomanip>  // Menyertakan pustaka untuk pengaturan output

using namespace std; // Menggunakan namespace std

int main() {
    int n_146; // Deklarasi variabel untuk menyimpan jumlah simpul
    cout << "Silakan masukan jumlah simpul: "; // Menampilkan pesan untuk memasukkan jumlah simpul
    cin >> n_146; // Membaca jumlah simpul dari pengguna
    
    vector<string> cities(n_146); // Membuat vektor untuk menyimpan nama-nama simpul (kota)
    vector<vector<int>> graph(n_146, vector<int>(n_146)); // Membuat matriks ketetanggaan untuk menyimpan bobot antar simpul
    
    cout << "Silakan masukan nama simpul" << endl; // Menampilkan pesan untuk memasukkan nama-nama simpul
    for (int i = 0; i < n_146; ++i) { // Loop untuk membaca nama-nama simpul
        cout << "Simpul " << i + 1 << ": "; // Menampilkan pesan untuk memasukkan nama simpul ke-i
        cin >> cities[i]; // Membaca nama simpul dari pengguna
    }
    
    cout << "Silakan masukan bobot antar simpul" << endl; // Menampilkan pesan untuk memasukkan bobot antar simpul
    for (int i = 0; i < n_146; ++i) { // Loop untuk setiap simpul asal
        for (int j = 0; j < n_146; ++j) { // Loop untuk setiap simpul tujuan
            cout << cities[i] << "--> " << cities[j] << " = "; // Menampilkan pesan untuk memasukkan bobot antara simpul asal dan tujuan
            cin >> graph[i][j]; // Membaca bobot dari pengguna
        }
    }
    
    cout << "\n"; // Menampilkan baris kosong untuk pemisahan
    cout << setw(10) << ""; // Mengatur lebar kolom untuk penampilan nama simpul
    for (int i = 0; i < n_146; ++i) { // Loop untuk menampilkan nama-nama simpul di baris pertama tabel
        cout << setw(10) << cities[i]; // Menampilkan nama simpul dengan lebar kolom 10
    }
    cout << "\n"; // Menampilkan baris baru
    
    for (int i = 0; i < n_146; ++i) { // Loop untuk setiap baris pada tabel
        cout << setw(10) << cities[i]; // Menampilkan nama simpul di awal baris
        for (int j = 0; j < n_146; ++j) { // Loop untuk setiap kolom pada tabel
            cout << setw(10) << graph[i][j]; // Menampilkan bobot dengan lebar kolom 10
        }
        cout << "\n"; // Menampilkan baris baru setelah setiap baris tabel selesai
    }
    
    return 0; // Mengembalikan nilai 0 menandakan program selesai dengan sukses
}
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan8/laprak8/ug1.png)

Kode di atas digunakan untuk merepresentasikan sebuah graph berbobot dengan simpul dan busur berdasarkan input pengguna. Program dimulai dengan meminta pengguna untuk memasukkan jumlah simpul, yang kemudian disimpan dalam variabel `n_146`. Selanjutnya, pengguna diminta untuk memasukkan nama-nama simpul yang disimpan dalam vektor `cities`. Setelah itu, program meminta pengguna untuk memasukkan bobot antar simpul, yang disimpan dalam matriks `graph`. Setelah semua input diterima, program menampilkan tabel yang memperlihatkan nama-nama simpul dan bobot antar simpul dalam format tabel yang terformat rapi menggunakan manipulasi output dengan `setw`. Setiap baris dan kolom tabel menampilkan nama simpul dan bobot yang sesuai, memberikan representasi visual dari graph berbobot yang telah diinput oleh pengguna. Program diakhiri dengan mengembalikan nilai 0, menandakan bahwa program selesai dengan sukses.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
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
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan8/laprak8/ug2.png)

Kodingan di atas adalah implementasi dari struktur data pohon biner dengan berbagai operasi dasar. Program dimulai dengan inisialisasi pohon, menetapkan pointer `root` ke `NULL`. Kemudian, ada fungsi untuk memeriksa apakah pohon kosong, membuat node baru sebagai root, menambahkan node di kiri dan kanan, memperbarui data node, mengambil data node, mencari node dan menampilkan informasi lengkap tentang node tersebut, serta tiga jenis traversal (preOrder, inOrder, postOrder). Selain itu, terdapat fungsi untuk menghapus seluruh node dalam pohon dan mengosongkannya. Menu interaktif memungkinkan pengguna untuk memilih berbagai operasi yang ingin dilakukan pada pohon. Program ini berlanjut meminta pilihan pengguna sampai pengguna memilih untuk keluar (pilihan '12'), yang kemudian mengakhiri program dengan mengembalikan nilai 0.

## Referensi

[1] Blumenthal, D. B., Bougleux, S., Gamper, J., & Brun, L. (2019, May). GEDLIB: A C++ library for graph edit distance computation. In International Workshop on Graph-Based Representations in Pattern Recognition (pp. 14-24). Cham: Springer International Publishing.

[2] Wu, Y., Lu, J., Zhang, Y., & Jin, S. (2021, January). Vulnerability detection in c/c++ source code with graph representation learning. In 2021 IEEE 11th Annual Computing and Communication Workshop and Conference (CCWC) (pp. 1519-1524). IEEE.

[3] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). MIT Press.

[4] Karumanchi, N. (2020). Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles (6th ed.). Careermonk Publications.




