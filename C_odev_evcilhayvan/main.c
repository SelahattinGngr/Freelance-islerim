#include "evcilhayvan.h"

void savePetsToFile(struct Pet pets[], int petCount)
{
    FILE *file = fopen("evcil_veri.txt", "w");
    if (file == NULL)
    {
        printf("Dosya acma hatasi!\n");
        return;
    }

    for (int i = 0; i < petCount; i++)
    {
        fprintf(file, "%s,%s,%d,%d\n", pets[i].species, pets[i].name, pets[i].energy, pets[i].happiness);
    }

    fclose(file);
}

int loadPetsFromFile(struct Pet pets[])
{
    FILE *file = fopen("evcil_veri.txt", "r");
    if (file == NULL)
    {
        printf("Dosya acma hatasi!\n");
        return 0;
    }

    int petCount = 0;
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *token = strtok(line, ",");
        strcpy(pets[petCount].species, token);

        token = strtok(NULL, ",");
        strcpy(pets[petCount].name, token);

        token = strtok(NULL, ",");
        pets[petCount].energy = atoi(token);

        token = strtok(NULL, ",");
        pets[petCount].happiness = atoi(token);

        petCount++;
    }

    fclose(file);
    return petCount;
}

void displayMenu()
{
    printf("\n-- Evcil Hayvan Kontrol Sistemi --\n");
    printf("1. Evcil hayvan ekle\n");
    printf("2. Evcil hayvan guncelle\n");
    printf("3. Evcil hayvan sil\n");
    printf("4. Evcil hayvani besle\n");
    printf("5. Evcil hayvana su ver\n");
    printf("6. Evcil hayvani oyun oynat\n");
    printf("7. Evcil hayvani temizle\n");
    printf("8. Evcil hayvani sev\n");
    printf("9. Evcil hayvani uyut\n");
    printf("10. Evcil hayvana odul ver\n");
    printf("0. cikis\n");
    printf("---------------------------------\n");
    printf("Seciminizi yapin: ");
}

void printStatus(struct Pet pet)
{
    printf("Evcil hayvanin durumu:\n");
    printf("Tur: %s\n", pet.species);
    printf("Ad: %s\n", pet.name);
    printf("Enerji Seviyesi: %d\n", pet.energy);
    printf("Mutluluk Seviyesi: %d\n", pet.happiness);
}

int main()
{
    struct Pet pets[MAX_PETS];
    int petCount = loadPetsFromFile(pets);

    int choice;
    char feedName[20];
    int feedIndex;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Evcil hayvan ekle
            if (petCount >= MAX_PETS)
            {
                printf("Maksimum evcil hayvan sayisina ulasildi!\n");
                break;
            }

            printf("Evcil hayvan turunu girin: ");
            scanf("%s", pets[petCount].species);

            printf("Evcil hayvan adini girin: ");
            scanf("%s", pets[petCount].name);

            pets[petCount].energy = 60;
            pets[petCount].happiness = 60;

            petCount++;
            savePetsToFile(pets, petCount);
            break;

        case 2: // Evcil hayvan guncelle
            printf("Guncellenecek evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                printf("Yeni ismi girin: ");
                scanf("%s", pets[feedIndex].name);

                savePetsToFile(pets, petCount);
                printf("Evcil hayvan guncellendi!\n");
            }
            break;

        case 3: // Evcil hayvan sil
            printf("Silinecek evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                for (int i = feedIndex; i < petCount - 1; i++)
                {
                    pets[i] = pets[i + 1];
                }

                petCount--;
                savePetsToFile(pets, petCount);
                printf("Evcil hayvan silindi!\n");
            }
            break;

        case 4: // Evcil hayvana yemek ver
            printf("Yemek verilecek evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                pets[feedIndex].energy += 15;
                pets[feedIndex].happiness += 10;

                if (pets[feedIndex].energy > 100)
                {
                    pets[feedIndex].energy = 100;
                }

                if (pets[feedIndex].happiness > 100)
                {
                    pets[feedIndex].happiness = 100;
                }

                savePetsToFile(pets, petCount);
                printf("Evcil hayvana yemek verildi!\n");
            }
            break;

        case 5: // Evcil hayvana su ver
            printf("Su verilecek evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                pets[feedIndex].energy += 5;
                pets[feedIndex].happiness += 5;

                if (pets[feedIndex].energy > 100)
                {
                    pets[feedIndex].energy = 100;
                }

                if (pets[feedIndex].happiness > 100)
                {
                    pets[feedIndex].happiness = 100;
                }

                savePetsToFile(pets, petCount);
                printf("Evcil hayvana su verildi!\n");
            }
            break;

        case 6: // Evcil hayvani oyun oynat
            printf("Oyun oynatilacak evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                pets[feedIndex].energy -= 15;
                pets[feedIndex].happiness += 15;

                if (pets[feedIndex].energy < 0)
                {
                    pets[feedIndex].energy = 0;
                }

                if (pets[feedIndex].happiness > 100)
                {
                    pets[feedIndex].happiness = 100;
                }

                savePetsToFile(pets, petCount);
                printf("Evcil hayvanla oyun oynandi!\n");
            }
            break;

        case 7: // Evcil hayvani temizle
            printf("Temizlenecek evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                pets[feedIndex].energy -= 10;
                pets[feedIndex].happiness -= 5;

                if (pets[feedIndex].energy < 0)
                {
                    pets[feedIndex].energy = 0;
                }

                if (pets[feedIndex].happiness < 0)
                {
                    pets[feedIndex].happiness = 0;
                }

                savePetsToFile(pets, petCount);
                printf("Evcil hayvan temizlendi!\n");
            }
            break;

        case 8: // Evcil hayvani sev
            printf("Sevgi gosterilecek evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                pets[feedIndex].happiness += 10;

                if (pets[feedIndex].happiness > 100)
                {
                    pets[feedIndex].happiness = 100;
                }

                savePetsToFile(pets, petCount);
                printf("Evcil hayvana sevgi gosterildi!\n");
            }
            break;

        case 9: // Evcil hayvani uyut
            printf("Uyutulacak evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                pets[feedIndex].energy += 20;

                if (pets[feedIndex].energy > 100)
                {
                    pets[feedIndex].energy = 100;
                }

                savePetsToFile(pets, petCount);
                printf("Evcil hayvan uyutuldu!\n");
            }
            break;

        case 10: // Evcil hayvana odul ver
            printf("odul verilecek evcil hayvanin adini girin: ");
            scanf("%s", feedName);

            feedIndex = -1;
            for (int i = 0; i < petCount; i++)
            {
                if (strcmp(pets[i].name, feedName) == 0)
                {
                    feedIndex = i;
                    break;
                }
            }

            if (feedIndex == -1)
            {
                printf("Evcil hayvan bulunamadi!\n");
            }
            else
            {
                pets[feedIndex].energy += 10;
                pets[feedIndex].happiness += 20;

                if (pets[feedIndex].energy > 100)
                {
                    pets[feedIndex].energy = 100;
                }

                if (pets[feedIndex].happiness > 100)
                {
                    pets[feedIndex].happiness = 100;
                }

                savePetsToFile(pets, petCount);
                printf("Evcil hayvana odul verildi!\n");
            }
            break;

        case 0: // cikis
            printf("Programdan cikiliyor...\n");
            break;

        default:
            printf("Gecersiz secim! Tekrar deneyin.\n");
            break;
        }

        if (choice != 0 && choice >= 1 && choice <= 10)
        {
            printf("Evcil hayvanin guncel durumu:\n");
            printStatus(pets[feedIndex]);
        }
    } while (choice != 0);

    return 0;
}
