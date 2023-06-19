#include <iostream>

int main() {
    int matris[5][5];
    int toplam = 0;
    int elemanSayisi = 0;

    std::cout << "5x5'lik matrisi doldurun:\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << "Matris[" << i << "][" << j << "]: ";
            std::cin >> matris[i][j];
            if (i + j == 4)
            { // Yedek köşegen üzerindeki elemanlar
                toplam += matris[i][j];
                elemanSayisi++;
            }
        }
    }

    int ortalama = toplam / elemanSayisi;

    std::cout << "Yedek kosegen uzerindeki elemanlarin ortalamasi: " << ortalama << std::endl;

    return 0;
}
