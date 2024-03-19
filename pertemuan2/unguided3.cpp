// DANENDRA ARDEN SHADUQ - 2311102146
#include <iostream>
#include <climits> // Untuk menggunakan INT_MIN dan INT_MAX
#include <iomanip> // Untuk mengatur presisi output

using namespace std;

int main()
{
    int n_2146;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n_2146;

    int arr[n_2146];

    // Input elemen array
    cout << "Masukkan elemen-elemen array:\n";
    for (int i = 0; i < n_2146; ++i)
    {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    // Menu untuk mencari nilai maksimum, minimum, dan rata-rata
    int pilihan;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Cari nilai maksimum\n";
        cout << "2. Cari nilai minimum\n";
        cout << "3. Cari nilai rata-rata\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan)
        {
        // Case 1: Mencari nilai maksimum dari elemen-elemen array
        case 1:
        {
            int maksimum = INT_MIN; // Inisialisasi nilai maksimum dengan nilai minimum yang mungkin
            // Iterasi melalui array untuk mencari nilai maksimum
            for (int i = 0; i < n_2146; ++i)
            {
                if (arr[i] > maksimum)
                {
                    maksimum = arr[i]; // Jika nilai saat ini lebih besar dari maksimum, update nilai maksimum
                }
            }
            cout << "Nilai maksimum: " << maksimum << endl; // Tampilkan nilai maksimum
            break;
        }

        // Case 2: Mencari nilai minimum dari elemen-elemen array
        case 2:
        {
            int minimum = INT_MAX; // Inisialisasi nilai minimum dengan nilai maksimum yang mungkin
            // Iterasi melalui array untuk mencari nilai minimum
            for (int i = 0; i < n_2146; ++i)
            {
                if (arr[i] < minimum)
                {
                    minimum = arr[i]; // Jika nilai saat ini lebih kecil dari minimum, update nilai minimum
                }
            }
            cout << "Nilai minimum: " << minimum << endl; // Tampilkan nilai minimum
            break;
        }

        // Case 3: Menghitung nilai rata-rata dari elemen-elemen array
        case 3:
        {
            int total = 0; // Inisialisasi variabel untuk total elemen array
            // Iterasi melalui array untuk menjumlahkan semua elemen
            for (int i = 0; i < n_2146; ++i)
            {
                total += arr[i]; // Menambahkan nilai elemen saat ini ke total
            }
            double rata_rata = static_cast<double>(total) / n_2146; // Hitung rata-rata
            cout << "Nilai rata-rata: " << fixed << setprecision(2) << rata_rata << endl; // Tampilkan rata-rata
            break;
        }

        // Case 4: Keluar dari program
        case 4:
            cout << "Terima kasih telah menggunakan program ini.\n"; // Tampilkan pesan keluar
            break;

        default:
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}
