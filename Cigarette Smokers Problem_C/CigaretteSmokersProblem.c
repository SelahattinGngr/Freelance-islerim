#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex kilidi ve semaforları tanımla
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t tutkal_sem = PTHREAD_COND_INITIALIZER;
pthread_cond_t kagit_sem = PTHREAD_COND_INITIALIZER;
pthread_cond_t kibrit_sem = PTHREAD_COND_INITIALIZER;

// Sigara içici fonksiyonları
void *sigaraIciciA(void *arg)
{
    while (1)
    {
        // Tutkalı almak için mutex kilidini kilitler
        pthread_mutex_lock(&mutex);
        // Tutkal semaforunu kontrol eder ve uygunsa içme işlemini gerçekleştirir
        pthread_cond_wait(&tutkal_sem, &mutex);
        printf("Sigara içici A: Sigarasını içti!\n");
        // Malzemeyi serbest bırakır
        pthread_mutex_unlock(&mutex);
        // Diğer sigara içicilerine haber verir
        pthread_cond_signal(&kagit_sem);
        pthread_cond_signal(&kibrit_sem);
    }
    return NULL;
}

void *sigaraIciciB(void *arg)
{
    while (1)
    {
        // Kağıdı almak için mutex kilidini kilitler
        pthread_mutex_lock(&mutex);
        // Kağıt semaforunu kontrol eder ve uygunsa içme işlemini gerçekleştirir
        pthread_cond_wait(&kagit_sem, &mutex);
        printf("Sigara içici B: Sigarasını içti!\n");
        // Malzemeyi serbest bırakır
        pthread_mutex_unlock(&mutex);
        // Diğer sigara içicilerine haber verir
        pthread_cond_signal(&tutkal_sem);
        pthread_cond_signal(&kibrit_sem);
    }
    return NULL;
}

void *sigaraIciciC(void *arg)
{
    while (1)
    {
        // Kibriti almak için mutex kilidini kilitler
        pthread_mutex_lock(&mutex);
        // Kibrit semaforunu kontrol eder ve uygunsa içme işlemini gerçekleştirir
        pthread_cond_wait(&kibrit_sem, &mutex);
        printf("Sigara içici C: Sigarasını içti!\n");
        // Malzemeyi serbest bırakır
        pthread_mutex_unlock(&mutex);
        // Diğer sigara içicilerine haber verir
        pthread_cond_signal(&tutkal_sem);
        pthread_cond_signal(&kagit_sem);
    }
    return NULL;
}

// Acente fonksiyonu
void *acente(void *arg)
{
    while (1)
    {
        // Rastgele bir malzeme üretir
        int malzeme = rand() % 3;
        // Mutex kilidini kilitler
        pthread_mutex_lock(&mutex);
        switch (malzeme)
        {
        case 0: // Tutkal üretti
            printf("Acente: Tutkal üretti!\n");
            // Tutkal semaforunu açar
            pthread_cond_signal(&tutkal_sem);
            break;
        case 1: // Kağıt üretti
            printf("Acente: Kağıt üretti!\n");
            // Kağıt semaforunu açar
            pthread_cond_signal(&kagit_sem);
            break;
        case 2: // Kibrit üretti
            printf("Acente: Kibrit üretti!\n");
            // Kibrit semaforunu açar
            pthread_cond_signal(&kibrit_sem);
            break;
        }
        // Mutex kilidini serbest bırakır
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t sigaraIciciAThread, sigaraIciciBThread, sigaraIciciCThread, acenteThread;

    // Sigara içici ve acente thread'lerini oluşturur
    pthread_create(&sigaraIciciAThread, NULL, sigaraIciciA, NULL);
    pthread_create(&sigaraIciciBThread, NULL, sigaraIciciB, NULL);
    pthread_create(&sigaraIciciCThread, NULL, sigaraIciciC, NULL);
    pthread_create(&acenteThread, NULL, acente, NULL);

    // Thread'lerin tamamlanmasını bekler
    pthread_join(sigaraIciciAThread, NULL);
    pthread_join(sigaraIciciBThread, NULL);
    pthread_join(sigaraIciciCThread, NULL);
    pthread_join(acenteThread, NULL);

    return 0;
}
