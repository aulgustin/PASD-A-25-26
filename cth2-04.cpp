#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

struct biodata	{
	char nama[20];
	int usia;
};
struct biodata mhs;
struct biodata queue[MAX];
void init(void);
int full(void);
int empty(void);
struct biodata entridata(void);
void enqueue(struct biodata mhs);
struct biodata dequeue(void);
void display(struct biodata mhs);
void baca(void);
int awal,akhir;
char nocomment[10];

int main()	{
char  pilih;
cout << "== Program Entri Data Mahasiswa ==" << endl;
init();
do	{
	cout << "MENU PILIHAN : " << endl;
	cout << "1. Input Data" << endl;
	cout << "2. Hapus Data" << endl;
	cout << "3. Lihat Daftar Mahasiswa" << endl;
	cout << "4. Hapus Semua Data" << endl;
} while(pilih != '5');
return 0;	}

void init(void)	{
	awal = -1;
	akhir = -1;
}

void enqueue(struct biodata mhs)	{
	if(empty() == true)	{
		awal = 0;
		akhir = 0;
		queue[awal] = mhs;
	} else if(full() != true)	{
		akhir++;
		queue[akhir] = mhs;
	} else 
		cout << "Queue sudah penuh..." << endl;
}

struct biodata dequeue(void)	{
	int i;
	if(empty() != true)	{
		mhs = queue[awal];
		for(i=awal; i<=akhir; i++)
			queue[i] = queue[i+1];
		akhir--;
		return(mhs);
	} else
		cout << "Queue kosong..." << endl;
}

int full(void)	{
	if(akhir == MAX -1) return(true);
	else return(false);
}

int empty(void)	{
	if(akhir == -1) return(true);
	else return(false);
}

void baca(void)	{
	int i;
	cout << "Isi Queue : " << endl;
	if(empty() != true)	{
		for(i=awal; i<=akhir; i++)	{
			display(queue[i]);
		}
	} else 
		cout << "Data kosong" << endl;
		cout << endl;
}

struct biodata entridata(void)	{
	struct biodata mhs;
		cout << endl;
		cout << "Masukkan Nama	: "; cin >> mhs.nama;
		cout << "Masukkan Usia	: "; cin >> mhs.usia;
		return(mhs);
}

void display(struct biodata mhs)	{
	int pilih;
	cout << endl;
	cout << "Nama	: " << mhs.nama << endl;
	cout << "Usia	: " << mhs.usia << endl;
	cout << "5. Selesai" << endl;
	cout << "Pilih 1 sd 5 : " << endl;
	cin >> pilih;
	switch(pilih)	{
		case '1' : mhs = entridata(); enqueue(mhs); break;
		case '2' : cout << "Data yang dihapus : " << endl;
				mhs = dequeue(); display(mhs); break;
		case '3' : baca(); break;
		case '4' : init(); cout << "Data telah dikosongkan" << endl;
				break;
		case '5' : break;
		default : cout << "Pilih 1 sd 5!" << endl;
				break;
	}
	cout << endl;
}