#include <iostream>
#include "Hayvan.h"
#include "Aslan.h"
#include "Zebra.h"
#include "Kartal.h"
#include "HayvanatBahcesi.h"

int main()
{

    /*
     * Testteki tüm caselerin çalışması durumunda 60 puan alacaksınız.
     * Hayvan ekleme 20 puan
     * Hayvanların gösterilmesi 10 puan
     * Hayvanların beslenmesi 10 puan
     * Hayvanların düzenlenmesi 20 puan
     * */

    Hayvan *aslan1 = new Aslan("Simba", "Aslan", 5, "Kahverengi");
    Hayvan *aslan2 = new Aslan("Mufasa", "Aslan", 8, "Sarı");
    Hayvan *zebra1 = new Zebra("Marty", "Zebra", 3, 4);
    Hayvan *zebra2 = new Zebra("Alex", "Zebra", 4, 3);
    Hayvan *kartal1 = new Kartal("Eagle", "Kartal", 2, 160);
    Hayvan *kartal2 = new Kartal("Hawk", "Kartal", 3, 170);

    HayvanatBahcesi hayvanatBahcesi;

    hayvanatBahcesi.hayvanEkle(aslan1);
    hayvanatBahcesi.hayvanEkle(aslan2);
    hayvanatBahcesi.hayvanEkle(zebra1);
    hayvanatBahcesi.hayvanEkle(zebra2);
    hayvanatBahcesi.hayvanEkle(kartal1);
    hayvanatBahcesi.hayvanEkle(kartal2);

    if (hayvanatBahcesi.hayvanlar.size() == 6)
    {
        for (Hayvan *hayvan : hayvanatBahcesi.hayvanlar)
        {
            if (hayvan->getAd() == "Simba")
            {
                std::cout << "HAYVAN EKLE BASARILI: 20 PUAN" << std::endl;
                break;
            }
        }
    }

    std::cout << "----- Hayvanlar -----" << std::endl;
    hayvanatBahcesi.hayvanlariGoster();
    std::cout << std::endl;

    std::cout << "----- Hayvanlari Besleme -----" << std::endl;
    hayvanatBahcesi.hayvanBesle("Simba");
    hayvanatBahcesi.hayvanBesle("Marty");
    hayvanatBahcesi.hayvanBesle("Eagle");
    std::cout << std::endl;

    hayvanatBahcesi.hayvanYasGuncelle("Simba", 6);
    hayvanatBahcesi.hayvanYasGuncelle("Marty", 4);
    hayvanatBahcesi.hayvanYasGuncelle("Eagle", 3);
    std::cout << std::endl;

    for (Hayvan *hayvan : hayvanatBahcesi.hayvanlar)
    {
        if (hayvan->getAd() == "Simba" && hayvan->getYas() == 6)
        {
            std::cout << "HAYVAN DUZENLE BASARILI: 20 puan" << std::endl;
            break;
        }
    }

    return 0;
}