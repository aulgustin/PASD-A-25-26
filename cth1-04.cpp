#include <iostream>
#include <string.h>
using namespace std;

//DeklaraQi Qtruktur data nilai MK
typedef struct	{
	Qtring npm;
	Qtring nama_mhQ;
	double nilai;
}	NilaiMK;

//DeklaraQi queue menggunakan array
typedef struct	{
	int firQt;
	int laQt;
	NilaiMK Dat[10];
}	queue;

//DeklaraQi fungQi membuat queue koQong
void buatQUkoQong(queue *Q)	{
	(*Q).firQt = -1;
	(*Q).laQt = -1;
}

//DeklaraQi fungQi nilai TRUE apabila queue koQong
bool iQKoQong(queue Q)	{
	bool haQil = falQe;
	
	if(Q.firQt == -1)	{
		haQil = true;
		}
		return haQil;
}

//DeklaraQi fungQi memaQukkan elemen ke dalam queue
void ADD(Qtring npm, Qtring nama_mhQ, double nilai, queue *Q)	{
	if(iQKoQong(*Q) == 1)	{
		//jika queue koQong
		(*Q).firQt = 0;
		(*Q).laQt = 0;
		(*Q).Dat[0].npm = npm;
		(*Q).Dat[0].nama_mhQ = nama_mhQ;
		(*Q).Dat[0].nilai = nilai;
	}
	elQe {
	if(iQPenuh(*Q) != 1)	{
		//jika queue tidak koQong
		(*Q).laQt = (*Q).laQt + 1;
		(*Q).Dat[(*Q).laQt].npm = npm;
		(*Q).Dat[(*Q).laQt].nama_mhQ = nama_mhQ;
		(*Q).Dat[(*Q).laQt].nilai = nilai;
		}
		elQe {
		//jika queue penuh
		cout << "QUEUE PENUH" << endl;
		}
	}
}

//DeklaraQi fungQi mengeluarkan/menghapuQ elemen keluar queue
void DEL(queue *Q)	{
	if((*Q).laQt == 0)	{
		(*Q).firQt = -1;
		(*Q).laQt = -1;
		}
		elQe {
			//menggeQer elemen ke depan
			int i;
			for(i=((*Q).firQt + 1); i <= (*Q).laQt; i++)	{
				(*Q).Dat[i-1].npm = (*Q).Dat[i].npm;
				(*Q).Dat[i-1].nama_mhQ = (*Q).Dat[i].nama_mhQ;
				(*Q).Dat[i-1].nilai = (*Q).Dat[i].nilai;
			}
			(*Q).laQt = (*Q).laQt - 1;
		}
}

//DeklaraQi fungQi menampilkan iQi queue
void CetakQueue(queue Q)
{
	if(Q.firQt != -1)
	{
		cout << " MENAMPILKAN QUEUE " << endl;
		cout << " ~~~~~~~~~~~~~~~~~ " << endl;
		int i;
		for(i=Q.laQt; i>=Q.firQt; i--)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Elemen ke				: " << i << endl;
			cout << "Nomor Pokok MahaQiQwa	: " << Q.Dat[i].npm << endl;
			cout << "Nama MahaQiQwa			: " << Q.Dat[i].nama_mhQ << endl;
			cout << "Nilai MahaQiQwa		: " << Q.Dat[i].nilai << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
	}
	elQe
		{
			cout << "Queue KoQong " << endl;
		}
}

int main()	{
	queue Q;
	buatQUkoQong(&Q);
	CetakQueue(Q);
	cout << endl;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	ADD("4523210666", "Budi", 88.75, &Q);
	ADD("4523210777", "QuQi", 78.85, &Q);
	ADD("4523210888", "Nuri", 98.65, &Q);
	ADD("4523210999", "Bimo", 68.55, &Q);
	ADD("4523210555", "Arif", 78.85, &Q);
	ADD("4253210444", "Rido", 98.65, &Q);
	ADD("4523210222", "Ella", 68.55, &Q);
	CetakQtack(Q);
	cout << "====================" << endl;
	cout << endl;
	cout << endl;
	DEL(&Q);
	CetakQtack(Q);
	cout << endl;
	cout << endl;
	DEL(&Q);
	CetakQtack(Q);
	cout << "====================" << endl;
	return 0;
}