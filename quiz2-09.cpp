#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    char INFO;
    struct Node* LEFT;
    struct Node* RIGHT;
};

typedef struct Node Simpul;

Simpul* BuatSimpul(char X) {
    Simpul* P = (Simpul*) malloc(sizeof(Simpul));
    if (P != NULL) {
        P->INFO = X;
        P->LEFT = NULL;
        P->RIGHT = NULL;
    }
    return P;
}

bool isEqual(Simpul* root1, Simpul* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->INFO == root2->INFO) &&
           isEqual(root1->LEFT, root2->LEFT) &&
           isEqual(root1->RIGHT, root2->RIGHT);
}

int main() {
    Simpul* Tree1 = BuatSimpul('X');
    Tree1->LEFT  = BuatSimpul('Y');
    Tree1->RIGHT = BuatSimpul('Z');

    Simpul* Tree2 = BuatSimpul('X');
    Tree2->LEFT  = BuatSimpul('Y');
    Tree2->RIGHT = BuatSimpul('Z');

    cout << "Tahap 1: Pengecekan Awal" << endl;
    if (isEqual(Tree1, Tree2))
        cout << "--> Tree1 dan Tree2 adalah SAMA." << endl;
    else
        cout << "--> Tree1 dan Tree2 BERBEDA." << endl;

    cout << "Menambahkan 'W' ke kiri 'Y' pada Tree1..." << endl;
    Tree1->LEFT->LEFT = BuatSimpul('W');

    cout << "Tahap 2: Pengecekan Setelah Modifikasi" << endl;
    if (isEqual(Tree1, Tree2))
        cout << "--> Tree1 dan Tree2 adalah SAMA." << endl;
    else
        cout << "--> Tree1 dan Tree2 BERBEDA." << endl;

    return 0;
}