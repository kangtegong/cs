#include <pthread.h>
#include <unistd.h>

#include <iostream>

// 뮤텍스와 조건 변수 선언
pthread_mutex_t mutex;
pthread_cond_t cond;
bool ready = false;

void* thread_job1(void* arg) {
    std::cout << "P1: 먼저 시작" << std::endl;

    pthread_mutex_lock(&mutex);
    std::cout << "P1: 2초 대기" << std::endl;
    while (!ready) {
        pthread_cond_wait(&cond, &mutex);  // 조건 변수 wait
    }
    pthread_mutex_unlock(&mutex);

    std::cout << "P1: 다시 시작" << std::endl;
    std::cout << "P1: 종료" << std::endl;

    return NULL;
}

void* thread_job2(void* arg) {
    std::cout << "P2: 2초 실행 시작" << std::endl;
    sleep(2);  // 2초 대기

    std::cout << "P2: 실행 완료" << std::endl;
    pthread_mutex_lock(&mutex);
    ready = true;
    pthread_cond_signal(&cond);  // 조건 변수 signal
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // 뮤텍스와 조건 변수 초기화
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    // 스레드 생성
    pthread_create(&t1, NULL, thread_job1, NULL);
    pthread_create(&t2, NULL, thread_job2, NULL);

    // 스레드 종료 대기
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // 뮤텍스와 조건 변수 해제
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}