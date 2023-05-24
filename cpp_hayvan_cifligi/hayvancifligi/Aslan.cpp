#include "Aslan.h"

Aslan::Aslan(const std::string &ad, const std::string &tur, int yas, const std::string &renk)
    : Hayvan(ad, tur, yas), renk(renk)
{
}

Aslan::~Aslan()
{
}

std::string Aslan::getRenk() const
{
    return renk;
}