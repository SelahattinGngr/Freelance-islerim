#include <iostream>

int main()
{
    int sayi;
    std::cout << "Bir tam sayi girin: ";
    std::cin >> sayi;

    int toplam = 0;
    int adet = 0;

    while (sayi > 0)
    {
        int basamak = sayi % 10;

        if (basamak % 2 == 0)
        {
            toplam += basamak;
            adet++;
        }

        sayi /= 10;
    }

    if (adet > 0) {
        int ortalama = toplam / adet;

        if (toplam % adet == 0)
            std::cout << "Ortalama tam sayidir: " << ortalama << std::endl;
        else
            std::cout << "Ortalama tam sayi degildir" << std::endl;
    }
    else
        std::cout << "Girilen sayida cift basamakli sayi bulunamadi." << std::endl;

    return 0;
}
