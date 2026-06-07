//Contoh : B-Tree Sisip (tanpa inputan)

#include <iostream>
using namespace std;

// Membuat Node
class BTreeNode {
    int *Kunci, t, n;
    bool leaf;
    BTreeNode **c;

public:
    BTreeNode(int tt, bool _leaf); // konstruktor
    void SisipTdkPenuh(int k);
    void SplitAnak(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k);
    friend class BTree;
};

// BTree
class BTree {
    int t;
    BTreeNode *root;

public:
    BTree(int tt) {
        root = NULL;
        t = tt;
    }
    void traverse() {
        if (root != NULL) root->traverse();
    }
    BTreeNode *search(int k) {
        return (root == NULL) ? NULL : root->search(k);
    }
    void Sisip(int k);
}; 

// Konstruktor untuk kelas BTreeNode
BTreeNode::BTreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
    Kunci = new int[2 * t - 1];
    c = new BTreeNode *[2 * t];
    n = 0;
}

// Fungsi untuk melintasi semua node dalam subpohon yang di-root
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (leaf == false)
            c[i]->traverse();
        cout << " " << Kunci[i];
    }
    if (leaf == false)
        c[i]->traverse();
}

// Fungsi untuk mencari kunci k pada subpohon yang di-root
BTreeNode *BTreeNode::search(int k) {
    int i = 0;
    while (i < n && k > Kunci[i])
        i++; 

    if (Kunci[i] == k)
        return this;
    if (leaf == true)
        return NULL;
    return c[i]->search(k);
}

// Fungsi menyisipkan kunci baru di B-Tree
void BTree::Sisip(int k) {
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->Kunci[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2 * t - 1) {
            BTreeNode *s = new BTreeNode(t, false);
            s->c[0] = root;
            s->SplitAnak(0, root);
            int i = 0; 
            if (s->Kunci[0] < k)
                i++;
            s->c[i]->SisipTdkPenuh(k);
            root = s; 
        } else
            root->SisipTdkPenuh(k);
    }
}

// Fungsi sisip
void BTreeNode::SisipTdkPenuh(int k) {
    int i = n - 1;
    if (leaf == true) {
        while (i >= 0 && Kunci[i] > k) {
            Kunci[i + 1] = Kunci[i];
            i--;
        }
        Kunci[i + 1] = k; 
        n = n + 1;         
    } else {
        while (i >= 0 && Kunci[i] > k)
            i--;
        if (c[i + 1]->n == 2 * t - 1) {
            SplitAnak(i + 1, c[i + 1]);
            if (Kunci[i + 1] < k)
                i++;
        }
        c[i + 1]->SisipTdkPenuh(k);
    }
}

// Fungsi split Anak
void BTreeNode::SplitAnak(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->Kunci[j] = y->Kunci[j + t]; 

    if (y->leaf == false)               
        for (int j = 0; j < t; j++)
            z->c[j] = y->c[j + t];

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--) 
        c[j + 1] = c[j];
    c[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        Kunci[j + 1] = Kunci[j];
    Kunci[i] = y->Kunci[t - 1];
    n = n + 1;
}

// Menu utama
int main() {
    BTree t(5); // A B-Tree with minimum degree 5
    t.Sisip(40);
    t.Sisip(49);
    t.Sisip(7);
    t.Sisip(89);
    t.Sisip(20);
    t.Sisip(66);
    t.Sisip(71);
    t.Sisip(75);
    t.Sisip(31);
    t.Sisip(56);
    t.Sisip(61);

	cout << " ----------------------------------- " << endl;
    cout << "   Pohon dengan menggunakan B-Tree   " << endl;
    cout << " ------------- m = 5 --------------- " << endl;
    cout << " ----------------------------------- " << endl;
    t.traverse();
    cout << endl;

	cout << endl;
    int k = 7;
    (t.search(k) != NULL) ? cout << "Kunci yang dicari " << k << " = Ditemukan" : cout << "Kunci yang dicari " << k << " = Tidak Ditemukan";
    cout << endl << endl;

    k = 15;
    (t.search(k) != NULL) ? cout << "Kunci yang dicari " << k << " = Ditemukan" : cout << "Kunci yang dicari " << k << " = Tidak Ditemukan";

    cin.get();
    return 0;
}