#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* task1(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Task 1 - Count: %d\n", i + 1);
        sleep(1); // Simulate work
    }
    return NULL;
}

void* task2(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Task 2 - Count: %d\n", i + 1);
        sleep(1); // Simulate work
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, task1, NULL);
    pthread_create(&thread2, NULL, task2, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished execution.\n");

    return 0;
}
