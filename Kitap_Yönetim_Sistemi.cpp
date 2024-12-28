#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Kitap Bilgisi Yapısı
struct Kitap {
    string baslik;
    string yazar;
    int yil;
};

// Kitapları Listele
void kitaplariListele(const vector<Kitap>& kitaplar) {
    if (kitaplar.empty()) {
        cout << "Kutuphanede hic kitap yok.\n";
        return;
    }

    cout << "\nKutuphanedeki Kitaplar:\n";
    for (size_t i = 0; i < kitaplar.size(); ++i) {
        cout << i + 1 << ". Baslik: " << kitaplar[i].baslik
            << ", Yazar: " << kitaplar[i].yazar
            << ", Yil: " << kitaplar[i].yil << endl;
    }
}

// Kitap Ekle
void kitapEkle(vector<Kitap>& kitaplar) {
    Kitap yeniKitap;
    cout << "Kitap Basligini Girin: ";
    cin.ignore();
    getline(cin, yeniKitap.baslik);
    cout << "Kitap Yazarini Girin: ";
    getline(cin, yeniKitap.yazar);
    cout << "Kitap Yilini Girin: ";
    cin >> yeniKitap.yil;

    kitaplar.push_back(yeniKitap);
    cout << "Kitap basariyla eklendi.\n";
}

// Kitap Ara
void kitapAra(const vector<Kitap>& kitaplar) {
    string arananBaslik;
    cout << "Aramak istediginiz kitap basligini girin: ";
    cin.ignore();
    getline(cin, arananBaslik);

    for (const auto& kitap : kitaplar) {
        if (kitap.baslik == arananBaslik) {
            cout << "Bulunan Kitap - Baslik: " << kitap.baslik
                << ", Yazar: " << kitap.yazar
                << ", Yil: " << kitap.yil << endl;
            return;
        }
    }
    cout << "Aradiginiz kitap bulunamadi.\n";
}

// Kitap Sil
void kitapSil(vector<Kitap>& kitaplar) {
    int silinecekIndex;
    cout << "Silmek istediginiz kitabin numarasini girin: ";
    cin >> silinecekIndex;

    if (silinecekIndex > 0 && silinecekIndex <= kitaplar.size()) {
        kitaplar.erase(kitaplar.begin() + silinecekIndex - 1);
        cout << "Kitap basariyla silindi.\n";
    }
    else {
        cout << "Gecersiz kitap numarasi.\n";
    }
}

int main() {
    vector<Kitap> kitaplar;
    int secim;

    do {
        cout << "\nKitap Yönetim Sistemi\n";
        cout << "1. Kitaplari Listele\n";
        cout << "2. Kitap Ekle\n";
        cout << "3. Kitap Ara\n";
        cout << "4. Kitap Sil\n";
        cout << "5. Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
        case 1:
            kitaplariListele(kitaplar);
            break;
        case 2:
            kitapEkle(kitaplar);
            break;
        case 3:
            kitapAra(kitaplar);
            break;
        case 4:
            kitapSil(kitaplar);
            break;
        case 5:
            cout << "Cikis yapiliyor...\n";
            break;
        default:
            cout << "Gecersiz secim.\n";
        }
    } while (secim != 5);

    return 0;
}

