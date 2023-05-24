#ifndef ZEBRA_H
#define ZEBRA_H

#include "Hayvan.h"

class Zebra : public Hayvan
{
private:
    int bantSayisi;

public:
    Zebra(const std::string &ad, const std::string &tur, int yas, int bantSayisi);
    ~Zebra();

    int getBantSayisi() const;
};

#endif
