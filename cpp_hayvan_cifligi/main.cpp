#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Hayvan {
protected:
    string tur;
    string isim;
    int yas;

public:
    Hayvan(const string& tur, const string& isim, int yas)
        : tur(tur), isim(isim), yas(yas) {}

    virtual void besle() const = 0;

    string getTur() const {
        return tur;
    }

    string getIsim() const {
        return isim;
    }

    void setIsim(const string& yeniIsim) {
        isim = yeniIsim;
    }

    int getYas() const {
        return yas;
    }

    void setYas(int yeniYas) {
        yas = yeniYas;
    }
};

class Aslan : public Hayvan {
public:
    Aslan(const string& tur, const string& isim, int yas)
        : Hayvan(tur, isim, yas) {}

    void besle() const override {
        cout << "Aslan " << getIsim() << " et ile beslendi." << endl;
    }
};

class Zebra : public Hayvan {
public:
    Zebra(const string& tur, const string& isim, int yas)
        : Hayvan(tur, isim, yas) {}

    void besle() const override {
        cout << "Zebra " << getIsim() << " ot ile beslendi." << endl;
    }
};

class Kartal : public Hayvan {
public:
    Kartal(const string& tur, const string& isim, int yas)
        : Hayvan(tur, isim, yas) {}

    void besle() const override {
        cout << "Kartal " << getIsim() << " et ile beslendi." << endl;
    }
};

class HayvanatBahcesi {
private:
    vector<Hayvan*> hayvanlar;

public:
    void hayvanlariGoster() {
        cout << "----------Hayvanlar---------" << endl;
        if (hayvanlar.empty()) {
            cout << "Hayvan bulunamadı." << endl;
            return;
        }

        for (const auto& hayvan : hayvanlar) {
            cout << "Tür: " << hayvan->getTur() << "\nİsim: " << hayvan->getIsim() << "\nYaş: " << hayvan->getYas() << endl;
        }
    }

    void hayvanEkle(Hayvan* hayvan) {
        hayvanlar.push_back(hayvan);
        cout << "Hayvan eklendi." << endl;
    }

    void hayvanSil() {
        if (hayvanlar.empty()) {
            cout << "Silinecek hayvan bulunamadı." << endl;
            return;
        }

        int indeks;
        cout << "Silinecek hayvanın indeksini girin: ";
        cin >> indeks;

        if (indeks < 0 || indeks >= hayvanlar.size()) {
            cout << "Geçersiz indeks! Silme işlemi iptal edildi." << endl;
            return;
        }

                delete hayvanlar[indeks];
        hayvanlar.erase(hayvanlar.begin() + indeks);
        cout << "Hayvan silindi." << endl;
    }

    void hayvanlariDuzenle() {
        if (hayvanlar.empty()) {
            cout << "Düzenlenecek hayvan bulunamadı." << endl;
            return;
        }

        int indeks;
        cout << "Düzenlenecek hayvanın indeksini girin: ";
        cin >> indeks;

        if (indeks < 0 || indeks >= hayvanlar.size()) {
            cout << "Geçersiz indeks! Düzenleme işlemi iptal edildi." << endl;
            return;
        }

        Hayvan* hayvan = hayvanlar[indeks];
        string yeniIsim;
        cout << "Yeni ismi girin: ";
        cin >> yeniIsim;

        hayvan->setIsim(yeniIsim);
        cout << "Hayvan düzenlendi." << endl;
    }

    void tumHayvanlariSil() {
        for (const auto& hayvan : hayvanlar) {
            delete hayvan;
        }

        hayvanlar.clear();
        cout << "Tüm hayvanlar silindi." << endl;
    }

    void hayvanlariBesle() const {
        cout << "----------Hayvan Besleme---------" << endl;
        if (hayvanlar.empty()) {
            cout << "Beslenecek hayvan bulunmuyor." << endl;
        } else {
            for (const auto& hayvan : hayvanlar) {
                hayvan->besle();
            }
        }
    }
};
int main() {
    HayvanatBahcesi hayvanatBahcesi;

    while (true) {
        cout << "----------Hayvanat Bahçesi Yönetim Sistemi---------" << endl;
        cout << "1. Hayvanları Göster" << endl;
        cout << "2. Hayvan Ekle" << endl;
        cout << "3. Hayvan Sil" << endl;
        cout << "4. Hayvanları Düzenle" << endl;
        cout << "5. Tüm Hayvanları Sil" << endl;
        cout << "6. Hayvan Besle" << endl;
        cout << "7. Çıkış" << endl;

        int secim;
        cout << "Bir seçenek girin: ";
        cin >> secim;

        if (secim == 1) {
            hayvanatBahcesi.hayvanlariGoster();
        } else if (secim == 2) {
            cout << "Hayvan türünü girin: ";
            string tur;
            cin >> tur;

            cout << "Hayvan ismini girin: ";
            string isim;
            cin >> isim;

            cout << "Hayvan yaşını girin: ";
            int yas;
            cin >> yas;

            if (tur == "Aslan") {
                hayvanatBahcesi.hayvanEkle(new Aslan(tur, isim, yas));
            } else if (tur == "Zebra") {
                hayvanatBahcesi.hayvanEkle(new Zebra(tur, isim, yas));
            } else if (tur == "Kartal") {
                hayvanatBahcesi.hayvanEkle(new Kartal(tur, isim, yas));
            } else {
                cout << "Geçersiz hayvan türü!" << endl;
            }
        } else if (secim == 3) {
            hayvanatBahcesi.hayvanSil();
        } else if (secim == 4) {
            hayvanatBahcesi.hayvanlariDuzenle();
        } else if (secim == 5) {
            hayvanatBahcesi.tumHayvanlariSil();
        } else if (secim == 6) {
            hayvanatBahcesi.hayvanlariBesle();
        } else if (secim == 7) {
            break;
        } else {
            cout << "Geçersiz seçenek!" << endl;
        }

        cout << endl;
    }

    return 0;
}
