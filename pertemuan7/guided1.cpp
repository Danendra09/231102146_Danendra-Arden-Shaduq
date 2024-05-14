#include <iostream>

using namespace std;

const int maksimalAntrian_146 = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (back == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// menambah antrian
void tambahData(string nama)
{
    if (isFull())
    {
        queueTeller[0] = nama;
        front++;
        back++;
    }
    else
    {
        queueTeller[back] = nama;
        back++;
    }
}

// mengurangi antrian
void kurangAntrian()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
        {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

// menghitung banyak antrian
int count()
{
    return back;
}

// menghapus seluruh antrian
void clearQueue()
{
    if (isEmpty())
    {
        cout << "antrian kosong" << endl;
    }
    else
    {
        for (int i = 0; i < back; i++)
            queueTeller[i] = "";
    }
    back = 0;
    front = 0;
}

// melihat antrian
void viewQueue()
{
    cout << "Data antrian: " << endl;
    for (int i = 0; i < maksimalAntrian_146; i++)
    {
        if (queueTeller[i] != "")
        {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        }
        else
        {
            cout << i + 1 << ". " << "antrian kosong" << endl;
        }
    }
}

int main()
{
    tambahData("Andi");
    tambahData("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    kurangAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << count() << endl;
    return 0;
}