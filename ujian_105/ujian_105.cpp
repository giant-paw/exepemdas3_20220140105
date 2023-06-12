#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x;                                               // variable untuk menyimpan input dari lingkaran maupun bujursangkar
public:
    bidangDatar() {                                     // constructor
        x = 0;
    }

    virtual void input() {}                             // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x

    virtual float Luas(int a) { return 0; }             // fungsi untuk menghitung luas

    virtual float Keliling(int a) { return 0; }         // fungsi untuk menghitung keliling

    void setX(int a) {                                  // fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }

    int getX() {                                        // fungsi untuk membaca atau mengambil nilai dalam x
        return x;
    }
};

class Bujursangkar : public bidangDatar {
public:
    void input() {
        int sisi;
        cout << "\nMasukkan Panjang Sisi Bujur Sangkar :";
        cin >> sisi;
        setX(sisi);
    }

    float Luas(int sisi) {
        return sisi * sisi;
    }

    float Keliling(int sisi) {
        return 4 * sisi;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        int jari2;
        cout << "\nMasukkan jari-jari lingkaran: ";
        cin >> jari2;
        setX(jari2);
    }

    float Luas(int jari2) {
        return 3.14 * jari2 * jari2;
    }

    float Keliling(int jari2) {
        return 2 * 3.14 * jari2;
    }
};

int main() {
    bidangDatar* benda;
    Lingkaran lingkaran;
    Bujursangkar bujursngkr;

    int inputan;
    cout << "Pilih Jenis Bangun Datar : " << endl;
    cout << "1. Bujur Sangkar " << endl;
    cout << "2. Lingkaran " << endl;
    cout << "\nMasukkan pilihan ( 1 Atau 2 ) : ";
    cin >> inputan;

    switch (inputan)
    {
    case 1 :
            benda = &bujursngkr;
            benda->input();

            cout << "\n====================================================\n";
            cout << "Luas Dari Bujur Sangkar Adalah : " << benda->Luas(benda->getX()) << endl;
            cout << "Keliling Dari Bujur Sangkar Adalah : " << benda->Keliling(benda->getX()) << endl;
            cout << "====================================================";
        
        
        break;

    case 2:
            benda = &lingkaran;
            benda->input();

            cout << "\n====================================================\n";
            cout << "Luas Dari lingkaran Adalah : " << benda->Luas(benda->getX()) << endl;
            cout << "Keliling Dari lingkaran Adalah: " << benda->Keliling(benda->getX()) << endl;
            cout << "====================================================";

            break;

    default:
        cout << "Pilihan Salah !!";
        break;
    }

    return 0;
}