#include <iostream>
#include <cmath>//Library yang menyediakan berbagai fungsi matematika yang sering digunakan.
using namespace std;

//Fungsi untuk menghitung perpangkatan
double perpangkatan(double basis,int pangkat)//double -> bilangan desimal, int -> bilangan bulat
{
    return pow(basis, pangkat);//pow() -> fungsi untuk memangkatkan
}

//Fungsi untuk menghitung akar
double akarKuadrat(double angka)
{
    return sqrt(angka);//sqrt() -> "square root" digunakan untuk menghitung akar kuadrat dari sebuah bilangan
}
// Fungsi untuk memeriksa apakah suatu angka adalah bilangan prima
bool prima(int angka)//bool -> tipe data yang hanya memiliki dua nilai yaitu true dan false.
{
    if (angka <= 1) return false;//Memeriksa apakah angka kurang dari atau sama dengan 1
    if (angka <= 3) return true;//Memeriksa apakah angka kurang dari atau sama dengan 3
    if (angka % 2 == 0 || angka % 3 == 0) return false;//Memeriksa apakah angka merupakan kelipatan dari 2 atau 3
    for (int i = 5; i * i <= angka; i += 6)//Memeriksa untuk faktor-faktor lain yang bukan kelipatan dari 2 atau 3
    {
        if (angka % i == 0 || angka % (i + 2) == 0) return false;
    }
    //Jika tidak ada faktor selain 1 dan angka itu sendiri, maka angka adalah bilangan prima
    return true;
}

int main() {
    char pilihan;
    int pangkat, angka;

    do {
        cout << "Pilih operasi yang ingin Anda lakukan:";
        cout << "\na. Perpangkatan";
        cout << "\nb. Akar";
        cout << "\nc. Identifikasi bilangan prima";
        cout << "\nd. Keluar";
        cout << "\nPilihan Anda: ";
        cin >> pilihan;

        switch (toupper(pilihan))//toupper() -> fungsi untuk mengubah karakter ke kapital
        {
            case 'A':
                double basis;
                cout << "Masukkan angka yang dipangkatkan: ";
                cin >> basis;
                cout << "Masukkan pangkat: ";
                cin >> pangkat;
                cout << "Hasil perpangkatan: " << perpangkatan(basis, pangkat) << endl;
                break;
            case 'B':
                cout << "Masukkan angka: ";
                cin >> angka;
                cout << "Akar kuadrat dari " << angka << " adalah: " << akarKuadrat(angka) << endl;
                break;
            case 'C':
                cout << "Masukkan angka: ";
                cin >> angka;
                if (prima(angka))
                    cout << angka << " adalah bilangan prima." << endl;
                else
                    cout << angka << " bukan bilangan prima." << endl;
                break;
            case 'D':
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (toupper(pilihan) != 'D');// jika tidak menginput 'D' atau 'd' maka terus berulang

    return 0;
}
