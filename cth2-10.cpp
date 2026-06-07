//Contoh : B-Tree (menggunakan inputan)

#include <iostream>
using namespace std;

struct CanBtree  
{
    int *d;
    CanBtree **CanAnakPointer;
    bool leaf;   
    int n;
} *r = NULL, *np = NULL, *x = NULL;

CanBtree* init()  // membuat simpul
{
    int i;
    np = new CanBtree;
    np->d = new int[6];              
    np->CanAnakPointer = new CanBtree *[7];
    np->n = 0;
    np->leaf = true;               
    for (i = 0; i < 7; i++) {
        np->CanAnakPointer[i] = NULL;
    }
    for (i = 0; i < 6; i++) {       
        np->d[i] = 0;
    }
    return np;
}

void PohonB(CanBtree *p)  // proses BTree
{
    cout << endl;
    int i;
    for (i = 0; i < p->n; i++) {
        if (p->leaf == false) {     
            PohonB(p->CanAnakPointer[i]); 
        }
        cout << " " << p->d[i];
    }
    if (p->leaf == false) {         
        PohonB(p->CanAnakPointer[i]);
    }
    cout << endl;
}

void Urut(int *p, int n)  // pengurutan dengan bubble sort
{
    int i, j, t;
    for (i = 0; i < n; i++) {       
        for (j = i; j <= n; j++) {
            if (p[i] > p[j]) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

int PecahAnak(CanBtree *x, int i)
{
    int j, mid;
    CanBtree *npl, *np3, *y;
    np3 = init();
    np3->leaf = true;                
    if (i == -1) {
        mid = x->d[2];
        x->d[2] = 0;
        x->n--;
    }
    return mid;
}

void Sisip(int a) {
    int i, j, mid, t;              
    CanBtree *npl, *np3, *y;       
    x = r;

    if (x == NULL) {               
        r = init();
        x = r;
        x->d[x->n] = a;          
        x->n++;
    } else {
        while (x->leaf == false) {  
            for (i = 0; i < (x->n); i++) {
                if ((a > x->d[i]) && (a < x->d[i + 1])) {
                    i++;
                    break;
                } else if (a < x->d[0]) {
                    if (x->n == 6) {  // perlu split jika penuh
                        npl = init();
                        npl->leaf = false;  
                        x->leaf = true;     
                        np3 = init();       
                        for (j = 3; j < 6; j++) {
                            np3->d[j - 3] = x->d[j];
                            np3->CanAnakPointer[j - 3] = x->CanAnakPointer[j];
                            np3->n++;
                            x->d[j] = 0;
                            x->n--;
                        }
                        for (j = 0; j < 6; j++) {
                            x->CanAnakPointer[j] = NULL;
                        }
                        mid = x->d[2];     
                        x->d[2] = 0;
                        x->n--;
                        npl->d[0] = mid;
                        npl->CanAnakPointer[npl->n] = x;
                        npl->CanAnakPointer[npl->n + 1] = np3;
                        npl->n++;
                        r = npl;
                        x = npl;
                    }
                    break;
                } else {
                    y = x->CanAnakPointer[i];
                    mid = y->d[2];
                    y->d[2] = 0;
                    y->n--;
                    np3 = init();           
                    for (j = 3; j < 6; j++) { 
                        np3->d[j - 3] = y->d[j];
                        np3->n++;
                        y->d[j] = 0;
                        y->n--;
                    }
                    x->CanAnakPointer[i] = y;   
                    x->CanAnakPointer[i + 1] = np3;
                    break;
                }
            }
            x = x->CanAnakPointer[i]; 
        }
        x->d[x->n] = a;
        Urut(x->d, x->n);
        x->n++;
    }
}

int main() {
    int i, n, t;
    cout << "Masukkan Jumlah Elemen Yang Akan Diinput = ";
    cin >> n;
    cout << endl;
    for (i = 0; i < n; i++) {
        cout << "Masukkan Isi Elemen = ";
        cin >> t;
        Sisip(t);
    }
    cout << endl;
    cout << endl;
    cout << "HASIL PENGURUTAN MENGGUNAKAN BTREE" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    PohonB(r);
    cin.get();              
}