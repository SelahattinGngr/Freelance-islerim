#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
    int label;
};

double mesafe(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int enyakinnokta(int x, int y, struct Point points[], int boyut) {
    double enyakinmesafe = INFINITY;
    int enyakinetiket = -1;

    for (int i = 0; i < boyut; i++) {
        int px = points[i].x;
        int py = points[i].y;
        int etiket = points[i].label;

        double mesaf = mesafe(x, y, px, py);
        if (mesaf < enyakinmesafe) {
            enyakinmesafe = mesaf;
            enyakinetiket = etiket;
        }
    }

    return enyakinetiket;
}

int main() {
    FILE* dosya = fopen("radar.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acilirken hata olustu!");
        return 1;
    }

    struct Point points[100];
    int boyut = 0;

    while (fscanf(dosya, "%d %d %d", &points[boyut].x, &points[boyut].y, &points[boyut].label) != EOF) {
        boyut++;
    }

    fclose(dosya);

    int yeni_x, yeni_y;
    printf("Yeni x koordinatini girin: ");
    scanf("%d", &yeni_x);
    printf("Yeni y koordinatini girin: ");
    scanf("%d", &yeni_y);

    int enyakinetiket = enyakinnokta(yeni_x, yeni_y, points, boyut);

    printf("En yakin etiket: %d\n", enyakinetiket);

    return 0;
}
