#include "Zebra.h"

Zebra::Zebra(const std::string &ad, const std::string &tur, int yas, int bantSayisi)
    : Hayvan(ad, tur, yas), bantSayisi(bantSayisi)
{
}

Zebra::~Zebra()
{
}

int Zebra::getBantSayisi() const
{
    return bantSayisi;
}