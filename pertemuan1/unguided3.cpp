#include <iostream>
#include <map>//library supaya bisa menggunakan fungsi map

using namespace std;
int main() {
    //Membuat map dengan key bertipe string dan value bertipe int
    map<string, int> nilai_2146;

    // Menambahkan data ke dalam map
    nilai_2146["Zoe"] = 85;
    nilai_2146["Samuel"] = 90;
    nilai_2146["Eli"] = 75;
    nilai_2146["Peter"] = 88;

    //Menampilkan nilai_2146 dari setiap elemen dalam map
    cout << "nilai Zoe: " << nilai_2146["Zoe"] << endl;
    cout << "nilai Samuel: " << nilai_2146["Samuel"] << endl;
    cout << "nilai Eli: " << nilai_2146["Eli"] << endl;
    cout << "nilai Peter: " << nilai_2146["Peter"] << endl;

    return 0;
}
