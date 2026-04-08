#include <iostream>
using namespace std;

//Pendeklarasian tipe data baru struct Mahasiswa
struct Mahasiswa{
		char NPM[9];
		char nama[30];
		float ipk;
		};
int main()	{
		//Buat variabel mhs bertipe data Mahasiswa
		Mahasiswa mhs;
		cout << "Nomor Pokok Mahasiswa		= "; cin >> mhs.NPM;
		cout << "Nama Mahasiswa 			= "; cin >> mhs.nama;
		cout << "Indeks Prestasi Kumulatif	= "; cin >> mhs.ipk;
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "					Data Anda " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Nomor Pokok Mahasiswa		= " << mhs.NPM << endl;
		cout << "Nama Mahasiswa				= " << mhs.nama << endl;
		cout << "Indeks Prestasi Kumulatif 	= " << mhs.ipk << endl;
		cin.get();
}