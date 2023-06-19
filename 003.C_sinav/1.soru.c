#include <stdio.h>
#include <string.h>

#define MAX_KAYIT 5
#define MAX 50

void	*my_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == src) || n == 0)
		return (dest);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

int main() {
    char tablo1[MAX_KAYIT][MAX] = {
        {"Ali Ak"},
        {"Mehmet Durak"},
        {"Berna Sava"},
        {"Ayse Benli"},
        {"Halil Ersoy"}
    };

    int i, j, k;
    
    char tmp[1][MAX];
    for(i = 0; i < 2; i++)
    {
        my_memcpy(tmp[0], tablo1[0], MAX);
        for (j = 0; j < MAX_KAYIT - 1; j++)
        {
            my_memcpy(tablo1[j], tablo1[j+1], MAX);
        }
        my_memcpy(tablo1[MAX_KAYIT - 1], tmp[0], MAX);
    }
    
    for (k = 0; k < MAX_KAYIT; k++) {
        printf("%d %s\n", k + 1, tablo1[k]);
    }

    return 0;
}