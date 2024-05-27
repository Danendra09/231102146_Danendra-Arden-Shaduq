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

Kode di atas digunakan untuk merepresentasikan sebuah graph berbobot dengan simpul dan busur berdasarkan input user. Program dimulai dengan meminta user untuk memasukkan jumlah simpul, yang kemudian disimpan dalam variabel `n_146`. Selanjutnya, user diminta untuk memasukkan nama-nama simpul yang disimpan dalam vektor `cities`. Setelah itu, program meminta user untuk memasukkan bobot antar simpul, yang disimpan dalam matriks `graph`. Setelah semua input diterima, program menampilkan tabel yang memperlihatkan nama-nama simpul dan bobot antar simpul dalam format tabel yang terformat rapi menggunakan manipulasi output dengan `setw`. Setiap baris dan kolom tabel menampilkan nama simpul dan bobot yang sesuai, memberikan representasi visual dari graph berbobot yang telah diinput oleh user. Program diakhiri dengan mengembalikan nilai 0, menandakan bahwa program selesai dengan sukses.

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!

```C++
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
```

#### Output:

##### Buat Node

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2a.png)


##### Tambah Node Kiri

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2b.png)


![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2d.png)


![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2f.png)


![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2g.png)


![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2i.png)


##### Tambah Node Kanan

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2c.png)


![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2e.png)


![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2h.png)


![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2j.png)


##### Update Node

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2k.png)


![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2l.png)


##### Retrieve Node

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2m.png)


##### Find Node

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2n.png)


##### Display Children

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2s.png)


##### Display Descendants

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2t.png)


##### Traversal PreOrder

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2o.png)


##### Traversal InOrder
![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2p.png)


##### Traversal PostOrder

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2q.png)


##### Karakteristik Node

![240302_00h00m06s_screenshot](https://github.com/Danendra09/231102146_Danendra-Arden-Shaduq/blob/main/pertemuan09/laprak9/ug2r.png)

Program dimulai dengan menginisialisasi pohon sebagai kosong. User kemudian disajikan dengan menu interaktif yang memungkinkan mereka untuk membuat root node, menambah node anak kiri dan kanan, memperbarui data node, mengambil dan mencari node, menampilkan anak-anak dan keturunan dari sebuah node, serta melakukan traversal preorder, inorder, dan postorder. Program juga memiliki fitur untuk menghapus subtree atau seluruh pohon dan menampilkan karakteristik pohon seperti ukuran dan tingginya. Setiap operasi disertai dengan pesan yang menjelaskan status atau hasil dari operasi tersebut. Struktur `Pohon` digunakan untuk merepresentasikan setiap node, yang berisi data, pointer ke anak kiri, anak kanan, dan parent. Proses penambahan, pengambilan, pembaruan, dan pencarian node dilakukan dengan rekursi dan traversal pohon. Program ini ditutup dengan pilihan untuk keluar dari menu.


## Referensi

[1] Blumenthal, D. B., Bougleux, S., Gamper, J., & Brun, L. (2019, May). GEDLIB: A C++ library for graph edit distance computation. In International Workshop on Graph-Based Representations in Pattern Recognition (pp. 14-24). Cham: Springer International Publishing.

[2] Wu, Y., Lu, J., Zhang, Y., & Jin, S. (2021, January). Vulnerability detection in c/c++ source code with graph representation learning. In 2021 IEEE 11th Annual Computing and Communication Workshop and Conference (CCWC) (pp. 1519-1524). IEEE.

[3] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). MIT Press.

[4] Karumanchi, N. (2020). Data Structures and Algorithms Made Easy: Data Structures and Algorithmic Puzzles (6th ed.). Careermonk Publications.




