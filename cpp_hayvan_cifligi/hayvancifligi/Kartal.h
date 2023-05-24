#ifndef KARTAL_H
#define KARTAL_H

#include "Hayvan.h"

class Kartal : public Hayvan
{
private:
    int kanatAraligi;

public:
    Kartal(const std::string &ad, const std::string &tur, int yas, int kanatAraligi);
    ~Kartal();

    int getKanatAraligi() const;
};

#endif
