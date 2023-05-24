#include "HayvanatBahcesi.h"
#include <iostream>

HayvanatBahcesi::HayvanatBahcesi()
{
}

HayvanatBahcesi::~HayvanatBahcesi()
{
    for (Hayvan *hayvan : hayvanlar)
    {
        delete hayvan;
    }
    hayvanlar.clear();
}

void HayvanatBahcesi::hayvanEkle(Hayvan *hayvan)
{
    hayvanlar.push_back(hayvan);
}

void HayvanatBahcesi::hayvanlariGoster()
{
    for (Hayvan *hayvan : hayvanlar)
    {
        std::cout << "Ad: " << hayvan->getAd() << ", Tur: " << hayvan->getTur() << ", Yas: " << hayvan->getYas() << std::endl;
    }
}

void HayvanatBahcesi::hayvanBesle(const std::string &ad)
{
    for (Hayvan *hayvan : hayvanlar)
    {
        if (hayvan->getAd() == ad)
        {
            // İlgili hayvanı besleme işlemleri
            break;
        }
    }
}

void HayvanatBahcesi::hayvanYasGuncelle(const std::string &ad, int yeniYas)
{
    for (Hayvan *hayvan : hayvanlar)
    {
        if (hayvan->getAd() == ad)
        {
            hayvan->setYas(yeniYas);
            // İlgili hayvanın Yasını güncelleme işlemleri
            break;
        }
    }
}
