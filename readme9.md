# <h1 align="center">Laporan Praktikum Modul 9 Graph dan Three </h1>
<p align="center">Haifa Zahra Azzimmi</p>

## Dasar Teori

A. GRAPH

Graph merupakan representasi suatu permasalahan menggunakan sekumpulan lingkaran (simpul/node) yang dimungkinkan untuk terhubungkan dengan sekumpulan garis (sisi/edge). Dalam konsep dasar graph diketahui bahwa definisi dari graph dan unsur-unsurnya akan disusun dengan menggunakan bahasa himpunan. 

Graph (G) didefinisikan dengan sebuah pasangan himbunan yang terdiri dari himpunan tak kosong dari simpul-simpul yang biasanya disimbolkan dengan (V/vertice), dan himpunan rusuk yang disimbolkan dengan (E/edge). Dimana, baik V/E menghasilkan sepasang simpul pada G. Kemudian, himpulan simpul pada G akan dinotasikan sebagai V, dan himpunan rusuk pada G akan dinotasikan dengan E. Sehingga, akan menghasilkan rumus sebagai berikut G=(V, E).

B. JENIS JENIS GRAPH

Secara umum, graph sendiri digolongkan kedalam dua jenis, yaitu graph sederhana dan graph tidak sederhana

1. Graph Sederhana (Simple Graph)

graph sederhana juga dapat diartikan sebagai graph yang terdiri dari himpunan tak kosong simpul-simpul dan himpunan pasangan tidak terurut yang berbeda yang kemudian disebut sebagai rusuk

2. Graph Tak Sederhana (Unsimple Graph)

graph tak sederhana juga dapat dikelompokkan berdasarkan orientasi arah pada rusuknya. Dimana, orientasi arah tersebut dibagi menjadi dua yaitu graph tak berarah dan graph berarah.
  
   - Graph Tak Berarah (Undirected Graph): merupakan sebuah graph yang rusuknya tidak mempunyai orientasi arah.
   - Graph berarah (Directed Graph): merupakan sebuah graph yang setiap rusuknya mempunyai orientasi arah.[1]

C. THREE

Tree/pohon merupakan struktur data yang tidak linear/non linear yang digunakan terutama untuk merepresentasikan hubungan data yang bersifat hierarkis antara elemenelemennya.
Definisi tree adalah kumpulan elemen yang salah satu elemennya disebut dengan root (akar) dan sisa elemen yang lain disebut sebagai simpul (node/vertex) yang terpecah menjadi sejumlah himpunan yang tidak saling berhubungan satu sama lain, yang disebut subtree/cabang”.

D. Istilah-istilah objek tree, adalah :

1. Simpul adalah elemen tree yang berisi informasi / data dan penunjuk pencabangan.
2. Tingkat/level suatu simpul ditentukan dari akar (root), sebagai level 1. Apabila simpul
dinyatakan sebagai tingkat N, maka simpul-simpul yang merupakan anaknya berada
pada tingkat N+1.
3. Derajat/degree menyatakan banyaknya anak/turunan di simpul tersebut.
Contoh : Simpul A memiliki derajat 2 (B dan C), simpul yang memiliki derajat 0 (nol)
disebut leaf (daun) seperti : I, J, K, L, N, dan O.
4. Tinggi (height) atau kedalaman (depth) suatu tree adalah tingkat maksimum dari tingkat
dalam tree tersebut dikurangi 1.
Contoh dalam tree di atas, mempunyai depth 4.
5. Ancestor suatu simpul adalah semua simpul yang terletak dalam satu jalur dengan
simpul tersebut, dari akar sampai simul yang ditinjaunya.
Contoh Ancestor L adalah A,C dan G.
6.Predecessor adalah simpul yang berada di atas simpul yang ditinjau.
Contoh : Predecessor D adalah B.
7. Successor adalah simpul yang berada di bawah simpul yang ditinjau.
Contoh : Successor D adalah I.
8. Descendant adalah seluruh simpul yang terletak sesudah simpul tertentu dan terletak
pada jalur yang sama.
Contoh : Descendant E adalah J dan K.
9. Sibling adalah simpul-simpul yang memiliki parent yang sama dengan simpul yang
ditinjau.
Contoh : Sibling J adalah K
10. Parent adalah simpul yang berada satu level di atas simpul yang ditinjau.
Contoh : Parent J adalah E

F. Pembentukan Binary Tree berdasarkan Preorder, Inorder atau Postorder

Untuk membentuk suatu binary tree berdasarkan preorder, inorder atau postorder dapat
dilakukan dengan syarat menggunakan 2 dari tiga penelusuran tersebut dan salah satunya
harus inorder.[2]

## Guided 

### 1. [GUIDED 1]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"};

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
        cout << " " << setiosflags(ios::left) << setw(15)
             << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom]
                     << ")";
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

Program ini mendefinisikan sebuah graph dengan 7 simpul yang merepresentasikan beberapa kota dan sebuah matriks busur yang merepresentasikan jarak antar kota. Fungsi `tampilGraph` mencetak setiap simpul beserta koneksinya dengan simpul lain yang memiliki jarak tidak nol. Program ini menampilkan nama kota beserta nama kota yang terhubung dan jaraknya. Di dalam fungsi `main`, program memanggil `tampilGraph` untuk menampilkan graph tersebut.

### 2. [GUIDED 2]

```C++
#include <iostream>
using namespace std;

// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};
// pointer global
Pohon *root;
// Inisialisasi
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child "
                "kiri << node->data << endl";
                return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child'"
                "kanan " << node->data << endl;
                return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
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
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
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
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
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
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
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
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
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
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
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
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}
int main()
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
}

```

Program ini menyediakan berbagai fungsi untuk membangun dan mengelola pohon biner, termasuk penambahan node, penghapusan node, dan penelusuran pohon dengan metode preOrder, inOrder, dan postOrder. 

## Unguided 

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.]

```C++
//Haifa Zahra Azzimmi
//2311102163
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int num_cities;
    int haifa_zahra_azzimmi_2311102163; // NIM
    cout << "Masukkan jumlah kota: ";
    cin >> num_cities;

    vector<string> cities(num_cities);
    cout << "Masukkan nama kota:\n";
    for (int i = 0; i < num_cities; i++) {
        cout << "Kota " << i + 1 << ": ";
        cin >> cities[i];
    }

    vector<vector<int>> distances(num_cities, vector<int>(num_cities, 0));
    cout << "Masukkan jarak antar kota:\n";
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_cities; j++) {
            if (i != j) {
                cout << "Jarak dari " << cities[i] << " ke " << cities[j] << ": ";
                cin >> distances[i][j];
            }
        }
    }

    // Mencetak header untuk matriks jarak antar kota
    cout << "\n    ";
    for (const auto& city : cities) {
        cout << city << "  ";
    }
    cout << endl;

    // Mencetak baris untuk matriks jarak antar kota
    for (int i = 0; i < num_cities; i++) {
        cout << cities[i] << "  ";
        for (int j = 0; j < num_cities; j++) {
            cout << distances[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/8ea60299-ab7e-4340-bd11-43d31eb85080)

Program ini meminta pengguna untuk memasukkan jumlah kota (num_cities) dan nama masing-masing kota.
Program kemudian meminta input untuk jarak antar setiap kota, kecuali jarak dari kota ke dirinya sendiri yang secara otomatis diatur ke 0.
Matriks jarak antar kota dicetak ke layar, dengan header dan baris yang menunjukkan nama kota.


### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!]

```C++
//Haifa Zahra Azzimmi
//2311102163
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    string data;
    vector<TreeNode*> children;

    TreeNode(const string& value) : data(value) {}
};

class Tree {
private:
    TreeNode* root;

public:
    Tree() : root(nullptr) {}

    void insertNode(TreeNode* parent, const string& value) {
        TreeNode* newNode = new TreeNode(value);
        if (!root) {
            root = newNode;
            cout << "Node " << value << " berhasil ditambahkan sebagai root.\n";
        } else {
            parent->children.push_back(newNode);
            cout << "Node " << value << " berhasil ditambahkan sebagai child dari " << parent->data << ".\n";
        }
    }

    void displayChildAndDescendant(TreeNode* node) {
        if (!node) return;

        if (!node->children.empty()) {
            cout << "Node " << node->data << " memiliki child:\n";
            for (TreeNode* child : node->children) {
                cout << child->data << " ";
            }
            cout << endl;
        }

        for (TreeNode* child : node->children) {
            displayChildAndDescendant(child);
        }
    }

    TreeNode* getRoot() const {
        return root;
    }
};

int main() {
    Tree tree;
    TreeNode* parentNode = nullptr;

    int numNodes;
    cout << "Masukkan jumlah node tree: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        string nodeName;
        cout << "Masukkan nama node " << i + 1 << ": ";
        cin >> nodeName;

        if (!tree.getRoot()) {
            tree.insertNode(nullptr, nodeName);
            parentNode = tree.getRoot();
        } else {
            tree.insertNode(parentNode, nodeName);
        }
    }

    cout << "\nTree yang telah dibuat:\n";
    tree.displayChildAndDescendant(tree.getRoot());

    return 0;
}

```
### Output
![image](https://github.com/Haifazahraa/Struktur-Data-Assigment/assets/162522762/ea1131f5-30f1-437f-ad66-3e9adb0d225f)

Program ini memungkinkan pengguna untuk memasukkan data tree sesuai dengan jumlah node yang diinginkan.
Setiap node memiliki nama yang dimasukkan oleh pengguna.
Program menampilkan struktur tree yang telah dibuat, beserta child dan descendant dari setiap node.
Fungsi displayChildAndDescendant ditambahkan untuk menampilkan informasi tentang child dan descendant dari sebuah node. Program ini memanfaatkan struktur data tree untuk mengelola hubungan antara node-node dalam tree yang dibuat oleh pengguna.


### Kesimpulan 
1. Dengan demikian, dapat disimpulkan bahwa graph G merupakan sebuah pasangan himpunan yang mana di dalamnya akan terdiri dari himpunan tak kosong dan himpunan rusuk yang keduanya kemudian disimbolkan dengan (V dan E).
2. Tree atau pohon adalah struktur data non-linear yang merepresentasikan hubungan hierarkis antar elemen dengan satu elemen sebagai root dan sisanya sebagai simpul. Setiap simpul berisi data dan penunjuk cabang, memiliki tingkat yang dihitung dari akar, derajat yang menyatakan jumlah anak, dan ketinggian yang merupakan tingkat maksimum dikurangi satu. Istilah-istilah terkait termasuk ancestor, predecessor, successor, descendant


### Referensi

[1]https://d1wqtxts1xzle7.cloudfront.net/78496908/TEKNIK_GRAPH-libre.pdf?1641894849=&response-content-disposition=inline%3B+filename%3DTEKNIK_GRAPH.pdf&Expires=1716981293&Signature=KtwioGEGblyaS~0PUI4tH663YplYfnCgWaSJvhznFdVjI0IP-SRliLAYlYuFAlkirdV19EwM~-vy1k8AJDmbRfsjXRRapXEJ8R5Z0FHm4bgzOKSXESDADJaOBWvFePQvyNIYOsIQQVco8EPFTGEXmXlZAVtEe530E9FQsp5inUIvXHIJ0enZ4aPLgLPtEoqjf6UVX23ZFNrUlE1QKs8AjspXQvW4evIw-aOGyKeigGEcFn2E8C0kwbOytDR7uMnPiOweo7FrKGNE~h7wiii5H54dKrYWFifiJvsduYqYh1aer2tsxZLRDvq3LJycEn1BmPTEJqu9fPLtS~68vnzVSg__&Key-Pair-Id=APKAJLOHF5GGSLRBV4ZA

[2]https://repository.unikom.ac.id/46090/1/TREE.pdf
