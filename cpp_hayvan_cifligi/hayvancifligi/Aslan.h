#ifndef ASLAN_H
#define ASLAN_H

#include "Hayvan.h"

class Aslan : public Hayvan
{
private:
    std::string renk;

public:
    Aslan(const std::string &ad, const std::string &tur, int yas, const std::string &renk);
    ~Aslan();

    std::string getRenk() const;
};

#endif
