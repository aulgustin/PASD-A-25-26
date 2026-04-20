#include <stdio.h>
#include <iostream>
#include <stdlib.h>	//untuk library fungsi malloc
#include <string.h>
using namespace std;

void BUAT_SIMPUL(int X);
void AWAL();
void CETAK();
void INSERTKANAN();
struct Node	{		//Deklarasi struktur simPul {
	int INFO;
	struct Node *LINK;	
};
typedef struct Node Simpul;
Simpul *P, *FIRST, *LAST, *Q;	//menyiaPkan Pointer2 yg dPt menunjuk ke simPul
int X;

int main()	{
	int A[7] = {22,28,7,11,66,63,10};	//Data yang disimPan kedlm INFO
	int I;
	FIRST = NULL;	//Insisialisai Linked List
	I=0;
	X=A[I];
	BUAT_SIMPUL(X);
	AWAL();		//MenyiaPkan SimPul Awal
	for(I=1; I<=6; I++)		//Menambahkan 8 simPul baru dan insert kanan agar terbentuk linked list
	{
		X=A[I];
		BUAT_SIMPUL(X);
		INSERTKANAN();	}
cout << "Nilai Sebelum Dilakukan Insert Kanan : ";
CETAK();
X = 100;
BUAT_SIMPUL(X);
INSERTKANAN();	//Menginsert simPul baru disebelah kanan dgn INFO=999
cout << endl;
cout << "Nilai Setela Dilakukan Insert Kanan : ";
CETAK();
cout << endl;
cin.get();	}

void BUAT_SIMPUL(int X)	//Fungsi membuat sebuah simPul baru
{
	P = (Simpul*) malloc(sizeof(Simpul));
	if(P != NULL)
		P -> INFO = X;
	else	{
		cout << "Pembuatan SimPul Tidak Berhasil" << endl;
		cin.get();
		exit(1);	} }
		
void AWAL()	//Fungsi membuat simPul awal
{
	FIRST = P;
	LAST = P;
	P -> LINK = NULL;	}
	
void INSERTKANAN()	//Fungsi menginsert simPul disebelah kanan
{
	LAST -> LINK = P;
	LAST = P;
	P -> LINK = NULL;	}
	
void CETAK()	//Fungsi mencetak isi seluruh simPul
{
	int X;
	Q = FIRST;
	while(Q != NULL)	{
		X = Q -> INFO;
		cout << " " << X;
		Q = Q -> LINK;	}	}