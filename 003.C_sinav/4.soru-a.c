#include <stdio.h>

void dosyayiguncelle() {
    FILE *dosya = fopen("1.txt", "r+");
    if (dosya == NULL) {
        printf("Dosya acma hatasi!");
        return;
    }
    
    fseek(dosya, 0, SEEK_END);
    long toplamKarakterler = ftell(dosya);
    rewind(dosya);

    char c;
    while ((c = fgetc(dosya)) != EOF) {
        if (c == 'f') {
            fseek(dosya, -1, SEEK_CUR);
            fputc('w', dosya);
            fseek(dosya, 0, SEEK_CUR);
        }
    }
    
    fclose(dosya);
    printf("Toplam karakter sayisi: %ld\n", toplamKarakterler);
}

int main() {
    dosyayiguncelle();
    return 0;
}
