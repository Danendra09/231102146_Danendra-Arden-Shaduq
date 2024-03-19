// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
using namespace std;

int main() {
    int dimensi1, dimensi2, dimensi3;

    // Meminta pengguna untuk memasukkan ukuran array tiga dimensi
    cout << "Masukkan ukuran array tiga dimensi:\n";
    cout << "Dimensi 1: ";
    cin >> dimensi1;
    cout << "Dimensi 2: ";
    cin >> dimensi2;
    cout << "Dimensi 3: ";
    cin >> dimensi3;

    // Deklarasi array
    int arr[dimensi1][dimensi2][dimensi3];

    // Input elemen
    for (int x = 0; x < dimensi1; x++) {
        for (int y = 0; y < dimensi2; y++) {
            for (int z = 0; z < dimensi3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output Array
    for (int x = 0; x < dimensi1; x++) {
        for (int y = 0; y < dimensi2; y++) {
            for (int z = 0; z < dimensi3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z
                     << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;

    // Tampilan array
    for (int x = 0; x < dimensi1; x++) {
        for (int y = 0; y < dimensi2; y++) {
            for (int z = 0; z < dimensi3; z++) {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
