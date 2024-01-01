#include <pthread.h>
#include <stdio.h>

int shared_data = 0;    // 공유 데이터
pthread_mutex_t mutex;  // 뮤텍스 선언

void* increment(void* arg) {
    int i;
    for (i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);    // 뮤텍스 락 획득
        shared_data++;                 // 공유 데이터 증가
        pthread_mutex_unlock(&mutex);  // 뮤텍스 락 해제
    }
    return NULL;
}

void* decrement(void* arg) {
    int i;
    for (i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);    // 뮤텍스 락 획득
        shared_data--;                 // 공유 데이터 감소
        pthread_mutex_unlock(&mutex);  // 뮤텍스 락 헤제
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);  // 뮤텍스 초기화

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, decrement, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_data: %d\n", shared_data);
    pthread_mutex_destroy(&mutex);  // 뮤텍스 해제
    return 0;
}
