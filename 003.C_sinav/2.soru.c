#include <stdio.h>

#define SATIR 8
#define SUTUN 9

int main() {
    int tablo[SATIR][SUTUN] = {
        {0}
    };

    // tuzaklarin bulunduğu konumlar
    int tuzakKonumlari[][2] = {
        {2, 2},
        {2, 7},
        {3, 4},
        {4, 7},
        {5, 5},
        {5, 9},
        {6, 1},
        {7, 6},
        {8, 3}
    };
    int tuzakSayisi = sizeof(tuzakKonumlari) / sizeof(tuzakKonumlari[0]);

    int tuzaklar = 0;
    int adimlar = 0;

    int basSatir, basSutun;
    int bitSatir, bitSutun;

    printf("Başlangıç noktasının satırını girin (1-%d arası): ", SATIR);
    scanf("%d", &basSatir);
    basSatir--;

    printf("Başlangıç noktasının sütununu girin (1-%d arası): ", SUTUN);
    scanf("%d", &basSutun);
    basSutun--;

    printf("Bitiş noktasının satırını girin (1-%d arası): ", SATIR);
    scanf("%d", &bitSatir);
    bitSatir--;

    printf("Bitiş noktasının sütununu girin (1-%d arası): ", SUTUN);
    scanf("%d", &bitSutun);
    bitSutun--;

    int mevcutSatir = basSatir;
    int mevcutSutun = basSutun;

    tablo[mevcutSatir][mevcutSutun] = 1;

    // Adımları bir dosyaya yaz
    FILE *dosya = fopen("adim.txt", "w");
    while (mevcutSatir != bitSatir || mevcutSutun != bitSutun) {
        fprintf(dosya, "gidilen konumlar: (%d,%d)\n", mevcutSatir + 1, mevcutSutun + 1);
        
        // Tuzak kontrolü
        if (tablo[mevcutSatir][mevcutSutun] == 2) {
            tuzaklar++;
        }

        // En kısa yolu bulmak için hedefe doğru hareket et
        if (mevcutSatir < bitSatir) {
            mevcutSatir++;
        } else if (mevcutSatir > bitSatir) {
            mevcutSatir--;
        } else {
            if (mevcutSutun < bitSutun) {
                mevcutSutun++;
            } else {
                mevcutSutun--;
            }
        }

        // Mevcut konumda tuzak kontrolü
        for (int i = 0; i < tuzakSayisi; i++) {
            if (mevcutSatir == tuzakKonumlari[i][0] - 1 && mevcutSutun == tuzakKonumlari[i][1] - 1) {
                tuzaklar++;
                tablo[mevcutSatir][mevcutSutun] = 2; // Tabloda tuzak konumunu işaretle
                break;
            }
        }

        // Mevcut konumu tabloda işaretle
        tablo[mevcutSatir][mevcutSutun] = 1;

        adimlar++;
    }

    // Son konumda tuzak kontrolü
    if (tablo[mevcutSatir][mevcutSutun] == 2) {
        tuzaklar++;
    }

    // Sonuçları bir dosyaya yaz    
    fprintf(dosya, "Adımlar: %d\nTuzaklar: %d\n", adimlar, tuzaklar);
    fclose(dosya);

    printf("Bitiş noktasına (%d,%d) %d adımda ulaşıldı ve %d tuzak bulundu.\n", bitSatir + 1, bitSutun + 1, adimlar, tuzaklar);

    return 0;
}
