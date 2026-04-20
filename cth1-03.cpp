#include <iostream>
#include <string>
using namespace std;

//1. Deklarasi struktur data nilai MK
typedef struct	{
	string npm;
	string nama_mhs;
	double nilai;
}	NilaiMK;

//2. Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm	{
	NilaiMK kontainer;
	alamatelm next;
}	elemen;

//3. Deklarasi struktur stack
typedef struct	{
	elemen* top;
}	stack;

//4. Deklarsai fungsi membuat stack kosong
void buatSTkosong(stack *S)	{
	(*S).top = NULL;
}

//5. Deklarasi fungsi membuat stack kosong
int isKosong(stack S)	{
	bool hasil = false;
	
	if(S.top == NULL)	{
	 hasil = true;
	 }
	 return hasil;
}

//6. Deklarasi fungsi menghitung jumlah elemen stack
int jmlElemen(stack S)	{
	int hasil = 0;
	
	if(S.top != NULL)	{
	//Kondisi stack tidak kosong
	elemen *bantu;
	//Inisialisasi
	bantu = S.top;
	
	while(bantu != NULL)	{
		hasil = hasil + 1;
		//Interaksi
		bantu = bantu -> next;
		}
	}
	return hasil;
}
	
//7. Deklarasi fungsi memasukkan elemen ke dalam stack
void push(string npm, string nama_mhs, double nilai, stack *S)	{
	elemen *info;
	info = new elemen;
	info -> kontainer.npm = npm;
	info -> kontainer.nama_mhs = nama_mhs;
	info -> kontainer.nilai = nilai;
	
	if((*S).top == NULL)	{
		cout << "Stack Penuh" << endl;
		//jika stack kosong
		info -> next = NULL;
		}
	else	{
		//jika stack tidak kosong
		info -> next = (*S).top;
		}
	(*S).top = info;
	info = NULL;
}

//8. Deklarasi fungsi mengeluarkan elemen keluar stack 
void Pop(stack *S)	{
	if((*S).top != NULL)	{
	//jika list bukan stack kosong
	elemen *hapus = (*S).top;
	
	if(jmlElemen(*S) == 1)	{
		//jika stack tidak kosong
		(*S).top = NULL;
		}
	else	{
		(*S).top = (*S).top -> next;
	}
	hapus -> next = NULL;
	delete hapus;
	}
 else	{
	cout << "Stack Kosong" << endl;
 }
}

//9. Deklarasi fungsi menampilkan isi stack
void CetakStack(stack S)
{
	if(S.top != NULL)
	{
		cout << "	MENAMPILKAN STACK	" << endl;
		elemen *bantu = S.top;
		int i = 1;
		while(bantu != NULL)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Elemen ke		: " << i << endl;
			cout << "Nomor Pokok Mahasiswa	: " << bantu -> kontainer.npm << endl;
			cout << "Nama Mahasiswa		: " << bantu -> kontainer.nama_mhs << endl;
			cout << "Nilai Mahasiswa		: " << bantu -> kontainer.nilai << endl;
		//iterasi
		bantu = bantu -> next;
		i = i + 1;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	else	
		{
			cout << "Stack Kosong" << endl;
		}
}

//Menu Utama
int main()	{
	stack S;
	
	buatSTkosong(&S);
	CetakStack(S);
	cout << endl;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	push("4523210666", "Budi", 88.75, &S);
	push("4523210777", "Susi", 78.85, &S);
	push("4523210888", "Nuri", 98.65, &S);
	push("4523210999", "Bimo", 68.55, &S);
	push("4523210555", "Arif", 78.85, &S);
	push("4253210444", "Rido", 98.65, &S);
	push("4523210222", "Ella", 68.55, &S);
	CetakStack(S);
	cout << "====================" << endl;
	cout << endl;
	cout << endl;
	Pop(&S);
	CetakStack(S);
	cout << endl;
	cout << endl;
	Pop(&S);
	CetakStack(S);
	cout << "====================" << endl;
	return 0;
}