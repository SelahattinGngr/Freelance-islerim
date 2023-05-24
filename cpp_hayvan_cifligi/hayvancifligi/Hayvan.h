// hayvan.h

#ifndef HAYVAN_H
#define HAYVAN_H

#include <string>

class Hayvan
{
private:
    std::string ad;
    std::string tur;
    int yas;

public:
    Hayvan(const std::string &ad, const std::string &tur, int yas);
    virtual ~Hayvan();

    std::string getAd() const;
    std::string getTur() const;
    int getYas() const;
    void setYas(int yeniYas);
};

#endif
