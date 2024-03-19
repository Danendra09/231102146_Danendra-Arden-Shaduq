// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
using namespace std;

int main() {
    int n_2146;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n_2146;

    int arr[n_2146];

    // Memasukkan elemen array
    cout << "Masukkan data array:";
    for (int i = 0; i < n_2146; ++i) {
        std::cin >> arr[i];
    }
    // Fungsi untuk mencari bilangan yang genap
    cout << "Bilangan genap: ";
    for (int i = 0; i < n_2146; ++i) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    // Fungsi untuk mencari bilangan yang ganjil
    cout << "Bilangan ganjil: ";
    for (int i = 0; i < n_2146; ++i) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}