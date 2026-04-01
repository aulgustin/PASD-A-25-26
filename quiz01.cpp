#include <iostream>
#include <string>
using namespace std;

int main()		{
//Deklarasi STRUKTUR
struct ay_BUKU	{
	string ay_judulBuku;
	string ay_pengarang;
	float ay_tahun;
	float ay_harga;	};
//Pendefinisian STRUKTUR
ay_BUKU a_buku;
//Pengaksesan anggota struktur
a_buku.ay_judulBuku = "Laut";
a_buku.ay_pengarang = "Aulya";
a_buku.ay_tahun = 2007;
a_buku.ay_harga = 2000;
cout<<endl;
cout<<endl;
cout<< "Judul Buku	= " << a_buku.ay_judulBuku << endl;
cout<< "Nama Pengarang	= " << a_buku.ay_pengarang << endl;
cout<< "Tahun		= " << a_buku.ay_tahun << endl;
cout<< "Harga		= " << a_buku.ay_harga << endl;
cin.get();		}