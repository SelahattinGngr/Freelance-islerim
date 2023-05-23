#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Araba {
public:
    int araba_no;
    int sorun_no;
    string varis_saati;
    int tamir_suresi;
    string plaka;

    Araba(int araba_no, int sorun_no, string varis_saati, int tamir_suresi, string plaka) {
        this->araba_no = araba_no;
        this->sorun_no = sorun_no;
        this->varis_saati = varis_saati;
        this->tamir_suresi = tamir_suresi;
        this->plaka = plaka;
    }
};

class Istasyon {
public:
    int istasyon_no;
    Araba* araba;

    Istasyon(int istasyon_no) {
        this->istasyon_no = istasyon_no;
        this->araba = nullptr;
    }

    void arabayiKabulEt(Araba* araba) {
        this->araba = araba;
    }

    void arabayiTamirEt() {
        if (araba != nullptr) {
            auto baslama_saati = chrono::system_clock::now();
            cout << "Istasyon " << istasyon_no << ", " << araba->araba_no << " numarali arabayi tamir ediyor.\n";
            this_thread::sleep_for(chrono::seconds(araba->tamir_suresi));
            auto bitis_saati = chrono::system_clock::now();
            chrono::duration<double> tamir_suresi = bitis_saati - baslama_saati;
            cout << "Istasyon " << istasyon_no << ", " << araba->araba_no << " numarali arabayi tamir etti. Tamir suresi: " << tamir_suresi.count() << " saniye.\n";
        
            ofstream outFile("cikti.txt", ios::app);
            if (outFile.is_open()) {
                outFile << "Istasyon " << istasyon_no << ", " << araba->araba_no << " numarali arabayi tamir etti. Tamir suresi: " << tamir_suresi.count() << " saniye.\n";
                outFile.close();
            }
        }
    }

    void arabayiBirak() {
        this->araba = nullptr;
    }
};

class Tamirhane {
public:
    Istasyon* istasyonlar[3];

    Tamirhane() {
        for (int i = 0; i < 3; i++) {
            istasyonlar[i] = new Istasyon(i+1);
        }
    }
    
    void arabayiKabulEt(Araba* araba) {
        if (araba->sorun_no < 1 || araba->sorun_no > 3) {
            cout << "Gecersiz sorun numarasi. Araba no: " << araba->araba_no << ", sorun no: " << araba->sorun_no << "\n";
            return;
        }
        istasyonlar[araba->sorun_no - 1]->arabayiKabulEt(araba);
        istasyonlar[araba->sorun_no - 1]->arabayiTamirEt();
        istasyonlar[araba->sorun_no - 1]->arabayiBirak();
    }
};

int main() {
    Tamirhane* tamirhane = new Tamirhane();

    ifstream file("Arac.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = 0;
            int araba_no, sorun_no, tamir_suresi;
            string varis_saati, plaka;

            pos = line.find(" ");
            araba_no = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(" ");
            sorun_no = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            pos = line.find(" ");
            varis_saati = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(" ");
            tamir_suresi = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            plaka = line;

            Araba* araba = new Araba(araba_no, sorun_no, varis_saati, tamir_suresi, plaka);
            tamirhane->arabayiKabulEt(araba);
        }
        file.close();
    }
    
    return 0;
}

