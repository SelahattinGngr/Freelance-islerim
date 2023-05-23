#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_TASKS 100
#define MAX_RESOURCES 10
#define STATE_COMPLETED 3

typedef struct {
    int available[10];
    int maximum[100][10];
    int allocated[MAX_TASKS][10];
    int need[100][10];
} resource_t;


typedef struct {
    int task_id;
    int priority;
    int state;
    int allocated[MAX_TASKS][MAX_RESOURCES];
    int required_resources[MAX_RESOURCES];
    pthread_t thread;
} pcb_t;

resource_t resources;
pcb_t tasks[MAX_TASKS];
pthread_mutex_t resource_mutex;
pthread_mutex_t task_mutex;
pthread_cond_t resource_cond;
int num_tasks = 0;

void initialize_resource_pool() {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        resources.available[i] = 10;
        for (int j = 0; j < MAX_TASKS; j++) {
            resources.allocated[j][i] = 0;
        }
    }
}

void* task_fn(void* arg) {
    pcb_t* task = (pcb_t*)arg;
    int task_id = task->task_id;

    // Göreve ait işleri yap
    // ...

    pthread_mutex_lock(&task_mutex);

    // Kaynakları serbest bırak
    for (int i = 0; i < MAX_RESOURCES; i++) {
        resources.available[i] += task->allocated[task_id][i];
        task->allocated[task_id][i] = i;
    }

    // Görevi tamamlandı olarak işaretle
    task->state = STATE_COMPLETED;

    pthread_mutex_unlock(&task_mutex);

    return NULL;
}



void* scheduler_fn(void* arg) {
    while (1) {
        pthread_mutex_lock(&task_mutex);
        int next_task_id = -1;
        int max_priority = -1;

        // En yüksek öncelikli görevi bul
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].state == 1 && tasks[i].priority > max_priority) {
                max_priority = tasks[i].priority;
                next_task_id = i;
            }
        }

        if (next_task_id != -1) {
            pcb_t* next_task = &tasks[next_task_id];

            // Görevin durumunu değiştir
            next_task->state = 2;
            pthread_mutex_unlock(&task_mutex);

            // Görevi başlat
            printf("Executing Task %d\n", next_task_id);
            pthread_create(&next_task->thread, NULL, task_fn, (void*)&next_task_id);
            pthread_join(next_task->thread, NULL);
        } else {
            pthread_mutex_unlock(&task_mutex);
        }
    }
}void* deadlock_fn(void* arg) {
    while (1) {
        pthread_mutex_lock(&task_mutex);
        pthread_mutex_lock(&resource_mutex);
        int deadlock = 1;

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].state == 1) {
                int can_be_allocated = 1;

                for (int j = 0; j < MAX_RESOURCES; j++) {
                    if (resources.available[j] < tasks[i].required_resources[j] - tasks[i].allocated[j][j]) {
                        can_be_allocated = 0;
                        break;
                    }
                }

                if (can_be_allocated) {
                    deadlock = 0;
                    break;
                }
            }
        }

        if (deadlock) {
            // Deadlock durumu var, kaynakları serbest bırak
            for (int i = 0; i < num_tasks; i++) {
                if (tasks[i].state == 1) {
                    for (int j = 0; j < MAX_RESOURCES; j++) {
                        resources.available[j] += tasks[i].allocated[i][j];
                        tasks[i].allocated[i][j] = 0;
                    }
                    tasks[i].state = 0;
                    printf("Task %d released its resources.\n", i);
                }
            }
        }

        pthread_mutex_unlock(&resource_mutex);
        pthread_mutex_unlock(&task_mutex);
    }
}
void create_task(int priority, int required_resources[]) {
    if (num_tasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
        return;
    }

    pthread_mutex_lock(&task_mutex);
    pcb_t* new_task = &tasks[num_tasks];
    new_task->task_id = num_tasks;
    new_task->priority = priority;
    new_task->state = 1;

    // Belirlediğimiz rastgele rakamlarla allocated kaynakları doldur
    srand(time(NULL));
    for (int i = 1; i < MAX_RESOURCES; i++) {
        int random_value = rand() % (resources.available[i] + 1);
        new_task->allocated[new_task->task_id][i] = random_value;
    }

    for (int i = 1; i < MAX_RESOURCES; i++) {
        new_task->required_resources[i] = required_resources[i];
    }

    num_tasks++;

    pthread_mutex_unlock(&task_mutex);
}

void destroy_task(int task_id) {
    pthread_mutex_lock(&task_mutex);
    if (task_id >= num_tasks || task_id < 0) {
        printf("Invalid task ID.\n");
        pthread_mutex_unlock(&task_mutex);
        return;
    }

    pcb_t* task = &tasks[task_id];
    if (task->state != 0) {
        // Görev hala çalışıyorsa iptal et
        pthread_cancel(task->thread);
    }

    // Görevi kaldır
    for (int i = task_id; i < num_tasks - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    num_tasks--;

    pthread_mutex_unlock(&task_mutex);
}
void list_tasks() {
    pthread_mutex_lock(&task_mutex);

    printf("Task List:\n");
    printf("-----------\n");

    for (int i = 0; i < num_tasks; i++) {
        pcb_t* task = &tasks[i];
        printf("Task ID: %d, Priority: %d, State: %d\n", task->task_id, task->priority, task->state);

        printf("Allocated Resources:\n");
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("Resource %d: %d\n", j, task->allocated[task->task_id][j]);
        }

        printf("-----------\n");
    }

    pthread_mutex_unlock(&task_mutex);
}

int main() {
    pthread_mutex_init(&resource_mutex, NULL);
    pthread_mutex_init(&task_mutex, NULL);
    pthread_cond_init(&resource_cond, NULL);
    int resource_cond = 0;
    // Kaynakları ve görevleri başlat
    for (int i = 0; i < MAX_RESOURCES; i++) {
        resources.available[i] = 10;
    }

    pthread_t scheduler_thread, deadlock_thread;
    pthread_create(&scheduler_thread, NULL, scheduler_fn, NULL);
    pthread_create(&deadlock_thread, NULL, deadlock_fn, NULL);

    char command;
    int task_id, priority;
    int required_resources[MAX_RESOURCES];

    while (1) {
        printf("\nTask Manager Menu:\n");
        printf("1. Create Task\n");
        printf("2. Destroy Task\n");
        printf("3. Task List\n");
        printf("4. Exit\n");
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case '1':
                printf("Enter task ID: ");
                scanf("%d", &task_id);
                printf("Enter task priority: ");
                scanf("%d", &priority);
                create_task(priority, required_resources);
                break;
            case '2':
                printf("Enter task ID: ");
                scanf("%d", &task_id);
                destroy_task(task_id);
                break;
            case '4':
                pthread_cancel(scheduler_thread);
                pthread_cancel(deadlock_thread);
                pthread_mutex_destroy(&resource_mutex);
                pthread_mutex_destroy(&task_mutex);
                            pthread_cond_destroy(&resource_cond);
                printf("Exiting Task Manager...\n");
                return 0;
            case '3':
                list_tasks();
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}