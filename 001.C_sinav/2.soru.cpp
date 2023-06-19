#include <iostream>

int main() {
    int dizininboyutu = 10;
    int dizi[dizininboyutu];
    int kucuksayi;

    std::cout << "Lutfen " << dizininboyutu << " adet sayi gir:" << std::endl;
    for (int i = 0; i < dizininboyutu; i++) {
        std::cout << "Sayi " << i + 1 << ": ";
        std::cin >> dizi[i];
    }

    kucuksayi = dizi[0];

    for (int i = 1; i < dizininboyutu; i++) {
        if (dizi[i] < kucuksayi) {
            kucuksayi = dizi[i];
        }
    }

    if (kucuksayi % 2 == 0) {
        std::cout << "En kucuk eleman: " << kucuksayi << " cift sayi" << std::endl;
    } else {
        std::cout << "En kucuk eleman: " << kucuksayi<< " tek sayi" << std::endl;
    }

    return 0;
}
