#include <stdio.h>

void altdiziyazdir(char *str, int baslangic, int bitis) {
    int uzunluk = bitis - baslangic + 1;
    char altdizi[uzunluk];
    int i, j;

    for (i = baslangic, j = 0; i < bitis; i++, j++) {
        altdizi[j] = str[i];
    }
    altdizi[j] = '\0';

    printf("%s\n", altdizi);
}

int main() {
    char *str = "1q2w345tyo";
    int baslangicindeksi = 2; // q karakterinden sonraki karakterler
    int bitisindeksi = baslangicindeksi + 3; // q karakterinden sonraki 3 karakteri temsil etmek için +2

    altdiziyazdir(str, baslangicindeksi, bitisindeksi);

    return 0;
}
