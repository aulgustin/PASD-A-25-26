#include <iostream>
#include <string>
using namespace std;

//1. Deklarasi struktur data jumlah_stok MK
typedef struct	{
	string kode_barang;
	string nama_barang;
	int jumlah_stok;
}	DataBarang;

//2. Deklarasi struktur elemen
typedef struct elm *alamatelm;
typedef struct elm	{
	DataBarang Kontainer;
	alamatelm next;
} elemen;

//3. Deklarasi struktur queue
typedef struct	{
	elemen *first;
	elemen *last;
}	queue;

//4. Deklarasi fungsi membuat queue kosong
void buatQUKosong(queue *Q)	{
	(*Q).first = NULL;
	(*Q).last = NULL;
}

//5. Deklarasi fungsi membuat queue kosong
int isKosong(queue Q)	{
	bool hasil = false;
	
	if(Q.first == NULL)	{
		hasil = true;
		}
		return hasil;
}

//6. Deklarsi fungsi menghitung jumlah elemen queue
int jmlElemen(queue Q)	{
	int hasil = 0;
	
	if(Q.first != NULL)	{
		//kondisi queue tidak kosong
		elemen *bantu;
		//inisialisasi
		bantu = Q.first;
		
		while(bantu != NULL)	{
			hasil = hasil + 1;
			//interasi
			bantu = bantu -> next;
			}
		}
		return hasil;
}

//7. Deklarasi fungsi memasukkan elemen ke dalam queue
void add(string kode_barang, string nama_barang, int jumlah_stok, queue *Q)	{
	elemen *info;
	info = new elemen;
	info -> Kontainer.kode_barang = kode_barang;
	info -> Kontainer.nama_barang = nama_barang;
	info -> Kontainer.jumlah_stok = jumlah_stok;
	info -> next = NULL;
	
	if((*Q).first == NULL)	{
		(*Q).first = info;
		}
	else	{
		(*Q).last -> next = info;
		}
	(*Q).last = info;
	info = NULL;
}

//8. Deklarasi fungsi mengeluarkan elemen keluar queue
void del(queue *Q)	{
	if((*Q).first != NULL)	{
		//jika queue bukan queue kosong
		elemen *hapus = (*Q).first;
		
		if(jmlElemen(*Q) == 1)	{
			(*Q).first = NULL;
			(*Q).last = NULL;
			}
		else	{
			(*Q).first = (*Q).first -> next;
			hapus -> next = NULL;
		}
		delete hapus;
		}
}

//9. Deklarasi fungsi menampilkan isi queue
void CetakQueue(queue Q)
{
	if(Q.first != NULL)
	{
		cout << "	MENAMPILKAN QUEUE " << endl;
		elemen *bantu = Q.first;
		int i = 1;
		while(bantu != NULL)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Elemen ke		: " << i << endl;
			cout << "Kode Barang	: " << bantu -> Kontainer.kode_barang << endl;
			cout << "Nama Barang	: " << bantu -> Kontainer.nama_barang << endl;
			cout << "Jumlah stok		: " << bantu -> Kontainer.jumlah_stok << endl;
		//iterasi
		bantu = bantu -> next;
		i = i + 1;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	else
		{
			cout << "Queue Kosong " << endl;
		}
}

int main()	{
	queue Q;
	buatQUKosong(&Q);
	CetakQueue(Q);
	cout << endl;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	add("4523210666", "Budi", 88.75, &Q);
	add("4523210777", "Susi", 78.85, &Q);
	add("4523210888", "Nuri", 98.65, &Q);
	add("4523210999", "Bimo", 68.55, &Q);
	add("4523210555", "Arif", 78.85, &Q);
	add("4253210444", "Rido", 98.65, &Q);
	add("4523210222", "Ella", 68.55, &Q);
	CetakQueue(Q);
	cout << "====================" << endl;
	cout << endl;
	cout << endl;
	del(&Q);
	CetakQueue(Q);
	cout << endl;
	cout << endl;
	del(&Q);
	CetakQueue(Q);
	cout << "====================" << endl;
	return 0;
}