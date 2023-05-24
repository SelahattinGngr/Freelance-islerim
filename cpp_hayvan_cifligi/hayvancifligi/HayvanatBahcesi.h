#ifndef HAYVANATBAHCESI_H
#define HAYVANATBAHCESI_H

#include <vector>
#include "Hayvan.h"

class HayvanatBahcesi
{
public:
    std::vector<Hayvan *> hayvanlar;
    HayvanatBahcesi();
    ~HayvanatBahcesi();

    void hayvanEkle(Hayvan *hayvan);
    void hayvanlariGoster();
    void hayvanBesle(const std::string &ad);
    void hayvanYasGuncelle(const std::string &ad, int yeniYas);
};

#endif
