#include <iostream>

int main()
{
    int num, digit, sum = 0;
    std::cout << "Bir tam sayi girin: ";
    std::cin >> num;

    // Negatif girisi pozitife cevirme
    if (num < 0)
        num = -num;

    // Basamaklardaki tek sayilari bulma ve toplama islemi
    while (num > 0)
    {
        digit = num % 10;  // Son basamagi al
        if (digit % 2 != 0) // Tek sayi mi?
            sum += digit;
        num /= 10;
    }

    std::cout << "Tek sayilarin toplami: " << sum << std::endl;
    if (sum % 2 == 0)
        std::cout << "Toplam cift sayidir." << std::endl;
    else
        std::cout << "Toplam tek sayidir." << std::endl;
    return 0;
}
