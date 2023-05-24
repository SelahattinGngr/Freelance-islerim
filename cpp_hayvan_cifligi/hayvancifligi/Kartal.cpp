#include "Kartal.h"

Kartal::Kartal(const std::string &ad, const std::string &tur, int yas, int kanatAraligi)
    : Hayvan(ad, tur, yas), kanatAraligi(kanatAraligi)
{
}

Kartal::~Kartal()
{
}

int Kartal::getKanatAraligi() const
{
    return kanatAraligi;
}
