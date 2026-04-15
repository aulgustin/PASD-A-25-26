#include <iostream>
using namespace std;

//Pendeklarasian tipe data baru struct Mahasiswa
class Barang{
		public:
		char kodeBarang[9];
		char namaBarang[30];
		float harga;
		};
int main()	{
		//Buat variabel mhs bertipe data Mahasiswa
		Barang a_brg;
		cout << "=== FORM INPUT BARANG ===" << endl;
		cout << "Masukkan Kode Barang		= "; cin >> a_brg.kodeBarang;
		cout << "Masukkan Nama Barang		= "; cin >> a_brg.namaBarang;
		cout << "Masukkan Harga Barang		= "; cin >> a_brg.harga;
		cout << endl;
		cout << "===================================================" << endl;
		cout << "		DATA BARANG YANG TERSIMPAN " << endl;
		cout << "===================================================" << endl;
		cout << "Kode Barang	= " << a_brg.kodeBarang << endl;
		cout << "Nama Barang	= " << a_brg.namaBarang << endl;
		cout << "Harga Barang 	= " << a_brg.harga << endl;
		cin.get();
}