// hayvan.cpp

#include "Hayvan.h"

Hayvan::Hayvan(const std::string &ad, const std::string &tur, int yas)
    : ad(ad), tur(tur), yas(yas)
{
}

Hayvan::~Hayvan()
{
}

std::string Hayvan::getAd() const
{
    return ad;
}

std::string Hayvan::getTur() const
{
    return tur;
}

int Hayvan::getYas() const
{
    return yas;
}

void Hayvan::setYas(int yeniYas)
{
    yas = yeniYas;
}
