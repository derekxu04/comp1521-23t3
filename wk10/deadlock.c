#include <stdio.h>
#include <pthread.h>

pthread_mutex_t a_lock;
pthread_mutex_t b_lock;
int global_total = 0;

void *print_a(void *data) {
    while (1) {
        pthread_mutex_lock(&a_lock);
        // Has Lock A
        pthread_mutex_lock(&b_lock);
        printf("a\n");
        pthread_mutex_unlock(&b_lock);
        pthread_mutex_unlock(&a_lock);
    }

    return NULL;
}

void *print_b(void *data) {
    while (1) {
        pthread_mutex_lock(&b_lock);
        // Has lock B
        pthread_mutex_lock(&a_lock);
        printf("b\n");
        pthread_mutex_unlock(&a_lock);
        pthread_mutex_unlock(&b_lock);
    }

    return NULL;
}

int main(void) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, print_a, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, print_b, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

}
